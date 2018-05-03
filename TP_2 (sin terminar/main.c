#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define limitePersonas 20

int main()
{
    EPersona lista[limitePersonas];
    char seguir='s';
    int opcion=0;
    int abonado_init(EPersona* lista);
    int auxiliarDni;

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                persona_alta(lista);
                break;
            case 2:
                getValidInt("Ingrese el dni de la persona que desea eliminar", "Error en el ingreso del dni", &auxiliarDni, 0, 1000000, 2);
                persona_eliminar(lista, auxiliarDni);
                break;
            case 3:
                persona_ordenar(lista, 1);
                break;
            case 4:
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
