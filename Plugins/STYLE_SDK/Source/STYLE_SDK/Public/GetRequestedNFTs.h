// Copyright 2023, STYLE Protocol, All rights reserved.

#pragma once

#include "Runtime/Online/HTTP/Public/Http.h"
#include "STYLEAsyncRequest.h"
#include "STYLERequestBuilder.h"
#include "GetRequestedNFTs.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOutputPinGetRequestedNFTs, FString, Response, int32, StatusCode);

UCLASS()
class STYLE_SDK_API UGetRequestedNFTs : public USTYLEAsyncRequest
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "style.sdk|generic")
		static UGetRequestedNFTs* GetRequestedNFTs(
			TArray<FString> metaverseFilter,
			TArray<FString> typeFilter,
			TArray<FString> subtypeFilter,
			int32 cursor = 0,
			int32 amount = 100,
			int32 chainId = 5
		);

	virtual void Activate() override;

protected:
	virtual void ProcessResponse(FHttpResponsePtr Response, int32 statusCode) override;

private:
	UPROPERTY(BlueprintAssignable, meta = (AllowPrivateAccess = true))
		FOutputPinGetRequestedNFTs OnResponseOutput;

	FSTYLEGetRequestedNFTsRequest RequestBuilder;
};