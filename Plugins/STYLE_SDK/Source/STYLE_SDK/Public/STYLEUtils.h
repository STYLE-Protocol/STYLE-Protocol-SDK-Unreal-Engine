// Copyright 2023, STYLE Protocol, All rights reserved.

#pragma once

#include "Json.h"

class STYLEUtils
{
public:
	static TSharedPtr<FJsonValue> CreateJsonValue(FString obj);

	static bool StatusCodeIsSuccess(int32 statusCode);

	static FString SerializeStringArray(const TArray<FString>& StringArray);
	static FString SerializeStringArrayDelimiter(const TArray<FString>& StringArray, const TCHAR* Delimiter);
	static bool IsGreater(FString str1, FString str2);
};