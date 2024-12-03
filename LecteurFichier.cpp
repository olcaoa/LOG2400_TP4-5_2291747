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
	return mapDeRetour;
}

LecteurFichier::LecteurFichier() {
	using namespace std;
	map<string, vector<string>> vols = lireCSV(chemin + "Vols.csv");
	map<string, vector<string>> hebergement = lireCSV(chemin + "Hebergements.csv");
	map<string, vector<string>> excursion = lireCSV(chemin + "Excursions");
	_donneesParCategorie[cles[0]] = vols;
	_donneesParCategorie[cles[1]] = hebergement;
	_donneesParCategorie[cles[2]] = excursion;
}

std::vector<std::string> LecteurFichier::obtenirDonnees(std::string categorie, std::string typeDonnee)
{
	return _donneesParCategorie[categorie][typeDonnee];
}

