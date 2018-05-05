#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eusuario.h"
#include "publicacion.h"
#include "utn.h"

static int buscarLugarLibre(ePublicacion* productos,int tam);


int producto_init(ePublicacion* productos,int tam)
{
    int retorno = -1;
    int i;
    if(tam > 0 && productos != NULL)
    {
        retorno = 0;
        for(i=0;i<tam;i++)
        {
            productos[i].isEmpty = 0;
        }
    }
    return retorno;
}

static int buscarLugarLibre(ePublicacion* productos,int tam)
{
    int retorno = -1;
    int i;
    if(tam > 0 && productos != NULL)
    {
        retorno = -2;
        for(i=0;i<tam;i++)
        {
            if(productos[i].isEmpty == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int producto_alta(ePublicacion* productos,int tam)
{
    int retorno = -1;
    char nombreProd[50];
    float precioProd;
    int stockProd;
    int indice;

     indice = buscarLugarLibre(productos,tam);
    if(tam > 0 && productos != NULL)
    {
        retorno = -2;
        if(indice >= 0)
        {
            retorno = -3;

            if(!getValidString("Nombre del producto?","Error","Overflow", nombreProd,50,2))
            {
                if(!getValidFloat("Precio del producto?","Error",&precioProd,0,100000,2))
                {
                    if(!getValidInt("Stock del producto?","Error",&stockProd,0, 1000,2))
                    {
                        retorno = 0;

                        strcpy(productos[indice].nombreProd,nombreProd);
                        productos[indice].precioProd = precioProd;
                        productos[indice].stockProd = stockProd;


                        productos[indice].isEmpty = 1;
                    }
                }
            }
        }
    }
    return retorno;
}

int producto_modificacion(ePublicacion* productos,int tam, int id)
{
    int retorno = -1;
    int indice;
    char nombreProd[50];
    float precioProd;
    int stockProd;

    indice = producto_buscarPorId(productos,tam,id);
    if(indice >= 0)
    {
        retorno = -2;

        if(!getValidString("Nombre del producto nuevo?","Error","Overflow", nombreProd,50,2))
            {
                if(!getValidFloat("Precio del producto nuevo?","Error", &precioProd,0, 100000,2))
                {
                    if(!getValidInt("Stock nuevo a ingresar?","Error", &stockProd,0, 100000,2))
                    {
                    retorno = 0;

                    strcpy(productos[indice].nombreProd,nombreProd);
                    productos[indice].precioProd = precioProd;
                    productos[indice].stockProd = stockProd;
                }
            }
    }
    return retorno;
}

}


int producto_baja(ePublicacion* productos,int tam, int id)
{

    int retorno = -1;
    int indice;
    indice = producto_buscarPorId(productos,tam,id);
    if(indice >= 0)
    {
        retorno = 0;
        productos[indice].isEmpty = 0;
    }
    return retorno;
}

int producto_mostrar(ePublicacion* productos,int tam)
{
    int retorno = -1;
    int i;
    if(tam > 0 && productos != NULL)
    {
        retorno = 0;
        for(i=0;i<tam;i++)
        {
            if(!productos[i].isEmpty)
            {
               printf("\n %s - %d - %d - %.2f - %d",productos[i].nombreProd,productos[i].idUsuario,productos[i].isEmpty, productos[i].precioProd, productos[i].stockProd);
            }
        }
    }
    return retorno;

}

int producto_buscarPorId(ePublicacion* productos,int tam, int id)
{
    int retorno = -1;
    int i;
    if(productos > 0 && productos != NULL)
    {
        retorno = -2;
        for(i=0;i<tam;i++)
        {
            if(productos[i].isEmpty == 1 && productos[i].idProducto == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



