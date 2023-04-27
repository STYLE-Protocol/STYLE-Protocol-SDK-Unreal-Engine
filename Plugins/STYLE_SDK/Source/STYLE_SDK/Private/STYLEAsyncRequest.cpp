// Copyright 2023, STYLE Protocol, All rights reserved.

#include "STYLEAsyncRequest.h"
#include "STYLEUtils.h"


void USTYLEAsyncRequest::OnResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (bWasSuccessful) {
		const int32 statusCode = Response->GetResponseCode();
		if (!STYLEUtils::StatusCodeIsSuccess(statusCode))
		{
			this->OnFailure.Broadcast();
			return;
		}

		const FString ResponseText = Response->GetContentAsString();

		this->ProcessResponse(Response, statusCode);

		return;
	}

	this->OnFailure.Broadcast();
}

void USTYLEAsyncRequest::ProcessResponse(FHttpResponsePtr Response, int32 statusCode)
{
}

