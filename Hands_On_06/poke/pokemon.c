#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include "pokemon.h"
 
#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"

#define MAXPOKEMON 151
#define POKEMONCAPTURED 2
#define POKEMONESCAPED 7
 
 int getRandom()
{
    return rand()%10;
}

void tractamentCaptured()
{
    int num = getRandom();

    if(num == POKEMONCAPTURED)
    {
        printf("capturado correctamente\n");
        exit(POKEMONCAPTURED);
    } else if (num == POKEMONESCAPED){
        printf("El pokemon se ha escapado\n");
        exit(POKEMONESCAPED);
    }else{
        printf("No has capturat al pokemon \n");
        kill(getpid(),SIGSTOP);
    
    }

    printf("%d \n", num);    
}


char *args[] = {"pokemon", "pokemon", NULL};
 
int main(int arc, char *arv[])
{
srand(getpid());
int endFlag=1;
int bayas = 0;
int seen = 0;
int captured = 0;

while (endFlag == 1) {
    
    char s[100];
    char choice;
    char choice2;

    sprintf(s, "################\n# E. Explore \n# Q. Quit\n################\n");
    if (write(1, s, strlen(s)) < 0) perror("Error writting the menu");
    scanf(" %c", &choice);

    switch (choice) {
    case 'Q':
    endFlag=0;
    break;
    case 'E':
        ;
        seen++;
        int pid = fork();
        if (pid == 0) 
        {

            
            signal(SIGUSR1,tractamentCaptured);
            while(1){

            }
            //exec();

        }else   
        {   
            printf("################\n# P. Capt \n# B. Baya\n# R. Run \n################\n");
            int escape = 0;
            int status;
            while(escape == 0)
            {
                
                scanf(" %c", &choice2);
                switch (choice2){

                case 'P':
                    kill(pid, SIGUSR1);
                    
                    waitpid(-1, &status, WUNTRACED);
                    kill(pid, SIGCONT);
                    if((WEXITSTATUS(status) == POKEMONCAPTURED) || (WEXITSTATUS(status) == POKEMONESCAPED))
                    {
                        if(WEXITSTATUS(status) == POKEMONCAPTURED){
                            captured++;
                        }
                        escape = 1;                   
                    }


                break;
                case 'B':

                    if(bayas <= 3)
                    {
                        printf("+1 baya en tens %d\n", bayas);
                        bayas++;
                    }else
                    {
                        printf("ja tens max bayas \n");
                    }
                    

                break;
                case 'R': 

                    escape = 1;
                    kill(pid, SIGINT);
                    wait(&pid);
                    printf("%s" "Has escapat del combat\n");                        
                    break;

                default:
                    printf("%s!!!!Invalid option. Try again. %s\n", KRED, KNRM);
            }
            }

            
        }

        break;
    default:
    sprintf(s, "%s!!!!Invalid option. Try again. %s\n", KRED, KNRM);
    if (write(1, s, strlen(s)) < 0) perror("Error writting invalid option");
    }
}
 
char s[100];
sprintf(s, "%s!!!!I'm tired from all the fun... %s\n", KMAG, KNRM);
if (write(1, s, strlen(s)) < 0) perror("Error writting the ending msg");

printf("vistos:  %d  \n", seen);fflush(stdout);
printf("atrapados:  %d  \n", captured);fflush(stdout);
exit(0);
 
}