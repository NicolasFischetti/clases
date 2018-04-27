#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abonado.h"
#include "utn.h"
#define QTY 10
#define OCUPADO 0
#define LIBRE 1

static int buscarLugarLibre(Abonado* array,int limite);
static int proximoId();



int abonado_init(Abonado* array,int limite)
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





int abonado_mostrar(Abonado* array,int limite)
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
               printf("\n[RELEASE] %s - %s - %d - %d - %d",array[i].nombre,array[i].apellido,array[i].numero,array[i].idAbonado,array[i].isEmpty);
            }
        }
    }
    return retorno;
}

int abonado_mostrarDebug(Abonado* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("\n[DEBUG] %s - %s - %d - %d - %d",array[i].nombre,array[i].apellido,array[i].numero,array[i].idAbonado,array[i].isEmpty);
        }
    }
    return retorno;
}



int abonado_alta(Abonado* array,int limite)
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
                    if(!getValidInt("Numero?","Error",&numero,0,1000,2))
                    {
                        retorno = 0;
                        strcpy(array[indice].nombre,nombre);
                        strcpy(array[indice].apellido,apellido);
                        array[indice].numero = numero;

                        array[indice].idAbonado = id;
                        array[indice].isEmpty = OCUPADO;
                    }
                }
            }
        }
    }
    return retorno;
}





int abonado_buscarPorId(Abonado* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == OCUPADO && array[i].idAbonado == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


int abonado_baja(Abonado* array,int limite, int id)
{

    int retorno = -1;
    int indice;
    indice = abonado_buscarPorId(array,limite,id);
    if(indice >= 0)
    {
        retorno = 0;
        array[indice].isEmpty = LIBRE;
    }
    return retorno;
}


int abonado_modificacion(Abonado* array,int limite, int id)
{
    int retorno = -1;
    int indice;
    char nombre[50];
    char apellido[50];
    indice = abonado_buscarPorId(array,limite,id);
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



static int buscarLugarLibre(Abonado* array,int limite)
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



int abonado_ordenar(Abonado* array,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    Abonado auxiliar;

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
}









































