// Copyright 2023, STYLE Protocol, All rights reserved.


#include "GetRequestedNFTs.h"
#include "Misc/AutomationTest.h"
#include "STYLEUtils.h"

BEGIN_DEFINE_SPEC(STYLE_SDKGetRequestedNFTs,
	"STYLE_SDK.STYLERequests.GetRequestedNFTs",
	EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask);
void OnResponse(FString Response, int32 StatusCode);
FDoneDelegate TestDoneDelegate;
END_DEFINE_SPEC(STYLE_SDKGetRequestedNFTs)

void STYLE_SDKGetRequestedNFTs::Define()
{
	Describe("Execute GetRequestedNFTs request tests",
		[this]()
		{
			LatentIt("GetRequestedNFTs Async Node",
				EAsyncExecution::TaskGraph, FTimespan(0, 0, 30),
				[this](const FDoneDelegate TestDone)
				{
					TestDoneDelegate = TestDone;
					UGetRequestedNFTs* GetRequestedNFTsInstance = UGetRequestedNFTs::GetRequestedNFTs(TArray<FString>(), TArray<FString>(), TArray<FString>());
					GetRequestedNFTsInstance->GetOnCompletedDelegate().AddRaw(this, &STYLE_SDKGetRequestedNFTs::OnResponse);
					GetRequestedNFTsInstance->Activate();
				});
		});
}

void STYLE_SDKGetRequestedNFTs::OnResponse(FString Response, int32 StatusCode)
{
	const bool bWasSuccessful = STYLEUtils::StatusCodeIsSuccess(StatusCode);

	TestTrue("CallContract Request run successfully!", bWasSuccessful);
	UE_LOG(LogTemp, Display, TEXT("CallContract Response: %s"), *Response);
	// const FString CorrectName("FaucetToken");
	// TestTrue("Total supply read correctly ", Response.Equals(CorrectName));
	TestDoneDelegate.Execute();
}