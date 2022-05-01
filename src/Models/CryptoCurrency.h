//
// Created by Rami Osman on 29/04/2022.
//

#ifndef MYAPP_CRYPTOCURRENCY_H
#define MYAPP_CRYPTOCURRENCY_H

#include "DigitalProduct.h"

class CryptoCurrency: public DigitalProduct{
private:
    string currencyCode;
    string currencyName;
    int amount;

public:
    CryptoCurrency(string currencyCode, string currencyName, string createdAt, string updatedAt, string providerName);
    int getBalance();
    string getCurrencyName();

};

#endif //MYAPP_CRYPTOCURRENCY_H