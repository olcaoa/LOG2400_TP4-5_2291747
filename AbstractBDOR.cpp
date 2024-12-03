#include "AbstractBDOR.h"

const std::vector<Reservation>& AbstractBDOR::operator[](std::string key) {
    return acceder(key);
}