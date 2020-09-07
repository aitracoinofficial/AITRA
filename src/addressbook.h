// Copyright (c) 2019 The PIVX developers
// Copyright (c) 2020 The AITRA Coin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef AITRA_Coin_ADDRESSBOOK_H
#define AITRA_Coin_ADDRESSBOOK_H

#include <map>
#include <string>

namespace AddressBook {

    namespace AddressBookPurpose {
        extern const std::string UNKNOWN;
        extern const std::string RECEIVE;
        extern const std::string SEND;
    }

/** Address book data */
    class CAddressBookData {
    public:

        std::string name;
        std::string purpose;

        CAddressBookData() {
            purpose = AddressBook::AddressBookPurpose::UNKNOWN;
        }

        typedef std::map<std::string, std::string> StringMap;
        StringMap destdata;

        bool isSendPurpose() const;
        bool isReceivePurpose() const;
    };

}

#endif //AITRA_Coin_ADDRESSBOOK_H
