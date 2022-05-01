//
//

#ifndef MYAPP_DATALOADER_H
#define MYAPP_DATALOADER_H
#include <string>
#include <vector>
#include "../../Models/Product.h"
#include "../../Models/BankProduct.h"
#include "../../Models/DigitalProduct.h"
#include "../../Models/CompteDevise.h"
#include "../../Models/CryptoCurrency.h"
#include "../../Models/Nft.h"
#include "../../Models/PEA.h"
#include <list>


class DataLoader {

private:
    string path;
    string readFileIntoString();
    CompteDevise toProductCompteDevise(Value& v);
    PEA toProductPEA(Value& v);
    Nft toProductNFT(Value &v);
    CryptoCurrency toProductCryptoCurrency(Value &v);
    std::list<CompteDevise> comptesDevise;
    std::list<CryptoCurrency> cryptoCurrencies;
    std::list<Nft> nfts;
    std::list<PEA> peas;

public:
    DataLoader();
    bool loadInProducts();
    void addProduct(string type, string subType, Value& element);
    std::list<PEA> getPeas();
};


#endif //MYAPP_DATALOADER_H
