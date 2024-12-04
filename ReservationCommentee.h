#pragma once
#include "AbstractReservationDecoree.h"
class ReservationCommentee : public Reservation, public AbstractReservationDecoree
{
protected:
	virtual void decorer() = 0;
	std::vector<std::string> commentaires;
public:
	ReservationCommentee& getReservation(std::string nom);
	const std::string& getNom() override = 0;
	void accept(VisiteurImprimeur& visiteur) override = 0;
	virtual AbstractReservation* clone() const override = 0;
	void ajouterCommentaire(std::string& comm);
	void enleverCommentaire(std::string& comm);
	std::vector<std::string> trouverCommentatires(std::string& comm);
};

