

voyage: Structure.o Trajet.o TrajetCompose.o TrajetSimple.o Menu.o main.o
	g++ -o voyage Structure.o Trajet.o TrajetCompose.o TrajetSimple.o Menu.o main.o

Trajet.o: Trajet.cpp Trajet.h
	g++ -c Trajet.cpp;

TrajetSimple.o: TrajetSimple.cpp TrajetSimple.h
	g++ -c TrajetSimple.cpp;

TrajetCompose.o: TrajetCompose.cpp TrajetCompose.h Structure.h
	g++ -c TrajetCompose.cpp;

Structure.o: Structure.cpp Structure.h Trajet.h
	g++ -c Structure.cpp;

Menu.o: Structure.h Trajet.h TrajetSimple.h TrajetCompose.h Menu.cpp Menu.h
	g++ -c Menu.cpp;

main.o: Menu.h main.cpp
	g++ -c main.cpp;
