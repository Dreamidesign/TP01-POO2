// Module de tests divers
#include "TrajetCompose.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TabTrajet.h"

#include <iostream>
using namespace std;

static void TestToString()
{
	Trajet * ts = new TrajetSimple ("A", "B", "Velo");
	char * text = ts->toString();
	cout << text << endl; // Doit afficher S:A;B;Velo
	delete [] text;
	
	Trajet * a = new TrajetSimple ("a", "b", "c");
	Trajet * b = new TrajetSimple ("b", "d", "c");
	Trajet * c = new TrajetSimple ("d", "e", "c");
	
	TabTrajet * tt = new TabTrajet;
	tt->AjouterTrajet(a);
	tt->AjouterTrajet(b);
	tt->AjouterTrajet(c);
	Trajet * tc = new TrajetCompose(tt);
	text = tc->toString();
	cout << text << endl;
	// Doit afficher C(S:a;b;c,S:b;d;c,S:d;e;c)
	
	delete[] text;
	delete ts;
	delete tc;
}

void MenuTests ()
{
	TestToString();
}