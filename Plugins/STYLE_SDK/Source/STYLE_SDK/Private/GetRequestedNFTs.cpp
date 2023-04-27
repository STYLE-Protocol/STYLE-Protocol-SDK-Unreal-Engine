// Copyright 2023, STYLE Protocol, All rights reserved.


#include "GetRequestedNFTs.h"
#include "STYLERequestBuilder.h"
#include "Constants.h"
#include "Secrets.h"
#include "STYLEUtils.h"

UGetRequestedNFTs* UGetRequestedNFTs::GetRequestedNFTs(
	TArray<FString> metaverseFilter,
	TArray<FString> typeFilter,
	TArray<FString> subtypeFilter,
	int32 cursor,
	int32 amount,
	int32 chainId)
{
	FString ENDPOINT = Secrets().ENDPOINTS.GetStringField(FString::FromInt(chainId));
	TArray< FStringFormatArg > args;
	args.Add(FStringFormatArg(Constants().API_HOST));
	args.Add(FStringFormatArg(ENDPOINT));
	FString url = FString::Format(TEXT("https://{0}/api/nfts/get-requested-nfts?endpoint={1}"), args);

	if (metaverseFilter.Num() != 0) {
		TArray< FStringFormatArg > argsT;
		argsT.Add(FStringFormatArg(url));
		argsT.Add(FStringFormatArg(STYLEUtils::SerializeStringArray(metaverseFilter)));
		url = FString::Format(TEXT("{0}&metaverseFilter={1}"), argsT);
	}
	if (typeFilter.Num() != 0) {
		TArray< FStringFormatArg > argsT;
		argsT.Add(FStringFormatArg(url));
		argsT.Add(FStringFormatArg(STYLEUtils::SerializeStringArray(typeFilter)));
		url = FString::Format(TEXT("{0}&typeFilter={1}"), argsT);
	}
	if (subtypeFilter.Num() != 0) {
		TArray< FStringFormatArg > argsT;
		argsT.Add(FStringFormatArg(url));
		argsT.Add(FStringFormatArg(STYLEUtils::SerializeStringArray(subtypeFilter)));
		url = FString::Format(TEXT("{0}&subtypeFilter={1}"), argsT);
	}

	UGetRequestedNFTs* GetRequestedNFTsInstance = NewObject<UGetRequestedNFTs>();
	GetRequestedNFTsInstance->RequestBuilder.Url = url;
	GetRequestedNFTsInstance->RequestBuilder.OnCompleteDelegate.BindUObject(GetRequestedNFTsInstance, &USTYLEAsyncRequest::OnResponse);

	return GetRequestedNFTsInstance;
}

void UGetRequestedNFTs::Activate()
{
	RequestBuilder.ExecuteRequest();
}

void UGetRequestedNFTs::ProcessResponse(FHttpResponsePtr Response, int32 statusCode)
{	
	Super::ProcessResponse(Response, statusCode);
	const FString ResponseText = Response->GetContentAsString();

	TArray<TSharedPtr<FJsonValue>> ContractsData;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseText);
	FJsonSerializer::Deserialize(Reader, ContractsData);

	TArray<FString> ArrayResponse;
	for (const TSharedPtr<FJsonValue>& Element : ContractsData)
	{
		FString ArrayResponseOne;
		const TSharedRef<TJsonWriter<TCHAR>> Writer = TJsonWriterFactory<>::Create(&ArrayResponseOne);
		FJsonSerializer::Serialize(Element, FString(), Writer);

		ArrayResponse.Add(ArrayResponseOne);
	}
	FString ResponseFinal = STYLEUtils::SerializeStringArrayDelimiter(ArrayResponse, Constants().Delimiter);

	OnResponseOutput.Broadcast(ResponseFinal, statusCode);
	OnCompleted.Broadcast(ResponseFinal, statusCode);
}
