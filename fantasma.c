#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fantasma.h"
#include "utn.h"
#define QTY 10
#define OCUPADO 0
#define LIBRE 1


int fantasma_init(Fantasma* array,int limite)
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





int fantasma_mostrar(Fantasma* array,int limite)
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
               printf("\n[RELEASE] %s - %d - %d",array[i].nombre,array[i].idFantasma,array[i].isEmpty);
            }
        }
    }
    return retorno;
}

int fantasma_mostrarDebug(Fantasma* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("\n[DEBUG] %s - %d - %d",array[i].nombre,array[i].idFantasma,array[i].isEmpty);
        }
    }
    return retorno;
}



int fantasma_alta(Fantasma* array,int limite)
{
    int retorno = -1;
    char nombre[50];
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
                retorno = 0;
                strcpy(array[indice].nombre,nombre);
                array[indice].idFantasma = id;
                array[indice].isEmpty = OCUPADO;
            }
        }
    }
    return retorno;
}





int fantasma_buscarPorId(Fantasma* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == OCUPADO && array[i].idFantasma == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


int fantasma_baja(Fantasma* array,int limite, int id)
{

    int retorno = -1;
    int indice;
    indice = fantasma_buscarPorId(array,limite,id);
    if(indice >= 0)
    {
        retorno = 0;
        array[indice].isEmpty = LIBRE;
    }
    return retorno;
}


int fantasma_modificacion(Fantasma* array,int limite, int id)
{
    int retorno = -1;
    int indice;
    char nombre[50];
    indice = fantasma_buscarPorId(array,limite,id);
    if(indice >= 0)
    {
        retorno = -2;
        if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))
        {
            retorno = 0;
            strcpy(array[indice].nombre,nombre);
        }


    }
    return retorno;
}



int buscarLugarLibre(Fantasma* array,int limite)
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


int proximoId()
{
    static int ultimoId = -1;
    ultimoId++;
    return ultimoId;
}



int fantasma_ordenar(Fantasma* array,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    Fantasma auxiliar;

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









































