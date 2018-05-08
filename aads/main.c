#include <stdio.h>
#include <stdlib.h>

// vale 13 y
  void muestra(int *x, int *y);
int main(void){
int x, y;
x=11;
y=13;
muestra(&x, &y);
printf("\n-----valores dentro de main----");
printf("\nx vale %d \ny vale %d", x, y);
 return 0;
}
void muestra(int *x, int *y)
{
*x = *y;
printf("\n-----valores dentro de la función muestra----");
printf("\nx vale %d \ny vale %d", *x, *y);
 return;
}

 //ordenar de mayor a menor
void main(){

int vector[10];
int i;
int mayor;

for (i=0; i<10; i++){
   printf( "ingrese 10 numeros enteros");
   scanf("%d", &vector[i]);
}


for (i=0; i<10; i++){
    if (vector[i]> mayor){
    mayor=vector[i];
    }
}
printf("El mayor es %d\n", mayor);
}

int main(void){
 int x;
 int vector[23]
 for(x=1; x<=10; x++){

 scanf("%d", vector[x]);
 printf("Su numero es %d", vector[x]);
 }
 return 0;
 }

void main(void)
{
int v[5],pos,i;
char seguir;
for(i=0;i<5;i++)
v[i]=0; // inicializamos vector
do
{
printf("Ingrese posici¢n");
scanf("%d",&pos);
printf("Ingrese valor a cargar en el vector");
scanf("%d",&v[pos]);
printf("Desea ingresar otro dato S/N?");
scanf("%c",&seguir);
}while(seguir=='s');
}

