#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>

class AbstractReservation 
{
protected:
	virtual std::string imprimer() = 0;
	std::string _nom;
	std::string _description;
	double _prix;
public:
	const AbstractReservation& getReservation();
	const virtual std::string& getNom();
	const virtual double& getPrix();
	friend std::ostream& operator<<(std::ostream& stream, AbstractReservation& reserv);
	friend class ImprimeurReservation;
};