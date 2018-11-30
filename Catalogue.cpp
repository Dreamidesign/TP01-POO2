/*************************************************************************
						   CATALOGUE  -  description
							 -------------------
	début                : ${date}
	copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <CATALOGUE> (fichier Catalogue) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>


//------------------------------------------------------ Include personnel
#include "Catalogue.h"
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void Catalogue::AjoutTrajet(Trajet *t)
{
	if (trajet == NULL)
		*trajet = t;
	else
	{
		trajet++;
		*trajet = t;
		nbTrajets++;
	}
}

Catalogue Catalogue::RechercheSimple(char* a, char* b) const
{
	Catalogue c1;
	for (int i=0; i<nbTrajets; i++)
	{
		if (strcmp(trajet[i]->getVilleDepart(), a) && strcmp(trajet[i]->getVilleArrive(),b))
		{
			c1.AjoutTrajet(*trajet);
		}
	}
	return c1;
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
	nbTrajets = unCatalogue.nbTrajets; 
	trajet = unCatalogue.trajet;

} //----- Fin de CATALOGUE (constructeur de copie)


Catalogue::Catalogue ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <CATALOGUE>" << endl;
#endif

	trajet = new Trajet*[nbTrajets];
} //----- Fin de CATALOGUE


Catalogue::~Catalogue ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <CATALOGUE>" << endl;
#endif
	for (int i = 0; i < nbTrajets; i++)
	{
		delete[] trajet[i];
	}
	delete[] trajet; 
} //----- Fin de ~CATALOGUE


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
