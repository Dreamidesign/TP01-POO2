/*************************************************************************
                           Menu  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Menu> (fichier Menu.h) ----------------
#if ! defined ( Menu_H )
#define Menu_H

//--------------------------------------------------- Interfaces utilisées
#include "Catalogue.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Menu>
//
//
//------------------------------------------------------------------------

class Menu
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

    void menuTrajet();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void mainMenu();
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    Menu ( const Menu & unMenu );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Menu ( Catalogue * c);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Menu ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
  int choix1 = 0; //Choix du premier menu
  int choix2 = 3; //choix du sous menu d'ajout de trajets
  Structure liste;
};

//-------------------------------- Autres définitions dépendantes de <Menu>

#endif // Menu_H
