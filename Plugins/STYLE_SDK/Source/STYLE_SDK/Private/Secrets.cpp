// Copyright 2023, STYLE Protocol, All rights reserved.

#include "Secrets.h"
#include "STYLEUtils.h"

Secrets::Secrets()
{
	ENDPOINTS.SetField(TEXT("5"), MakeShared<FJsonValueString>("https://goerli.infura.io/v3/b11900c9ab7d46baa4df3c6f00486790"));

	ALCHEMY_KEY = FString(TEXT("fkzaA-XsSzn8mMUVjGzWnan4_HgNlTRf"));
}
