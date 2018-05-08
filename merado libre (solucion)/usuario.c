#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "usuario.h"
#include "utn.h"


static int proximoId();
static int buscarLugarLibre(Usuario* array,int limite);

/** \brief
 * \param array Usuario*
 * \param limite int
 * \return int
 *
 */
int usuario_init(Usuario* array,int limite)
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

int usuario_mostrarDebug(Usuario* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("[DEBUG] - %d", array[i].idUsuario);
        }
    }
    return retorno;
}

int usuario_mostrar(Usuario* array,int limite)
{
    int retorno = -1;
    int i;
    float promedio;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
            {
                if(array[i].cantidadVentas!=0)
                {
                    promedio = array[i].calificacionAcum/(float)array[i].cantidadVentas;
                }
                else
                {
                    promedio=0;
                }
                printf("Nombre: %s - Calificacion: %g \n", array[i].nombre, promedio);
            }

        }
    }
    return retorno;
}

int usuario_alta(Usuario* array,int limite)
{
    int retorno = -1;
    int i;
    char nombre[50];
    char pass[50];
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",nombre,40,2))
            {
                if(!getValidString("\nPass? ","\nEso no es una pass","El maximo es 40",pass,40,2))
                {
                    retorno = 0;
                    strcpy(array[i].nombre,nombre);
                    strcpy(array[i].pass,pass);
                    array[i].calificacionAcum = 0;
                    array[i].cantidadVentas = 0;
                                        //------------------------------
                                        //------------------------------
                    array[i].idUsuario = proximoId();
                    array[i].isEmpty = 0;
                }
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
    return retorno;
}


int usuario_baja(Usuario* array,int limite, int id)
{
    int retorno = 0;
    int indiceAEliminar = usuario_buscarPorId(array, limite, id);
    if(indiceAEliminar>0)
    {
        array[indiceAEliminar].isEmpty = 1;
    }
    else
    {
        retorno=indiceAEliminar;
    }
    return retorno;
}




int usuario_modificacion(Usuario* array,int limite, int id)
{
    int retorno = -1;
    int indiceAModificar;
    char nombre[50];
    char pass[50];
    indiceAModificar = usuario_buscarPorId(array, limite, id);
    if(indiceAModificar>=0)
    {
        if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",nombre,40,2))
        {
            strcpy(array[indiceAModificar].nombre,nombre);
            if(!getValidString("\nPass? ","\nEso no es una pass","El maximo es 40",pass,40,2))
            {
                retorno=0;
                strcpy(array[indiceAModificar].pass, pass);
            }
            else
            {
                retorno=-3;
            }
        }
        else
        {
            retorno = -2;
        }
    }
    return retorno;
}

int usuario_ordenar(Usuario* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Usuario auxiliarEstructura;

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

static int buscarLugarLibre(Usuario* array,int limite)
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


static int proximoId()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}


int usuario_buscarPorId(Usuario* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idUsuario==id)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int usuario_altaForzada(Usuario* array,int limite,char* nombre,char* pass)
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
            strcpy(array[i].pass,pass);
            array[i].calificacionAcum = 0;
            array[i].cantidadVentas = 0;
            //------------------------------
            //------------------------------
            array[i].idUsuario = proximoId();
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}
