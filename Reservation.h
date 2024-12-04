#pragma once
#include "ReservationComposite.h"

class Reservation : public ReservationComposite
{
public:
	Reservation& getReservation(std::string nom);
	void ajouterReservation(Reservation* r);
	void enleverReservation(Reservation* r);
	bool comparerReservations(Reservation compare);
	~Reservation() = default;
	void accept(VisiteurImprimeur& visiteur) override;
	Reservation();
	Reservation(const Reservation& other);
	Reservation(std::string nom, std::string description, double prix);
	AbstractReservation* clone() const override;
};