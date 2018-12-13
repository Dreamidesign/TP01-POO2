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
#include "TabTrajet.h"
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
    //Contrat : Redéfinition de la méthode virtuelle pure de la classe mère Trajet
    //

  //   bool estEgal (const Trajet * t) const ;
     // Mode d'emploi : Compare t et this
     //                 Redéfinition de estEgal de Trajet
     // Contrat : Aucun
     //

     char * getVilleArrive(void) const ;
     // Mode d'emploi : Renvoi la ville d'arrivee
     //
     // Contrat : Aucun
     //

     char * getVilleDepart (void) const ;
     // Mode d'emploi : Renvoi la ville de départ
     //
     // Contrat : Aucun
     //
     char* getMoyenTransport(void) const ;
     // Mode d'emploi : retourne le moyen de transport employé
     //
     // Contrat : Aucun
     //

//-------------------------------------------- Constructeurs - destructeur

    TrajetCompose (TabTrajet *s);
    // Mode d'emploi : définition des attributs des instances de trajet composé
    //                 à partir des paramètres formels du constructeur
    // Contrat : Aucun
    //

    virtual ~TrajetCompose ( );
    // Mode d'emploi : libère les allocations dynamiques réalisées
    //
    // Contrat : Aucun
    //

protected:

//----------------------------------------------------- Attributs protégés
  TabTrajet * tabTC;
};

//--------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TrajetCompose_H
