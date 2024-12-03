#include "AbstractBDOR.h"

std::vector<Reservation>& AbstractBDOR::operator[](std::string key) {
    return acceder(key);
}