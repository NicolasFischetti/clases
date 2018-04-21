#include <stdio.h>
#include "Productos.h"

int buscarLibre(eProducto[], int id, int tam) // recibe el array de productos y la cantidad
{
    int i;
    int posicionLibre= -1;
    for (i=0; i<tam; i++)
    {
        if(eProducto[i].estado==0)
        {
             posicionLibre= i;
             break;
        }
        return i;
    }
}

eProducto pedirProducto()
{
    int i;
    int posicion= buscarLibre(id, tam);

        if (posicion != -1)
        {
            printf("\n Ingrese el id del producto: ");
            fflush(stdin);
            gets(eProducto[posicion].id);
            printf("\ Ingrese la descripcion del producto: ");
            fflush(stdin);
            gets(eProducto[posicion].descripcion);
            printf("\n Ingrese el stock:" );
            fflush(stdin);
            gets(eProducto[posicion].stock);
            printf("\n Ingrese el precio unitario:");
            fflush(stdin);
            gets(eProducto[posicion].precioUnitario);

            eProducto[posicion].estado=1;
        }
}
int ingresarProductoEnLista(eProducto[], int id, int tam)
{
     int i;

    for (i=0; i< tam;i++)
    {
        if (eProducto[i].estado==1)
        {
            pedirProducto();
        }
    }
}

int modificarProducto(eProducto, float precioUnitario, int stock, char descripcion ) //isdigit si es un digito o numero //isalfa determina si es un valor alfabetico

int borrarProducto(eProducto, int id, int stock)

void mostrarListaDeProductos(eProducto,int idProducto, char descripcion, int stock, float precioUnitario, int cant)
{
    int i;
    for (i=0;i<tam;i++)
    {
        if(eProducto[i].estado==1)
        {
            printf("\nLos productos son: %d", eProducto[i].id);
        }
    }
}

void mostrarUnProducto(eProducto)
{
    if (eProducto[i].estado==1)
    {
        printf("\nIngrese el id del producto:")
        eProducto
    }
}

void ordenarProductos(eProducto, int id, int stock, int precioUnitario)
