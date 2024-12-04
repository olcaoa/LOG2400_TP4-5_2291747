#include "Segment.h"
#include <sstream>


Journee Segment::getJournee(std::string nom)
{
    return *dynamic_cast<Journee*>(getReservation(nom));
}

Segment::Segment(std::string nom) : ReservationComposite() {
    _nom = nom;
}

Segment::~Segment()
{
    _reservations.clear();
    _reservations.shrink_to_fit();
}

Segment::Segment(const Segment& autreSegment)
{
    *this = *dynamic_cast<Segment*>(autreSegment.clone());
}

void Segment::ajouterJournee(Journee& j)
{
    ReservationComposite::ajouterReservation(&j);
}

void Segment::accept(VisiteurImprimeur& visiteur) {
    visiteur.visit(*this);
}

AbstractReservation* Segment::clone() const
{
    Segment* nouveauSeg = new Segment(this->_nom);
    for (AbstractReservation* r : this->_reservations) {
        AbstractReservation* currRes = r;
        Journee* r = dynamic_cast<Journee*>(currRes);
        nouveauSeg->ReservationComposite::ajouterReservation(new Journee(*r));
    }
    return nouveauSeg;
}
