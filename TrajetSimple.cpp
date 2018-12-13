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

//----------------------------------------------------- Méthodes publiques

void TrajetSimple::Affichage (const char* c) const
{
    Trajet::Affichage("TS : ");
    cout << "en "<< moyenTransport << endl;
} //----- Fin de Méthode

char* TrajetSimple::getVilleDepart(void) const
{
  return villeDepart;
} //----- Fin de getVilleDepart

char* TrajetSimple::getVilleArrive(void) const
{
  return villeArrive;
} //----- Fin de getVilleDepart

char* TrajetSimple::getMoyenTransport(void) const
{
    return moyenTransport;
} //----- Fin de Méthode

bool TrajetSimple :: estEgal(const Trajet * t) const
{
  if (     !strcmp(villeDepart,t->getVilleDepart())
        && !strcmp(villeArrive,t->getVilleArrive())
        && !strcmp(moyenTransport,t->getMoyenTransport())
     )
  {
      return true;
  }
  else
  {
    return false;
  }
} //-- Fin estEgal

//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple ( const char* uneVilleDepart,
                             const char* uneVilleArrive,
                             const char* unMoyenTransport)
{
  #ifdef MAP
      cout << "Appel au constructeur de <TrajetSimple>" << endl;
  #endif
  //Allocation et copie des paramètres pour l'encapsulation
  villeDepart = new char [strlen(uneVilleDepart)+1];
  villeDepart = strcpy (villeDepart,uneVilleDepart);
  villeArrive = new char [strlen(uneVilleArrive)+1];
  villeArrive = strcpy (villeArrive,uneVilleArrive);
  moyenTransport = new char [strlen(unMoyenTransport)+1];
  moyenTransport = strcpy(moyenTransport, unMoyenTransport);
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
  delete[] villeDepart;
  delete[] villeArrive;
	delete[] moyenTransport;
} //----- Fin de ~TrajetSimple
