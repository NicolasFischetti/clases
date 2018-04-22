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

eProducto pedirProducto()
{
    int i;
    int posicion= buscarLibre(eProducto, tam);

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

int modificarProducto(eProducto[], int id, float precioUnitario, int stock, char descripcion, int tam ) //isdigit si es un digito o numero //isalfa determina si es un valor alfabetico
{
    flag =0;
    mostrarListaDeProductos(eProducto,id,descripcion,stock,precioUnitario, cant);
    printf("Ingrese la id del producto: %d");
    fflush(stdin);
    gets(idProducto);
    int nuevoStock;
    for (i=0; i<tam; i++)
    {
        if (id= eProducto[i].id)
        {
            printf("%5d %20s %5d %.2f\n", id[i], descripcion[i], stock[i], precioUnitario[i]);)
            printf("\n Ingrese un nuevo stock\n");
            scanf("%d", nuevoStock);
            printf("\Desea realizar el cambio? :\n");
            seguir =getche();

        }
    }


}

int borrarProducto(eProducto[], int id, int tam)
{
    int i;
    int idProducto;
    printf("\Ingrese el id del producto para dar de baja: \n);
    scanf("%d", &idProducto);
    for (i=0; i<tam; i++)
    {
        if(idProducto==eProducto[i].id)
        {
            eProducto[i].estado=0;
        }
    }
}

void mostrarListaDeProductos(eProducto[],int id, char descripcion, int stock, float precioUnitario, int cant)
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

void mostrarUnProducto(eProducto);

void ordenarProductos(eProducto[], int id, int stock, int precioUnitario)
