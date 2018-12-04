
//---------- Interface de la classe <Catalogue> (fichier Catalogue) ------
#if ! defined ( CATALOGUE )
#define CATALOGUE

//--------------------------------------------------- Interfaces utilis�es
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
#include <cstring>

//------------------------------------------------------------------------
// R�le de la classe <Catalogue>
//
//
//------------------------------------------------------------------------

class Catalogue
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
	void AjoutTrajet(Trajet* t);
	void RechercheSimple(char* a, char* b) const;
	//Catalogue RechercheComposee(char* a, char* b) const;
	void Affichage() const;
	Trajet** getTabTrajet() const;
	int getNbTrajets() const;

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
	//----------------------------------------------------- M�thodes prot�g�es

private:
	//------------------------------------------------------- M�thodes priv�es

protected:
	//----------------------------------------------------- Attributs prot�g�s
	Trajet ** trajet; //Liste de trajets
	int nbTrajets = 0; //Nombre de trajets dans le catalogue
	int nbAllocated = 100; //Espace alloué

private:
	//------------------------------------------------------- Attributs priv�s

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Catalogue>

#endif // CATALOGUE
