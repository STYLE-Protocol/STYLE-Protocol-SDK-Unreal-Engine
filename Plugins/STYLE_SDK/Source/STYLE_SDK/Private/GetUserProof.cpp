// Copyright 2023, STYLE Protocol, All rights reserved.


#include "GetUserProof.h"
#include "Constants.h"
#include "Endpoints/GetAccounts.h"
#include "STYLEUtils.h"
#include "GetContractsData.h"
#include "Endpoints/RpcCall.h"

UGetUserProof* UGetUserProof::GetUserProof()
{
	UGetUserProof* GetUserProofInstance = NewObject<UGetUserProof>();

	GetUserProofInstance->EntryInstance = UGetAccounts::GetAccounts(nullptr, 5, "");
	GetUserProofInstance->EntryInstance->GetOnCompletedDelegate().AddUObject(GetUserProofInstance, &UGetUserProof::OnResponse1);
	return GetUserProofInstance;
}

void UGetUserProof::Activate()
{
	EntryInstance->Activate();
}

void UGetUserProof::ProcessResponse(FHttpResponsePtr Response, int32 statusCode)
{
	Super::ProcessResponse(Response, statusCode);
	const FString ResponseText = Response->GetContentAsString();
	OnResponseOutput.Broadcast(ResponseText, statusCode);
	OnCompleted.Broadcast(ResponseText, statusCode);
}

void UGetUserProof::OnResponse1(FString Response, int32 StatusCode)
{
	WalletAddress = Response;
	UGetContractsData* GetContractsDataInstance = UGetContractsData::GetContractsData();
	GetContractsDataInstance->GetOnCompletedDelegate().AddUObject(this, &UGetUserProof::OnResponse2);
	GetContractsDataInstance->Activate();
}

void UGetUserProof::OnResponse2(FString Response, int32 StatusCode)
{
	if (!STYLEUtils::StatusCodeIsSuccess(StatusCode))
	{
		OnResponseOutput.Broadcast(Response, StatusCode);
		OnCompleted.Broadcast(Response, StatusCode);
		return;
	}

	TSharedPtr<FJsonObject> ContractsData;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response);
	FJsonSerializer::Deserialize(Reader, ContractsData);

	StorageMessage = ContractsData->GetStringField("StorageMessage");

	TArray< FStringFormatArg > args;
	args.Add(FStringFormatArg(StorageMessage));
	args.Add(FStringFormatArg(WalletAddress));
	FString request = FString::Format(TEXT("{\"method\": \"personal_sign\",\"params\": [\"{0}\", \"{1}\"]}"), args);

	URpcCall* RpcCallInstance = URpcCall::RpcCall(nullptr, request, 5);
	RpcCallInstance->GetOnCompletedDelegate().AddUObject(this, &UGetUserProof::OnResponse3);
	RpcCallInstance->Activate();
}

void UGetUserProof::OnResponse3(FString Response, int32 StatusCode)
{
	if (!STYLEUtils::StatusCodeIsSuccess(StatusCode))
	{
		OnResponseOutput.Broadcast(Response, StatusCode);
		OnCompleted.Broadcast(Response, StatusCode);
		return;
	}	

	TArray< FStringFormatArg > args;
	args.Add(FStringFormatArg(WalletAddress));
	args.Add(FStringFormatArg(Response));
	FString UserProofSer = FString::Format(TEXT("{\"walletAddress\":\"{0}\",\"signature\":\"{1}\"}"), args);

	OnResponseOutput.Broadcast(UserProofSer, 200);
	OnCompleted.Broadcast(UserProofSer, 200);
}
