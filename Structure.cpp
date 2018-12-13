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
#define TAILLE 20
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


Trajet** Structure::getTabTrajet(void) const
{
  return trajet;
} //-- Fin getTabTrajet

int Structure::getNbTrajets(void) const
{
  return nbTrajets;
} //-- Fin getNbTrajets

void Structure::Affichage(void) const
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
{
//Réallocation dynamique du tableau de pointeur de trajet si il est plein
if(nbAllocated == nbTrajets)
{
  #ifdef MAP
      cout << "Reallocation de la structure" << endl;
  #endif
		Trajet ** temp;
		nbAllocated += 30;
		temp = new Trajet *[nbAllocated];

		for (int i = 0; i < nbTrajets; i++) {
			temp[i] = trajet[i];
		}

    delete[] trajet;
    trajet = temp;
	}

  //Ajout du trajet au tableau
  nbTrajets++;
  #ifdef MAP
      cout << "NbTrajets : " << nbTrajets << endl;
      cout << "nbAllocated : " << nbAllocated << endl;
      cout << "ajout en position : " << (nbTrajets-1) << endl;
      cout << "Ajout du trajet à la structure" << endl;
  #endif

	trajet[nbTrajets - 1] = t;
} //-- Fin ajouterTrajet

//-------------------------------------------- Constructeurs - destructeur

Structure::Structure (void)
{
#ifdef MAP
    cout << "Appel au constructeur de <Structure>" << endl;
#endif
nbTrajets =0;
nbAllocated = TAILLE ;
trajet = new Trajet*[TAILLE];
} //----- Fin de Structure

Structure::~Structure ( )
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

//----------------------------------------------------- Méthodes protégées
