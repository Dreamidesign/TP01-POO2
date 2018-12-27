/*************************************************************************
                           GestionFichier - gestion de R&W dans un fichier
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//-- Interface du module <GestionFichier> (fichier GestionFichier.h) -----
#if ! defined ( GESTION_FICHIER_H )
#define GESTION_FICHIER_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "TabTrajet.h"
#include "Trajet.h"
#include "Catalogue.h"
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types
enum Critere_e
{
    SANS,
    TYPE,
    VILLE,
    SELECTION
}; // Type de Critere

enum ChoixAction
{
    QUITTER,
    CHANGER_NOM,
    SAUV,
    REST
}; // Choix de l'action a effectuer

// Definit un Critere, avec son type, et ses éventuels paramètres
// m et n (villes ou indices de trajets).
// m et n dependent du type :
// - si SANS, ils sont ignores
// - si TYPE, n[0] contient 'S' ou 'C'
// - si VILLE, n est la ville de de part et m la ville d'arrivee (les chaines sont valides).
// - si SELECTION, m et n sont des chaines valides contenant un entier positif ou nul.
struct Critere
{
    Critere_e type;
    char * n;
    char * m;
};


//------------------------------------------------------------------------
// Rôle du module <GestionFichier>
//  Module referencant toutes les fonctions liees a la manipulation 
//  de fichiers du catalogue.
//------------------------------------------------------------------------

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

    void GestionFichier_Main (Catalogue & c);
    // Mode d'emploi :
    //  Controle le bon deroulement de la gestion du fichier en appelant
    //  les bons menus et les bonnes methodes dans l'ordre.
    // Contrat : aucun.

    void Restitution(Critere &Critere);

    void Sauvegarde(Critere &Critere);

    void lecture_TS(TabTrajet* tab, string content);

    void lecture_TC(TabTrajet* tab, string content);

    bool TrajetValideAuCritere (Trajet * t, unsigned int i = -1);
    // Mode d'emploi :
    //  Indique si le trajet fourni est valide au critere.
    //  t : Pointeur de Trajet
    //  i : indice du trajet fourni dans le catalogue (facultatif)
    // Contrat :
    //  Les parametres fournis sont valides, en particulier le critere.

    ChoixAction MenuChoixAction ();
    // Mode d'emploi :
    //  Permet a l'utilisateur de choisir l'action a faire vers 
    //  ou depuis son catalogue.
    //  Renvoie l'action choisie.
    // Contrat : aucun.

    void MenuNomFichier ();
    // Mode d'emploi :
    //  Permet a l'utilisateur de choisir le fichier sur lequel il travaille
    //  via la saisie de son nom.
    // Contrat : aucun.

    void MenuChoixCritere ();
    // Mode d'emploi :
    //  Permet a l'utilisateur de choisir le critere sur lequel se basera 
    //  la manipulation des trajets.
    // Contrat : aucun.

    void MenuDefinitionCritere ();
    // Mode d'emploi :
    //  Permet a l'utilisateur de preciser ses voeux pour le critere 
    //  qu'il a choisi.


//--------------------------------------------------- Surcharge d operateurs --
//-------------------------------------------- Constructeurs - destructeur

//------------------------------------------------------------------ PROTEGE
//------------------------------------------------------- Methodes protegees --
//----------------------------------------------------- Attributs protégés
Catalogue * cat; // Le catalogue lu ou modifie au besoin.
Critere cri; // Le critere demande par l'utilisateur.
string nomFichier; // Le nom du fichier que l'on manipule.

#endif // ifndef GESTION_FICHIER_H
