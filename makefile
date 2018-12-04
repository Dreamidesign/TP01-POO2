

voyage: Catalogue.o Trajet.o TrajetCompose.o TrajetSimple.o main.o
	g++ -o voyage Catalogue.o Trajet.o TrajetCompose.o TrajetSimple.o main.o

Trajet.o: Trajet.cpp Trajet.h
	g++ -c Trajet.cpp;

TrajetSimple.o: TrajetSimple.cpp TrajetSimple.h
	g++ -c TrajetSimple.cpp;

TrajetCompose.o: TrajetSimple.cpp TrajetCompose.h
	g++ -c TrajetCompose.cpp;

Catalogue.o: Catalogue.cpp Catalogue.h
	g++ -c Catalogue.cpp;

main.o: main.cpp
	g++ -c main.cpp;
