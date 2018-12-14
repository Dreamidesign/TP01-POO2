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
#include "TrajetCompose.h"
//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//Implemente le catalogue de trajets : mon mode d'affichage - les méthodes d'ajout
// - la  recherche de trajets ainsi que l'interface utilisateur
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void ajoutSimple(void);
    // Mode d'emploi : ajoute un trajet simple au catalogue à partir des infos
    //                 saisies par l'utilisateur dans le flux de sortie cin
    //                 avec vérificatin  des contraintes d'ajout (doublons)

    void ajoutCompose(void);
    // Mode d'emploi : ajoute un trajet simple au catalogue à partir des infos
    //                 saisies par l'utilisateur dans le flux de sortie cin
    // Contrat : l'utilisateur saisit les villes composant le trajet, vérification
    //           de la validité du trajet à la saisie

    void rechercher(void);
    // Mode d'emploi : recherche un trajet dans le catalogue à partir d'une ville
    //                 de départ et ville d'arrivé saisies par l'utilisateur,
    //                 utilisation du polymorphisme

    void rechercheAvancee(void);

    void rechercheEnProfondeur(char* recherche, TrajetCompose* branche, Structure* res);

    void menuTrajet(void);
    // Mode d'emploi : implémente l'interface d'ajout des trajets
    //


    void mainCatalogue(void);
    // Mode d'emploi : implémente l'interface principale du catalogue
    //

//-------------------------------------------- Constructeurs - destructeur
    Catalogue (void);
    // Mode d'emploi : constructeur vide
    //

    virtual ~Catalogue ( );
    // Mode d'emploi : destructeur vide- rien est alloué dynamiquement
    //


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
void freeTab(char ** tab , int size);
// Mode d'emploi : permet de libérer les tableaux de chaines de caractères utilisés
//                 pour stocker les variables récupérées du flux cin

//----------------------------------------------------- Attributs protégés
  int choix1 ; //Choix du premier Catalogue
  int choix2 ; //choix du sous Catalogue d'ajout de trajets
  Structure liste;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // Catalogue_H
