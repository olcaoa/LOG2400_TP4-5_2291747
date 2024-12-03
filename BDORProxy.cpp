#include "BDORProxy.h"

BDORProxy::BDORProxy() {
    _bdor = &BDOR::getInstance();
}

std::vector<Reservation>& BDORProxy::acceder(std::string categorie) {
    if (!_bdor) {
        _bdor = &BDOR::getInstance();
    }
    return _bdor->acceder(categorie);
}