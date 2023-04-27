// Copyright 2023, STYLE Protocol, All rights reserved.


#include "ApproveERC20.h"
#include "Misc/AutomationTest.h"
#include "STYLEUtils.h"

BEGIN_DEFINE_SPEC(STYLE_SDKApproveERC20,
	"STYLE_SDK.STYLERequests.ApproveERC20",
	EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask);
void OnResponse(FString Response, int32 StatusCode);
FDoneDelegate TestDoneDelegate;
END_DEFINE_SPEC(STYLE_SDKApproveERC20)

void STYLE_SDKApproveERC20::Define()
{
	Describe("Execute ApproveERC20 request tests",
		[this]()
		{
			LatentIt("ApproveERC20 Async Node",
				EAsyncExecution::TaskGraph, FTimespan(0, 0, 30),
				[this](const FDoneDelegate TestDone)
				{
					TestDoneDelegate = TestDone;
					UApproveERC20* ApproveERC20Instance = UApproveERC20::ApproveERC20("{\"tokenAddress\":\"0x0f2612d401cdd2926e62d6e0657948afb1279a27\",\"tokenId\":0,\"payment\":{\"value\":\"21000000\",\"stringValue\":\"21\"},\"paymentToken\":{\"address\":\"0x4ae6392804974b5b5d83e937a091c276fd42a771\",\"name\":\"USD Coin\",\"symbol\":\"USDC\"},\"type\":\"AVATAR\",\"subtype\":\"Other\",\"tailorId\":\"6321fde1b83ce271a3ad00d0\",\"jobId\":\"642bfe13676dd46d67fdab88\",\"uri\":\"ipfs://QmWue878EMjXujkqo1XqVJvyU9MERczUnXRuft3zHo5uG2\",\"bidder\":\"0x1902abc4d785bd176a6db7d5f185483f6b979274\",\"signature\":\"0x5f9829930abaf84f63c18b8ef0a828d75d9da76e6de5423603250446eb1c99ff1ec3aa28e6357e55a192cad439bb39098f966ff0ad460e765b595793250d245a1b\",\"environment\":\"0x7aFC56E5A260B43146085479E0D97AE4fAe4dE24\",\"metaverseId\":0,\"modelId\":0,\"adminSignature\":\"0x0358d22d530d464a56acb30ef800c6659ddea1c40c39eaeb0eb4117391ad30ac552725547c562552ba62a6d4aed56f852a89624ee0c3fd8dd9fe5732352311241c\",\"numberOfDerivatives\":10,\"cid\":\"QmYuwJPgXZDh2BmbFUA7prwYJtuekw9jDg18aL6woaFous\",\"asset\":{\"name\":\"Derivative of Testing\",\"description\":\"Style Protocol derivative from Testing for DECENTRALAND\\n\\nhttps://www.protocol.style\",\"image\":\"ipfs://bafybeialntzdds3mpalblnrcwpbyem54kbfxbzwvugs3m7dzrsxr4nip2m/image.png\",\"animation_url\":\"ipfs://bafybeigi6lgvpkdtt4fylcgr66dgrg7esc5sq7po34bwttgbr5zzaffuty/show.webp\",\"model_url\":\"https://style-protocol-api.vercel.app/api/data/0x5df979601Bd0308224887a6308A412F6142eFC19/amazonia.glb\"}}");
					ApproveERC20Instance->GetOnCompletedDelegate().AddRaw(this, &STYLE_SDKApproveERC20::OnResponse);
					ApproveERC20Instance->Activate();
				});
		});
}

void STYLE_SDKApproveERC20::OnResponse(FString Response, int32 StatusCode)
{
	const bool bWasSuccessful = STYLEUtils::StatusCodeIsSuccess(StatusCode);

	TestTrue("ApproveERC20 Request run successfully!", bWasSuccessful);
	UE_LOG(LogTemp, Display, TEXT("CallContract Response: %s"), *Response);
	// const FString CorrectName("FaucetToken");
	// TestTrue("Total supply read correctly ", Response.Equals(CorrectName));
	TestDoneDelegate.Execute();
}