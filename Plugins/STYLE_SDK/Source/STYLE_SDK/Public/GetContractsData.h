// Copyright 2023, STYLE Protocol, All rights reserved.

#pragma once

#include "Runtime/Online/HTTP/Public/Http.h"
#include "STYLEAsyncRequest.h"
#include "STYLERequestBuilder.h"
#include "GetContractsData.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOutputPinGetContractsData, FString, Response, int32, StatusCode);

UCLASS()
class STYLE_SDK_API UGetContractsData : public USTYLEAsyncRequest
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "style.sdk|generic")
		static UGetContractsData* GetContractsData();

	virtual void Activate() override;

protected:
	virtual void ProcessResponse(FHttpResponsePtr Response, int32 statusCode) override;

private:
	UPROPERTY(BlueprintAssignable, meta = (AllowPrivateAccess = true))
		FOutputPinGetContractsData OnResponseOutput;

	FSTYLEGetContractsDataRequest RequestBuilder;
};