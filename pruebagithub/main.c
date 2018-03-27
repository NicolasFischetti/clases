#include <stdio.h>
#include <stdlib.h>

int main()
{
    char apellido;
    float sueldo;
    int aumento;
    float aumentoParcial;
    float aumentoFinal;
    int contador = 1;

   while (contador == 1)

    {
        contador++;
        printf("Ingrese su apellido\n");
        scanf("%c", &apellido);
        fflush(stdin);

        printf("Ingrese su sueldo\n");
        scanf("%f", &sueldo);

        printf("Ingrese su aumento\n");
        scanf("%d", &aumento);

        aumentoParcial= (sueldo * aumento) / 100;
        aumentoFinal= aumentoParcial + sueldo;

        while (aumento > 100 || aumento < 0)
        {
            printf("Ingrese su aumento nuevamente\n");
            scanf("%d", &aumento);
        }

        if (aumentoFinal > 18.500)
        {
            printf("Su sueldo es alto, %.3f\n", aumentoFinal);
        }

    }

}

