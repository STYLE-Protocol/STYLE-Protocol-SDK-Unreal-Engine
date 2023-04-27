// Copyright 2023, STYLE Protocol, All rights reserved.

#pragma once

#include "HTTP/Public/Interfaces/IHttpRequest.h"

class FSTYLEBaseRequest
{
public:
	virtual ~FSTYLEBaseRequest() = default;

	int32 ChainID;
	FString ChainMetadataVar;
	FHttpRequestCompleteDelegate OnCompleteDelegate;

	void ExecuteRequest()
	{
		InitializeRequest();
		BuildRequest();
		FinalizeRequest();
	};

protected:
	void InitializeRequest();
	virtual void BuildRequest() = 0;
	void FinalizeRequest() const;

	typedef TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>> FCondensedJsonStringWriterFactory;
	typedef TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR>> FCondensedJsonStringWriter;

	FString RequestUrl;
	FHttpRequestPtr Request;
};

class FSTYLEGetRequestedNFTsRequest : public FSTYLEBaseRequest
{
public:
	FString Url;
protected:
	virtual void BuildRequest() override;
};

class FSTYLEGetOwnedDerivativesRequest : public FSTYLEBaseRequest
{
public:
	FString Url;
protected:
	virtual void BuildRequest() override;
};

class FSTYLEGetContractsDataRequest : public FSTYLEBaseRequest
{
public:
	FString Url;
protected:
	virtual void BuildRequest() override;
};