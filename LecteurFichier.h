#pragma once
#include <sstream>
#include <string>
#include <io.h>
#include <map>
#include <vector>
using namespace std;
class LecteurFichier
{
// private:
public:
	LecteurFichier();
	std::map<std::string, std::map<std::string, std::vector<std::string>>> _donneesParCategorie;
	std::vector<std::string>& obtenirDonnees(std::string categorie, std::string typeDonnee);
};

