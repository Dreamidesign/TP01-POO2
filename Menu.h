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
#include "Structure.h"
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

    Menu ();
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
void freeTab(char ** tab , int size);
// Mode d'emploi :
//
// Contrat :
//
//----------------------------------------------------- Attributs protégés
  int choix1 ; //Choix du premier menu
  int choix2 ; //choix du sous menu d'ajout de trajets
  Structure liste;
};

//-------------------------------- Autres définitions dépendantes de <Menu>

#endif // Menu_H