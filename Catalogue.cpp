/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <cstring>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TabTrajet.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//----------------------------------------------------- Méthodes publiques

void Catalogue::rechercheEnProfondeur(char* recherche, TrajetCompose* branche, Structure* res)
{
	for(int i = 0; i < liste.getNbTrajets(); i++)
	{
		bool used = false;
		for(int j = 0; j < branche->getTab()->getNbTrajets(); j++)
		{
			char * desBranche = branche->getTab()->getTabTrajet()[j]->toString();
			char * desCurr = liste.getTabTrajet()[i]->toString();

			if(strcmp(desCurr, desBranche) == 0)
			{
				used = true;
				delete [] desBranche;
				delete [] desCurr;
				break;
			}
			delete [] desBranche;
			delete [] desCurr;
		}
    if(!used && (strcmp(liste.getTabTrajet()[i]->getVilleDepart(), branche->getVilleArrive()) == 0))
    {
			Structure * temp_S = new Structure();
			for(int k = 0; k < branche->getTab()->getNbTrajets(); k++)
			{
				temp_S->ajouterTrajet(branche->getTab()->getTabTrajet()[k]);
			}
			temp_S->ajouterTrajet(liste.getTabTrajet()[i]);
			TrajetCompose* temp = new TrajetCompose(temp_S); //Creer une nouvelle branche a partir de l'ancienne
			res->ajouterTrajet(temp);


			#ifdef MAP
			cout << "analyse POUSSEE trajet suivant:" << endl;
			liste.getTabTrajet()[i]->Affichage();
			cout << endl;
			cout << "Construction branche :" << endl;
			temp->Affichage();
			#endif


      if(strcmp(liste.getTabTrajet()[i]->getVilleArrive(), recherche) == 0)
      {
				cout << "- Trajet :" << endl;
        temp->Affichage();
      }
			else{
				rechercheEnProfondeur(recherche, temp, res);
			}
    }
	}

}


void Catalogue::rechercheAvancee(){
	char depart [100];
	char arrivee [100];

	cout << "Bonjour, quelle est votre destination de depart ? " << endl;
	cin >> depart;
	cout << "Et votre ville d'arrivee" << endl;
	cin >> arrivee;

	cout << "\n" << "\n" << "Resultats de la requete : " << endl;

	Structure* resultats = new Structure();

	for(int i = 0; i < liste.getNbTrajets(); i++)
	{
		#ifdef MAP
				cout << "Debut recherche avancee" << endl;
				cout << "Nombre de trajets TOTAL : " << liste.getNbTrajets() << '\n';
		#endif

    if(strcmp(liste.getTabTrajet()[i]->getVilleDepart(), depart) == 0)
    {
		#ifdef MAP
			cout << "analyse trajet suivant :" << endl;
			liste.getTabTrajet()[i]->Affichage();
			cout << endl;
		#endif

		Structure *tabT (new Structure());
		tabT->ajouterTrajet(liste.getTabTrajet()[i]);
		TrajetCompose* temp = new TrajetCompose(tabT); //On va remplir le trajetComposé au fur et à mesure du parcours
		resultats->ajouterTrajet(temp);

      if(strcmp(liste.getTabTrajet()[i]->getVilleArrive(), arrivee) == 0)
      {
				cout << "- Trajet :" << endl;
        liste.getTabTrajet()[i]->Affichage("");
      }
			else{
				rechercheEnProfondeur(arrivee, temp, resultats);
			}
    }
	}
	// resultats->destructionRecherche();
	// resultats = nullptr;
	// delete resultats;


}



void Catalogue::ajoutSimple(void)
{
	char depart [100];
	char arrivee [100];
	char mt [100];

	cout << "Quel est le depart du trajet" << endl;
	cin >> depart;
	cout << "Quelle est l'arrivee du trajet" << endl;
	cin >> arrivee;
	cout << "Quel est le moyen de transport employe ?" << endl;
	cin >> mt;

	TrajetSimple* t (new TrajetSimple(depart, arrivee, mt));

	bool used = false;
	for(int j = 0; j < liste.getNbTrajets(); j++)
	{
		char * t_S =t->toString();
		char * l_S = liste.getTabTrajet()[j]->toString();

		if(strcmp(t_S, l_S) == 0)
		{
			used = true;
			cout << "\n" << "Trajet existant" << "\n" << endl;
			delete [] t_S;
			delete [] l_S;
			break;
		}
		delete [] t_S;
		delete [] l_S;
	}

	if(used == false)
	{
		liste.AjouterTrajet(t);
		cout << "\n" << "Trajet Ajoute !" << endl;
	}
	else
	{
		delete t;
	}

} //----- Fin de AjoutSimple

