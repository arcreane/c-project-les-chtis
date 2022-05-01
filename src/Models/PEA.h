//
// Created by Rami Osman on 29/04/2022.
//

#ifndef MYAPP_PEA_H
#define MYAPP_PEA_H

#include <iostream>
#include <list>
#include "BankProduct.h"

class PEA: public BankProduct{
private:
    std::list<string> values;
public:
    PEA(string name, string accountId, string createdAt, string updatedAt, string providerName);
    void addOrder(string order);
    std::list<string> getOrders();
};

#endif //MYAPP_PEA_H