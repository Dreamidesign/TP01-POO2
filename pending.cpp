// // Mode d'emploi :
// //  Indique si le trajet fourni est valide au critere.
// //  t : Pointeur de Trajet
// //  c : structure Critere
// //  i : indice du trajet fourni dans le catalogue (facultatif)
// // Contrat :
// //  Les parametres fournis sont valides, en particulier le critere.
// bool TrajetValideAuCritere (trajet * t, Critere c, unsigned int i = -1);
//
// enum Critere_e
// {
//     SANS,
//     TYPE,
//     VILLE,
//     SELECTION
// }; // Type de critere
//
// // Definit un critere, avec son type, et ses éventuels paramètres
// // m et n (villes ou indices de trajets).
// // m et n dependent du type :
// // - si SANS, ils sont ignores
// // - si TYPE, n[0] contient 'S' ou 'C'
// // - si VILLE, n est la ville de depart et m la ville d'arrivee (les chaines sont valides).
// // - si SELECTION, m et n sont des chaines valides contenant un entier positif ou nul.
// struct Critere
// {
//     Critere_e type;
//     char * n;
//     char * m
// };
//
// bool TrajetValideAuCritere (Trajet * t, Critere & c, unsigned int i)
// {
//     if (t == nullptr)
//     {   return false;
//     }
//     char trajet = t->toString();
//
//         switch (c.type)
//         {
//             case SANS:
//                 return true;
//             case TYPE:
//                 // Si les types du critere et du trajet sont identiques.
//                 return ( ! strcmp (c.n[0], trajet[0]) ) ? true : false;
//             case VILLE:
//                 // Si c.n n'est pas vide, on compare c.n a la ville de depart :
//                 if (( strcmp (c.n, "") ) && ( strcmp (c.n, t->GetVilleDepart() ) )
//                 {   return false;
//                 }
//                 if (( strcmp (c.m, "") ) && ( strcmp (c.m, t->GetVilleArrivee() ) )
//                 {   return false;
//                 }
//                 return true;
//
//                 return
//             case SELECTION:
//                 // Si i est entre c.n inclus et c.m inclus.
//                 return ((i >= atoi (c.n)) && (i <= atoi(c.m))) ? true : false;
//             default:
//                 cerr << “Type de critere invalide !” << endl;
//                 return false;
//         }
//   }
