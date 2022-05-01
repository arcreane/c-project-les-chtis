//
// Created by Rami Osman on 29/04/2022.
//

#ifndef MYAPP_COMPTEDEVISE_H
#define MYAPP_COMPTEDEVISE_H

#include "BankProduct.h"

class CompteDevise: public BankProduct {
private:
    int rate;
    int ceiling;
    int amount;
public:
    CompteDevise(int amount, int rate, int ceiling, string accountId ,string name, string createdAt, string updatedAt, string providerName);
    int getRate();
    int getCeiling();
    int getAmount();
};


#endif //MYAPP_COMPTEDEVISE_H