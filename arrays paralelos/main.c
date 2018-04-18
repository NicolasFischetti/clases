#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5

int main()
{
    //ARRAYS PARALELOS - CLASE 7
     // crear un char para apellido [5][20]
    //int [5] nota uno 0/10
    // int [5]   nota dos
    //float [5]   promedio
    // hacer un for hasta 5
    //

    char arrayApellido [TAM][20] = {"Lopez", "Alvarez", "Zapata", "Perez", "Albornos"};
    int notaUno[TAM] = {10, 4 , 2, 9, 8};
    int notaDos[TAM] = {1 , 8 , 2, 8, 10};
    float promedio[TAM];
    int i;

   mostrarPromedio(arrayApellido[20],notaUno,notaDos, promedio, TAM);



}

       /* if (getInt("\n Ingrese el nota UNO", "\nFuera de rango", 5, 0, 10, &notaUno[TAM])==0)
        {
            printf("\n La nota es %d", notaUno[TAM]);
        }
        else
        {
            printf("Error");
        }
         if (getInt("/n Ingrese el nota DOS", "/nFuera de rango", 5, 0, 10, &notaDos[TAM])==0)
        {
            printf("/n La nota es %d", nota[TAM]);
        }
        else
        {
            printf("Error");
        }
    }





}*/
