// Copyright 2023, STYLE Protocol, All rights reserved.


#include "GetOwnedDerivatives.h"
#include "Misc/AutomationTest.h"
#include "STYLEUtils.h"

BEGIN_DEFINE_SPEC(STYLE_SDKGetOwnedDerivatives,
	"STYLE_SDK.STYLERequests.GetOwnedDerivatives",
	EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask);
void OnResponse(FString Response, int32 StatusCode);
FDoneDelegate TestDoneDelegate;
END_DEFINE_SPEC(STYLE_SDKGetOwnedDerivatives)

void STYLE_SDKGetOwnedDerivatives::Define()
{
	Describe("Execute GetOwnedDerivatives request tests",
		[this]()
		{
			LatentIt("GetOwnedDerivatives Async Node",
				EAsyncExecution::TaskGraph, FTimespan(0, 0, 30),
				[this](const FDoneDelegate TestDone)
				{
					TestDoneDelegate = TestDone;
					UGetOwnedDerivatives* GetOwnedDerivativesInstance = UGetOwnedDerivatives::GetOwnedDerivatives(FString(TEXT("{\"signature\":\"0xb15175d683d88007e8121811122abd16895b7e2ad47aaa64d5883f38d0c57c434a695c6ef01526ca94a9dce6aa38221afd31d80a65468d00b62f672beab753c51b\",\"walletAddress\":\"0x67701e71F9412Af1BcB2D77897F40139B6Ccc073\"}")));
					GetOwnedDerivativesInstance->GetOnCompletedDelegate().AddRaw(this, &STYLE_SDKGetOwnedDerivatives::OnResponse);
					GetOwnedDerivativesInstance->Activate();
				});
		});
}

void STYLE_SDKGetOwnedDerivatives::OnResponse(FString Response, int32 StatusCode)
{
	const bool bWasSuccessful = STYLEUtils::StatusCodeIsSuccess(StatusCode);

	TestTrue("GetOwnedDerivatives Request run successfully!", bWasSuccessful);
	UE_LOG(LogTemp, Display, TEXT("CallContract Response: %s"), *Response);
	// const FString CorrectName("FaucetToken");
	// TestTrue("Total supply read correctly ", Response.Equals(CorrectName));
	TestDoneDelegate.Execute();
}