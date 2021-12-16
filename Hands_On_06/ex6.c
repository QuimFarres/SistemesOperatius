#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
 
int main(int argc, char *argv[]){
    int fd[2];
    char s[100];
    char *p1[] = {"ls", NULL};
    char *p2[] = {"wc", "-l", NULL};
    
    //execvp(p1[0], p1);
    if (pipe(fd)<0){
        perror("Error de creació del pipe fd[]");
        exit(-1);
    }
    int pid, pid1;
    switch (pid = fork()){
        case -1:
            perror("Error fork()");
            exit(-2);
            break;
        case 0: //fill 1
            close(fd[0]);
            dup2(fd[1], 1);
            execvp(p1[0], p1);
            
            
        default: 
             if(pid1 = fork() == 0) //fill 2
             {
                close(fd[1]);          
                dup2(fd[0], 0);
                execvp(p2[0], p2);

             }else{ //pare
                close(fd[1]);
                waitpid(pid1, 0 ,0);
                waitpid(pid,0 ,0);
             }

            

    }
}