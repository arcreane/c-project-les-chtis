//
// Created by Rami Osman on 29/04/2022.
//
#include "Nft.h"

Nft::Nft(string seller, string cote, string createdAt, string updatedAt, string providerName): DigitalProduct("NFT_"+seller, createdAt, updatedAt, providerName) {
    this->currentCote = cote;
}


string Nft::getCurrentCote() {
    return this->currentCote;
}
