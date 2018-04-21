#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "empleado.h"
#define T 3


int main()
{
    int idProducto[T]= {};
    char descripcion[T][50];
    int stock[T];
    float precioUnitario[T];
    int opcion;
    int posicion;
    char seguir;
    int i;

    do
    {
        printf("1. Cargar\n2. Mostrar\n3.Ordenar\n9.Salir");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                printf("CARGO\n");

                posicion = buscarLibre(idProducto, T);
                if(posicion!=-1)
                {
                    printf("Ingrese ID: ");
                    scanf("%d", &idProducto[posicion]);
                    printf("Ingrese descripcion: ");
                    fflush(stdin);
                    scanf("%[^\n]", descripcion[posicion]);
                    //gets(descripcion[posicion-1]);
                    printf("Ingrese stock: ");
                    scanf("%d", &stock[posicion]);
                    printf("Ingrese precio unitario: ");
                    scanf("%f", &precioUnitario[posicion]);

                }
                else
                {
                    printf("No hay espacio!");
                }


                break;
            case 2:
                printf("Listado:\n");
                mostrarProductos(idProducto, descripcion, stock, precioUnitario, T);
                break;
            case 3:
                printf("ORDENO\n");
                                ordenarProductos(idProducto, descripcion, stock, precioUnitario, T);

                break;
            case
        }

        system("pause");
        system("cls");
    }
    while(opcion!=9);

    return 0;

}
