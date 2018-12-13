/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 23/11/18
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$ 
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( Trajet_H )
#define Trajet_H

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// Implémente un trajet entre uneVilleDepart et uneVilleArrive
//
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    virtual void Affichage ( const char * c = "") const = 0;
    // Mode d'emploi : char* c permet d'afficher un texte avec l'affichage
    //
    // Contrat :
    // il s'agit d'un méthode virtuelle pure (=0) on définit ainsi une classe abstraite
	  // son constructeur est déclaré en protected pour bien eviter la création d'instances
	  // de trajet ce qui n'a aucun sens

    virtual char * getVilleDepart (void) const = 0;
    // Mode d'emploi : Renvoi la ville de départ
    //
    // Contrat : Aucun
    //

    virtual char * getVilleArrive(void) const = 0;
    // Mode d'emploi : Renvoi la ville d'arrivee
    //
    // Contrat : Aucun
    //

    virtual char* getMoyenTransport(void) const = 0 ;
    // Mode d'emploi : retourne le moyen de transport employé
    //
    // Contrat : Aucun
    //

//-------------------------------------------- Constructeurs - destructeur

    virtual ~Trajet ( );
    // Mode d'emploi : libère toutes les allocations dynamiques effectuées
    //
    // Contrat : Aucun
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
	Trajet();
	// Mode d'emploi :
	//
	// Contrat : constructeur protégé - interdicteion de création d'instance
  //           car classe abstraite
  //
//----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // Trajet_H
