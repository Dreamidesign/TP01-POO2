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

	//----------------------------------------------------------------- PUBLIC

	//----------------------------------------------------- Méthodes publiques
	void Trajet::Affichage(const char * c ) const
	{
		cout << c << "De " << GetVilleDepart() << " a " << GetVilleArrive() << " ";
	} //----- Fin de Affichage

	//-------------------------------------------- Constructeurs - destructeur

	Trajet::~Trajet()
	{
	#ifdef MAP
		cout << "Appel au destructeur de <Trajet>" << endl;
	#endif
	} //----- Fin de ~Trajet

	void Trajet::ChaineEnMaj (char * ch)
	{
		unsigned int i = 0;
		while (ch[i] != '\0')
		{
			if (ch[i] >= 'a' && ch[i] <= 'z')
			{
				ch[i] += 'A' - 'a';
			}
			++i;
		}
	}

	//------------------------------------------------------------------ PROTEGE
	Trajet::Trajet()
	{
	#ifdef MAP
		cout << "Appel au constructeur de <Trajet>" << endl;
	#endif

	} //----- Fin de Trajet
