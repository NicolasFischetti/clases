#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eusuario.h"
#include "utn.h"

static int buscarLugarLibre(eUsuario* array,int tam);
static int proximoId();

int usuario_init(eUsuario* array,int tam)
{
    int retorno = -1;
    int i;
    if(tam > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<tam;i++)
        {
            array[i].isEmpty = 0;
        }
    }
    return retorno;
}

static int buscarLugarLibre(eUsuario* array,int tam)
{
    int retorno = -1;
    int i;
    if(tam > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<tam;i++)
        {
            if(array[i].isEmpty == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int usuario_alta(eUsuario* array,int tam)
{
    int retorno = -1;
    char nombre[50];
    char apellido[50];
    char password[50];
    int id;
    int indice;
     indice = buscarLugarLibre(array,tam);
    if(tam > 0 && array != NULL)
    {
        retorno = -2;

        if(indice >= 0)
        {
             id = proximoId();
            retorno = -3;
            if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))
            {
                if(!getValidString("Apellido?","Error","Overflow", apellido,50,2))
                {
                    if(!getValidPassword("Password?","Error",password,50,2))
                    {
                        retorno = 0;

                        strcpy(array[indice].nombre,nombre);
                        strcpy(array[indice].apellido,apellido);
                         strcpy(array[indice].password,password);

                        array[indice].idUsuario = id;
                        array[indice].isEmpty = 1;
                    }
                }
            }
        }
    }
    return retorno;
}

int usuario_modificacion(eUsuario* array,int tam, int id)
{
    int retorno = -1;
    int indice;
    char nombre[50];
    char apellido[50];
    char password[50];

    indice = usuario_buscarPorId(array,tam,id);
    if(indice >= 0)
    {
        retorno = -2;

        if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))
            {
                if(!getValidString("Apellido?","Error","Overflow", apellido,50,2))
                {
                    if(!getValidPassword("password?","Error", password,50,2))
                    {
                    retorno = 0;

                    strcpy(array[indice].nombre,nombre);
                    strcpy(array[indice].apellido,apellido);
                    strcpy(array[indice].password,password);
                }
            }
    }
    return retorno;
    }
}

int usuario_baja(eUsuario* array,int tam, int id)
{

    int retorno = -1;
    int indice;
    indice = usuario_buscarPorId(array,tam,id);
    if(indice >= 0)
    {
        retorno = 0;
        array[indice].isEmpty = 0;
    }
    return retorno;
}

int usuario_mostrar(eUsuario* array,int tam)
{
    int retorno = -1;
    int i;
    if(tam > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<tam;i++)
        {
            if(array[i].isEmpty == 1)
            {
               printf("\n %s - %s - %d - %d",array[i].nombre,array[i].apellido,array[i].idUsuario,array[i].isEmpty);
            }
        }
    }
    return retorno;

    }

    int usuario_ordenar(eUsuario* array,int tam, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    eUsuario auxiliar;

    if(tam > 0 && array != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<tam-1;i++)
            {
                    if(array[i].isEmpty == 1 && array[i+1].isEmpty == 1 )
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
int usuario_buscarPorId(eUsuario* array,int ram, int id)
{
    int retorno = -1;
    int i;
    if(array > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<ram;i++)
        {
            if(array[i].isEmpty == 1 && array[i].idUsuario == id)
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
