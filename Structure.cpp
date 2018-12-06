/*************************************************************************
                           Structure  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Structure> (fichier Structure.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Structure.h"

//------------------------------------------------------------- Constantes
#define TAILLE 100
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Structure::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
Trajet** getTabTrajet() const
{
  return trajet;
}

int getNbTrajets() const
{
  return nbTrajets;
}

void Affichage() const
{
  for (int i = 0; i < nbTrajets; i++)
	{
		trajet[i]->Affichage();
	}
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur


Structure::Structure ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Structure>" << endl;
#endif
nbAllocated = TAILLE ;
trajet = new Trajet*[TAILLE];
} //----- Fin de Structure


Structure::~Structure ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Structure>" << endl;
#endif

	for (int i = 0; i < nbAllocated; i++)
	{
		delete trajet[i];
	}
	delete[] trajet;
} //----- Fin de ~Structure


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
