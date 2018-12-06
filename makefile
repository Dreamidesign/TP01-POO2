

voyage: Structure.o Trajet.o TrajetCompose.o TrajetSimple.o Catalogue.o main.o
	g++ -o voyage Structure.o Trajet.o TrajetCompose.o TrajetSimple.o Catalogue.o main.o

Trajet.o: Trajet.cpp Trajet.h
	g++ -c Trajet.cpp;

TrajetSimple.o: TrajetSimple.cpp TrajetSimple.h
	g++ -c TrajetSimple.cpp;

TrajetCompose.o: TrajetCompose.cpp TrajetCompose.h Structure.h
	g++ -c TrajetCompose.cpp;

Structure.o: Structure.cpp Structure.h Trajet.h
	g++ -c Structure.cpp;

Catalogue.o: Structure.h Trajet.h TrajetSimple.h TrajetCompose.h Catalogue.cpp Catalogue.h
	g++ -c Catalogue.cpp;

main.o: Catalogue.h main.cpp
	g++ -c main.cpp;
