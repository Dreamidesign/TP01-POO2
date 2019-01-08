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
	DefinirAutorisations ();
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

	onSauvegarde = ((action == SAUV) ? true : false);

	Critere_e cr_e = MenuChoixCritere ();
	if ( MenuDefinitionCritere (cr_e))
	{
		onSauvegarde ? Sauvegarde () : Restitution ();
	}
	else
	{
		cerr << "Arret de GestionFichier." << endl;
	}
} // -- Fin de GestionFichier

void Sauvegarde()
{
	//Déclaration d'un flux permettant d'écrire dans un fichier.
	ofstream monFlux(nomFichier.c_str());

	if(monFlux)  //On teste si tout est OK
	{
		int nbTS=0; // Nombre de trajets simples (metadonnees)
		int nbTC=0; // Nombre de trajets composes (metadonnees)
		TabTrajet & liste = cat->GetTabTrajet(); // Raccourci
		string * content = new string [liste.GetNbTrajets()];
		int effec = 0; //nombre de trajets effectivement stockés

		for(int i = 0; i < liste.GetNbTrajets(); i++)
		{
			if(TrajetValideAuCritere(liste[i], i))
			{
				content[effec] = liste[i]->toStringAsString();
				((content[effec][0] == 'S') ? nbTS : nbTC)++;
				effec++;
			}
		}

		monFlux << nbTS << ";" << nbTC << endl;

		for(int i=0; i < effec; i++)
		{
			monFlux << content[i] << endl;
		}
		delete [] content;
		cout << effec << " trajets correctement ecrits dans le fichier ";
		cout << nomFichier << '.' << endl;
	}
	else
	{
	    cerr << "ERREUR: Impossible d'ouvrir le fichier." << endl;
	}
} // -- Fin de Sauvegarde

void Restitution()
{
	ifstream monFlux(nomFichier.c_str());

	if(monFlux)
	{
		unsigned int effec = 0;
		int ligneNum = 0;
		string trajetLigne;

		// Lecture des metadonnees
		unsigned int nbTC = 0, nbTS = 0;
		monFlux >> nbTS;
		monFlux.ignore(1, ';');
		monFlux >> nbTC;
		monFlux.ignore(9999, '\n');

#ifdef MAP
		cout << "NB TS : " << nbTS << ", NB TC : " << nbTC << endl;
#endif

		// Lecture des trajets
		while(getline(monFlux, trajetLigne))
		{
#ifdef MAP
			cout << "Lecture d'une ligne " << endl;
#endif
			/* Etapes de la lecture d'un TC :
			 * 1. On enleves les parenthèses --> que le contenu
			 * 2. Lecture entre les virgules
			 * 3. Lecture de soit un TS, soit on recommence pour un TC
			 * 4. A chaque étape on ajoute le contenu a un tabTrajet
			 */
			Trajet* t;

			// Ajout d'un trajet simple
			if(nbTS && trajetLigne[0] == 'S')
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

				t= new TrajetSimple(villeD.c_str(), villeA.c_str(),
					mT.c_str());
				-- nbTS;
			}

			// Ajout d'un trajet compose
			else
			{
				if ( ! nbTC ) continue;

				trajetLigne.erase(0, 2);
				trajetLigne.erase(trajetLigne.length()-1,
					trajetLigne.length());

				TabTrajet* tabT = new TabTrajet();
				string delimiter = ",";
				size_t pos = 0; //position du delimiter
				string temp;
				while((pos = trajetLigne.find(delimiter)) != string::npos)
				{
					temp = trajetLigne.substr(0, pos);
					trajetLigne.erase(0, pos + delimiter.length());

					temp[0] == 'S' ?
						lecture_TS(tabT, temp) :
						lecture_TC(tabT, temp);
				}
				trajetLigne[0] == 'S' ?
					lecture_TS(tabT, trajetLigne) :
					lecture_TC(tabT, trajetLigne);

				t = new TrajetCompose(tabT);
				-- nbTC;
			}

#ifdef MAP
			cout << "Trajet etudie : " << t->toStringAsString () << '.' << endl;
#endif
			if(TrajetValideAuCritere(t, ligneNum))
			{
#ifdef MAP
				cout << "Il est valide au critere." << endl;
#endif
				cat->GetTabTrajet().AjouterTrajet(t);
				++ effec;
			}
			else
			{
#ifdef MAP
				cout << "Il n'est pas valide au critere." << endl;
#endif
				delete t;
			}

			ligneNum++;
			if ((unsigned long)ligneNum == nbTS + nbTC) break;
		}
		cout << effec << " trajets correctement importes depuis le fichier ";
		cout << nomFichier << endl;
	}
	else
	{
	    cerr << "ERREUR: Impossible d'ouvrir le fichier." << endl;
	}
} // -- Fin de Restitution

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
} // -- Fin de lecture_TS

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
} // -- Fin de lecture_TC

