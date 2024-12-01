#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>

class AbstractReservation
{

protected:
	std::string nom;
	std::string description;
	double prix;
	virtual std::string imprimer() = 0;

public:
	const virtual std::string& getNom() = 0;
};