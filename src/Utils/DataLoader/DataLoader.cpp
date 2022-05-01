//
// Created by CYTech Student on 01/05/2022.
//

#include "DataLoader.h"
#include "../../Models/Product.cpp"
#include "../../Models/BankProduct.cpp"
#include "../../Models/DigitalProduct.cpp"
#include "../../Models/CompteDevise.cpp"
#include "../../Models/CryptoCurrency.cpp"
#include "../../Models/Nft.cpp"
#include "../../Models/PEA.cpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <sstream>
#include "../../../rapidjson/document.h"
#include "../../../rapidjson/writer.h"
#include "../../../rapidjson/stringbuffer.h"

using std::cout;
using std::cout;
using std::endl;
using std::string;
using std::ifstream; using std::ostringstream;

using namespace rapidjson;

DataLoader::DataLoader() {
    path = "../Resources/assets/Resources/Data.json";
}

string DataLoader::readFileIntoString() {
    ifstream input_file(this->path);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    return string(std::istreambuf_iterator<char>(input_file), std::istreambuf_iterator<char>());
}

bool DataLoader::loadInProducts() {
    try {
        string json_product = this->readFileIntoString();
        const char *formatted = json_product.data();
        Document doc;
        doc.Parse(formatted);
        if (doc.HasMember("type") && doc.HasMember("elements")) {
            Value &productElements = doc["elements"];
            if (productElements.IsArray()) {
                for (Value &v: productElements.GetArray()) {
                    if (v.HasMember("type") && v.HasMember("elements")) {
                        string globalType = v["type"].GetString();
                        Value &subProductElements = v["elements"];
                        if (subProductElements.IsArray()) {
                            for (Value &v2: subProductElements.GetArray()) {
                                if (v2.HasMember("type") && v2.HasMember("elements")) {
                                    string subType = v2["type"].GetString();
                                    Value &finalProductElements = v2["elements"];
                                    if (finalProductElements.IsArray()) {
                                        for (Value &v3: finalProductElements.GetArray()) {
                                            this->addProduct(globalType, subType, v3);
                                        }
                                    }

                                }
                            }
                        }
                    }
                }
            }
        }

        return true;
    } catch (int err) {
        cerr << "ERROR " << err;
    }

}

std::list<PEA> DataLoader::getPeas() {
    return this->peas;
}

void DataLoader::addProduct(string type, string subType, Value &element) {

    if (type == "BankProduct") {
        if (subType == "CompteDevise") {
            CompteDevise cd = this->toProductCompteDevise(element);
            this->comptesDevise.push_back(cd);
        } else if (subType == "PEA") {
            PEA pea = this->toProductPEA(element);
            this->peas.push_back(pea);
        }
    } else if (type == "DigitalProduct") {
        if (subType == "NFT") {
            Nft nft = this->toProductNFT(element);
            this->nfts.push_back(nft);
        }else if(subType == "CryptoCurrency"){
            CryptoCurrency ccr = this->toProductCryptoCurrency(element);
            this->cryptoCurrencies.push_back(ccr);
        }

    }
}

CompteDevise DataLoader::toProductCompteDevise(Value &v) {
    int ceiling = v["ceiling"].GetInt();
    int rate = v["rate"].GetInt();
    int amount = v["amount"].GetInt();
    string accountId = v["accountId"].GetString();
    string name = v["name"].GetString();
    string createdAt = v["createdAt"].GetString();
    string updatedAt = v["updatedAt"].GetString();
    CompteDevise cd(amount, rate, ceiling, accountId, name, createdAt, updatedAt, "LOCAL_PROVIDER");
    return cd;
}

PEA DataLoader::toProductPEA(Value &v) {
    string values = v["values"].GetString();
    string accountId = v["accountId"].GetString();
    string name = v["name"].GetString();
    string createdAt = v["createdAt"].GetString();
    string updatedAt = v["updatedAt"].GetString();

    PEA pea(name, accountId, createdAt, updatedAt, "PEA_PROVIDER");
    pea.addOrder(values);
    return pea;
}

Nft DataLoader::toProductNFT(Value &v) {
    string currentCote = v["currentCote"].GetString();
    string seller = v["seller"].GetString();
    string createdAt = v["createdAt"].GetString();
    string updatedAt = v["updatedAt"].GetString();

    Nft nft(seller, currentCote, createdAt, updatedAt, "NFT_PROVIDER");
    return nft;
}

CryptoCurrency DataLoader::toProductCryptoCurrency(Value &v){
    string currencyCode = v["currencyCode"].GetString();
    string currencyName = v["currencyName"].GetString();
    int amount = v["amount"].GetInt();
    string createdAt = v["createdAt"].GetString();
    string updatedAt = v["updatedAt"].GetString();

    CryptoCurrency cc(amount, currencyCode, currencyName, createdAt, updatedAt, "CRYPTO_PROVIDER");
    return cc;
}