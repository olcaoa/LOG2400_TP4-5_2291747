#pragma once
#include "AbstractReservationDecoree.h"
class ReservationCommentee : public Reservation, public AbstractReservationDecoree
{
protected:
	virtual void decorer() override;
	std::vector<std::string> commentaires;
public:
	ReservationCommentee(Reservation& r);
	ReservationCommentee& getReservation(std::string nom);
	const std::string& getNom() override;
	void accept(VisiteurImprimeur& visiteur) override;
	virtual AbstractReservation* clone() const override;
	void ajouterCommentaire(std::string comm);
	void enleverCommentaire(std::string comm);
	std::vector<std::string> trouverCommentatires(std::string comm);
};

