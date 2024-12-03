#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "VisiteurImprimeur.h"

class AbstractReservation 
{
protected:
	AbstractReservation();
	VisiteurImprimeur* _visite;
	std::string _nom;
	std::string _description;
	double _prix;
	virtual void accept(VisiteurImprimeur& visiteur) = 0;
	virtual AbstractReservation* clone() const = 0;
	friend class ReservationComposite;
public:
	~AbstractReservation() = default;
	AbstractReservation& getReservation();
	const virtual std::string& getNom();
	const virtual double& getPrix();
	friend std::ostream& operator<<(std::ostream& stream, AbstractReservation& reserv);
	friend class ImprimeurReservation;
};