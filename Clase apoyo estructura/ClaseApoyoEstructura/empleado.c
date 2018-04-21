#ifndef EMPLEADO_C_INCLUDED
#define EMPLEADO_C_INCLUDED
#include <stdio.h>
#include "empleado.h"
#include <string.h>

int buscarLibre(int id[], int tam)
{
    int index = -1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(id[i]==0)
        {
            index = i;
            break;
        }
    }

    return index;
}

void cargarProductos(int id[], char descripcion[][50], int stock[], float precioUnitario[])
{
    int i;
    int posicion= buscarLibre(id,tam);
    if (posicion!=-1)
    {
        printf("\n Ingrese id del producto");
        fflush(stdin);
        scanf("%d", id[posicion]);
        printf("\n Ingrese la descripcion del producto");
        fflush(stdin);
        scanf("%s", descripcion[posicion]);
        printf("\n Ingrese el stock");
        fflush(stdin);
        scanf("%d", stock[posicion]);
        printf("\n Ingrese precio unitario");
        fflush(stdin);
        scanf("%f", precioUnitario[posicion]);
    }

}


void darDeBaja (int idProducto[], char descripcion[][50], int stock[], float precioUnitario[])
{

        printf("\n Ingrese id del producto");
        fflush(stdin);
        scanf("%d", id[posicion]);
        printf("\n Ingrese la descripcion del producto");
        fflush(stdin);
        scanf("%s", descripcion[posicion]);
        printf("\n Ingrese el stock");
        fflush(stdin);
        scanf("%d", stock[posicion]);
        printf("\n Ingrese precio unitario");
        fflush(stdin);
        scanf("%f", precioUnitario[posicion]);
}
// baja:
// 1) pedir id del producto
// 2) busco el id en el vector
// 3)  a) si encuentro. muestro dato . pido el stock hago un menu
// 4)  preguntar si realiza modificacin: si modifico. no cancelar
// 5) si no encuentro el dato, el dato no se encontro

void mostrarProductos(int idProducto[], char descripcion[][50], int stock[], float precioUnitario[], int cant)
{
    int i;
    printf("%5s %20s %5s %s\n","id","descripcion","stock","precio");
    for(i=0; i<cant; i++)
    {
        if(idProducto[i]!=0)
        {
            printf("%5d %20s %5d %.2f\n", idProducto[i], descripcion[i], stock[i], precioUnitario[i]);
        }
    }
}

void ordenarProductos(int idProducto[], char descripcion[][50], int stock[], float precioUnitario[], int cant)
{
    int auxInt;
    float auxFloat;
    char auxString[50];
    int i;
    int j;
    for(i=0; i<cant-1; i++)
    {
        for(j=i+1; j<cant; j++)
        {
            if(stricmp(descripcion[i],descripcion[j])>0)
            {
                strcpy(auxString,descripcion[i]);
                strcpy(descripcion[i],descripcion[j]);
                strcpy(descripcion[j], auxString);


                auxInt = idProducto[i];
                idProducto[i]= idProducto[j];
                idProducto[j]=auxInt;


                auxInt = stock[i];
                stock[i]= stock[j];
                stock[j]=auxInt;


                auxFloat = precioUnitario[i];
                precioUnitario[i]= precioUnitario[j];
                precioUnitario[j]=auxFloat;


            }
        }
    }




}


#endif // EMPLEADO_C_INCLUDED
