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
#include <string>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include <cstring>

	//----------------------------------------------------------------- PUBLIC

	//----------------------------------------------------- Méthodes publiques
	void Trajet::Affichage(const char * c ) const
	{
		cout << c << "De " << GetVilleDepart() << " a " << GetVilleArrive() << " ";
	} //----- Fin de Affichage

	std::string Trajet::toStringAsString (void) const
	{
		char * s = toString ();
		std::string str (s);
		delete [] s;
		return str;
	}

	//-------------------------------------------- Constructeurs - destructeur

	Trajet::~Trajet()
	{
	#ifdef MAP
		cout << "Appel au destructeur de <Trajet>" << endl;
	#endif
	} //----- Fin de ~Trajet


	//------------------------------------------------------------------ PROTEGE
	Trajet::Trajet()
	{
	#ifdef MAP
		cout << "Appel au constructeur de <Trajet>" << endl;
	#endif

	} //----- Fin de Trajet
