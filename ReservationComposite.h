#pragma once
#include "AbstractReservation.h"
#include "ImprimeurReservation.h"
#include "VisiteurCopieur.h"

class ReservationComposite : public AbstractReservation
{
private:
	ImprimeurReservation imprimeur;
protected:
	std::vector<AbstractReservation*> _reservations;
	double calculerPrix();
public:
	ReservationComposite();
    ReservationComposite(const ReservationComposite& autreComposite);
	const virtual double& getPrix() override;
	void ajouterReservation(AbstractReservation* r);
	void enleverReservation(AbstractReservation* r);
	std::vector<AbstractReservation*>& obtenirReservations();
	void accept(VisiteurImprimeur& visiteur) override;
	AbstractReservation* clone() const override;
};

