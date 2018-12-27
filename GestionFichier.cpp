/*************************************************************************
                         GestionFichier  -  gestion de R&W dans un fichier
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//--Réalisation du module <GestionFichier> (fichier GestionFichier.cpp) --


//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
#include <cstring>
//------------------------------------------------------ Include personnel
#include "GestionFichier.h"
#include "TrajetSimple.h"

//------------------------------------------------------------- CONSTANTES

//----------------------------------------------------------------- PUBLIC
//------------------------------------------------- Fonctions publiques --

void GestionFichier_Main (Catalogue & c) 
{
	cat = &c;
	ChoixAction action = CHANGER_NOM; // Valeur par defaut.
	do
	{
		action = MenuChoixAction();	
		if (action == CHANGER_NOM)
		{
			MenuNomFichier();
		}
	} while (action == CHANGER_NOM);

	if (action == QUITTER)
	{
		return;
	}

	onSauvegarde = (action == SAUV) ? true : false;
} // -- Fin de GestionFichier

void Sauvegarde()
{
	//Déclaration d'un flux permettant d'écrire dans un fichier.
	ofstream monFlux(nomFichier.c_str());

	if(monFlux)  //On teste si tout est OK
	{

		//--- Construction des métadonnées

		//On compte le nombre de trajet de chaque sorte
		int nbTS=0;
		int nbTC=0;
		TabTrajet & liste = cat->GetTabTrajet();
		for(int i = 0; i<liste.GetNbTrajets(); i++)
		{
			liste.GetTabTrajet()[i]->toString()[0] == 'S' ? nbTS++: nbTC++;
		}

		monFlux << nbTS << ";" << nbTC << endl;

		for(int i=0; i < liste.GetNbTrajets(); i++)
		{
			if(TrajetValideAuCritere(liste.GetTabTrajet()[i], i))
			{
				monFlux << liste.GetTabTrajet()[i]->toString() << endl;
			}
		}
	}
	else
	{
	    cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
	}
}

void Restitution()
{
	//Déclaration d'un flux permettant d'écrire dans un fichier.
	ifstream monFlux(nomFichier.c_str());

	if(monFlux)  //On teste si tout est OK
	{
		int ligneNum = 0;
		string trajetLigne;
		while(getline(monFlux, trajetLigne))
		{

			/* Etapes de la lecture d'un TC :
			 * 1. On enleves les parenthèses --> que le contenu
			 * 2. Lecture entre les virgules
			 * 3. Lecture de soit un TS, soit on recommence pour un TC
			 * 4. A chaque étape on ajoute le contenu a un tabTrajet
			 */
			Trajet* t;

			//Ajout d'un trajet simple
			if(trajetLigne[0] == 'S')
			{
			trajetLigne.erase(0, 2);
			string delimiter = ";";
			size_t pos = 0;
			string temp;
			string villeD;
			string villeA;
			string mT;
			unsigned int count = 0;
			while ((pos = trajetLigne.find(delimiter)) != string::npos)
			{
				temp = trajetLigne.substr(0, pos);
				trajetLigne.erase(0, pos + delimiter.length());
				if(count == 0) {villeD = temp;}
				if(count == 1)
				{
					villeA = temp;
					mT = trajetLigne;
				}
				count ++;
			}
				t = new TrajetSimple(villeD.c_str(), villeA.c_str(), mT.c_str());
			}

			else
			{
				trajetLigne.erase(0, 2);
				trajetLigne.erase(trajetLigne.length()-1, trajetLigne.length());

				TabTrajet* tabT = new TabTrajet();
				string delimiter = ",";
			  size_t pos = 0; //position du delimiter
				string temp;
			  while((pos = trajetLigne.find(delimiter)) != string::npos)
			  {
			    temp = trajetLigne.substr(0, pos);
			    trajetLigne.erase(0, pos + delimiter.length());

			    temp[0] == 'S' ? lecture_TS(tabT, temp) : lecture_TC(tabT, temp);
			  }
				trajetLigne[0] == 'S' ? lecture_TS(tabT, trajetLigne) : lecture_TC(tabT, trajetLigne);

				t = new TrajetCompose(tabT);
			}

			if(TrajetValideAuCritere(t, ligneNum))
			{
				cat->GetTabTrajet().AjouterTrajet(t);
			}
			ligneNum++;
		}
	}
	else
	{
	    cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
	}
}

void lecture_TS(TabTrajet* tab, string content)
{
	content.erase(0, 2);
	string delimiter = ";";
	size_t pos = 0; //position du delimiter
	string temp;
	string villeD;
	string villeA;
	string mT;
	int count = 0; // Nombre d'elements recuperes

	while ((pos = content.find(delimiter)) != string::npos)
	{
			temp = content.substr(0, pos);
			content.erase(0, pos + delimiter.length());
			if(count == 0)
			{
				villeD = temp;
			}
			if(count == 1)
			{
				villeA = temp;
				mT = content;
			}
			count ++;
	}

	tab->AjouterTrajet
	(
		new TrajetSimple(villeD.c_str(), villeA.c_str(), mT.c_str())
	);
}

