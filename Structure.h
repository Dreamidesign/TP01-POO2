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
//  Implémente un tableau dynamique de pointeur de trajet pour en stocker une liste
//  ordonnée par ordre d'ajout.
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

    Trajet** getTabTrajet(void) const;
    // Mode d'emploi : Renvoie le tableau de pointeur de trajets contenus dans la structure
    //
    // Contrat :
    //

  	int getNbTrajets(void) const;
    // Mode d'emploi : Renvoie le nombre de trajets pointés par la structure
    //
    // Contrat :
    //

    void Affichage(void) const;
    // Mode d'emploi : Parcours le tableau de pointeur de trajet et appelle
    //                 leur méthode affichage
    // Contrat :
    //

    void ajouterTrajet(Trajet *t);
    // Mode d'emploi : Ajoute *t au tableau de pointeur de trajets de la structure
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Structure (void);
    // Mode d'emploi : Création d'une structure.
    //
    // Contrat :
    //

    virtual ~Structure ( );
    // Mode d'emploi : Libéraation mémoire de la structure et de ses attributs
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
