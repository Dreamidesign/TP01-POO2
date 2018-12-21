bool valideAuCritere (trajet * t, critere c);
void gestionfichir (Critere & c, bool sauvegardeornot);

enum Critere_e {SANS, TYPE, VILLE, SELECTION]; // Type de critere
struct Critere {Critere_e type; char * n; char * m}; // Definit un critere, avec son type, et ses éventuels paramètres m et n (villes ou indices de trajets).

bool valideAuCritere (Trajet * t, Critere & c, int i)
{
    if (t == nullptr) 
    {   return false;
    }
    char trajet = t->toString();

        switch (c.type)
        {
            case SANS:
                return true;
            case TYPE:
                // Si les types du critere et du trajet sont identiques.
                return ( ! strcmp (c.n[0], trajet[0]) ) ? true : false;
            case VILLE:
                {
                    if ( ! strcmp (c.n, “”) && ! 
                    {    int villeDepart = atoi (c.n);

                    // Test ville d’arrivee
                }
            case SELECTION:
                return ((i >= atoi (c.n)) && (i <= atoi(c.m))) ? true : false;
            default:
                cerr << “Type de critere invalide !” << endl;
                return false;
        }
    }
