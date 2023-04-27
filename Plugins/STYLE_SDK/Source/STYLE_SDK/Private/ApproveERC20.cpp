// Copyright 2023, STYLE Protocol, All rights reserved.


#include "ApproveERC20.h"
#include "Constants.h"
#include "Endpoints/GetAccounts.h"
#include "Endpoints/CallContract.h"
#include "Endpoints/SendContract.h"
#include "STYLEUtils.h"
#include "GetContractsData.h"

UApproveERC20* UApproveERC20::ApproveERC20(FString NFT, int32 chainId)
{
	UApproveERC20* ApproveERC20Instance = NewObject<UApproveERC20>();

	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(NFT);
	FJsonSerializer::Deserialize(Reader, ApproveERC20Instance->NFTParsed);

	ApproveERC20Instance->ChainId = chainId;

	ApproveERC20Instance->EntryInstance = UGetAccounts::GetAccounts(nullptr, 5, "");
	ApproveERC20Instance->EntryInstance->GetOnCompletedDelegate().AddUObject(ApproveERC20Instance, &UApproveERC20::OnResponse1);
	return ApproveERC20Instance;
}

void UApproveERC20::Activate()
{
	EntryInstance->Activate();
}

void UApproveERC20::ProcessResponse(FHttpResponsePtr Response, int32 statusCode)
{
	Super::ProcessResponse(Response, statusCode);
	const FString ResponseText = Response->GetContentAsString();
	OnResponseOutput.Broadcast(ResponseText, statusCode);
	OnCompleted.Broadcast(ResponseText, statusCode);
}

void UApproveERC20::OnResponse1(FString Response, int32 StatusCode)
{
	if (!STYLEUtils::StatusCodeIsSuccess(StatusCode))
	{
		OnResponseOutput.Broadcast(Response, StatusCode);
		OnCompleted.Broadcast(Response, StatusCode);
		return;
	}

	WalletAddress = Response;
	UGetContractsData* GetContractsDataInstance = UGetContractsData::GetContractsData();
	GetContractsDataInstance->GetOnCompletedDelegate().AddUObject(this, &UApproveERC20::OnResponse2);
	GetContractsDataInstance->Activate();
}

void UApproveERC20::OnResponse2(FString Response, int32 StatusCode)
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

	ProtocolContract = ContractsData->GetObjectField("protocols")->GetStringField(FString::FromInt(ChainId));
	FString PaymentToken = NFTParsed->GetObjectField("paymentToken")->GetStringField("address");

	TArray<FString> params;
	params.Add(WalletAddress);
	params.Add(ProtocolContract);


	UCallContract* CallContractInstance = UCallContract::CallContract(nullptr,
		PaymentToken,
		"allowance",
		Constants().ERC20_ABI,
		params,
		-1,
		"0",
		5);
	CallContractInstance->GetOnCompletedDelegate().AddUObject(this, &UApproveERC20::OnResponse3);
	CallContractInstance->Activate();
}

void UApproveERC20::OnResponse3(FString Response, int32 StatusCode)
{
	if (!STYLEUtils::StatusCodeIsSuccess(StatusCode))
	{
		OnResponseOutput.Broadcast(Response, StatusCode);
		OnCompleted.Broadcast(Response, StatusCode);
		return;
	}

	FString PaymentValue = NFTParsed->GetObjectField("payment")->GetStringField("value");
	FString Allowance = Response;
	FString PaymentToken = NFTParsed->GetObjectField("paymentToken")->GetStringField("address");
	
	if (STYLEUtils::IsGreater(PaymentValue, Allowance)) {
		TArray<FString> params;
		params.Add(ProtocolContract);
		params.Add(PaymentValue);

		USendContract* SendContractInstance = USendContract::SendContract(nullptr,
			PaymentToken,
			"approve",
			Constants().ERC20_ABI,
			params,
			-1,
			"",
			5);
		SendContractInstance->GetOnCompletedDelegate().AddUObject(this, &UApproveERC20::OnResponse4);
		SendContractInstance->Activate();
	}
	else {
		OnResponseOutput.Broadcast("true", 200);
		OnCompleted.Broadcast("true", 200);
	}
}

void UApproveERC20::OnResponse4(FString Response, int32 StatusCode)
{
	if (!STYLEUtils::StatusCodeIsSuccess(StatusCode))
	{
		OnResponseOutput.Broadcast(Response, StatusCode);
		OnCompleted.Broadcast(Response, StatusCode);
		return;
	}

	OnResponseOutput.Broadcast("true", 200);
	OnCompleted.Broadcast("true", 200);
}