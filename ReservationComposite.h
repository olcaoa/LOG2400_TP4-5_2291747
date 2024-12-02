#pragma once
#include "AbstractReservation.h"
#include "ImprimeurReservation.h"
class ReservationComposite : public AbstractReservation
{
private:
	ImprimeurReservation imprimeur;
protected:
	std::vector<AbstractReservation*> _reservations;
	double calculerPrix();
public:
	const virtual double& getPrix() override;
	void ajouterReservation(AbstractReservation* r);
	void enleverReservation(AbstractReservation* r);
	std::vector<AbstractReservation*>& obtenirReservations();
	void accept(VisiteurImprimeur& visiteur) override;
};

