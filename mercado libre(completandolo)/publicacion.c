#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eusuario.h"
#include "publicacion.h"
#include "utn.h"

static int buscarLugarLibre(ePublicacion* productos,int tam);
static int proximoId();

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
    int id;

     indice = buscarLugarLibre(productos,tam);
    if(tam > 0 && productos != NULL)
    {
        retorno = -2;
        if(indice >= 0)
        {
             id = proximoId();
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
                        productos[indice].cantidadVendida=0;
                        productos[indice].idProducto = id;
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
            if(productos[i].isEmpty== 1)
            {
               printf("\n %s - %d - %.2f - %d -%d",productos[i].nombreProd,productos[i].isEmpty, productos[i].precioProd, productos[i].stockProd, productos[i].idProducto);
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
static int proximoId()
{
    static int ultimoId = -1;
    ultimoId++;
    return ultimoId;
}



int venderDeProducto(ePublicacion* productos, int tam, eUsuario* array, int id)
{
    int retorno = -1;
    int calificacion;
    int indiceCompra;
    int indiceUsuario;
    indiceCompra= producto_buscarPorId(productos,tam,id);
    if(indiceCompra >= 0)
    {
            retorno = -1;
            if (productos[indiceCompra].stockProd > 0)
            {
                if(!getValidInt("\nCalificacion", "No es una calificacion", &calificacion, 0, 10,1))
                    {


                productos[indiceCompra].stockProd--;
                productos[indiceCompra].cantidadVendida++;
                indiceUsuario= usuario_buscarPorId(array,tam, productos[indiceCompra].idUsuario);
                array[indiceUsuario].calificacionAcum += calificacion;
                array[indiceUsuario].cantidadVentas++;

                }
            }
        }
        return retorno;
    }