bool TrajetValideAuCritere (const Trajet * t, long int index)
{
	if (t == nullptr)
    {   return false;
    }

    string trajet = t->toStringAsString();

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
            	( cri.n.compare("_") ) &&
            	( cri.n.compare(t->GetVilleDepart()) )
            )
            {   return false;
            }
            // Idem ville d'arrivee
            if
            (
            	( cri.m.compare("_") ) &&
            	( cri.m.compare(t->GetVilleArrive()) )
            )
            {   return false;
            }
            return true;

		case SELECTION:
            // Si i est entre c.n inclus et c.m inclus.
            return
            (
            	(index >= stoi (cri.n)) &&
            	(index <= stoi (cri.m))
            ) ? true : false;

		default:
			// N'est pas sense se produire.
            cerr << "Type de Critere invalide !" << endl;
            return false;
    }
} // -- Fin de TrajetValideAuCritere

ChoixAction MenuChoixAction ()
{
	unsigned int choix;
	do
	{
		cout << "Que souhaitez-vous faire ?" << endl;
		cout << "Le fichier selectionne est \"" << nomFichier << "\"" << endl;
		if (autorisations.ecriture)
		{
			cout << "1. Exporter le catalogue courant." << endl;
		}
		if (autorisations.lecture)
		{
			cout << "2. Importer / restituer le catalogue courant." << endl;
		}
		cout << "3. Modifier le nom du fichier." << endl;
		cout << "4. Retourner au menu principal." << endl;

		choix = -1;
		cin >> choix;
		switch (choix)
		{
			case 1:
				if (autorisations.ecriture)
				{
					return SAUV;
				}
				else
				{
					cout << "Choix invalide." << endl;
					break;
				}
			case 2:
				if (autorisations.lecture)
				{
					return REST;
				}
				else
				{
					cout << "Choix invalide." << endl;
					break;
				}
			case 3:
				return CHANGER_NOM;
			case 4:
				return QUITTER;
			case 99:
				EasterEgg();
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
} // -- Fin de MenuChoixAction

void MenuNomFichier ()
{
	int fini;
	cout << std::boolalpha;
	do
	{
		cout << "Quel nom de fichier manipuler ?" << endl;
		cin >> nomFichier;
		cout << "Test des autorisations de " << nomFichier << '.' << endl;

		// Definition autorisations
		DefinirAutorisations();

		// Test possible de lire
		ifstream ifs (nomFichier);
		cout << "Lecture : " << autorisations.lecture << endl;
		cout << "Ecriture : " << autorisations.ecriture << endl;

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
	cout << std::noboolalpha;
} // -- Fin de MenuNomFichier

Critere_e MenuChoixCritere ()
{
	cout <<
		"Choix du critere pour la " <<
		(onSauvegarde ? "sauvegarde" : "restitution") <<
		"du catalogue avec le fichier \"" << nomFichier << "\"." << endl;

	unsigned int choix = -1;
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
				return SANS;
				break;
			case 2:
				return TYPE;
				break;
			case 3:
				return VILLE;
				break;
			case 4:
				return SELECTION;
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
	return SANS;
} // -- Fin de MenuChoixCritere

bool MenuDefinitionCritere (Critere_e cr_e)
{
	cri.type = cr_e;
	switch (cr_e)
	{
		case SANS:
			cri.n = "";
			cri.m = "";
			break;
		case TYPE:
			{
				cout << "Trajets simples ou composes ?" << endl;
				unsigned int choix = -1;
				while (choix != 1 && choix != 2)
				{
					cout << "1 pour simple, 2 pour compose." << endl;
					cin >> choix;
					if ( ! cin )
					{
						cin.clear();
						cin.ignore (250, '\n');
					}
				}
				cri.n = ((choix == 1) ? "S" : "C");
				// *(cri.n+1) = '\0';
				cri.m = "";
				break;
			}
		case VILLE:
			cout << "Souhaitez-vous imposer la ville de depart ? " <<
				"Si oui, saisissez-la, sinon mettez caractere '_'." << endl;
			cin >> cri.n;
			cout << "Souhaitez-vous imposer la ville d'arrivee ? " <<
				"Si oui, saisissez-la, sinon mettez le caractere '_' ." << endl;
			cin >> cri.m;
			break;
		case SELECTION:
			{
				unsigned int choix = -1;
				unsigned int maxIndice = (onSauvegarde) ?
					cat->GetTabTrajet().GetNbTrajets() :
					GetNombreLignesFichier ();

				cout << "Vous allez saisir l'intervalle d'indices." << endl;
				cout << "Les deux nombres sont entre 0 et " << maxIndice << '.';
				cout << endl;

				cout << "Saisir l'indice de depart." << endl;
				while (choix > maxIndice)
				{
					if ( ! cin )
					{
						cin.clear();
						cin.ignore (250, '\n');
					}
					cin >> choix;
				}
				cri.n = to_string(choix);

				cout << "Saisir l'indice d'arrivee." << endl;
				choix = -1;
				while (choix > maxIndice || choix < (unsigned int)(stoi(cri.n)))
				{
					cin >> choix;
					if ( ! cin )
					{
						cin.clear();
						cin.ignore (250, '\n');
					}
				}
				cri.m = to_string(choix);
				break;
			}
		default:
			cerr << "Format du type de critere invalide." << endl;
			return false;
	}

	return true;
} // -- Fin de MenuDefinitionCritere

unsigned int GetNombreLignesFichier ()
{
	ifstream ifs (nomFichier);
	int nb1, nb2;
	ifs >> nb1;
	ifs.ignore (1, ';');
	ifs >> nb2;
	ifs.close();
	return nb1 + nb2 - 1; // On triche un peu.
} // -- Fin de GetNombreLignesFichier

void DefinirAutorisations ()
{
	ifstream ifs (nomFichier);
	autorisations.lecture  = bool(ifs);
	ofstream ofs (nomFichier, ios_base::out | ios_base::app);
	autorisations.ecriture = bool(ofs);
} // -- Fin de DefinirAutorisations

void EasterEgg ()
{
	ofstream ofs ("easter_egg.txt");
	if ( ! ofs ) 
	{
		cout << "Desoles... erreur d'ecriture." << endl;
		return;
	}
	ofs << "4;3" << endl;
	
	ofs << "S:VILLE_A;VILLE_B;VELO" << endl;
	
	ofs << "C(S:AJACCIO;BASTIA;MICHELINE,S:BASTIA;PORTO-VECCHIO;JET-SKI)";
	ofs << endl;
	
	ofs << "C(S:LYON;AIX;VOITURE,S:AIX;PERPIGNAN;HELICO,";
	ofs << "S:PERPIGNAN;VALENCIA;SOUS-MARIN)" << endl;
	
	ofs << "S:MAISON;ECOLE;SCOOTER" << endl;
	
	ofs << "S:BLAISE PASCAL;BEURK;JETPACK" << endl;
	
	ofs << "C(S:PARIS;PAU;TRAIN,S:PAU;PARIS;TRAIN DE NUIT COUCHETTE ";
	ofs << "ET MI-COUPLE)" << endl;
	
	ofs << "S:LIT;CHOCAPIC;FLEMME" << endl;
	
	ofs << "C(S:INSA;TRAVAIL;MOYENNE,S:TRAVAIL;RETRAITE;ARGENT)" << endl;
	
	nomFichier = "easter_egg.txt";
	DefinirAutorisations();
	cout << "Et si vous importiez ? :D" << endl;
}

//---------------------------------------------- Surcharge d operateurs --

//----------------------------------------- Constructeurs - Destructeur --


//------------------------------------------------------------------ PRIVE

//---------------------------------------------------Attributs prives --
//-------------------------------------------------- Methodes protegees --
