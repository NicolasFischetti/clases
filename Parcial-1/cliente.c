#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "biblioteca.h"

//Funciones privadas
static int proximoId(void);
static int buscarLugarLibre(Cliente* array,int limite);
//__________________

/** \brief
 * \param array Cliente*
 * \param limite int
 * \return int
 *
 */
int cliente_init(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}

int cliente_mostrar(Cliente* array,int limite)
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
                printf("%d - %s - %s - %s\n",array[i].idCliente, array[i].nombre, array[i].apellido, array[i].cuit);
            }
        }
    }
    return retorno;
}

int cliente_alta(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    char nombre[50];
    char apellido[50];
    char cuit[30];
    int tipo;
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidString("\nIngrese el nombre: ","\nEso no es un nombre\n","\nEl maximo es 50\n",nombre,50,2))
            {
                if(!getValidString("\nIngrese el apellido: ","\nEso no es un apellido\n","\nEl maximo es 50\n",apellido,50,2))
                {
                    getString("\nIngrese el cuit: ",cuit);
                    retorno = 0;
                    strcpy(array[i].nombre,nombre);
                    strcpy(array[i].apellido,apellido);
                    strcpy(array[i].cuit,cuit);
                    array[i].idCliente = proximoId();
                    array[i].isEmpty = 0;
                }
            }
            else
            {
                retorno = -3;
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}


int cliente_baja(Cliente* array,int limite, int id)
{
    int indiceAEliminar;
    int retorno=-1;
    indiceAEliminar = cliente_buscarPorId(array,limite,id);
    if(indiceAEliminar>=0)
    {
        array[indiceAEliminar].isEmpty=1;
        retorno=0;
    }
    return retorno;
}

int cliente_modificacion(Cliente* array,int limite, int id)
{
    int retorno = -1;
    int indiceAModificar;
    char nombre[50];
    char apellido[50];
    char cuit[30];

    indiceAModificar = cliente_buscarPorId(array,limite,id);
    if(indiceAModificar>=0)
    {
        if(!getValidString("\nIngrese el nombre: ","\nEso no es un nombre\n","\nEl maximo es 50\n",nombre,50,2))
        {
            if(!getValidString("\nIngrese el apellido: ","\nEso no es un apellido\n","\nEl maximo es 50\n",apellido,50,2))
            {
                if(!getValidCuilt("\nIngrese el cuit: ","\nEso no es un cuit\n",cuit,30,2))
                {
                    retorno = 0;
                    strcpy(array[indiceAModificar].nombre,nombre);
                    strcpy(array[indiceAModificar].apellido,apellido);
                    strcpy(array[indiceAModificar].cuit,cuit);
                }
            }
        }
        else
        {
            retorno = -3;
        }
    }
    return retorno;
}

int cliente_ordenar(Cliente* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Cliente auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && !orden)) //******
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

static int buscarLugarLibre(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



static int proximoId(void)
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}


int cliente_buscarPorId(Cliente* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idCliente==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



int cliente_altaForzada(Cliente* array,int limite,char* nombre,char* apellido, char* cuit)
{
    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(array[i].nombre,nombre);
            strcpy(array[i].apellido,apellido);
            strcpy(array[i].cuit,cuit);
            array[i].idCliente = proximoId();
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}








