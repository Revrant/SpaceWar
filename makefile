SpaceWar: main.o StarWars.o StarTrek.o FightManager.o
	g++ -std=c++11 -g -Wall main.o StarWars.o StarTrek.o FightManager.o -o SpaceWar
main.o: main.cpp FightManager.h
	g++ -std=c++11 -g -Wall -c main.cpp
StarWars.o: SpaceShip.h StarWars.h StarWars.cpp
	g++ -std=c++11 -g -Wall -c StarWars.cpp
StarTrek.o: SpaceShip.h StarTrek.h StarTrek.cpp
	g++ -std=c++11 -g -Wall -c StarTrek.cpp
FightManager.o: FightManager.h FightManager.cpp
	g++ -std=c++11 -g -Wall -c  FightManager.cpp
clean:
	rm *.o SpaceWar
