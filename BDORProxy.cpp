#include "BDORProxy.h"

BDORProxy::BDORProxy() {
    bdor = &BDOR::getInstance();
}

std::vector<Reservation>& BDORProxy::acceder(std::string categorie) {
    if (!bdor) {
        bdor = &BDOR::getInstance();
    }
    return bdor->acceder(categorie);
}