void Catalogue::AjoutCompose(void)
{
	int nbVilles = 0;
	cout <<"Combien d'etapes comporte votre trajet (nombre de villes total)" << endl;
	cin >> nbVilles;

	while(nbVilles <= 2) //On ne prend en compte que les trajets composés
	{
		cout << "Erreur : Le nombre d'etapes minimum est 3" << endl;
		cout << "Combien d'étapes comporte votre trajet ? (nombre de villes total)" << endl;
		cin >> nbVilles;
	}

	char** tabVille (new char *[nbVilles]);
	char** tabMT (new char *[nbVilles]);
	TabTrajet *tabTS (new TabTrajet());
	for (int i = 0; i < nbVilles; i++)
	{
		cout << "Rentrer la " << (i+1) << "eme ville : " << endl;
		tabVille[i] = new char[20];
		cin >> tabVille[i];

		if(i != nbVilles - 1) tabMT[i]=new char[20];
		//On a moins de moyens de transport que de villes
		if (i != 0)
		{
			cout << "Quel est le moyen de transport entre " << tabVille[i - 1] <<
			 " et " << tabVille[i] << " ?" << endl;
			cin >> tabMT[i-1];
			//Le moyen de transport est stocke e l'adresse de la ville d'arrivee,
			// aucun moyen de transport en 0

			Trajet* t = new TrajetSimple(tabVille[i - 1], tabVille[i], tabMT[i-1]);
			tabTS->AjouterTrajet(t);
		}
	}

	TrajetCompose* tc(new TrajetCompose(tabTS));

	bool used = false;
	for(int j = 0; j < liste.getNbTrajets(); j++)
	{
		char * t_S =tc->toString();
		char * l_S = liste.getTabTrajet()[j]->toString();

		if(strcmp(t_S, l_S) == 0)
		{
			used = true;
			cout << "\n" << "Trajet existant" << "\n" << endl;
			delete [] t_S;
			delete [] l_S;
			break;
		}
		delete [] t_S;
		delete [] l_S;
	}
	if(!used)
	{
		liste.ajouterTrajet(tc);
		cout << "\n" << "Trajet ajoute !" << endl;
	}
	else{
		delete tc;
	}

	freeTab (tabMT , nbVilles-1);
	freeTab ( tabVille , nbVilles) ;
} //----- Fin de AjoutCompose

void Catalogue::Rechercher(void)
{
	char depart [100];
	char arrivee[100];
	int count = 0 ;
	cout << "Bonjour, quelle est votre destination de depart ? " << endl;
	cin >> depart;
	cout << "Et votre ville d'arrivee" << endl;
	cin >> arrivee;

	cout << "\n" << "\n" << "Resultats de la requete : " << endl;

	for (int i=0; i<liste.GetNbTrajets(); i++)
	{
		if (!strcmp(liste.GetTabTrajet()[i]->GetVilleDepart(), depart) &&
		 	  !strcmp(liste.GetTabTrajet()[i]->GetVilleArrive(), arrivee))
		{
			cout << "Trajet : ", liste.GetTabTrajet()[i]->Affichage();
			count++;
		}
	}
	if ( count ==0)
	{
		cout << "Désolé, ce trajet n'est pas disponible!" << endl ;
	}

} //----- Fin de Rechercher

void Catalogue::MenuTrajet(void) {
	do
	{
		cout << "Quel est le type de trajet ?" << endl;
		cout << "1. Simple" << endl;
		cout << "2. Compose" << endl;
		cout << "3. Retour au Catalogue" << endl;
		cin >> choix2;

		switch (choix2)
		{
		case 1:
			cout << "Ajout d'un trajet simple" << endl;
			AjoutSimple();
			break;
		case 2:
			cout << "Ajout d'un trajet compose" << endl;
			AjoutCompose();
			break;
		case 3:
			break;
		default:
		cout << "Choix invalide. Attendu : 1-2-3" << endl;
			break;
		}
	} while (choix2 != 3);

} //----- Fin de MenuTrajet

void Catalogue::MenuCatalogue(void)
{
	do
	{
		choix2 = 0;

		cout <<"\n"<<"\n"<< "------Bienvenue sur FlexiTrip------" <<"\n"<< endl;
  	cout << "         Catalogue         " << endl;
  	cout << "1. Ajouter un trajet" << endl;
  	cout << "2. Afficher le catalogue de trajets proposes" << endl;
  	cout << "3. Rechercher un parcours" << endl;
  	cout << "4. Rechercher un parcours - recherche avancee" << endl;
  	cout << "5. Quitter" << endl;
  	cin >> choix1;

		switch (choix1)
		{
		case 1:
			cout << "*Ajout d'un trajet*" << endl;
			MenuTrajet();
			break;
		case 2:
			cout << "*------Catalogue-------*" << endl;
			liste.Affichage();
			break;
		case 3:
			cout << "*Recherche...*" << endl;
			Rechercher();
			break;
		case 4:
			cout << "4. Rechercher un parcours - recherche avancee" << endl;
			rechercheAvancee();
			break;
		case 5:
			break;
		default:
		 cout << "Choix invalide. Attendu : 1-2-3-4" << endl;
			break;
		}

	} while (choix1 != 5);
}//----- Fin de mainCatalogue

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue (void)
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
	 choix1 = 0;
	 choix2 = 3;
} //----- Fin de Catalogue


Catalogue::~Catalogue ()
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif

} //----- Fin de ~Catalogue

void Catalogue::freeTab ( char ** tab , int size )
{
	for ( int i = 0 ; i<size ; i++ )
	{
		delete[] tab[i] ;
	}
	delete [] tab ;
}//----- Fin de freeTab
