main_v2: main_v2.o pokedex.o
	gcc main_v2.o pokedex.o -o main_v2
	gcc -c pokedex.c
main_v2.o: main_v2.c
	gcc -c main_v2.c
clean:
	/usr/bin/rm -rf *.o main_v2
execute:
	./main_v2