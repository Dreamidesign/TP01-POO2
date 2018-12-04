#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Catalogue.h"
#include <iostream>
#include <cstring>

using namespace std;

int choix1 = 0; //Choix du premier menu
int choix2 = 3; //choix du sous menu d'ajout de trajets


void ajoutSimple(Catalogue* monCatalogue)
{
	char* depart = new char [100];
	char* arrivee = new char[100];
	char* mt = new char[100];

	cout << "Quel est le depart du trajet" << endl;
	cin >> depart;
	cout << "Quelle est l'arrivee du trajet" << endl;
	cin >> arrivee;
	cout << "Quel est le moyen de transport employe ?" << endl;
	cin >> mt;

	TrajetSimple* t = new TrajetSimple(depart, arrivee, mt);
	cout << sizeof(t) << endl ;

	bool canBeAdded = true;
	for(int i=0; i<monCatalogue->getNbTrajets(); i++)
	{
			if(!strcmp(monCatalogue->getTabTrajet()[i]->getType(), t->getType())
			&& !strcmp(monCatalogue->getTabTrajet()[i]->getVilleDepart(), depart)
			&& !strcmp(monCatalogue->getTabTrajet()[i]->getVilleArrive(), arrivee)
			&& !strcmp(monCatalogue->getTabTrajet()[i]->getMoyenTransport(), t->getMoyenTransport()))
			{
				canBeAdded = false;
				cout << "\n" << "Trajet existant" << "\n" << endl;
				break;
			}
	}
	if(canBeAdded == true)
	{
		monCatalogue->AjoutTrajet(t);
		cout << "\n" << "Trajet ajoute !" << endl;
	}
	else{
		//delete t;
	}

	/*delete[] depart;
	delete[] arrivee;
	delete[] mt;*/
}

void ajoutCompose(Catalogue* monCatalogue)
{
	int nbVilles = 0;
	cout << "Combien d'etapes comporte votre trajet (nombre de villes total)" << endl;
	cin >> nbVilles;
	char** tabVille = new char *[nbVilles];
	char** tabMT = new char *[nbVilles];
	Trajet ** tabTrajets;
	tabTrajets = new Trajet *[nbVilles - 1];


	cout << nbVilles << endl;
	for (int i = 0; i < nbVilles; i++)
	{
		cout << "Rentrer la " << (i+1) << "eme ville : " << endl;
		tabVille[i] = new char[20];
		cin >> tabVille[i];
		if (i != 0)
		{
			// cout << "soucis1" << endl;
			cout << "Quel est le moyen de transport entre " << tabVille[i - 1] << " et " << tabVille[i] << " ?" << endl;
			tabMT[i] = new char[20];
			cin >> tabMT[i]; //Le moyen de transport est stocke e l'adresse de la ville d'arrivee, aucun moyen de transport en 0


			Trajet* t = new TrajetSimple(tabVille[i - 1], tabVille[i], tabMT[i]);
			tabTrajets[i - 1] = t;
		}
	}

	TrajetCompose* tc = new TrajetCompose(tabVille[0], tabVille[nbVilles - 1], nbVilles - 1, tabTrajets);

	monCatalogue->AjoutTrajet(tc);
	cout << "\n" << "Trajet ajoute !" << endl;

/*	for (int i = 0; i < nbVilles; i++) {
		delete [] tabVille[i];
	}
	delete [] tabVille;

	for (int i = 1; i < nbVilles; i++) {
		delete [] tabMT[i];
	}
	delete [] tabMT; */
}

void rechercher(Catalogue* monCatalogue)
{
	char* depart = new char[100];
	char* arrivee = new char[100];

	cout << "Bonjour, quelle est votre destination de depart ? " << endl;
	cin >> depart;
	cout << "Et votre ville d'arrivee" << endl;
	cin >> arrivee;

	cout << "\n" << "\n" << "Resultats de la requete : " << endl;
	monCatalogue->RechercheSimple(depart, arrivee);
}


void mainMenu()
{
	cout << "\n" << "\n" << "------Bienvenue sur FlexiTrip------" << "\n" << endl;
	cout << "         Menu         " << endl;
	cout << "1. Ajouter un trajet" << endl;
	cout << "2. Afficher le catalogue de trajets proposes" << endl;
	cout << "3. Rechercher un parcours" << endl;
	cout << "4. Quitter" << endl;
	cin >> choix1;
}

void menuTrajet(Catalogue *monCatalogue) {
	do
	{
		cout << "Quel est le type de trajet ?" << endl;
		cout << "1. Simple" << endl;
		cout << "2. Compose" << endl;
		cout << "3. Retour au menu" << endl;
		cin >> choix2;

		switch (choix2)
		{
		case 1:
			cout << "Ajout d'un trajet simple" << endl;
			ajoutSimple(monCatalogue);
			break;
		case 2:
			cout << "Ajout d'un trajet compose" << endl;
			ajoutCompose(monCatalogue);
			break;
		case 3:
			break;
		default:
			break;
		}
	} while (choix2 != 3);

}

void menu(Catalogue* monCatalogue)
{
	do
	{
		choix2 = 0;
		mainMenu();
		switch (choix1)
		{
		case 1:
			cout << "*Ajout d'un trajet*" << endl;
			menuTrajet(monCatalogue);
			break;
		case 2:
			cout << "*------Catalogue-------*" << endl;
			monCatalogue->Affichage();
			break;
		case 3:
			cout << "*Recherche...*" << endl;
			rechercher(monCatalogue);
			break;
		case 4:
			break;
		default:
			break;
		}

	} while (choix1 != 4);
}

int main()
{

	Catalogue * c = new Catalogue();
	menu(c);

	delete c;

	return 0;
}
