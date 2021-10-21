#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>


int merge(int x, int y)
{
    unsigned pow = 10;
    while(y >= pow)
        pow *=10;
    return x * pow + y;
}
int RandomNumberGenerator(const int nMin, const int nMax)
{
  int nRandonNumber = 0;
    srand(getpid());
    nRandonNumber = rand()%(nMax-nMin) + nMin;

    return nRandonNumber;
}


int main(){
    
    int val;
    val = fork();


    
    if(val==0){
        int a, b,exi, mer;
        printf("Hola sóc en Ned fill del matrimoni del Richard i la Lyarra amb pid = %d \n",getpid());
        val = fork();
        b = RandomNumberGenerator(1,2);
        a = wait(&exi);
        mer = merge(WEXITSTATUS(exi), b);
        


 

        if(val==0){

            printf("Hola sóc en Robb Stark amb pid = %d, sóc un fill del matrimoni de la Catelyn Stark i Ned Stark.\n" ,getpid());
            int random0 = RandomNumberGenerator(1,2);

            exit(random0);
        }

        exit(mer);

    }
    else if(val>0){

    printf("Hola sóc Rickard Stark casat amb Lyarra Stark amb pid = %d \n",getpid()); 

    int stat;
    wait(&stat);
    
    int nieto = WEXITSTATUS(stat) / 10;
    int hijo = WEXITSTATUS(stat) - nieto*10;

    if(nieto == 1)
    {
        printf("Soc en Robb i he estat apunyalat \n");
    }else
    {
         printf("Soc en Robb i he estat decapitat \n");
    }
    if(hijo == 1)
    {
        printf("Soc en Ned i he estat apunyalat \n");
    }else
    {
         printf("Soc en Ned i he estat decapitat \n");
    }

    }


    else{
        printf("Error\n");
    }

    exit(0);




}
