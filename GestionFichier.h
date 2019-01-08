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
// - si VILLE, n est la ville de de part et m la ville d'arrivee.
//   Si elles valent '_' alors on ne s'intéresse pas.
// - si SELECTION, m et n sont des strings contenant un entier positif ou nul.
struct Critere
{
    Critere_e type;
    string n;
    string m;
};

// Indique les autorisations liees au fichier selectionne.
struct Autorisations
{
    bool lecture;
    bool ecriture;
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

    void Restitution();

    void Sauvegarde();

    void lecture_TS(TabTrajet* tab, string content);

    void lecture_TC(TabTrajet* tab, string content);

    bool TrajetValideAuCritere (const Trajet * t, long int index);
    // Mode d'emploi :
    //  Indique si le trajet fourni est valide au critere.
    //  t : Pointeur de Trajet
    //  index : indice du trajet fourni dans le catalogue
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

    Critere_e MenuChoixCritere ();
    // Mode d'emploi :
    //  Permet a l'utilisateur de choisir le critere sur lequel se basera 
    //  la manipulation des trajets.
    // Contrat : aucun.

    bool MenuDefinitionCritere (Critere_e cr_e);
    // Mode d'emploi :
    //  Permet a l'utilisateur de preciser ses voeux pour le critere 
    //  qu'il a choisi.
    //  Constante nommee associee au type choisi.
    // Contrat : aucun.

    unsigned int GetNombreLignesFichier ();
    // Mode d'emploi :
    //  Renvoie le nombre de lignes du fichier.
    //  On le parcourt rapidement.
    // Contrat : aucun (si URL fichier invalide, zero);

    void DefinirAutorisations ();
    // Mode d'emploi :
    //  Procedure sans parametres qui enregistre les autorisations liees 
    //  au fichier selectionne.
    // Contrat : le fichier existe.

    void EasterEgg();
    // Mode d'emploi : mystere...
    // Contrat : droits en ecriture dans le dossier courant.


//--------------------------------------------------- Surcharge d operateurs --
//-------------------------------------------- Constructeurs - destructeur

//------------------------------------------------------------------ PROTEGE
//------------------------------------------------------- Methodes protegees --
//----------------------------------------------------- Attributs protégés
Catalogue * cat; // Le catalogue lu ou modifie au besoin.
Critere cri; // Le critere demande par l'utilisateur.
string nomFichier("catalogueExport.txt"); // Le nom du fichier qu'on manipule.
bool onSauvegarde; // Vaut true si l'utilisateur vaut sauvegarder, sinon false.
Autorisations autorisations; // Liees au fichier selectionne.

#endif // ifndef GESTION_FICHIER_H
