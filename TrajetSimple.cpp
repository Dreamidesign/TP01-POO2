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

TrajetSimple::TrajetSimple ( char* a , char* b , char* mT) : Trajet (a,b) , moyenTransport  (mT) 
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
