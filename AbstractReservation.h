#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>

class AbstractReservation
{

protected:
	std::string _nom;
	std::string _description;
	double _prix;
public:
	virtual std::string imprimer() = 0;
	const virtual std::string& getNom();
	const virtual double& getPrix();
	friend std::ostream& operator<<(std::ostream& stream, AbstractReservation& reserv);
};