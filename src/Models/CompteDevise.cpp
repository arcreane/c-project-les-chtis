//
// Created by Rami Osman on 29/04/2022.
//
#include "CompteDevise.h"
#include "BankProduct.h"
#include <string>

using std::string;

CompteDevise::CompteDevise(int amount, int rate, int ceiling, string accountId, string name, string createdAt,
                           string updatedAt,
                           string providerName) : BankProduct(name, accountId, createdAt, updatedAt, providerName) {

    this->ceiling = ceiling;
    this->rate = rate;
    this->amount = amount;
}

int CompteDevise::getCeiling() {
    return ceiling;
}

int CompteDevise::getRate() {
    return rate;
}

int CompteDevise::getAmount() {
    return amount;
}