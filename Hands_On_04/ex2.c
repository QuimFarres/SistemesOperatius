#include <sys/types.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>
int main () {
        pid_t p1 = fork();
        assert (p1 >= 0);
        if(p1 == 0)
        {
            printf("Hola sóc el procés fill amb pid %d \n", getpid());
        }else
        if(p1 > 0)
        {
            printf("Hola sóc el procés pare amb pid %d \n", getpid());
        }
       
}