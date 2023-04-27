// Copyright 2023, STYLE Protocol, All rights reserved.

#pragma once

#include "Runtime/Online/HTTP/Public/Http.h"
#include "STYLEAsyncRequest.h"
#include "Json.h"
#include "Endpoints/GetAccounts.h"
#include "ApproveERC20.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOutputPinApproveERC20, FString, Response, int32, StatusCode);

UCLASS()
class STYLE_SDK_API UApproveERC20 : public USTYLEAsyncRequest
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "style.sdk|generic")
		static UApproveERC20* ApproveERC20(
			FString NFT,
			int32 chainId = 5
		);

	virtual void Activate() override;

protected:
	virtual void ProcessResponse(FHttpResponsePtr Response, int32 statusCode) override;
	virtual void OnResponse1(FString Response, int32 StatusCode);
	virtual void OnResponse2(FString Response, int32 StatusCode);
	virtual void OnResponse3(FString Response, int32 StatusCode);
	virtual void OnResponse4(FString Response, int32 StatusCode);

private:
	UPROPERTY(BlueprintAssignable, meta = (AllowPrivateAccess = true))
		FOutputPinApproveERC20 OnResponseOutput;

	UGetAccounts* EntryInstance;
	TSharedPtr<FJsonObject> NFTParsed;
	int32 ChainId;
	FString ProtocolContract;
	FString WalletAddress;

};