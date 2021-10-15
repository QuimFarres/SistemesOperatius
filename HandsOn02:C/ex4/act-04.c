#include <stdio.h>
#include <math.h>
 
typedef struct {
float x;
float y;
} point ;

typedef struct {
    point a;
    point b;
} recta;

// Heu de fer servir la estructura recta a la funció dist enlloc dels punts
 
float dist( recta R) {
return(sqrt((R.a.x - R.b.x)*(R.a.x - R.b.x) + (R.a.y - R.b.y)*(R.a.y - R.b.y)));
}
 
int main(){

 
float d;
point A, B;
recta R;

printf("The coordinates of the point A are: ");
scanf("%f %f",&R.a.x,&R.a.y);
 

printf("\nThe coordinates of the point B are: ");
scanf("%f %f",&R.b.x,&R.b.y);
 

printf("\nThe distance between A and B is %f\n", dist(A,B));
 
exit (0);
}