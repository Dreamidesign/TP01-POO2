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
#include "TabTrajet.h"
#include "TrajetCompose.h"

#define TAILLE_NOM 100
//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//Implemente le catalogue de trajets : mon mode d'affichage - les méthodes d'Ajout
// - la  Recherche de trajets ainsi que l'interface utilisateur
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void AjoutSimple(void);
    // Mode d'emploi : Ajoute un trajet simple au catalogue à partir des infos
    //                 saisies par l'utilisateur dans le flux de sortie cin
    //                 avec vérificatin  des contraintes d'Ajout (doublons)

    void AjoutCompose(void);
    // Mode d'emploi : Ajoute un trajet simple au catalogue à partir des infos
    //                 saisies par l'utilisateur dans le flux de sortie cin
    // Contrat : l'utilisateur saisit les villes composant le trajet, vérification
    //           de la validité du trajet à la saisie

    void Rechercher(void);
    // Mode d'emploi : Recherche un trajet dans le catalogue à partir d'une ville
    //                 de départ et ville d'arrivé saisies par l'utilisateur,
    //                 utilisation du polymorphisme

    void RechercheAvancee(void);

    void RechercheEnProfondeur(char* Recherche, TrajetCompose* branche, TabTrajet* res);

    void MenuTrajet(void);
    // Mode d'emploi : implémente l'interface d'Ajout des trajets
    //


    void MenuCatalogue(void);
    // Mode d'emploi : implémente l'interface principale du catalogue
    //
  
    static void SaisirNom (char * dest);
    // Mode d'emploi : recupere la saisie de l'utilisateur et l'enregistre dans dest.
    // Contrat : la zone pointee par dest est de taille TAILLE_NOM.

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
	// Mode d'emploi : permet de libérer un tableau de chaines de caractères.

//----------------------------------------------------- Attributs protégés
	int choix1 ; //Choix du premier Catalogue
	int choix2 ; //choix du sous Catalogue d'Ajout de trajets
	TabTrajet liste;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // Catalogue_H
