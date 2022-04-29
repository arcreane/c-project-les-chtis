//
// Created by Rami Osman on 29/04/2022.
//
#include "CompteDevise.h"
#include "BankProduct.h"

CompteDevice::CompteDevice(int rate, int ceiling, string accountId, string name, string createdAt, string updatedAt,
                           string providerName) : BankProduct(name, accountId, createdAt, updatedAt, providerName) {

    this->ceiling = ceiling;
    this->rate = rate;
}

int CompteDevice::getCeiling() {
    return this->ceiling;
}

int CompteDevice::getRate() {
    return this->rate;
}