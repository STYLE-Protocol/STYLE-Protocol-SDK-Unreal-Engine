// Copyright 2023, STYLE Protocol, All rights reserved.


#include "STYLERequestBuilder.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "STYLEUtils.h"

void FSTYLEBaseRequest::InitializeRequest()
{
	Request = FHttpModule::Get().CreateRequest();
	Request->SetVerb(TEXT("GET"));
}

void FSTYLEBaseRequest::FinalizeRequest() const
{
	Request->SetURL(RequestUrl);
	Request->OnProcessRequestComplete() = OnCompleteDelegate;
	UE_LOG(LogTemp, Warning, TEXT("Processing request in stylebaserequest finalize request for %s"), *RequestUrl)
		Request->ProcessRequest();
}

void FSTYLEGetRequestedNFTsRequest::BuildRequest()
{
	RequestUrl = Url;
}

void FSTYLEGetOwnedDerivativesRequest::BuildRequest()
{
	RequestUrl = Url;
}

void FSTYLEGetContractsDataRequest::BuildRequest()
{
	RequestUrl = Url;
}