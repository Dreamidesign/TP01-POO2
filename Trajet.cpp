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

	Trajet::Trajet(char* a, char* b)
		// Algorithme :
		//
	{
	#ifdef MAP
		cout << "Appel au constructeur de <Trajet>" << endl;
	#endif
		villeDepart = a;
		villeArrive = b;

/*
		for (unsigned int i = 0; i < strlen(a); i++) {
			if (a[i] == '\0')
			{
				villeDepart[i] = '\0';
				break;
			}
			villeDepart[i] = a[i];

		}

		for (unsigned int i = 0; i < strlen(b); i++) {
			if (b[i] == '\0')
			{
				villeArrive[i] = '\0';
				break;
			}
			villeArrive[i] = b[i];
		}
*/
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
