// Copyright 2023, STYLE Protocol, All rights reserved.


#include "GetContractsData.h"
#include "Misc/AutomationTest.h"
#include "STYLEUtils.h"

BEGIN_DEFINE_SPEC(STYLE_SDKGetContractsData,
	"STYLE_SDK.STYLERequests.GetContractsData",
	EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask);
void OnResponse(FString Response, int32 StatusCode);
FDoneDelegate TestDoneDelegate;
END_DEFINE_SPEC(STYLE_SDKGetContractsData)

void STYLE_SDKGetContractsData::Define()
{
	Describe("Execute GetContractsData request tests",
		[this]()
		{
			LatentIt("GetContractsData Async Node",
				EAsyncExecution::TaskGraph, FTimespan(0, 0, 30),
				[this](const FDoneDelegate TestDone)
				{
					TestDoneDelegate = TestDone;
					UGetContractsData* GetContractsDataInstance = UGetContractsData::GetContractsData();
					GetContractsDataInstance->GetOnCompletedDelegate().AddRaw(this, &STYLE_SDKGetContractsData::OnResponse);
					GetContractsDataInstance->Activate();
				});
		});
}

void STYLE_SDKGetContractsData::OnResponse(FString Response, int32 StatusCode)
{
	const bool bWasSuccessful = STYLEUtils::StatusCodeIsSuccess(StatusCode);

	TestTrue("GetContractsData Request run successfully!", bWasSuccessful);
	UE_LOG(LogTemp, Display, TEXT("CallContract Response: %s"), *Response);
	// const FString CorrectName("FaucetToken");
	// TestTrue("Total supply read correctly ", Response.Equals(CorrectName));
	TestDoneDelegate.Execute();
}