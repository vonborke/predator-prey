
game: main.o simulation.o critter.o doodlebug.o ant.o menu.o utility.o coordinates.o
	g++ -std=c++11 main.o simulation.o critter.o doodlebug.o ant.o menu.o utility.o coordinates.o -o game

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

simulation.o: simulation.cpp simulation.hpp
	g++ -c -std=c++11 simulation.cpp
	
critter.o: critter.cpp critter.hpp
	g++ -c -std=c++11 critter.cpp
	
doodlebug.o: doodlebug.cpp doodlebug.hpp
	g++ -c -std=c++11 doodlebug.cpp
	
ant.o: ant.cpp ant.hpp
	g++ -c -std=c++11 ant.cpp
	
menu.o: menu.cpp menu.hpp
	g++ -c -std=c++11 menu.cpp
	
utility.o: utility.cpp utility.hpp
	g++ -c -std=c++11 utility.cpp

coordinates.o: coordinates.cpp coordinates.hpp
	g++ -c -std=c++11 coordinates.cpp

clean:
	rm *.o game
	
