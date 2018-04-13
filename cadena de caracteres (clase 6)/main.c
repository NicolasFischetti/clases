#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXIMO_NUM 30
#define CARACTERES 4096

int main()
{

   int edad;
   if (getInt("Edad?", "Fuera de rango", 2, 0, 199, &edad)==0)
   {
        printf("La edad es %d", edad);
   }
   else
   {
       printf("Error");
   }

   float numeroauxiliar;
   char str[MAXIMO_NUM];
   printf("Ingrese su numero\n");
    gets(str);
   numeroauxiliar = atof(str);
   printf("El valor del string es = %s, el valor del float es= %.2f\n", str, numeroauxiliar);
   return(0);



    char strr[CARACTERES];
    int numeroAuxiliar;
    printf("Ingrese su numero\n");
    gets(strr);
    numeroAuxiliar= atoi(strr);
    if (numeroAuxiliar > 0 && numeroAuxiliar < 4096)
    printf("Valor del string: %s, Valor del entero %d",strr, numeroAuxiliar);
    return 0;

    char texto[20];
    printf("Ingrese el texto: %s\n", texto);
    gets (texto);

    if (strcmp(texto,"1234")==0)
    {
        printf("El texto es correcto\n");
    }
    else
    {
        printf("Incorrecto");
    }


    char texto1[20];
    char texto2[20];
    printf("Ingrese una palabra: \n");
    scanf("%s", texto1);

    strcpy(texto2,texto1);

    printf("Se ingreso: %s , la copia es %s", texto1, texto2);

    char vectorCantidad[MAXIMO_NUM];
    int variableUno;
    printf("\nIngrese su nombre: ");
    scanf("%s", vectorCantidad);
    variableUno= strlen (vectorCantidad);
    printf("\nLa cantidad de letras es %d:  ", variableUno);
}




