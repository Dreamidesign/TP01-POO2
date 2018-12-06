/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp)

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetSimple::Affichage (const char* c) const
// Algorithme :
//
{
    Trajet::Affichage(c);
    cout << "en "<< moyenTransport << endl;
} //----- Fin de Méthode

char* TrajetSimple::getMoyenTransport() const
// Algorithme :
//
{
    return moyenTransport;
} //----- Fin de Méthode

const char* TrajetSimple::getType()
{
	return "TS";
}//--Fin de getType()


//-------------------------------------------- Constructeurs - destructeur


TrajetSimple::TrajetSimple ( const char* uneVilleDepart,
                             const char* uneVilleArrive,
                             const char* unMoyenTransport):
Trajet (uneVilleDepart,uneVilleArrive)
// Algorithme :
//
{
  #ifdef MAP
      cout << "Appel au constructeur de <TrajetSimple>" << endl;
  #endif
  moyenTransport = new char [strlen(unMoyenTransport)];
  moyenTransport = strcpy(moyenTransport, unMoyenTransport);
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
	delete[] moyenTransport;
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
