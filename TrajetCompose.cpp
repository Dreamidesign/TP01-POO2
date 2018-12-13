/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//-------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp)

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;
//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Affichage (const char* c = "") const
{
	Trajet::Affichage("TC : ");
	cout << "Le trajet est compose de " << tabTC->getNbTrajets()
			 << "trajets : " << endl;
	for (int i = 0; i < tabTC->getNbTrajets(); i++)
	{
		tabTC->getTabTrajet()[i]->Affichage(c);
	}
	cout << "\n";
} //----- Fin de Affichage

/*bool estEgal (const Trajet * t) const
{
	for (int i = 0 ; i < tabTC->getNbTrajets(); i++)
	{
		if (!(t->getTabTrajet()[i]->estEgal(tabTC[i])))
		{
			return false;
		}
	}
	return true ;
} //----- Fin de estEgal*/

char* TrajetCompose::getVilleDepart(void) const
{
  return tabTC->getTabTrajet()[0]->getVilleDepart();
} //----- Fin de getVilleDepart

char* TrajetCompose::getVilleArrive(void) const
{
  return tabTC->getTabTrajet()[tabTC->getNbTrajets()-1]->getVilleArrive();
} //----- Fin de getVilleDepart


char* TrajetCompose::getMoyenTransport(void) const
{
	char * moyenTransport = new char [20] ;
	strcpy(moyenTransport,"MT");
	return moyenTransport;
} //----- Fin de getMoyenTrasport


//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose (TabTrajet *tab) : tabTC (tab)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
	//Trajet::~Trajet();

	delete tabTC;
} //----- Fin de ~TrajetCompose
