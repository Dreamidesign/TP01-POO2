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


Trajet** Structure::getTabTrajet(void) const
// Algorithme :
//
{
  return trajet;
} //-- Fin getTabTrajet

int Structure::getNbTrajets(void) const
// Algorithme :
//
{
  return nbTrajets;
} //-- Fin getNbTrajets

void Structure::Affichage(void) const
// Algorithme :
//
{
  if (nbTrajets == 0)
  {
    cout << "Le catalogue est vide!" << endl;
  }
  for (int i = 0; i < nbTrajets; i++)
	{
		trajet[i]->Affichage();
	}
} //-- Fin Affichage



void Structure::ajouterTrajet(Trajet *t)
// Algorithme :
//
{

//Réallocation dynamique du tableau de pointeur de trajet si il est plein
if(nbAllocated == nbTrajets)
	{
		Trajet ** temp;
		nbAllocated += 30;
		temp = new Trajet *[nbAllocated];

		for (int i = 0; i < nbTrajets; i++) {
			temp[i] = trajet[i];
		}
		trajet = temp;

    for (int i = 0; i < nbAllocated; i++)
    {
      delete temp[i];
    }
    delete[] temp;
	}
  //Ajout du trajet au tableau
	nbTrajets++;
	trajet[nbTrajets - 1] = t;
} //-- Fin ajouterTrajet


//-------------------------------------------- Constructeurs - destructeur


Structure::Structure (void)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Structure>" << endl;
#endif
nbTrajets =0;
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

	for (int i = 0; i < nbTrajets; i++)
	{
		delete trajet[i];
	}
	delete[] trajet;
} //----- Fin de ~Structure


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
