/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 23/11/18
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//------ Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ------
#if ! defined ( TrajetCompose_H )
#define TrajetCompose_H
//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "Structure.h"
//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
// Implémente un trajet compose de n trajets (éventuellement simple ou composé)
// reliant une ville de départ et une ville d'arrivé.
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void Affichage (const char* c)const ;
    // Mode d'emploi : Affiche les caractéristiques du trajet avec la possibilité
    //                 d'ajouter des specifications grace au char * c
    //
    //Contrat : Redéfinition de la méthode virtuelle pure de la classe mère Trajet


     char* getMoyenTransport(void) const ;
     // Mode d'emploi : getter de l'attribut protected moyenTransport
     //                 sert uniquement à éviter l'existence de doublon  
     //

//-------------------------------------------- Constructeurs - destructeur

    TrajetCompose ( const char* uneVilleDepart,
                    const char* uneVilleArrive,
                    Structure *s);
    // Mode d'emploi : définition des attributs des instances de trajet composé
    //                 à partir des paramètres formels du constructeur
    //                 L'attribut moyenTransport est construit à partir de la
    //                 concaténation des différents moyens de transport utilisés
    //                 dans les trajets composants le trajet composé
    //

    virtual ~TrajetCompose ( );
    // Mode d'emploi : libère les allocations dynamiques réalisées
    //
    //

protected:

//----------------------------------------------------- Attributs protégés
  Structure * tabTC;
  char* moyenTransport;
};

//--------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TrajetCompose_H
