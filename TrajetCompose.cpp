/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Affichage (const char* c = "") const 
// Algorithme :
//
{
	Trajet::Affichage(c); 
	cout << "Le trajet est composé des trajets suivants :" << endl;
	for (int i = 0; i < nbTrajets; i++)
	{
		trajet[i]->Affichage(); // a revoir ( possibilite d'afficher un trajet simple ou compose ) 
	}
} //----- Fin de Méthode
void TrajetCompose::ajouterTrajet(Trajet ** t, int nb)
{
	//trajet = new Trajet*[nb]; 
	for(int i = 0; i < nb; i++)
	{
		trajet[i] = t[i];
	}
}

//-------------------------------------------- Constructeurs - destructeur
 

TrajetCompose::TrajetCompose ( char* a , char* b , int nb  , Trajet ** t ) : Trajet(a, b)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
	//ajouterTrajet(t, nb);
	trajet = t;
	nbTrajets = nb;

} //----- Fin de TrajetCompose

TrajetCompose::TrajetCompose(const Trajet & unTrajet)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie  de <TrajetCompose>" << endl;
#endif
	//ajouterTrajet(t, nb);
	nbTrajets = unTrajet.nbTrajets;
	trajet = unTrajet.trajet;
} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
	for (int i = 0; i < nbTrajets; i++)
	{
		delete[] trajet[i];
	}
	delete[] trajet;
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
