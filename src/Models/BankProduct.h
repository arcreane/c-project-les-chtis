//
// Created by Rami Osman on 29/04/2022.
//

#ifndef MYAPP_BANKPRODUCT_H
#define MYAPP_BANKPRODUCT_H

#endif //MYAPP_BANKPRODUCT_H

#include "Product.h"

class BankProduct: public Product{
private:
    string bankName;
    string accountId;
    int balance;
public:
    BankProduct(string bankName, string accountId, string createdAt, string updatedAt, string providerName);
    void addBalance(int amount);
    int getBalance();
};