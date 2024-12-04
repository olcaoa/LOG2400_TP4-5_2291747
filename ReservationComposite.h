#pragma once
#include "AbstractReservation.h"
#include "ImprimeurReservation.h"

class ReservationComposite : virtual public AbstractReservation
{
protected:
	AbstractReservation* getReservation(std::string nom);
	void ajouterReservation(AbstractReservation* r);
	void enleverReservation(AbstractReservation* r);
	std::vector<AbstractReservation*> obtenirReservations();
	std::vector<AbstractReservation*> _reservations;
	double calculerPrix();
public:
	~ReservationComposite() = default;
	ReservationComposite();
	const double getPrix() override;
	void accept(VisiteurImprimeur& visiteur) override;
	friend class ImprimeurReservation;
};

