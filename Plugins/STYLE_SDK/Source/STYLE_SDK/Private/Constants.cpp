// Copyright 2023, STYLE Protocol, All rights reserved.


#include "Constants.h"

Constants::Constants()
{
	GATEWAY = FString(TEXT("styleprotocol.mypinata.cloud"));

	API_HOST = FString(TEXT("style-protocol-api.vercel.app"));

	ERC20_ABI = FString(TEXT("[{\"constant\":true,\"inputs\":[],\"name\":\"name\",\"outputs\":[{\"name\":\"\",\"type\":\"string\"}],\"payable\":false,\"stateMutability\":\"view\",\"type\":\"function\"},{\"constant\":false,\"inputs\":[{\"name\":\"_spender\",\"type\":\"address\"},{\"name\":\"_value\",\"type\":\"uint256\"}],\"name\":\"approve\",\"outputs\":[{\"name\":\"\",\"type\":\"bool\"}],\"payable\":false,\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"constant\":true,\"inputs\":[],\"name\":\"totalSupply\",\"outputs\":[{\"name\":\"\",\"type\":\"uint256\"}],\"payable\":false,\"stateMutability\":\"view\",\"type\":\"function\"},{\"constant\":false,\"inputs\":[{\"name\":\"_from\",\"type\":\"address\"},{\"name\":\"_to\",\"type\":\"address\"},{\"name\":\"_value\",\"type\":\"uint256\"}],\"name\":\"transferFrom\",\"outputs\":[{\"name\":\"\",\"type\":\"bool\"}],\"payable\":false,\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"constant\":true,\"inputs\":[],\"name\":\"decimals\",\"outputs\":[{\"name\":\"\",\"type\":\"uint8\"}],\"payable\":false,\"stateMutability\":\"view\",\"type\":\"function\"},{\"constant\":true,\"inputs\":[{\"name\":\"_owner\",\"type\":\"address\"}],\"name\":\"balanceOf\",\"outputs\":[{\"name\":\"balance\",\"type\":\"uint256\"}],\"payable\":false,\"stateMutability\":\"view\",\"type\":\"function\"},{\"constant\":true,\"inputs\":[],\"name\":\"symbol\",\"outputs\":[{\"name\":\"\",\"type\":\"string\"}],\"payable\":false,\"stateMutability\":\"view\",\"type\":\"function\"},{\"constant\":false,\"inputs\":[{\"name\":\"_to\",\"type\":\"address\"},{\"name\":\"_value\",\"type\":\"uint256\"}],\"name\":\"transfer\",\"outputs\":[{\"name\":\"\",\"type\":\"bool\"}],\"payable\":false,\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"constant\":true,\"inputs\":[{\"name\":\"_owner\",\"type\":\"address\"},{\"name\":\"_spender\",\"type\":\"address\"}],\"name\":\"allowance\",\"outputs\":[{\"name\":\"\",\"type\":\"uint256\"}],\"payable\":false,\"stateMutability\":\"view\",\"type\":\"function\"},{\"payable\":true,\"stateMutability\":\"payable\",\"type\":\"fallback\"},{\"anonymous\":false,\"inputs\":[{\"indexed\":true,\"name\":\"owner\",\"type\":\"address\"},{\"indexed\":true,\"name\":\"spender\",\"type\":\"address\"},{\"indexed\":false,\"name\":\"value\",\"type\":\"uint256\"}],\"name\":\"Approval\",\"type\":\"event\"},{\"anonymous\":false,\"inputs\":[{\"indexed\":true,\"name\":\"from\",\"type\":\"address\"},{\"indexed\":true,\"name\":\"to\",\"type\":\"address\"},{\"indexed\":false,\"name\":\"value\",\"type\":\"uint256\"}],\"name\":\"Transfer\",\"type\":\"event\"}]"));

	PROTOCOL_ABI = FString(TEXT(
		"[{\"inputs\":[{\"internalType\":\"address\",\"name\":\"style_\",\"type\":\"address\"},{\"internalType\":\"address\",\"name\":\"stable_\",\"type\":\"address\"},{\"internalType\":\"address payable\",\"name\":\"weth_\",\"type\":\"address\"},{\"internalType\":\"address\",\"name\":\"dclAdmin_\",\"type\":\"address\"}],\"stateMutability\":\"nonpayable\",\"type\":\"constructor\"},{\"inputs\":[],\"name\":\"DCLLot\",\"type\":\"error\"},{\"inputs\":[],\"name\":\"DerivativesDisallowed\",\"type\":\"error\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"admin\",\"type\":\"address\"}],\"name\":\"DisallowedAdmin\",\"type\":\"error\"},{\"inputs\":[],\"name\":\"DisallowedModelId\",\"type\":\"error\"},{\"inputs\":[],\"name\":\"ImproperItemStatus\",\"type\":\"error\"},{\"inputs\":[],\"name\":\"ImproperMetaverseIds\",\"type\":\"error\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"tokenAddress\",\"type\":\"address\"},{\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"},{\"internalType\":\"address\",\"name\":\"owner\",\"type\":\"address\"}],\"name\":\"ImproperOwnerOfStake\",\"type\":\"error\"},{\"inputs\":[],\"name\":\"ImproperRoyalties\",\"type\":\"error\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"recoveredAdmin\",\"type\":\"address\"}],\"name\":\"ImproperSignature\",\"type\":\"error\"},{\"inputs\":[],\"name\":\"ImproperTailorFee\",\"type\":\"error\"},{\"inputs\":[{\"internalType\":\"uint256\",\"name\":\"fee\",\"type\":\"uint256\"}],\"name\":\"InsufficientFunds\",\"type\":\"error\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"tokenAddress\",\"type\":\"address\"},{\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"}],\"name\":\"LackOfDerivatives\",\"type\":\"error\"},{\"inputs\":[],\"name\":\"MetaverseIdAlreadyClaimed\",\"type\":\"error\"},{\"inputs\":[],\"name\":\"NoSuchListing\",\"type\":\"error\"},{\"inputs\":[],\"name\":\"NotAdmin\",\"type\":\"error\"},{\"inputs\":[],\"name\":\"NotBridgeRouter\",\"type\":\"error\"},{\"inputs\":[],\"name\":\"NotContractOwner\",\"type\":\"error\"},{\"inputs\":[],\"name\":\"NotDCLLot\",\"type\":\"error\"},{\"inputs\":[],\"name\":\"NotDerivative\",\"type\":\"error\"},{\"inputs\":[],\"name\":\"NotEnoughtSTYLETokens\",\"type\":\"error\"},{\"inputs\":[],\"name\":\"NotOwner\",\"type\":\"error\"},{\"inputs\":[{\"internalType\":\"uint256\",\"name\":\"payment\",\"type\":\"uint256\"},{\"internalType\":\"address\",\"name\":\"paymentToken\",\"type\":\"address\"}],\"name\":\"PriceNotMet\",\"type\":\"error\"},{\"inputs\":[],\"name\":\"SameERC1155AlreadyStaked\",\"type\":\"error\"},{\"anonymous\":false,\"inputs\":[{\"indexed\":false,\"internalType\":\"bytes\",\"name\":\"adminSignature\",\"type\":\"bytes\"}],\"name\":\"DCLInit\",\"type\":\"event\"},{\"anonymous\":false,\"inputs\":[{\"indexed\":true,\"internalType\":\"address\",\"name\":\"contract_\",\"type\":\"address\"}],\"name\":\"GenerationMint\",\"type\":\"event\"},{\"anonymous\":false,\"inputs\":[{\"indexed\":true,\"internalType\":\"bytes\",\"name\":\"signature\",\"type\":\"bytes\"},{\"indexed\":true,\"internalType\":\"address\",\"name\":\"redeemer\",\"type\":\"address\"},{\"indexed\":false,\"internalType\":\"address\",\"name\":\"tokenAddress\",\"type\":\"address\"},{\"indexed\":false,\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"},{\"indexed\":true,\"internalType\":\"uint96\",\"name\":\"metaverseId\",\"type\":\"uint96\"}],\"name\":\"ItemBuyAndMint\",\"type\":\"event\"},{\"anonymous\":false,\"inputs\":[{\"indexed\":true,\"internalType\":\"bytes\",\"name\":\"signature\",\"type\":\"bytes\"},{\"indexed\":true,\"internalType\":\"address\",\"name\":\"redeemer\",\"type\":\"address\"},{\"indexed\":false,\"internalType\":\"address\",\"name\":\"tokenAddress\",\"type\":\"address\"},{\"indexed\":false,\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"},{\"indexed\":true,\"internalType\":\"uint96\",\"name\":\"metaverseId\",\"type\":\"uint96\"}],\"name\":\"ItemClaimSingular\",\"type\":\"event\"},{\"anonymous\":false,\"inputs\":[{\"indexed\":false,\"internalType\":\"address\",\"name\":\"redeemer\",\"type\":\"address\"},{\"indexed\":false,\"internalType\":\"address\",\"name\":\"contract_\",\"type\":\"address\"},{\"indexed\":false,\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"},{\"indexed\":false,\"internalType\":\"string\",\"name\":\"voucherURI\",\"type\":\"string\"}],\"name\":\"NFTMint\",\"type\":\"event\"},{\"anonymous\":false,\"inputs\":[{\"indexed\":false,\"internalType\":\"address\",\"name\":\"signer\",\"type\":\"address\"},{\"indexed\":false,\"internalType\":\"address\",\"name\":\"redeemer\",\"type\":\"address\"},{\"indexed\":false,\"internalType\":\"address\",\"name\":\"contract_\",\"type\":\"address\"},{\"indexed\":false,\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"},{\"indexed\":false,\"internalType\":\"string\",\"name\":\"voucherURI\",\"type\":\"string\"}],\"name\":\"NFTRedeem\",\"type\":\"event\"},{\"anonymous\":false,\"inputs\":[{\"indexed\":true,\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"},{\"indexed\":true,\"internalType\":\"address\",\"name\":\"tokenAddress\",\"type\":\"address\"}],\"name\":\"Staked\",\"type\":\"event\"},{\"anonymous\":false,\"inputs\":[{\"indexed\":true,\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"},{\"indexed\":true,\"internalType\":\"address\",\"name\":\"tokenAddress\",\"type\":\"address\"}],\"name\":\"Unstaked\",\"type\":\"event\"},{\"inputs\":[],\"name\":\"DOMAIN_SEPARATOR\",\"outputs\":[{\"internalType\":\"bytes32\",\"name\":\"\",\"type\":\"bytes32\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"admin\",\"type\":\"address\"}],\"name\":\"addAdmin\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"components\":[{\"internalType\":\"uint256\",\"name\":\"amount\",\"type\":\"uint256\"},{\"internalType\":\"address\",\"name\":\"redeemer\",\"type\":\"address\"},{\"components\":[{\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"},{\"internalType\":\"uint256\",\"name\":\"payment\",\"type\":\"uint256\"},{\"internalType\":\"address\",\"name\":\"tokenAddress\",\"type\":\"address\"},{\"internalType\":\"uint96\",\"name\":\"metaverseId\",\"type\":\"uint96\"},{\"internalType\":\"address\",\"name\":\"paymentToken\",\"type\":\"address\"},{\"internalType\":\"uint88\",\"name\":\"modelId\",\"type\":\"uint88\"},{\"internalType\":\"address\",\"name\":\"bidder\",\"type\":\"address\"},{\"internalType\":\"address\",\"name\":\"environment\",\"type\":\"address\"},{\"internalType\":\"string\",\"name\":\"uri\",\"type\":\"string\"},{\"internalType\":\"bytes\",\"name\":\"signature\",\"type\":\"bytes\"}],\"internalType\":\"struct ILazyMintingStructs.NonmintedNFT\",\"name\":\"nonmintedNFT\",\"type\":\"tuple\"},{\"internalType\":\"bytes\",\"name\":\"signature\",\"type\":\"bytes\"}],\"internalType\":\"struct INFTMarketplaceStructs.RequstedData[]\",\"name\":\"requestedDataArr\",\"type\":\"tuple[]\"}],\"name\":\"batchBuy\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"redeemer\",\"type\":\"address\"},{\"components\":[{\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"},{\"internalType\":\"uint256\",\"name\":\"payment\",\"type\":\"uint256\"},{\"internalType\":\"address\",\"name\":\"tokenAddress\",\"type\":\"address\"},{\"internalType\":\"uint96\",\"name\":\"metaverseId\",\"type\":\"uint96\"},{\"internalType\":\"address\",\"name\":\"paymentToken\",\"type\":\"address\"},{\"internalType\":\"uint88\",\"name\":\"modelId\",\"type\":\"uint88\"},{\"internalType\":\"address\",\"name\":\"bidder\",\"type\":\"address\"},{\"internalType\":\"address\",\"name\":\"environment\",\"type\":\"address\"},{\"internalType\":\"string\",\"name\":\"uri\",\"type\":\"string\"},{\"internalType\":\"bytes\",\"name\":\"signature\",\"type\":\"bytes\"}],\"internalType\":\"struct ILazyMintingStructs.NonmintedNFT\",\"name\":\"nonmintedNFT\",\"type\":\"tuple\"},{\"internalType\":\"bytes\",\"name\":\"signature\",\"type\":\"bytes\"}"
		", {\"internalType\":\"uint256\",\"name\":\"amount\",\"type\":\"uint256\"}],\"name\":\"buyAndMint\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"redeemer\",\"type\":\"address\"},{\"components\":[{\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"},{\"internalType\":\"uint256\",\"name\":\"payment\",\"type\":\"uint256\"},{\"internalType\":\"address\",\"name\":\"tokenAddress\",\"type\":\"address\"},{\"internalType\":\"uint96\",\"name\":\"metaverseId\",\"type\":\"uint96\"},{\"internalType\":\"address\",\"name\":\"paymentToken\",\"type\":\"address\"},{\"internalType\":\"uint88\",\"name\":\"modelId\",\"type\":\"uint88\"},{\"internalType\":\"address\",\"name\":\"bidder\",\"type\":\"address\"},{\"internalType\":\"address\",\"name\":\"environment\",\"type\":\"address\"},{\"internalType\":\"string\",\"name\":\"uri\",\"type\":\"string\"},{\"internalType\":\"bytes\",\"name\":\"signature\",\"type\":\"bytes\"}],\"internalType\":\"struct ILazyMintingStructs.NonmintedNFT\",\"name\":\"nonmintedNFT\",\"type\":\"tuple\"},{\"internalType\":\"bytes\",\"name\":\"signature\",\"type\":\"bytes\"},{\"internalType\":\"uint256\",\"name\":\"amount\",\"type\":\"uint256\"},{\"internalType\":\"bytes\",\"name\":\"DCLSignature\",\"type\":\"bytes\"}],\"name\":\"buyDCL\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"components\":[{\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"},{\"internalType\":\"address\",\"name\":\"tokenAddress\",\"type\":\"address\"},{\"internalType\":\"uint96\",\"name\":\"metaverseId\",\"type\":\"uint96\"},{\"internalType\":\"address\",\"name\":\"bidder\",\"type\":\"address\"},{\"internalType\":\"uint88\",\"name\":\"modelId\",\"type\":\"uint88\"},{\"internalType\":\"string\",\"name\":\"uri\",\"type\":\"string\"},{\"internalType\":\"bytes\",\"name\":\"signature\",\"type\":\"bytes\"}],\"internalType\":\"struct ILazyMintingStructs.NonmintedNFTSingular\",\"name\":\"nonmintedNFT\",\"type\":\"tuple\"},{\"internalType\":\"bytes\",\"name\":\"signature\",\"type\":\"bytes\"}],\"name\":\"claimSingularNFT\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"components\":[{\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"},{\"internalType\":\"address\",\"name\":\"tokenAddress\",\"type\":\"address\"},{\"internalType\":\"uint96\",\"name\":\"metaverseId\",\"type\":\"uint96\"},{\"internalType\":\"address\",\"name\":\"bidder\",\"type\":\"address\"},{\"internalType\":\"uint88\",\"name\":\"modelId\",\"type\":\"uint88\"},{\"internalType\":\"string\",\"name\":\"uri\",\"type\":\"string\"},{\"internalType\":\"bytes\",\"name\":\"signature\",\"type\":\"bytes\"}],\"internalType\":\"struct ILazyMintingStructs.NonmintedNFTSingular\",\"name\":\"nonmintedNFT\",\"type\":\"tuple\"},{\"internalType\":\"bytes\",\"name\":\"signature\",\"type\":\"bytes\"},{\"internalType\":\"bytes\",\"name\":\"DCLSignature\",\"type\":\"bytes\"}],\"name\":\"claimSingularNFTDCL\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"uint256\",\"name\":\"cursor\",\"type\":\"uint256\"},{\"internalType\":\"uint256\",\"name\":\"howMany\",\"type\":\"uint256\"}],\"name\":\"getAdmins\",\"outputs\":[{\"internalType\":\"address[]\",\"name\":\"admins\",\"type\":\"address[]\"},{\"internalType\":\"uint256\",\"name\":\"newCursor\",\"type\":\"uint256\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"tokenAddress\",\"type\":\"address\"},{\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"}],\"name\":\"getAncestor\",\"outputs\":[{\"internalType\":\"address\",\"name\":\"ancestor\",\"type\":\"address\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"bytes32\",\"name\":\"cutSignature\",\"type\":\"bytes32\"},{\"internalType\":\"address\",\"name\":\"redeemer\",\"type\":\"address\"}],\"name\":\"getDCLBought\",\"outputs\":[{\"internalType\":\"uint256\",\"name\":\"\",\"type\":\"uint256\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"bytes32[]\",\"name\":\"cutSignatures\",\"type\":\"bytes32[]\"}],\"name\":\"getIfSignsProceeded\",\"outputs\":[{\"internalType\":\"bool[]\",\"name\":\"result\",\"type\":\"bool[]\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"bytes32\",\"name\":\"cutSignature\",\"type\":\"bytes32\"}],\"name\":\"getLotInfo\",\"outputs\":[{\"internalType\":\"bool\",\"name\":\"\",\"type\":\"bool\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[],\"name\":\"getOwner\",\"outputs\":[{\"internalType\":\"address\",\"name\":\"owner\",\"type\":\"address\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"tokenAddress\",\"type\":\"address\"},{\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"}],\"name\":\"getStake\",\"outputs\":[{\"components\":[{\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"},{\"internalType\":\"address\",\"name\":\"tokenAddress\",\"type\":\"address\"},{\"internalType\":\"uint96\",\"name\":\"numberOfDerivatives\",\"type\":\"uint96\"},{\"internalType\":\"address\",\"name\":\"stakeOwner\",\"type\":\"address\"},{\"internalType\":\"uint88\",\"name\":\"modelId\",\"type\":\"uint88\"},{\"internalType\":\"bool\",\"name\":\"isERC1155\",\"type\":\"bool\"}],\"internalType\":\"struct IStakingStructs.Stake\",\"name\":\"\",\"type\":\"tuple\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"tokenAddress\",\"type\":\"address\"},{\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"}],\"name\":\"getStakeSingular\",\"outputs\":[{\"components\":[{\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"},{\"internalType\":\"uint256\",\"name\":\"tailorFee\",\"type\":\"uint256\"},{\"internalType\":\"address\",\"name\":\"tokenAddress\",\"type\":\"address\"},{\"internalType\":\"uint88\",\"name\":\"modelId\",\"type\":\"uint88\"},{\"internalType\":\"bool\",\"name\":\"isERC1155\",\"type\":\"bool\"},{\"internalType\":\"address\",\"name\":\"stakeOwner\",\"type\":\"address\"},{\"internalType\":\"uint96[]\",\"name\":\"metaverseIds\",\"type\":\"uint96[]\"}],\"internalType\":\"struct IStakingStructs.StakeSingular\",\"name\":\"\",\"type\":\"tuple\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"uint256\",\"name\":\"cursor\",\"type\":\"uint256\"},{\"internalType\":\"uint256\",\"name\":\"howMany\",\"type\":\"uint256\"}],\"name\":\"getStakes\",\"outputs\":[{\"components\":[{\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"},{\"internalType\":\"address\",\"name\":\"tokenAddress\",\"type\":\"address\"},{\"internalType\":\"uint96\",\"name\":\"numberOfDerivatives\",\"type\":\"uint96\"},{\"internalType\":\"address\",\"name\":\"stakeOwner\",\"type\":\"address\"},{\"internalType\":\"uint88\",\"name\":\"modelId\",\"type\":\"uint88\"},{\"internalType\":\"bool\",\"name\":\"isERC1155\",\"type\":\"bool\"}],\"internalType\":\"struct IStakingStructs.Stake[]\",\"name\":\"stakes\",\"type\":\"tuple[]\"},{\"internalType\":\"uint256\",\"name\":\"newCursor\",\"type\":\"uint256\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"uint256\",\"name\":\"cursor\",\"type\":\"uint256\"},{\"internalType\":\"uint256\",\"name\":\"howMany\",\"type\":\"uint256\"},{\"internalType\":\"address\",\"name\":\"owner\",\"type\":\"address\"}],\"name\":\"getStakesByOwner\",\"outputs\":[{\"components\":[{\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"},{\"internalType\":\"address\",\"name\":\"tokenAddress\",\"type\":\"address\"},{\"internalType\":\"uint96\",\"name\":\"numberOfDerivatives\",\"type\":\"uint96\"},{\"internalType\":\"address\",\"name\":\"stakeOwner\",\"type\":\"address\"},{\"internalType\":\"uint88\",\"name\":\"modelId\",\"type\":\"uint88\"},{\"internalType\":\"bool\",\"name\":\"isERC1155\",\"type\":\"bool\"}],\"internalType\":\"struct IStakingStructs.Stake[]\",\"name\":\"stakes\",\"type\":\"tuple[]\"},{\"internalType\":\"uint256\",\"name\":\"newCursor\",\"type\":\"uint256\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"uint256\",\"name\":\"cursor\",\"type\":\"uint256\"},{\"internalType\":\"uint256\",\"name\":\"howMany\",\"type\":\"uint256\"}],\"name\":\"getStakesSingular\",\"outputs\":[{\"components\":[{\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"},{\"internalType\":\"uint256\",\"name\":\"tailorFee\",\"type\":\"uint256\"},{\"internalType\":\"address\",\"name\":\"tokenAddress\",\"type\":\"address\"},{\"internalType\":\"uint88\",\"name\":\"modelId\",\"type\":\"uint88\"},{\"internalType\":\"bool\",\"name\":\"isERC1155\",\"type\":\"bool\"},{\"internalType\":\"address\",\"name\":\"stakeOwner\""
		",\"type\":\"address\"},{\"internalType\":\"uint96[]\",\"name\":\"metaverseIds\",\"type\":\"uint96[]\"}],\"internalType\":\"struct IStakingStructs.StakeSingular[]\",\"name\":\"stakes\",\"type\":\"tuple[]\"},{\"internalType\":\"uint256\",\"name\":\"newCursor\",\"type\":\"uint256\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"uint256\",\"name\":\"cursor\",\"type\":\"uint256\"},{\"internalType\":\"uint256\",\"name\":\"howMany\",\"type\":\"uint256\"},{\"internalType\":\"address\",\"name\":\"owner\",\"type\":\"address\"}],\"name\":\"getStakesSingularByOwner\",\"outputs\":[{\"components\":[{\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"},{\"internalType\":\"uint256\",\"name\":\"tailorFee\",\"type\":\"uint256\"},{\"internalType\":\"address\",\"name\":\"tokenAddress\",\"type\":\"address\"},{\"internalType\":\"uint88\",\"name\":\"modelId\",\"type\":\"uint88\"},{\"internalType\":\"bool\",\"name\":\"isERC1155\",\"type\":\"bool\"},{\"internalType\":\"address\",\"name\":\"stakeOwner\",\"type\":\"address\"},{\"internalType\":\"uint96[]\",\"name\":\"metaverseIds\",\"type\":\"uint96[]\"}],\"internalType\":\"struct IStakingStructs.StakeSingular[]\",\"name\":\"stakes\",\"type\":\"tuple[]\"},{\"internalType\":\"uint256\",\"name\":\"newCursor\",\"type\":\"uint256\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"tokenAddress\",\"type\":\"address\"},{\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"}],\"name\":\"getTailor\",\"outputs\":[{\"internalType\":\"address\",\"name\":\"tailor\",\"type\":\"address\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"contract_\",\"type\":\"address\"},{\"internalType\":\"bytes32\",\"name\":\"salt\",\"type\":\"bytes32\"}],\"name\":\"isDerivative\",\"outputs\":[{\"internalType\":\"bool\",\"name\":\"\",\"type\":\"bool\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"tokenAddress\",\"type\":\"address\"},{\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"},{\"internalType\":\"address\",\"name\":\"redeemer\",\"type\":\"address\"},{\"internalType\":\"uint96\",\"name\":\"metaverseId\",\"type\":\"uint96\"},{\"internalType\":\"uint88\",\"name\":\"modelId\",\"type\":\"uint88\"},{\"internalType\":\"string\",\"name\":\"tokenURI\",\"type\":\"string\"},{\"internalType\":\"string\",\"name\":\"name\",\"type\":\"string\"},{\"internalType\":\"string\",\"name\":\"symbol\",\"type\":\"string\"}],\"name\":\"mint\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"string\",\"name\":\"tokenURI\",\"type\":\"string\"},{\"internalType\":\"uint88\",\"name\":\"modelId\",\"type\":\"uint88\"},{\"internalType\":\"uint96\",\"name\":\"numberOfDerivatives\",\"type\":\"uint96\"},{\"components\":[{\"internalType\":\"uint16\",\"name\":\"environmentRoyaltyPercent\",\"type\":\"uint16\"},{\"internalType\":\"uint16\",\"name\":\"stakeOwnerRoyaltyPercent\",\"type\":\"uint16\"},{\"internalType\":\"uint80\",\"name\":\"tailorRoyaltyStable\",\"type\":\"uint80\"},{\"internalType\":\"uint16\",\"name\":\"tailorRoyaltyPercent\",\"type\":\"uint16\"}],\"internalType\":\"struct IStakingStructs.Royalties\",\"name\":\"royalties_\",\"type\":\"tuple\"}],\"name\":\"mintGenerationAndStake\",\"outputs\":[{\"internalType\":\"address\",\"name\":\"clone\",\"type\":\"address\"}],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"string\",\"name\":\"tokenURI\",\"type\":\"string\"},{\"internalType\":\"uint256\",\"name\":\"tailorFee\",\"type\":\"uint256\"},{\"internalType\":\"uint88\",\"name\":\"modelId\",\"type\":\"uint88\"},{\"internalType\":\"uint96[]\",\"name\":\"metaverseIds\",\"type\":\"uint96[]\"},{\"internalType\":\"address payable\",\"name\":\"paymentToken\",\"type\":\"address\"},{\"internalType\":\"uint256\",\"name\":\"paymentAmount\",\"type\":\"uint256\"}],\"name\":\"mintGenerationAndStakeSingular\",\"outputs\":[{\"internalType\":\"address\",\"name\":\"clone\",\"type\":\"address\"}],\"stateMutability\":\"payable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"\",\"type\":\"address\"},{\"internalType\":\"address\",\"name\":\"\",\"type\":\"address\"},{\"internalType\":\"uint256[]\",\"name\":\"\",\"type\":\"uint256[]\"},{\"internalType\":\"uint256[]\",\"name\":\"\",\"type\":\"uint256[]\"},{\"internalType\":\"bytes\",\"name\":\"\",\"type\":\"bytes\"}],\"name\":\"onERC1155BatchReceived\",\"outputs\":[{\"internalType\":\"bytes4\",\"name\":\"\",\"type\":\"bytes4\"}],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"\",\"type\":\"address\"},{\"internalType\":\"address\",\"name\":\"\",\"type\":\"address\"},{\"internalType\":\"uint256\",\"name\":\"\",\"type\":\"uint256\"},{\"internalType\":\"uint256\",\"name\":\"\",\"type\":\"uint256\"},{\"internalType\":\"bytes\",\"name\":\"\",\"type\":\"bytes\"}],\"name\":\"onERC1155Received\",\"outputs\":[{\"internalType\":\"bytes4\",\"name\":\"\",\"type\":\"bytes4\"}],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"\",\"type\":\"address\"},{\"internalType\":\"address\",\"name\":\"\",\"type\":\"address\"},{\"internalType\":\"uint256\",\"name\":\"\",\"type\":\"uint256\"},{\"internalType\":\"bytes\",\"name\":\"\",\"type\":\"bytes\"}],\"name\":\"onERC721Received\",\"outputs\":[{\"internalType\":\"bytes4\",\"name\":\"\",\"type\":\"bytes4\"}],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"admin\",\"type\":\"address\"}],\"name\":\"removeAdmin\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"dclAdmin_\",\"type\":\"address\"}],\"name\":\"setDCLAdmin\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"tokenAddress\",\"type\":\"address\"},{\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"},{\"internalType\":\"uint88\",\"name\":\"modelId\",\"type\":\"uint88\"},{\"internalType\":\"uint96\",\"name\":\"numberOfDerivatives\",\"type\":\"uint96\"},{\"components\":[{\"internalType\":\"uint16\",\"name\":\"environmentRoyaltyPercent\",\"type\":\"uint16\"},{\"internalType\":\"uint16\",\"name\":\"stakeOwnerRoyaltyPercent\",\"type\":\"uint16\"},{\"internalType\":\"uint80\",\"name\":\"tailorRoyaltyStable\",\"type\":\"uint80\"},{\"internalType\":\"uint16\",\"name\":\"tailorRoyaltyPercent\",\"type\":\"uint16\"}],\"internalType\":\"struct IStakingStructs.Royalties\",\"name\":\"royalties_\",\"type\":\"tuple\"},{\"internalType\":\"bool\",\"name\":\"isERC1155\",\"type\":\"bool\"}],\"name\":\"stake\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"tokenAddress\",\"type\":\"address\"},{\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"},{\"internalType\":\"uint256\",\"name\":\"tailorFee\",\"type\":\"uint256\"},{\"internalType\":\"uint88\",\"name\":\"modelId\",\"type\":\"uint88\"},{\"internalType\":\"uint96[]\",\"name\":\"metaverseIds\",\"type\":\"uint96[]\"},{\"internalType\":\"bool\",\"name\":\"isERC1155\",\"type\":\"bool\"},{\"internalType\":\"address payable\",\"name\":\"paymentToken\",\"type\":\"address\"},{\"internalType\":\"uint256\",\"name\":\"paymentAmount\",\"type\":\"uint256\"}],\"name\":\"stakeSingular\",\"outputs\":[],\"stateMutability\":\"payable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"tokenAddress\",\"type\":\"address\"},{\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"}],\"name\":\"unstake\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"bridgeRouter_\",\"type\":\"address\"}],\"name\":\"updateBridgeRouter\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"components\":[{\"internalType\":\"uint16\",\"name\":\"minEnvironmentRoyaltyPercent\",\"type\":\"uint16\"},{\"internalType\":\"uint16\",\"name\":\"maxEnvironmentRoyaltyPercent\",\"type\":\"uint16\"},{\"internalType\":\"uint16\",\"name\":\"minStakeOwnerRoyaltyPercent\",\"type\":\"uint16\"},{\"internalType\":\"uint16\",\"name\":\"maxStakeOwnerRoyaltyPercent\",\"type\":\"uint16\"},{\"internalType\":\"uint80\",\"name\":\"minTailorRoyaltyStable\",\"type\":\"uint80\"},{\"internalType\":\"uint80\",\"name\":\"maxTailorRoyaltyStable\",\"type\":\"uint80\"},{\"internalType\":\"uint16\",\"name\":\"minTailorRoyaltyPercent\",\"type\":\"uint16\"},{\"internalType\":\"uint16\",\"name\":\"maxTailorRoyaltyPercent\",\"type\":\"uint16\"}],\"internalType\":\"struct IStakingStructs.FeesLimits\",\"name\":\"feesLimits_\",\"type\":\"tuple\"}],\"name\":\"updateFeesLimits\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"uint88\",\"name\":\"modelId\""
		",\"type\":\"uint88\"},{\"components\":[{\"internalType\":\"uint256\",\"name\":\"minTailorFee\",\"type\":\"uint256\"},{\"internalType\":\"uint256\",\"name\":\"maxTailorFee\",\"type\":\"uint256\"}],\"internalType\":\"struct IStakingStructs.FeesLimitsSingular\",\"name\":\"feesLimitsSingular_\",\"type\":\"tuple\"}],\"name\":\"updateFeesLimitsSingular\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"uint96\",\"name\":\"metaverseId\",\"type\":\"uint96\"},{\"internalType\":\"uint256\",\"name\":\"fee\",\"type\":\"uint256\"}],\"name\":\"updateMetaverseFee\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"components\":[{\"internalType\":\"uint256\",\"name\":\"minStyleNFTs\",\"type\":\"uint256\"},{\"internalType\":\"uint256\",\"name\":\"minStyleAssets\",\"type\":\"uint256\"}],\"internalType\":\"struct IStakingStructs.StyleLimits\",\"name\":\"styleLimits_\",\"type\":\"tuple\"}],\"name\":\"updateStyleLimits\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"token\",\"type\":\"address\"},{\"internalType\":\"uint256\",\"name\":\"amount\",\"type\":\"uint256\"}],\"name\":\"withdraw\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"}]"
	));

	Delimiter = TEXT("|*/|*/|*/|*/|*/|*/|*/|*/|*/|*/|*/|*/|*/|*/|*/");
}
