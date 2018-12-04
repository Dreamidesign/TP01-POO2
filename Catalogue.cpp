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


//------------------------------------------------------ Include personnel
#include "Catalogue.h"
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques

void Catalogue::AjoutTrajet(Trajet *t)
{


	if (nbTrajets = 0)
	{
		*trajet = t;
	}
	else if(nbAllocated == nbTrajets)
	{
		Trajet ** temp;
		nbAllocated += 30;
		temp = new Trajet *[nbAllocated];

		for (int i = 0; i < nbTrajets; i++) {
			temp[i] = Trajet[i];
		}

		Trajet = temp;

		*Trajet[nbTrajets + 1] = t;
		nbTrajets++;
	}
	else
	{
		trajet++;
		*trajet = t;
		nbTrajets++;
	}

}

void Catalogue::RechercheSimple(char* a, char* b) const
{
	for (int i=0; i<nbTrajets; i++)
	{
		if (strcmp(trajet[i]->getVilleDepart(), a) && strcmp(trajet[i]->getVilleArrive(),b))
		{
			trajet[i]->Affichage();
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

	trajet = new Trajet*[nbAllocated];
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

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
