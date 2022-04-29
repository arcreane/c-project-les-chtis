//
// Created by Rami Osman on 28/04/2022.
//
#include <string>
#ifndef MYAPP_PRODUCT_H
#define MYAPP_PRODUCT_H

#endif //MYAPP_PRODUCT_H
using namespace std;
class Product{
private:
    string name;
    string createdAt;
    string updatedAt;
    string providerName;
public:
    Product(string name, string createdAt, string updatedAt, string providerName);
    string getName();
    string getCreatedAt();
    string getUpdatedAt();
    string getProviderName();
};