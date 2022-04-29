//
// Created by Rami Osman on 29/04/2022.
//

#ifndef MYAPP_COMPTEDEVISE_H
#define MYAPP_COMPTEDEVISE_H

#endif //MYAPP_COMPTEDEVISE_H
#include "BankProduct.h"

class CompteDevice: public BankProduct {
private:
    int rate;
    int ceiling;
public:
    CompteDevice(int rate, int ceiling, string accountId ,string name, string createdAt, string updatedAt, string providerName);
    int getRate();
    int getCeiling();
};