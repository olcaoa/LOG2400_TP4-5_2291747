#pragma once
#include "AbstractReservation.h"
#include "ImprimeurReservation.h"

class ReservationComposite : public AbstractReservation
{
protected:
	std::vector<AbstractReservation*> _reservations;
	double calculerPrix();
public:
	~ReservationComposite() = default;
	ReservationComposite();
	const virtual double& getPrix() override;
	void ajouterReservation(AbstractReservation* r);
	void enleverReservation(AbstractReservation* r);
	std::vector<AbstractReservation*> obtenirReservations();
	void accept(VisiteurImprimeur& visiteur) override;
	friend class ImprimeurReservation;
};

