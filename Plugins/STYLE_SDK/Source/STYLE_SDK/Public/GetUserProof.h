// Copyright 2023, STYLE Protocol, All rights reserved.

#pragma once

#include "Runtime/Online/HTTP/Public/Http.h"
#include "STYLEAsyncRequest.h"
#include "Json.h"
#include "Endpoints/GetAccounts.h"
#include "GetUserProof.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOutputPinGetUserProof, FString, Response, int32, StatusCode);

UCLASS()
class STYLE_SDK_API UGetUserProof : public USTYLEAsyncRequest
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "style.sdk|generic")
		static UGetUserProof* GetUserProof();

	virtual void Activate() override;

protected:
	virtual void ProcessResponse(FHttpResponsePtr Response, int32 statusCode) override;
	virtual void OnResponse1(FString Response, int32 StatusCode);
	virtual void OnResponse2(FString Response, int32 StatusCode);
	virtual void OnResponse3(FString Response, int32 StatusCode);

private:
	UPROPERTY(BlueprintAssignable, meta = (AllowPrivateAccess = true))
		FOutputPinGetUserProof OnResponseOutput;

	UGetAccounts* EntryInstance;
	TSharedPtr<FJsonObject> NFTParsed;
	int32 ChainId;
	FString StorageMessage;
	FString WalletAddress;
};