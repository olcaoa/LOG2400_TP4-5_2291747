#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "VisiteurImprimeur.h"


class AbstractReservation 
{
protected:
	std::string _nom;
	std::string _description;
	double _prix;
public:
	const AbstractReservation& getReservation();
	const virtual std::string& getNom();
	const virtual double& getPrix();

    virtual void accept(VisiteurImprimeur& visiteur) = 0;

	friend std::ostream& operator<<(std::ostream& stream, AbstractReservation& reserv);
	friend class ImprimeurReservation;
};