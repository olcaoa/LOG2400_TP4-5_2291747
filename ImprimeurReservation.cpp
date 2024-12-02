#include "ImprimeurReservation.h"
using namespace std;

const string ImprimeurReservation::imprimer(AbstractReservation& r) {
	return r.imprimer();
}
