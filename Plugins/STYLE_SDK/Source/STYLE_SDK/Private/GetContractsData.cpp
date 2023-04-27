// Copyright 2023, STYLE Protocol, All rights reserved.


#include "GetContractsData.h"
#include "STYLERequestBuilder.h"
#include "Constants.h"

UGetContractsData* UGetContractsData::GetContractsData()
{
	TArray< FStringFormatArg > args;
	args.Add(FStringFormatArg(Constants().API_HOST));
	FString url = FString::Format(TEXT("https://{0}/api/contracts"), args);

	UGetContractsData* GetContractsDataInstance = NewObject<UGetContractsData>();
	GetContractsDataInstance->RequestBuilder.Url = url;
	GetContractsDataInstance->RequestBuilder.OnCompleteDelegate.BindUObject(GetContractsDataInstance, &USTYLEAsyncRequest::OnResponse);

	return GetContractsDataInstance;
}

void UGetContractsData::Activate()
{
	RequestBuilder.ExecuteRequest();
}

void UGetContractsData::ProcessResponse(FHttpResponsePtr Response, int32 statusCode)
{
	Super::ProcessResponse(Response, statusCode);
	const FString ResponseText = Response->GetContentAsString();
	OnResponseOutput.Broadcast(ResponseText, statusCode);
	OnCompleted.Broadcast(ResponseText, statusCode);
}
