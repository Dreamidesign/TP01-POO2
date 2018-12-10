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

char* TrajetSimple::getMoyenTransport(void) const
// Algorithme :
//
{
    return moyenTransport;
} //----- Fin de Méthode

bool TrajetSimple :: doublon (const Trajet * t) const
// Algorithme :
//
{
  if (Trajet::doublon(t))
  {
    if (!strcmp(moyenTransport,t->getMoyenTransport()))
    {
      return true;
    }
    else
    {
      return false ;
    }
  }
  else
  {
    return false;
  }
} //-- Fin de doublon


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
  moyenTransport = new char [strlen(unMoyenTransport)+1];
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
