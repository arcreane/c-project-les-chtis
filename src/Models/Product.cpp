//
// Created by Rami Osman on 29/04/2022.
//
#include <iostream>
#include "Product.h"

Product::Product(string name, string createdAt, string updatedAt, string providerName) {
    this->name = name;
    this->createdAt = createdAt;
    this->updatedAt = updatedAt;
    this->providerName = providerName;
}

string Product::getCreatedAt() {
    return this->createdAt;
}

string Product::getUpdatedAt() {
    return this->updatedAt;
}

string Product::getName() {
    return this->name;
}

string Product::getProviderName() {
    return this->providerName;
}
