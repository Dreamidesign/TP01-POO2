CXX=g++
CXXFLAGS=-g -W -ansi -Wall -Wextra -std=c++11 -pedantic -O2 -DMAP
LDFLAGS=
EXEC=voyage

all : $(EXEC)

voyage: Structure.o Trajet.o TrajetCompose.o TrajetSimple.o Catalogue.o main.o
	 $(CXX) -o voyage Structure.o Trajet.o TrajetCompose.o TrajetSimple.o Catalogue.o main.o $(LDFLAGS)
Trajet.o: Trajet.cpp Trajet.h
	 $(CXX) -c Trajet.cpp $(CXXFLAGS)

TrajetSimple.o: TrajetSimple.cpp TrajetSimple.h
	 $(CXX) -c TrajetSimple.cpp $(CXXFLAGS)

TrajetCompose.o: TrajetCompose.cpp TrajetCompose.h Structure.h
	 $(CXX) -c TrajetCompose.cpp $(CXXFLAGS);

Structure.o: Structure.cpp Structure.h Trajet.h
	 $(CXX) -c Structure.cpp $(CXXFLAGS)

Catalogue.o: Structure.h Trajet.h TrajetSimple.h TrajetCompose.h Catalogue.cpp Catalogue.h
	 $(CXX) -c Catalogue.cpp $(CXXFLAGS)

main.o: Catalogue.h main.cpp
	 $(CXX) -c main.cpp $(CXXFLAGS)

clean:
	 rm -rf *.o

mrproper: clean
	 rm -rf $(EXEC)
