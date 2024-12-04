#include "BDORProxy.h"

BDORProxy::BDORProxy() {
    _bdor = &BDOR::getInstance();
}

int BDORProxy::getNombreOffres() const
{
    return _bdor->getNombreOffres();
}

void BDORProxy::ajusterPrix(double facteur)
{
    _bdor->ajusterPrix(facteur);
}

void BDORProxy::ajouterRabais(Reservation& r, std::string categorie, double rabais)
{
    _bdor->ajouterRabais(r, categorie, rabais);
}

std::vector<Reservation>& BDORProxy::acceder(std::string categorie) {
    if (!_bdor) {
        _bdor = &BDOR::getInstance();
    }
    return _bdor->acceder(categorie);
}