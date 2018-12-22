// Module de tests divers
#include "TrajetCompose.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TabTrajet.h"

#include <iostream>
using namespace std;

void MenuTests ()
{
	Trajet * ts = new TrajetSimple ("A", "B", "Velo");
	cout << ts->toString() << endl; // Doit afficher S:A;B;Velo
	
	Trajet * a = new TrajetSimple ("a", "b", "c");
	Trajet * b = new TrajetSimple ("b", "d", "c");
	Trajet * c = new TrajetSimple ("d", "e", "c");
	
	TabTrajet tt;
	tt.AjouterTrajet(a);
	tt.AjouterTrajet(b);
	tt.AjouterTrajet(c);
	Trajet * tc = new TrajetCompose(&tt);
	cout << tc->toString() << endl;
	// Doit afficher C(S:a;b;c,S:b;d;c,S:d;e;c)
}