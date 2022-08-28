application: funktionengenerator
	gcc main.c -o funktionengenerator -lfunktionen -lm

funktionengenerator:
	gcc sawtooth.c sinusfct.c rectfct.c triangfct.c -c
	ar -crs libfunktionen.a sawtooth.o sinusfct.o rectfct.o triangfct.o
	sudo cp funktionen.h /usr/include
	sudo cp libfunktionen.a /usr/lib
