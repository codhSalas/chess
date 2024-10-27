main: obj/jeu.o obj/tour.o obj/roi.o obj/reine.o obj/pion.o obj/fou.o obj/cavalier.o obj/main.o  obj/echiquier.o obj/piece.o obj/vide.o
	g++ -O3 obj/jeu.o obj/tour.o obj/roi.o obj/reine.o obj/pion.o obj/fou.o obj/cavalier.o obj/main.o  obj/echiquier.o obj/piece.o obj/vide.o -o prog

obj/main.o :main.cpp
	g++ -c -Wall main.cpp -o obj/main.o

obj/jeu.o :include/jeu.hpp src/jeu.cpp
	g++ -c -Wall src/jeu.cpp -o obj/jeu.o

obj/echiquier.o : include/echiquier.hpp src/echiquier.cpp
	g++ -c -Wall src/echiquier.cpp -o obj/echiquier.o

obj/piece.o : include/piece.hpp src/piece.cpp
	g++ -c -Wall src/piece.cpp -o obj/piece.o

obj/vide.o : include/vide.hpp src/vide.cpp
	g++ -c -Wall src/vide.cpp -o obj/vide.o

obj/cavalier.o : include/cavalier.hpp src/cavalier.cpp
	g++ -c -Wall src/cavalier.cpp -o obj/cavalier.o

obj/fou.o : include/fou.hpp src/fou.cpp
	g++ -c -Wall src/fou.cpp -o obj/fou.o

obj/pion.o : include/pion.hpp src/pion.cpp
	g++ -c -Wall src/pion.cpp -o obj/pion.o

obj/reine.o : include/reine.hpp src/reine.cpp
	g++ -c -Wall src/reine.cpp -o obj/reine.o

obj/roi.o : include/roi.hpp src/roi.cpp
	g++ -c -Wall src/roi.cpp -o obj/roi.o

obj/tour.o : include/tour.hpp src/tour.cpp
	g++ -c -Wall src/tour.cpp -o obj/tour.o



clean:
	rm -f obj/*.o ./prog
	clear
.PHONEY: clean