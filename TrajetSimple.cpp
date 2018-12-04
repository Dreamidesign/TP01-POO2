/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

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
/*TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajetSimple )
// Algorithme :
//

{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
#endif
	villeDepart = unTrajetSimple.villeArrive;
	villeArrive = unTrajetSimple.villeDepart;
    moyenTransport = unTrajetSimple.moyenTransport;
} //----- Fin de TrajetSimple (constructeur de copie)
*/

TrajetSimple::TrajetSimple (  char* a ,  char* b ,  char* mT) : Trajet (a , b)
// Algorithme :
//
{
  #ifdef MAP
      cout << "Appel au constructeur de <TrajetSimple>" << endl;
  #endif

  moyenTransport = mT;
/*
  for (unsigned int i = 0; i < strlen(mT); i++) {
    moyenTransport[i] = mT[i];
  }*/
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
	Trajet ::~Trajet();
	delete[] moyenTransport;
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
