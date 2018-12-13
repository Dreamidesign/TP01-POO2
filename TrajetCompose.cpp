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
	cout << "Le trajet est compose de " << tabTC->GetNbTrajets()
			 << "trajets : " << endl;
	for (int i = 0; i < tabTC->GetNbTrajets(); i++)
	{
		tabTC->GetTabTrajet()[i]->Affichage(c);
	}
	cout << "\n";
} //----- Fin de Affichage

/*bool EstEgal (const Trajet * t) const
{
	for (int i = 0 ; i < tabTC->GetNbTrajets(); i++)
	{
		if (!(t->GetTabTrajet()[i]->EstEgal(tabTC[i])))
		{
			return false;
		}
	}
	return true ;
} //----- Fin de EstEgal*/

char* TrajetCompose::GetVilleDepart(void) const
{
  return tabTC->GetTabTrajet()[0]->GetVilleDepart();
} //----- Fin de GetVilleDepart

char* TrajetCompose::GetVilleArrive(void) const
{
  return tabTC->GetTabTrajet()[tabTC->GetNbTrajets()-1]->GetVilleArrive();
} //----- Fin de GetVilleDepart


char* TrajetCompose::GetMoyenTransport(void) const
{
	char * moyenTransport = new char [20] ;
	strcpy(moyenTransport,"MT");
	return moyenTransport;
} //----- Fin de GetMoyenTrasport


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
