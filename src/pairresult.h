// Copyright (c) 2019 The PIVX developers
// Copyright (c) 2020 The AITRA Coin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef AITRA_Coin_PAIRRESULT_H
#define AITRA_Coin_PAIRRESULT_H


class PairResult {

public:
    PairResult(bool res):result(res){}
    PairResult(bool res, std::string* statusStr):result(res), status(statusStr){}

    bool result;
    std::string* status = nullptr;
};


#endif //AITRA_Coin_PAIRRESULT_H
