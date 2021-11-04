#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define RUNINGDIR "./"
#define LOGFILE RUNINGDIR"log.txt"

enum accions {pokemonEscaped = 7 ,pokemonCaptured = 2};


void logger(char* missatge)
{
    time_t now;
    time(&now);
    FILE* f = fopen(LOGFILE, "a");
    fprintf(f, "%s:%s \n" , ctime(&now),missatge);
    fclose(f);
}

int getRandom()
{
    
    return rand()%10;
}

void tractament()
{
    char log[100];
    int num = getRandom();
    sprintf(log, "el valor de la variable es: %d \n", num);
    logger(log);
    if(num == pokemonEscaped)
    {
        exit(pokemonEscaped);
    }
   
    
}
void tractament2()
{
    //if(num == pokemonCaptured)
    
    exit(0);
    

}
void tractIgnor()
{

}



int main()
{

signal(SIGUSR1,tractament);
signal(SIGUSR2,tractament2);
signal(SIGINT, SIG_IGN);
srand(getpid());


    while(1)
    {
        
    }


}