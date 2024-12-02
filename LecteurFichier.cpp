#include "LecteurFichier.h"
#include <fstream>

std::map<std::string, std::vector<std::string>>& lireCSV(std::string cheminFichier) {
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
}

