// Copyright 2023, STYLE Protocol, All rights reserved.

#include "STYLEUtils.h"

TSharedPtr<FJsonValue> STYLEUtils::CreateJsonValue(FString obj) {
	TSharedPtr<FJsonValue> val;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(obj);
	FJsonSerializer::Deserialize(Reader, val);
	return val;
}

bool STYLEUtils::StatusCodeIsSuccess(int32 statusCode)
{
	if (statusCode > 199 && statusCode < 300)
	{
		return true;
	}
	return false;
}

FString STYLEUtils::SerializeStringArray(const TArray<FString>& StringArray)
{
	TArray<FString> QuotedArray;
	for (const FString& Element : StringArray)
	{
		QuotedArray.Add(FString::Printf(TEXT("\"%s\""), *Element));
	}

	// Join the elements of the quoted array with a comma delimiter
	FString Joined = FString::Join(QuotedArray, TEXT(","));

	// Surround the string with square brackets
	FString SerializedData = FString::Printf(TEXT("[%s]"), *Joined);

	return SerializedData;
}

FString STYLEUtils::SerializeStringArrayDelimiter(const TArray<FString>& StringArray, const TCHAR* Delimiter)
{
	TArray<FString> QuotedArray;
	for (const FString& Element : StringArray)
	{
		QuotedArray.Add(FString::Printf(TEXT("%s"), *Element));
	}

	// Join the elements of the quoted array with a comma delimiter
	FString Joined = FString::Join(QuotedArray, Delimiter);

	return Joined;
}