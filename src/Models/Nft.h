//
// Created by Rami Osman on 29/04/2022.
//

#ifndef MYAPP_NFT_H
#define MYAPP_NFT_H


#include "DigitalProduct.h"

class Nft: public DigitalProduct{
private:
    string currentCote;
    string seller;
public:
    Nft(string seller, string cote, string createdAt, string updatedAt, string providerName);
    string getCurrentCote();
};

#endif //MYAPP_NFT_H