CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++17

TRGDIR=/tmp/rysowanie_3D

__start__: ./rysowanie_3D
	./rysowanie_3D

./rysowanie_3D: obj obj/main.o obj/lacze_do_gnuplota.o obj/scena.o obj/dno.o obj/woda.o obj/wektor3D.o obj/powierzchnia.o obj/dron.o obj/wirnik.o obj/figura_geo.o obj/macierz3D.o obj/menu.o obj/przeszkoda.o
	g++ -Wall -g -pedantic -o ./rysowanie_3D obj/main.o obj/lacze_do_gnuplota.o obj/scena.o obj/dno.o obj/woda.o obj/wektor3D.o obj/powierzchnia.o obj/dron.o obj/wirnik.o obj/figura_geo.o obj/macierz3D.o obj/menu.o obj/przeszkoda.o

obj:
	mkdir -p obj

obj/menu.o: src/menu.cpp inc/menu.hh inc/lacze_do_gnuplota.hh inc/scena.hh inc/dron.hh
	g++ -c ${CXXFLAGS} -o obj/menu.o src/menu.cpp

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp
	g++ -c ${CXXFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/main.o: src/main.cpp inc/lacze_do_gnuplota.hh inc/scena.hh inc/dron.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/dron.o: src/dron.cpp inc/dron.hh inc/figura_geo.hh inc/macierz3D.hh
	g++ -c ${CXXFLAGS} -o obj/dron.o src/dron.cpp

obj/wirnik.o: src/wirnik.cpp inc/wirnik.hh inc/figura_geo.hh inc/wektor3D.hh
	g++ -c ${CXXFLAGS} -o obj/wirnik.o src/wirnik.cpp

obj/przeszkoda.o: src/przeszkoda.cpp inc/przeszkoda.hh inc/figura_geo.hh
	g++ -c ${CXXFLAGS} -o obj/przeszkoda.o src/przeszkoda.cpp

obj/scena.o: src/scena.cpp inc/scena.hh inc/woda.hh inc/dno.hh 
	g++ -c ${CXXFLAGS} -o obj/scena.o src/scena.cpp

obj/dno.o: src/dno.cpp inc/dno.hh inc/powierzchnia.hh
	g++ -c ${CXXFLAGS} -o obj/dno.o src/dno.cpp

obj/woda.o: src/woda.cpp inc/woda.hh inc/powierzchnia.hh
	g++ -c ${CXXFLAGS} -o obj/woda.o src/woda.cpp

obj/figura_geo.o: src/figura_geo.cpp inc/figura_geo.hh inc/powierzchnia.hh
	g++ -c ${CXXFLAGS} -o obj/figura_geo.o src/figura_geo.cpp

obj/powierzchnia.o: src/powierzchnia.cpp inc/powierzchnia.hh inc/wektor3D.hh inc/stale_wartosci.h
	g++ -c ${CXXFLAGS} -o obj/powierzchnia.o src/powierzchnia.cpp

obj/wektor3D.o: src/wektor3D.cpp inc/wektor3D.hh inc/wektor.hh inc/stale_wartosci.h
	g++ -c ${CXXFLAGS} -o obj/wektor3D.o src/wektor3D.cpp

obj/macierz3D.o: src/macierz3D.cpp inc/macierz3D.hh inc/wektor3D.hh
	g++ -c ${CXXFLAGS} -o obj/macierz3D.o src/macierz3D.cpp

clean:
	rm -f obj/*.o ./rysowanie_3D
