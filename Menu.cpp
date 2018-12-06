/*************************************************************************
                           Menu  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Menu> (fichier Menu.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <cstring>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Menu.h"
#include "Structure.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Menu::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Menu::ajoutSimple()
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

	bool canBeAdded = true;
	for(int i=0; i<liste->getNbTrajets(); i++)
	{
			if(!strcmp(liste->getTabTrajet()[i]->getType(), t->getType())
			&& !strcmp(liste->getTabTrajet()[i]->getVilleDepart(), depart)
			&& !strcmp(liste->getTabTrajet()[i]->getVilleArrive(), arrivee)
			&& !strcmp(liste->getTabTrajet()[i]->getMoyenTransport(), t->getMoyenTransport()))
			{
				canBeAdded = false;
				cout << "\n" << "Trajet existant" << "\n" << endl;
				break;
			}
	}
	if(canBeAdded == true)
	{
		liste->ajouterTrajet(t);
		cout << "\n" << "Trajet ajoute !" << endl;
	}
	else{
		delete t;
	}

	delete[] depart;
	delete[] arrivee;
	delete[] mt;
}

void Menu::ajoutCompose()
{
	int nbVilles = 0;
	cout << "Combien d'etapes comporte votre trajet (nombre de villes total)" << endl;
	cin >> nbVilles;
	char** tabVille = new char *[nbVilles];
	char** tabVilleTemp = new char *[nbVilles];
	char** tabMT = new char *[nbVilles];
	// Trajet ** tabTrajets;
	// tabTrajets = new Trajet *[nbVilles - 1];
	Structure *tabTS = new Structure();

	cout << nbVilles << endl;
	for (int i = 0; i < nbVilles; i++)
	{
		cout << "Rentrer la " << (i+1) << "eme ville : " << endl;
		tabVille[i] = new char[20];
		cin >> tabVille[i];

		//On veut éviter la libération double des villes
		tabVilleTemp[i] = new char[20];
		strcpy(tabVilleTemp[i],tabVille[i]);
		if (i != 0)
		{
			cout << "Quel est le moyen de transport entre " << tabVille[i - 1] << " et " << tabVille[i] << " ?" << endl;
			tabMT[i] = new char[20];
			cin >> tabMT[i]; //Le moyen de transport est stocke e l'adresse de la ville d'arrivee, aucun moyen de transport en 0


			 Trajet* t = new TrajetSimple(tabVille[i - 1], tabVilleTemp[i], tabMT[i]);
			// tabTrajets[i - 1] = t;
			tabTS->ajouterTrajet(t);
		}
	}

	TrajetCompose* tc = new TrajetCompose(tabVille[0], tabVille[nbVilles-1], tabTS);

	liste->ajouterTrajet(tc);
	cout << "\n" << "Trajet ajoute !" << endl;

	freeTab (tabMT , nbVilles);
	freeTab ( tabVille , nbVilles) ;
	freeTab ( tabVilleTemp , nbVilles);
}

void Menu::rechercher()
{
	char* depart = new char[100];
	char* arrivee = new char[100];

	cout << "Bonjour, quelle est votre destination de depart ? " << endl;
	cin >> depart;
	cout << "Et votre ville d'arrivee" << endl;
	cin >> arrivee;

	cout << "\n" << "\n" << "Resultats de la requete : " << endl;

	for (int i=0; i<liste->getNbTrajets(); i++)
	{
		if (!strcmp(liste->getTabTrajet()[i]->getVilleDepart(), depart) && !strcmp(liste->getTabTrajet()[i]->getVilleArrive(), arrivee))
		{
			cout << "Trajet : ", liste->getTabTrajet()[i]->Affichage();
		}
	}

	delete [] depart ;
	delete [] arrivee ;

}

void Menu::menuTrajet() {
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
			ajoutSimple();
			break;
		case 2:
			cout << "Ajout d'un trajet compose" << endl;
			ajoutCompose();
			break;
		case 3:
			break;
		default:
		cout << "Choix invalide. Attendu : 1-2-3" << endl;

		}
	} while (choix2 != 3);

}

void Menu::mainMenu()
{
	do
	{
		choix2 = 0;

		cout << "\n" << "\n" << "------Bienvenue sur FlexiTrip------" << "\n" << endl;
  	cout << "         Menu         " << endl;
  	cout << "1. Ajouter un trajet" << endl;
  	cout << "2. Afficher le catalogue de trajets proposes" << endl;
  	cout << "3. Rechercher un parcours" << endl;
  	cout << "4. Quitter" << endl;
  	cin >> choix1;

		switch (choix1)
		{
		case 1:
			cout << "*Ajout d'un trajet*" << endl;
			menuTrajet();
			break;
		case 2:
			cout << "*------Catalogue-------*" << endl;
			liste->Affichage();
			break;
		case 3:
			cout << "*Recherche...*" << endl;
			rechercher();
			break;
		case 4:
			break;
		default:
			break;
		}

	} while (choix1 != 4);
}


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Menu::Menu ( const Menu & unMenu )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Menu>" << endl;
#endif
} //----- Fin de Menu (constructeur de copie)


Menu::Menu ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Menu>" << endl;
#endif
  // Structure s();
	// liste = s;
	liste = new Structure();
  // mainMenu();

} //----- Fin de Menu


Menu::~Menu ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Menu>" << endl;
#endif
	delete liste;
} //----- Fin de ~Menu

void Menu::freeTab ( char ** tab , int size )
{
	for ( int i = 0 ; i<size ; i++ )
	{
		delete[] tab[i] ;
	}
	delete [] tab ;
}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
