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

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

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

    char * getVilleDepart (void) const;
    // Mode d'emploi : Renvoi la ville de départ
    //
    // Contrat :
    //

    char * getVilleArrive(void) const ;
    // Mode d'emploi : Renvoi la ville d'arrivee
    //
    // Contrat :
    //

    virtual char* getMoyenTransport(void) const =0 ;
    // Mode d'emploi : Renvoi le moyen de transport employé
    //
    // Contrat :
    //

    virtual bool doublon (const Trajet * t) const ;
    // Mode d'emploi : Verifie si le trajet *t est egal a this
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur

    virtual ~Trajet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
	Trajet( const char*uneVilleDepart, const char*uneVilleArrive);
	// Mode d'emploi :
	//
	// Contrat :
	//
//----------------------------------------------------- Attributs protégés
	char * villeDepart;
	char * villeArrive;
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // Trajet_H
