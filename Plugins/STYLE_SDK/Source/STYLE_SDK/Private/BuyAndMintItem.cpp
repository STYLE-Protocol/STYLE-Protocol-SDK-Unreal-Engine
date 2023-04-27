// Copyright 2023, STYLE Protocol, All rights reserved.


#include "BuyAndMintItem.h"
#include "Constants.h"
#include "Endpoints/GetAccounts.h"
#include "Endpoints/SendContract.h"
#include "STYLEUtils.h"
#include "GetContractsData.h"

UBuyAndMintItem* UBuyAndMintItem::BuyAndMintItem(FString NFT, int32 chainId)
{
	UBuyAndMintItem* BuyAndMintItemInstance = NewObject<UBuyAndMintItem>();

	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(NFT);
	FJsonSerializer::Deserialize(Reader, BuyAndMintItemInstance->NFTParsed);

	BuyAndMintItemInstance->ChainId = chainId;

	BuyAndMintItemInstance->EntryInstance = UGetAccounts::GetAccounts(nullptr, 5, "");
	BuyAndMintItemInstance->EntryInstance->GetOnCompletedDelegate().AddUObject(BuyAndMintItemInstance, &UBuyAndMintItem::OnResponse1);
	return BuyAndMintItemInstance;
}

void UBuyAndMintItem::Activate()
{
	EntryInstance->Activate();
}

void UBuyAndMintItem::ProcessResponse(FHttpResponsePtr Response, int32 statusCode)
{
	Super::ProcessResponse(Response, statusCode);
	const FString ResponseText = Response->GetContentAsString();
	OnResponseOutput.Broadcast(ResponseText, statusCode);
	OnCompleted.Broadcast(ResponseText, statusCode);
}

void UBuyAndMintItem::OnResponse1(FString Response, int32 StatusCode)
{
	if (!STYLEUtils::StatusCodeIsSuccess(StatusCode))
	{
		OnResponseOutput.Broadcast(Response, StatusCode);
		OnCompleted.Broadcast(Response, StatusCode);
		return;
	}

	WalletAddress = Response;
	UGetContractsData* GetContractsDataInstance = UGetContractsData::GetContractsData();
	GetContractsDataInstance->GetOnCompletedDelegate().AddUObject(this, &UBuyAndMintItem::OnResponse2);
	GetContractsDataInstance->Activate();
}

void UBuyAndMintItem::OnResponse2(FString Response, int32 StatusCode)
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
	
	FString PaymentValue = NFTParsed->GetObjectField("payment")->GetStringField("value");
	FString PaymentToken = NFTParsed->GetObjectField("paymentToken")->GetStringField("address");
	
	TArray<FString> params0;
	params0.Add(NFTParsed->GetStringField("tokenId"));
	params0.Add(PaymentValue);
	params0.Add(NFTParsed->GetStringField("tokenAddress"));
	params0.Add(NFTParsed->GetStringField("metaverseId"));
	params0.Add(PaymentToken);
	params0.Add(NFTParsed->GetStringField("modelId"));
	params0.Add(NFTParsed->GetStringField("bidder"));
	params0.Add(NFTParsed->GetStringField("environment"));
	params0.Add(NFTParsed->GetStringField("uri"));
	params0.Add(NFTParsed->GetStringField("signature"));

	TArray<FString> params;
	params.Add(WalletAddress);
	params.Add(STYLEUtils::SerializeStringArray(params0));
	params.Add(NFTParsed->GetStringField("adminSignature"));
	params.Add(PaymentValue);

	USendContract* SendContractInstance = USendContract::SendContract(nullptr,
		ProtocolContract,
		"buyAndMint",
		Constants().PROTOCOL_ABI,
		params,
		-1,
		"0",
		5);
	SendContractInstance->GetOnCompletedDelegate().AddUObject(this, &UBuyAndMintItem::OnResponse3);
	SendContractInstance->Activate();
}

void UBuyAndMintItem::OnResponse3(FString Response, int32 StatusCode)
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