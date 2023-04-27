// Copyright 2023, STYLE Protocol, All rights reserved.

#pragma once

#include "Runtime/Online/HTTP/Public/Http.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "STYLEAsyncRequest.generated.h"

// Wider support for c++ bindings since c++ fxns cannot bind to dynamic delegates

DECLARE_MULTICAST_DELEGATE_TwoParams(FSTYLEOnCompleted, FString, int32);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSTYLEFailedOutputPin);

UCLASS()
class USTYLEAsyncRequest : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	FSTYLEOnCompleted& GetOnCompletedDelegate() { return OnCompleted; }

protected:
	virtual void OnResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	virtual void ProcessResponse(FHttpResponsePtr Response, int32 statusCode);

	// Call from child class
	FSTYLEOnCompleted OnCompleted;

private:
	UPROPERTY(BlueprintAssignable, meta = (AllowPrivateAccess = true))
		FSTYLEFailedOutputPin OnFailure;
};

