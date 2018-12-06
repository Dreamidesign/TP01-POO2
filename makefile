

voyage: Catalogue.o Trajet.o TrajetCompose.o TrajetSimple.o Menu.o main.o
	g++ -o voyage Catalogue.o Trajet.o TrajetCompose.o TrajetSimple.o Menu.o main.o

Trajet.o: Trajet.cpp Trajet.h
	g++ -c Trajet.cpp;

TrajetSimple.o: TrajetSimple.cpp TrajetSimple.h
	g++ -c TrajetSimple.cpp;

TrajetCompose.o: TrajetCompose.cpp TrajetCompose.h
	g++ -c TrajetCompose.cpp;

Catalogue.o: Catalogue.cpp Catalogue.h Trajet.h
	g++ -c Catalogue.cpp;

Menu.o: Catalogue.h Trajet.h TrajetSimple.h TrajetCompose.h Menu.cpp Menu.h
	g++ -c Menu.cpp;

main.o: Menu.h Catalogue.h main.cpp
	g++ -c main.cpp;
