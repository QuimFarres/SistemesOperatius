# SistemesOperatius

Els autors d'aquest repo som:

* Carles
* Jonathan
* Quim

main_v1: main_v1.o 
	gcc main_v1.o -o main_v1  
main_v1.o: main_v1.c
	gcc -c main_v1.c
clean:
	/bin/rm -rf *.o main_v1
execute:
	./main_v1