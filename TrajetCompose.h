/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 23/11/18
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//------ Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ------
#if ! defined ( TrajetCompose_H )
#define TrajetCompose_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "Structure.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
//
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void Affichage (const char* c)const ;
    // Mode d'emploi :
    //
    // Contrat :
    //

	   const char* getType();
     // Mode d'emploi :
     //
     // Contrat :
     //

//-------------------------------------------- Constructeurs - destructeur

    TrajetCompose ( const char* uneVilleDepart,
                    const char* uneVilleArrive,
                    Structure *s);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~TrajetCompose ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
  Structure * tabTC;
};

//--------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TrajetCompose_H
