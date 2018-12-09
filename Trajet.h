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
//
//
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    virtual void Affichage ( const char * c = "") const = 0;
    // Mode d'emploi :
    //
    // Contrat :
    // il s'agit d'un méthode virtuelle pure ( =0) on définit ainsi une classe abstraite
	// son constructeur est déclaré en protected pour bien eviter la création d'instances
	//de trajet ce qui n'a aucun sens

    char * getVilleDepart () const;
    char * getVilleArrive() const ;
    virtual char* getMoyenTransport() const =0 ; //renvoie le moyen de transport
    virtual bool doublon (const Trajet * t) const ;


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
