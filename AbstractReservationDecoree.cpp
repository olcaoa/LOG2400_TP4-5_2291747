#include "AbstractReservationDecoree.h"

AbstractReservationDecoree::AbstractReservationDecoree(Reservation& r)
{
	this->_reservation = &r;
}