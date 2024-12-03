#include "LecteurFichier.h"
#include <fstream>
#include <iostream>

const std::string chemin = "MV_offres_de_reservation_";

std::map<std::string, std::vector<std::string>> lireCSV(std::string cheminFichier) {
	using namespace std;
	map<string, vector<string>> mapDeRetour;
	vector<string> cles;
	ifstream fichier;
	fichier.open(cheminFichier, ios::in);
	string ligne, donnee;
	getline(fichier, ligne);
	stringstream streamLigne(ligne);
	while (getline(streamLigne, donnee, ',')) {
		cles.push_back(donnee);
	}
	while (getline(fichier, ligne)) {
		int i = 0;
		stringstream streamLigne(ligne);
		while (getline(streamLigne, donnee, ',')) {
			mapDeRetour[cles[i++]].push_back(donnee);
		}
	}
	fichier.close();
	return mapDeRetour;
}


void effacerMap(map<string, vector<string>> map) {
	for (auto pair : map) {
		for (auto vector : pair.second) {
			vector.clear();
			vector.shrink_to_fit();
		}
	}
	map.clear();
}


LecteurFichier::LecteurFichier() {
	using namespace std;
	map<string, vector<string>> vols = lireCSV(chemin + "Vols.csv");
	map<string, vector<string>> hebergement = lireCSV(chemin + "Hebergement.csv");
	map<string, vector<string>> excursion = lireCSV(chemin + "Excursions.csv");
	_donneesParCategorie[cles[0]] = vols;
	_donneesParCategorie[cles[1]] = hebergement;
	_donneesParCategorie[cles[2]] = excursion;
}

LecteurFichier::~LecteurFichier()
{
		effacerMap(_donneesParCategorie[cles[0]]);
		effacerMap(_donneesParCategorie[cles[1]]);
		effacerMap(_donneesParCategorie[cles[2]]);
		_donneesParCategorie.clear();
}

std::vector<std::string>* LecteurFichier::obtenirDonnees(std::string categorie, std::string typeDonnee)
{
	return &_donneesParCategorie[categorie][typeDonnee];
}

