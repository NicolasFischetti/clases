#include <stdio.h>
#include "Productos.h"

int buscarLibre(eProducto[], int tam) // recibe el array de productos y la cantidad
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

eProducto ingresarProducto()
{
    int i;
    int posicion= buscarLibre(eProducto, tam);

        if (posicion != -1)
        {
            /* ingresar datos del producto (los que estan en la estructura productos.h)*/
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

int modificarProducto(eProducto[], int tam) //isdigit si es un digito o numero //isalfa determina si es un valor alfabetico
{
    mostrarListaDeProductos(eProducto,tam);
    printf("Ingrese la id del producto que desea modificar: %d");
    fflush(stdin);
    gets(idProducto);
    do
    {
        printf("Seleccione que campo desea modificar :\n1. descripcion\n2. stock\n3. precioUnitario\n4. cant\n5. Salir");
        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                printf("\n Ingrese una nueva descripcion\n");
                scanf("%s",descripcionNueva);
                eProducto[idProducto].descripcion == descripcionNueva;
                break;
            case 2:
                printf("\n Ingrese una nueva stock\n");
                scanf("%s",descripcionNueva);
                eProducto[idProducto].stock == descripcionNueva;
                break;
            case 3:
                printf("\n Ingrese una nueva precioUnitario\n");
                scanf("%s",precioUnitario);
                eProducto[idProducto].precioUnitario == descripcionNueva;
                break;
            case 4:
                printf("\n Ingrese una nueva cant\n");
                scanf("%s",cant);
                eProducto[idProducto].cant == descripcionNueva;
                break;
        }
    }while(opcion!=5);
}

int borrarProducto(eProducto[], int tam)
{
    int i;
    int idProducto;
    printf("\Ingrese el id del producto para dar de baja: \n");
    scanf("%d", &idProducto);
    for (i=0; i<tam; i++)
    {
        if(idProducto==eProducto[i].id)
        {
            eProducto[i].estado=0;
        }
    }
}

void mostrarListaDeProductos(eProducto[], int tam)
{
    int i;
    for (i=0;i<tam;i++)
    {
        if(eProducto[i].estado==1)
        {
            printf("%5d %20s %5d %.2f\n", id[i], descripcion[i], stock[i], precioUnitario[i], int cant[i]);
        }
    }
}

void mostrarUnProducto(eProducto[], int tam)
{
    int i;
    int idProducto;
    printf("\Ingrese el id del producto para mostrar: \n");
    scanf("%d", &idProducto);
    for (i=0;i<tam;i++)
    {
        if(eProducto[i].id==idProducto && eProducto[i].estado==1)
        {
            printf("%5d %20s %5d %.2f\n", id[i], descripcion[i], stock[i], precioUnitario[i], int cant[i]);
            break;
        }
    }
}

void ordenarProductos(eProducto[], int id, int stock, int precioUnitario)
