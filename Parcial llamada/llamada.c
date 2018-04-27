#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llamada.h"
#include "utn.h"
#define QTY 10
#define OCUPADO 0
#define LIBRE 1

#define EN_CURSO 0
#define SOLUCIONADO 1
#define NO_SOLUCIONADO 2

static int buscarLugarLibre(Llamada* array,int limite);
static int proximoId();


int llamada_init(Llamada* array,int limite)
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





int llamada_mostrar(Llamada* array,int limite)
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
               printf("\n[RELEASE] %d - %d - %d - %d- %d - %d",array[i].idAbonado,array[i].idEstado,array[i].idMotivo,array[i].tiempo,array[i].idLlamada,array[i].isEmpty);
            }
        }
    }
    return retorno;
}

int llamada_mostrarDebug(Llamada* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
               printf("\n[DEBUG] %d - %d - %d - %d- %d - %d",array[i].idAbonado,array[i].idEstado,array[i].idMotivo,array[i].tiempo,array[i].idLlamada,array[i].isEmpty);
        }
    }
    return retorno;
}



int llamada_alta(Llamada* array,int limite)
{
    int retorno = -1;
    int idAbonado;
    int idMotivo;
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
            if(!getValidInt("Id Abonado?","Error",&idAbonado,0,1000,2))
            {
                if(!getValidInt("Motivo?","Error",&idMotivo,0,1000,2))
                {

                    retorno = 0;
                    array[indice].idAbonado = idAbonado;
                    array[indice].idEstado = EN_CURSO ;
                    array[indice].idMotivo = idMotivo;
                    array[indice].tiempo = -1;

                    array[indice].idLlamada = id;
                    array[indice].isEmpty = OCUPADO;

                }
            }
        }
    }
    return retorno;
}





int llamada_buscarPorId(Llamada* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == OCUPADO && array[i].idLlamada == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


int llamada_baja(Llamada* array,int limite, int id)
{

    int retorno = -1;
    int indice;
    indice = llamada_buscarPorId(array,limite,id);
    if(indice >= 0)
    {
        retorno = 0;
        array[indice].isEmpty = LIBRE;
    }
    return retorno;
}


int llamada_modificacion(Llamada* array,int limite, int id)
{
    int retorno = -1;
    int indice;
    int rtaEstado;
    int tiempo;
    indice = llamada_buscarPorId(array,limite,id);
    if(indice >= 0)
    {
        retorno = -2;
        if(!getValidInt("Solucionado [0] / NO Solucionado [1]?","Error",&rtaEstado,0,1000,2))
        {
            if(!getValidInt("Tiempo?","Error",&tiempo,0,1000,2))
            {
                retorno = 0;
                if(rtaEstado == 0)
                    array[indice].idEstado = SOLUCIONADO ;
                else
                    array[indice].idEstado = NO_SOLUCIONADO ;

                array[indice].tiempo = tiempo;
                array[indice].idLlamada = id;
                array[indice].isEmpty = OCUPADO;
            }
        }
    }
    return retorno;
}



static int buscarLugarLibre(Llamada* array,int limite)
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



int llamada_ordenar(Llamada* array,int limite, int orden)
{
    int retorno = -1;
 /*   int flagSwap;
    int i;
    Llamada auxiliar;

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
*/
    return retorno;
}









































