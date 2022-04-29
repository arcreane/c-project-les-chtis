//
// Created by Rami Osman on 29/04/2022.
//
#include "Product.h"
#ifndef MYAPP_DIGITALPRODUCT_H
#define MYAPP_DIGITALPRODUCT_H
#endif //MYAPP_DIGITALPRODUCT_H

class DigitalProduct: public Product{
private:
    string token;

public:
    DigitalProduct(string name, string createdAt, string updatedAt, string providerName);
    void setToken(string token);
    string getToken();
};