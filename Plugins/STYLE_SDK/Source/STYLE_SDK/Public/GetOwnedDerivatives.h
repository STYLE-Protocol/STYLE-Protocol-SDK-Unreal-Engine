// Copyright 2023, STYLE Protocol, All rights reserved.

#pragma once

#include "Runtime/Online/HTTP/Public/Http.h"
#include "STYLEAsyncRequest.h"
#include "STYLERequestBuilder.h"
#include "GetOwnedDerivatives.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOutputPinGetOwnedDerivatives, FString, Response, int32, StatusCode);

UCLASS()
class STYLE_SDK_API UGetOwnedDerivatives : public USTYLEAsyncRequest
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "style.sdk|generic")
		static UGetOwnedDerivatives* GetOwnedDerivatives(
			TArray<FString> metaverseFilter,
			TArray<FString> typeFilter,
			TArray<FString> subtypeFilter,
			FString userProof,
			int32 chainId = 5
		);

	virtual void Activate() override;

	typedef TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>> FCondensedJsonStringWriterFactory;
	typedef TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR>> FCondensedJsonStringWriter;

protected:
	virtual void ProcessResponse(FHttpResponsePtr Response, int32 statusCode) override;

private:
	UPROPERTY(BlueprintAssignable, meta = (AllowPrivateAccess = true))
		FOutputPinGetOwnedDerivatives OnResponseOutput;

	FSTYLEGetOwnedDerivativesRequest RequestBuilder;
};