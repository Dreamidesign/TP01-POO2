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
    
    virtual void Affichage ( const char * c = "") const; 
    // Mode d'emploi :
    //
    // Contrat :
    //

    char * getVilleDepart () const;
    char * getVilleArrive() const ; 



//-------------------------------------------- Constructeurs - destructeur
    Trajet ( const Trajet & unTrajet );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //



    virtual ~Trajet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
	Trajet(char* a, char* b);
	// Mode d'emploi :
	//
	// Contrat :
	//
//----------------------------------------------------- Attributs protégés
	char * villeDepart ; 
	char * villeArrive; 
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // Trajet_H

