// Copyright (c) 2017-2020 The PIVX developers
// Copyright (c) 2020 The AITRA Coin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "blocksignature.h"
#include "main.h"

bool SignBlockWithKey(CBlock& block, const CKey& key)
{
	if (!key.Sign(block.GetHash(), block.vchBlockSig))
		return error("%s: failed to sign block hash with key", __func__);

	return true;
}

bool SignBlock(CBlock& block, const CKeyStore& keystore)
{
	CKeyID keyID;
	if (block.IsProofOfWork()) {
		bool fFoundID = false;
		for (const CTxOut& txout : block.vtx[0].vout) {
			if (!txout.GetKeyIDFromUTXO(keyID))
				continue;
			fFoundID = true;
			break;
		}
		if (!fFoundID)
			return error("%s: failed to find key for PoW", __func__);
	}
	else {
		if (!block.vtx[1].vout[1].GetKeyIDFromUTXO(keyID))
			return error("%s: failed to find key for PoS", __func__);
	}

	CKey key;
	if (!keystore.GetKey(keyID, key))
		return error("%s: failed to get key from keystore", __func__);

	return SignBlockWithKey(block, key);
}

bool CheckBlockSignature(const CBlock& block)
{
	if (block.IsProofOfWork())
		return block.vchBlockSig.empty();

	if (block.vchBlockSig.empty())
		return error("%s: vchBlockSig is empty!", __func__);

	CPubKey pubkey;
	txnouttype whichType;
	std::vector<valtype> vSolutions;
	const CTxOut& txout = block.vtx[1].vout[1];
	if (!Solver(txout.scriptPubKey, whichType, vSolutions))
		return false;
	if (whichType == TX_PUBKEY || whichType == TX_PUBKEYHASH) {
		valtype& vchPubKey = vSolutions[0];
		pubkey = CPubKey(vchPubKey);
	}

	if (!pubkey.IsValid())
		return error("%s: invalid pubkey %s", __func__, HexStr(pubkey));

	return pubkey.Verify(block.GetHash(), block.vchBlockSig);
}
