//
// Created by Rami Osman on 28/04/2022.
//
#include <string>
#include "../../../rapidjson/document.h"
#include "../../../rapidjson/writer.h"
#include "../../../rapidjson/stringbuffer.h"
#ifndef MYAPP_PRODUCT_H
#define MYAPP_PRODUCT_H

using namespace rapidjson;
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
#endif //MYAPP_PRODUCT_H
