
//---------- Interface de la classe <Catalogue> (fichier Catalogue) ------
#if ! defined ( CATALOGUE )
#define CATALOGUE

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
#include <cstring>

//------------------------------------------------------------------------ 
// Rôle de la classe <Catalogue>
//
//
//------------------------------------------------------------------------ 

class Catalogue
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	void AjoutTrajet(Trajet* t);
	Catalogue RechercheSimple(char* a, char* b) const;
	//Catalogue RechercheComposee(char* a, char* b) const;
	void Affichage() const;

//-------------------------------------------- Constructeurs - destructeur
	Catalogue (const Catalogue &unCatalogue);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Catalogue ();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Catalogue ();
	// Mode d'emploi :
	//
	// Contrat :
	//


//------------------------------------------------------------------ PRIVE 

protected:
	//----------------------------------------------------- Méthodes protégées

private:
	//------------------------------------------------------- Méthodes privées

protected:
	//----------------------------------------------------- Attributs protégés
	Trajet ** trajet; //Liste de trajets
	int nbTrajets = 0; //Nombre de trajets dans le catalogue

private:
	//------------------------------------------------------- Attributs privés

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes privées

	//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Catalogue>

#endif // CATALOGUE
