/*************************************************************************
                           Structure  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Structure> (fichier Structure.h) ----------
#if ! defined ( Structure_H )
#define Structure_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include <cstring>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Structure>
//
//
//------------------------------------------------------------------------

class Structure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    Trajet** getTabTrajet() const;
  	int getNbTrajets() const;
    void Affichage() const;
    // void ajouterTabTrajet(Structure* s);
    void ajouterTrajet(Trajet *t);

//-------------------------------------------- Constructeurs - destructeur
    Structure ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Structure ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
Trajet** trajet ;  //Liste de trajets
int nbTrajets;    //Nombre de trajets dans le catalogue
int nbAllocated; //Espace alloué
};

//-------------------------------- Autres définitions dépendantes de <Structure>

#endif // Structure_H
