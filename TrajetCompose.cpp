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
	cout << "Le trajet est compose de " << tabTC->getNbTrajets() << "trajets : " << endl;
	for (int i = 0; i < tabTC->getNbTrajets(); i++)
	{
		tabTC->getTabTrajet()[i]->Affichage(c);
	}
} //----- Fin de Affichage

char* TrajetCompose::getMoyenTransport(void) const
{
	return moyenTransport;
} //----- Fin de getMoyenTrasport


//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose (const char* uneVilleDepart,
															const char* uneVilleArrive,
															Structure *tab ) :
Trajet (uneVilleArrive,uneVilleDepart)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
tabTC = tab;
moyenTransport = new char [(tab->getNbTrajets()+1)*30];
strcpy(moyenTransport,"MT:");
for (int i = 0 ; i < tab->getNbTrajets(); i ++)
{
	moyenTransport= strcat(moyenTransport, tab->getTabTrajet()[i]->getMoyenTransport());
}
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
	delete[] moyenTransport;
} //----- Fin de ~TrajetCompose
