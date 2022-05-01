//
// Created by Rami Osman on 29/04/2022.
//

#include "CryptoCurrency.h"

CryptoCurrency::CryptoCurrency(int amount, string currencyCode, string currencyName, string createdAt, string updatedAt,
                               string providerName) : DigitalProduct("CRYPTO_" + currencyCode, createdAt, updatedAt, providerName){
    this->currencyName = currencyName;
    this->currencyCode = currencyCode;
    this->amount = amount;
}

int CryptoCurrency::getBalance() {
    return this->amount;
}

string CryptoCurrency::getCurrencyName() {
    return this->currencyName;
}