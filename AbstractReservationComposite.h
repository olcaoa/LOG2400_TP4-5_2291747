#pragma once
#include "AbstractReservation.h"
class ReservationComposite : public AbstractReservation
{
protected:
	std::vector<AbstractReservation*> _reservations;
	double calculerPrix();
	virtual std::string imprimerEnfants();
	virtual std::string imprimer() = 0;
public:
	const virtual double& getPrix() override;
	void ajouterReservation(AbstractReservation* r);
	void enleverReservation(AbstractReservation* r);
	std::vector<AbstractReservation*>& obtenirReservations();
};

