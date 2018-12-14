#define _CRT_SECURE_NO_WARNINGS
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
void TrajetCompose::Affichage (const char* c) const
{
	Trajet::Affichage("TC : ");
	cout << "Le trajet est compose de " << tabTC->getNbTrajets()
			 << " trajets : " << endl;
	for (int i = 0; i < tabTC->getNbTrajets(); i++)
	{
		tabTC->getTabTrajet()[i]->Affichage(c);
	}
} //----- Fin de Affichage

char * TrajetCompose::toString(void)
{
	char * description = new char[1000];
	description[0]='\0';
	for(int i=0; i<tabTC->getNbTrajets(); i++)
	{
		char * t_S =tabTC->getTabTrajet()[i]->toString();
		strcat(description, t_S);
		delete [] t_S;
	}
	return description;
}//-- Fin toString

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

Structure* TrajetCompose::getTab(void)
{
	return tabTC;
}//-- Fin getTab

//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose (Structure *tab) : tabTC (tab)
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
	delete tabTC;
} //----- Fin de ~TrajetCompose
