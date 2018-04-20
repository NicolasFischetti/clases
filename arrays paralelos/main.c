#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5
#define CANT 5
#include "estrcutraempleado.h"

int main()
{
    //ARRAYS PARALELOS - CLASE 7
     // crear un char para apellido [5][20]
    //int [5] nota uno 0/10
    // int [5]   nota dos
    //float [5]   promedio
    // hacer un for hasta 5
    //

   /* char arrayApellido [TAM][20] = {"Lopez", "Alvarez", "Zapata", "Perez", "Albornos"};
    int notaUno[TAM] = {10, 4 , 2, 9, 8};
    int notaDos[TAM] = {1 , 8 , 2, 8, 10};
    float promedio[TAM];
    int i;

   mostrarPromedio(arrayApellido[20],notaUno,notaDos, promedio, TAM);*/

   int proximoId= 0;
   int seguir= 's';
   int continuar;
   Empleado arrayEmpleado[CANT];
   do
   {
       printf("1-Mostrar lista\n");
       printf("2- Mostrar alta\n");
       printf("3- Mostrar baja\n");
       printf("4- Salir \n");
        getInt("Ingrese una opcion", "Error", 2, 1, 3,*continuar)

       scanf("%d", continuar);

        switch(continuar)
        {

            case 1:
            emp_mostrar(arrayEmpleado,CANT);
            break;
            case 2:
            emp_alta(arrayEmpleados,CANT);
            proximoId++;
            break;
            case 3:
            emp_baja(arrayEmpleados,CANT);
            proximoId--;
            break;

        }

   }while (seguir!= 'n')


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
