#include "BDORProxy.h"

BDORProxy::BDORProxy(BDOR* bdor) : bdor(bdor) {}

const std::vector<Reservation>& BDORProxy::acceder(std::string categorie) {
    if (!bdor) {
        throw std::runtime_error("Accès à un BDOR non initialisé.");
    }

    return bdor->acceder(categorie);
}