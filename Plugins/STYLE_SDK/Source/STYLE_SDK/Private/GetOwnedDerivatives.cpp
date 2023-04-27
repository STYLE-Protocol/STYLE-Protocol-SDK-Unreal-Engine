// Copyright 2023, STYLE Protocol, All rights reserved.


#include "GetOwnedDerivatives.h"
#include "STYLERequestBuilder.h"
#include "Constants.h"
#include "Secrets.h"
#include "STYLEUtils.h"

UGetOwnedDerivatives* UGetOwnedDerivatives::GetOwnedDerivatives(
	FString userProof,
	int32 chainId)
{
	FString ENDPOINT = Secrets().ENDPOINTS.GetStringField(FString::FromInt(chainId));
	FString ALCHEMY_KEY = Secrets().ALCHEMY_KEY;

	TArray< FStringFormatArg > args;
	args.Add(FStringFormatArg(Constants().API_HOST));
	args.Add(FStringFormatArg(ENDPOINT));
	args.Add(FStringFormatArg(ALCHEMY_KEY));
	args.Add(FStringFormatArg(userProof));

	FString url = FString::Format(TEXT("https://{0}/api/nfts/get-owned-derivatives?endpoint={1}&alchemyKey={2}&userProof={3}"), args);

	UGetOwnedDerivatives* GetOwnedDerivativesInstance = NewObject<UGetOwnedDerivatives>();
	GetOwnedDerivativesInstance->RequestBuilder.Url = url;
	GetOwnedDerivativesInstance->RequestBuilder.OnCompleteDelegate.BindUObject(GetOwnedDerivativesInstance, &USTYLEAsyncRequest::OnResponse);

	return GetOwnedDerivativesInstance;
}

void UGetOwnedDerivatives::Activate()
{
	RequestBuilder.ExecuteRequest();
}

void UGetOwnedDerivatives::ProcessResponse(FHttpResponsePtr Response, int32 statusCode)
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
