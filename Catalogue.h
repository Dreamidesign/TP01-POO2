/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------
#if ! defined ( Catalogue_H )
#define Catalogue_H

//--------------------------------------------------- Interfaces utilisées
#include "Structure.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//
//
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void ajoutSimple();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void ajoutCompose();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void rechercher();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void CatalogueTrajet();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void mainCatalogue();
    // Mode d'emploi :
    //
    // Contrat :
    //



//-------------------------------------------- Constructeurs - destructeur
    Catalogue ( const Catalogue & unCatalogue );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Catalogue ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Catalogue ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
void freeTab(char ** tab , int size);
// Mode d'emploi :
//
// Contrat :
//
//----------------------------------------------------- Attributs protégés
  int choix1 ; //Choix du premier Catalogue
  int choix2 ; //choix du sous Catalogue d'ajout de trajets
  Structure liste;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // Catalogue_H
