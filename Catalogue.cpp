/*************************************************************************
						   CATALOGUE  -  description
							 -------------------
	d�but                : ${date}
	copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <CATALOGUE> (fichier Catalogue) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <cstring>
//coucou

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
//------------------------------------------------------------- Constantes
#define TAILLE 100
//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques

Trajet** Catalogue::getTabTrajet() const
{
	return trajet;
}

int Catalogue::getNbTrajets() const
{
	return nbTrajets;
}

void Catalogue::AjoutTrajet(Trajet *t)
{

if(nbAllocated == nbTrajets)
	{
		Trajet ** temp;
		nbAllocated += 30;
		temp = new Trajet *[nbAllocated];

		for (int i = 0; i < nbTrajets; i++) {
			temp[i] = trajet[i];
		}
		trajet = temp;
		delete temp ; //depend de la structure  
	}
	nbTrajets++;
	trajet[nbTrajets - 1] = t;

}

void Catalogue::RechercheSimple(char* a, char* b) const
{
	for (int i=0; i<nbTrajets; i++)
	{
		if (!strcmp(trajet[i]->getVilleDepart(), a) && !strcmp(trajet[i]->getVilleArrive(),b))
		{
			cout << "Trajet : ", trajet[i]->Affichage();
		}
	}
}

/*Catalogue Catalogue::RechercheComposee(char* a, char* b) const
{
}*/

void Catalogue::Affichage() const
{
	for (int i = 0; i < nbTrajets; i++)
	{
		trajet[i]->Affichage();
	}
}

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue (const Catalogue &unCatalogue)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <CATALOGUE>" << endl;
#endif
	// nbTrajets = unCatalogue.nbTrajets;
	// trajet = unCatalogue.trajet;

} //----- Fin de CATALOGUE (constructeur de copie)


Catalogue::Catalogue ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <CATALOGUE>" << endl;
#endif
	nbTrajets= 0 ;
	nbAllocated = TAILLE;
	trajet = new Trajet*[TAILLE];
} //----- Fin de CATALOGUE


Catalogue::~Catalogue ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <CATALOGUE>" << endl;
#endif

	for (int i = 0; i < nbAllocated; i++)
	{
		delete trajet[i];
	}
	delete[] trajet;
} //----- Fin de ~CATALOGUE


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
