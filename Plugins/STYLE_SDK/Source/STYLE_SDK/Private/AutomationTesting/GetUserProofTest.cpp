// Copyright 2023, STYLE Protocol, All rights reserved.


#include "GetUserProof.h"
#include "Misc/AutomationTest.h"
#include "STYLEUtils.h"

BEGIN_DEFINE_SPEC(STYLE_SDKGetUserProof,
	"STYLE_SDK.STYLERequests.GetUserProof",
	EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask);
void OnResponse(FString Response, int32 StatusCode);
FDoneDelegate TestDoneDelegate;
END_DEFINE_SPEC(STYLE_SDKGetUserProof)

void STYLE_SDKGetUserProof::Define()
{
	Describe("Execute GetUserProof request tests",
		[this]()
		{
			LatentIt("GetUserProof Async Node",
				EAsyncExecution::TaskGraph, FTimespan(0, 0, 30),
				[this](const FDoneDelegate TestDone)
				{
					TestDoneDelegate = TestDone;
					UGetUserProof* GetUserProofInstance = UGetUserProof::GetUserProof();
					GetUserProofInstance->GetOnCompletedDelegate().AddRaw(this, &STYLE_SDKGetUserProof::OnResponse);
					GetUserProofInstance->Activate();
				});
		});
}

void STYLE_SDKGetUserProof::OnResponse(FString Response, int32 StatusCode)
{
	const bool bWasSuccessful = STYLEUtils::StatusCodeIsSuccess(StatusCode);

	TestTrue("GetUserProof Request run successfully!", bWasSuccessful);
	UE_LOG(LogTemp, Display, TEXT("CallContract Response: %s"), *Response);
	// const FString CorrectName("FaucetToken");
	// TestTrue("Total supply read correctly ", Response.Equals(CorrectName));
	TestDoneDelegate.Execute();
}