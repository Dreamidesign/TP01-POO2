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
		cout << c << "de " << villeDepart << " a " << villeArrive << " ";
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


	//-------------------------------------------- Constructeurs - destructeur
	Trajet::Trajet(const Trajet & unTrajet)
		// Algorithme :
		//
	{
	#ifdef MAP
		cout << "Appel au constructeur de copie de <Trajet>" << endl;
	#endif
		villeDepart = unTrajet.villeDepart;
		villeArrive = unTrajet.villeArrive;
	} //----- Fin de Trajet (constructeur de copie)


	Trajet::Trajet(char* a, char* b) : villeDepart(a), villeArrive(b)
		// Algorithme :
		//
	{
	#ifdef MAP
		cout << "Appel au constructeur de <Trajet>" << endl;
	#endif
	} //----- Fin de Trajet


	Trajet::~Trajet()
		// Algorithme :
		//
	{
#ifdef MAP
		cout << "Appel au destructeur de <Trajet>" << endl;
#endif
	} //----- Fin de ~Trajet


	//------------------------------------------------------------------ PRIVE

	//----------------------------------------------------- Méthodes protégées

