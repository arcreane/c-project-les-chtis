//
// Created by Rami Osman on 29/04/2022.
//

#include "BankProduct.h"

BankProduct::BankProduct(string bankName, string accountId, string createdAt, string updatedAt, string providerName)
:Product("BANK_" + bankName, createdAt, updatedAt, providerName) {
    this->balance = 0 ;
    this->bankName = bankName;
    this->accountId = accountId;
}