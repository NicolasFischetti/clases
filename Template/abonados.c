#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define QTY 10
#define OCUPADO 0
#define LIBRE 1
#include "abonados.h"

static int buscarLugarLibre(Abonados* array,int limite);
static int proximoId();

int abonados_init(Abonados* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty = 1;
        }
    }
    return retorno;
}

int abonados_buscarPorId(Abonados* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == OCUPADO && array[i].idAbonados == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int abonados_baja(Abonados* array,int limite, int id)
{

    int retorno = -1;
    int indice;
    indice = abonados_buscarPorId(array,limite,id);
    if(indice >= 0)
    {
        retorno = 0;
        array[indice].isEmpty = LIBRE;
    }
    return retorno;
}


int abonados_mostrar(Abonados* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
            {
               printf("\n[RELEASE] %s - %d - %d",array[i].nombre,array[i].idAbonados,array[i].isEmpty);
            }
        }
    }
    return retorno;
}

int abonados_mostrarDebug(Abonados* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("\n[DEBUG] %s - %d - %d",array[i].nombre,array[i].idAbonados,array[i].isEmpty);
        }
    }
    return retorno;
}


int abonados_alta(Abonados* array,int limite)
{
    int retorno = -1;
    char nombre[50];
    char apellido[50];
    int numero;
    int id;
    int indice;

    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        indice = buscarLugarLibre(array,limite);
        if(indice >= 0)
        {
            retorno = -3;
            id = proximoId();
            if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))
            {
                if(!getValidString("Apellido?","Error","Overflow", apellido,50,2))
                {
                        if(!getValidInt("Ingrese un numero","Error", &numero, 0 , 1500,2))
                    {

                            retorno = 0;
                            strcpy(array[indice].nombre,nombre);
                            strcpy(array[indice].apellido,apellido);
                            array[indice].numero, numero;
                            array[indice].idAbonados = id;
                            array[indice].isEmpty = OCUPADO;

                        }
                    }
            }
        }
    }
    return retorno;
}



int abonados_modificacion(Abonados* array,int limite, int id)
{
    int retorno = -1;
    int indice;
    char nombre[50];
    char apellido[50];
    indice = abonados_buscarPorId(array,limite,id);
    if(indice >= 0)
    {
        retorno = -2;
        if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))
        {
            if(!getValidString("Apellido?","Error","Overflow", apellido,50,2))
                {
                    retorno = 0;
                    strcpy(array[indice].nombre,nombre);
                    strcpy(array[indice].apellido,apellido);
        }

    }

    }
    return retorno;
}


static int buscarLugarLibre(Abonados* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == LIBRE)
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



int abonados_ordenar(Abonados* array,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    Abonados auxiliar;

    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                    if(array[i].isEmpty == OCUPADO && array[i+1].isEmpty == OCUPADO )
                    {
                        if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && !orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && orden)) //<------------
                        {
                            auxiliar = array[i];
                            array[i] = array[i+1];
                            array[i+1] = auxiliar;
                            flagSwap = 1;
                        }
                    }
            }
        }while(flagSwap);
    }

    return retorno;
}*/









