void lecture_TC(TabTrajet* tab, string content)
{
	//On recupère uniquement le contenu du TC
	content.erase(0, 2);
	content.erase(content.length()-1, content.length());
	string temp;
	string delimiter = ",";

	size_t pos = 0; //position du delimiter
	while((pos = content.find(delimiter)) != string::npos)
	{
		temp = content.substr(0, pos);
		content.erase(0, pos + delimiter.length());

		temp[0] == 'S' ? lecture_TS(tab, temp) : lecture_TC(tab, temp);
	}
	
	// Partie restante
	content[0] == 'S' ? lecture_TS(tab, content) : lecture_TC(tab, content);
}

bool TrajetValideAuCritere (Trajet * t, unsigned int i)
{
	char * trajet;

    if (t == nullptr)
    {   return false;
    }
    
    trajet = t->toString();

    switch (cri.type)
    {
        case SANS:
            return true;

		case TYPE:
            // Si les types du Critere et du trajet sont identiques.
            return ( cri.n[0] == trajet[0] ) ? true : false;

		case VILLE:
            // Si cri.n n'est pas vide, on compare cri.n a la ville de depart :
            if
            ( 
            	( strcmp (cri.n, "") ) && 
            	( strcmp (cri.n, t->GetVilleDepart()) )
            )
            {   return false;
            }
            // Idem ville d'arrivee
            if 
            (
            	( strcmp (cri.m, "") ) && 
            	( strcmp (cri.m, t->GetVilleArrive()) ) 
            )
            {   return false;
            }
            return true;

		case SELECTION:
            // Si i est entre c.n inclus et c.m inclus.
            return 
            (
            	((long int)(i) >= atoi (cri.n)) && 
            	((long int)(i) <= atoi (cri.m))
            ) ? true : false;

		default:
			// N'est pas sense se produire.
            cerr << "Type de Critere invalide !" << endl;
            return false;
    }
}

ChoixAction MenuChoixAction ()
{
	unsigned int choix;
	do 
	{
		cout << "Que souhaitez-vous faire ?" << endl;
		cout << "Le fichier selectionne est \"catalogueExport.txt\"" << endl;
		cout << "1. Exporter le catalogue courant." << endl;
		cout << "2. Importer / restituer le catalogue courant." << endl;
		cout << "3. Modifier le nom du fichier." << endl;
		cout << "4. Retourner au menu principal." << endl;

		choix = -1;
		cin >> choix;
		switch (choix)
		{
			case 1:
				return SAUV; 
			case 2:
				return REST;
			case 3:
				return CHANGER_NOM;
			case 4:
				return QUITTER;
			default:
				cout << "Choix invalide." << endl;
				while ( ! cin )
				{
					cin.clear();
					cin.ignore(250, '\n');
				}
		}
	} while (true);
}

void MenuNomFichier ()
{
	int fini;
	string tmp;
	do 
	{
		cout << "Quel nom de fichier manipuler ?" << endl;
		cin >> tmp;
		cout << "Test des autorisations de " << tmp << '.' << endl;

		// Test possible de lire
		ifstream ifs (tmp);
		if (ifs.eof())
		{
			cout << "Fichier vide, lecture impossible." << endl;
		} 
		else 
		{
			cout << "Lecture : " << (ifs ? "OUI" : "NON") << endl;
		}

		// Test possible d'ecrire
		ofstream ofs (tmp);
		cout << "Ecriture : " << (ofs ? "OUI" : "NON") << endl;

		// Confirmation et boucle ou validation
		cout << endl << "Cela vous convient ? 1 pour oui, 0 pour non" << endl;
		cin >> fini;
		while ( ! cin )
		{
			cin.clear();
			cin.ignore(250, '\n');
			fini = 0;
		}
	} while ( ! fini);
	nomFichier = tmp;
}

void MenuChoixCritere ()
{
	cout << 
		"Choix du critere pour la " << 
		(onSauvegarde ? "sauvegarde" : "restitution") <<
		"du catalogue avec le fichier \"" << nomFichier << "\"." << endl;

	unsigned int choix = -1;
	Critere_e cr_e = SANS;
	while 
	(
		(choix != 1) && 
		(choix != 2) && 
		(choix != 3) && 
		(choix != 4)
	)
	{
		cout << "Quel critere de selection appliquer ?" << endl;
		cout << "1. Aucun critere, prendre tous les trajets." << endl;
		cout << "2. Seulement les trajets simples OU composes." << endl;
		cout << "3. Seulement les trajets arrivant ou partant d’une "
			<< "certaine ville." << endl;
		cout << "4. Seulement les trajets d’un certain intervalle "
			<< "(depuis l’ordre de saisie dans le catalogue)." << endl;
		

		cin >> choix;
		switch (choix)
		{
			case 1:
				cr_e = SANS;
				break;
			case 2:
				cr_e = TYPE;
				break;
			case 3:
				cr_e = VILLE;
				break;
			case 4:
				cr_e = SELECTION;
				break;
			default:
				cout << "Choix invalide." << endl;
				while ( ! cin )
				{
					cin.clear();
					cin.ignore(250, '\n');
				}
		}
	}
	MenuDefinitionCritere (cr_e);
}

void MenuDefinitionCritere (Critere_e cr_e)
{
	// a faire
}

//---------------------------------------------- Surcharge d operateurs --

//----------------------------------------- Constructeurs - Destructeur --


//------------------------------------------------------------------ PRIVE

//---------------------------------------------------Attributs prives --
//-------------------------------------------------- Methodes protegees --
