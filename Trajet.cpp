/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include <cstring>

//------------------------------------------------------------- Constantes

	//----------------------------------------------------------------- PUBLIC

	//----------------------------------------------------- Méthodes publiques
	void Trajet::Affichage(const char * c ) const
		// Algorithme :
		//
	{
		cout << c << "De " << villeDepart << " a " << villeArrive << " ";
	} //----- Fin de Affichage


	char* Trajet::getVilleDepart() const
		// Algorithme :
		//
	{
		return villeDepart;
	} //----- Fin de getVilleDepart

	char* Trajet::getVilleArrive() const
		// Algorithme :
		//
	{
		return villeArrive;
	} //----- Fin de getVilleDepart

	const char* Trajet::getType()
	{
		return "";
	}

	char* Trajet::getMoyenTransport() const
	{
		return villeArrive;
	}


	//-------------------------------------------- Constructeurs - destructeur
	/*Trajet::Trajet(const Trajet & unTrajet)
		// Algorithme :
		//
	{
	#ifdef MAP
		cout << "Appel au constructeur de copie de <Trajet>" << endl;
	#endif
		villeDepart = unTrajet.villeDepart;
		villeArrive = unTrajet.villeArrive;
	} //----- Fin de Trajet (constructeur de copie)
	*/

	Trajet::Trajet(const char* uneVilleDepart , const char* uneVilleArrive)
		// Algorithme :
		//
	{
	#ifdef MAP
		cout << "Appel au constructeur de <Trajet>" << endl;
	#endif
		villeDepart = new char [strlen(uneVilleDepart)+1];
		villeDepart = strcpy (villeDepart,uneVilleDepart);
		villeArrive = new char [strlen(uneVilleArrive)+1];
		villeArrive = strcpy (villeArrive,uneVilleArrive);
	} //----- Fin de Trajet


	Trajet::~Trajet()
		// Algorithme :
		//
	{
	#ifdef MAP
		cout << "Appel au destructeur de <Trajet>" << endl;
	#endif
		delete[] villeDepart;
		delete[] villeArrive;
	} //----- Fin de ~Trajet


	//------------------------------------------------------------------ PRIVE

	//----------------------------------------------------- Méthodes protégées
