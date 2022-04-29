//
// Created by Rami Osman on 29/04/2022.
//
#include <iostream>
#include "DigitalProduct.h"

DigitalProduct::DigitalProduct(string name, string createdAt, string updatedAt, string providerName): Product("DIGITAL_" + name, createdAt, updatedAt, providerName){

}

void DigitalProduct::setToken(string token) {
    this->token = token;
}

string DigitalProduct::getToken() {
    return this->token;
}