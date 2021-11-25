#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>

void main(){
    int fd[2];
    pid_t pidFill;

    if (pipe(fd) < 0) perror("pipe fd");

    pidFill = fork();

    if(pidFill == -1){
        perror("fork");
        exit(1);
    } else if (pidFill == 0){
        /*El procés fill tanca la escriptura per la pipe*/
        close(fd[1]);
        /*El procés fill bloquejat fins rebré dades a la pipe*/
        char * msg = malloc(4);
        printf("Procés fill %d -> esperant read(fd[0],%s,%d)\n", getpid(),msg,sizeof(msg));
        int nbytes = read(fd[0], msg, sizeof(msg));

        if ( nbytes < 0) {
            perror("read fd[0]");
        }
        else{
            printf("Procés fill %d -> ha rebut una cadena a read(fd[0],%s,%d)\n", getpid(),msg,sizeof(msg));
            exit(0);
        }
    } else {
        /* El procés pare tanca la lectura per la pipe */
        close(fd[0]);
        char * msg = malloc(4);
        sprintf(msg,"Hola");
        printf("Procés pare %d -> escrivint dades write(fd[1],%s,%d)\n", getpid(),msg,sizeof(msg));
        int codret = write(fd[1], msg, sizeof(msg));
        
        if (codret == -1) perror("write fd[1]");

        wait(NULL);
        exit(0);
    }
}