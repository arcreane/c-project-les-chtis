//
// Created by Rami Osman on 30/04/2022.
//

#include "PEA.h"
#include "BankProduct.h"
#include <iostream>
#include <list>

PEA::PEA(string bankName, string accountId, string createdAt, string updatedAt, string providerName): BankProduct(bankName, accountId, createdAt, updatedAt, providerName){

}

void PEA::addOrder(string order) {
    this->values.push_back(order);
}

std::list<string> PEA::getOrders() {
    return this->values;
}