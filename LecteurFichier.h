#pragma once
#include <sstream>
#include <string>
#include <io.h>
#include <map>
#include <vector>
using namespace std;
class LecteurFichier
{
public:
	std::vector<std::string>* obtenirDonnees(std::string categorie, std::string typeDonnee);
private:
	std::vector<string> cles = {"Vols", "Hebergement", "Excursions"};
	LecteurFichier();
	std::map<std::string, std::map<std::string, std::vector<std::string>>> _donneesParCategorie;
	friend class BDOR;
	~LecteurFichier();
};

