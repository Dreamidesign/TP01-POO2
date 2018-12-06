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

Trajet** Structure::getTabTrajet() const
{
  return trajet;
}

int Structure::getNbTrajets() const
{
  return nbTrajets;
}

void Structure::Affichage() const
{
  for (int i = 0; i < nbTrajets; i++)
	{
		trajet[i]->Affichage();
	}
}

/*
void Structure::ajouterTabTrajet(Structure * s)
{
  // nbTrajets = nb;
  // trajet = new Trajet* [nbTrajets];
  for(int i = 0; i < s->getNbTrajets(); i++)
  {
    // trajet[i] = new Trajet*;
    // trajet[i] = t[i];
    ajouterTrajet(s->getTabTrajet()[i]);

  }
}*/



void Structure::ajouterTrajet(Trajet *t)
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

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur


Structure::Structure ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Structure>" << endl;
#endif
nbTrajets = 0;
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
