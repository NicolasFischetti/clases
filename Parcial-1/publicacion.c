#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "publicacion.h"
#include "biblioteca.h"
#include "cliente.h"
#define PAUSADA 0
#define ACTIVA 1

//Funciones privadas
static int proximoId(void);
static int buscarPorId(Publicacion* array,int limite, int id);
static int buscarLugarLibre(Publicacion* array,int limite);
//__________________

int publ_init(Publicacion* array,int limite)
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

int publ_mostrar(Publicacion* array,int limite)
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
                printf("%d - %d - %s - %d - %s - %d\n",array[i].idPublicacion, array[i].idCliente,array[i].cuit,array[i].rubro,array[i].aviso,array[i].estado);
            }
        }
    }
    return retorno;
}
int publ_pausar(Publicacion* array,int limite, int id)
{
    int retorno = -1;
    int indiceAModificar;
    char confirmacion;

    indiceAModificar = buscarPorId(array,limite,id);
    if(indiceAModificar>=0)
    {
        printf("\nDesea cambiar el estado de la publicacion? Ingrese S para SI y N para NO: \n");
        fflush(stdin);
        scanf("%c",&confirmacion);
        if(confirmacion!='n' && confirmacion=='s')
        {
            retorno = 0;
            array[indiceAModificar].estado=PAUSADA;
        }
    }
    return retorno;
}
int publ_reanudar(Publicacion* array,int limite, int id)
{
    int retorno = -1;
    int indiceAModificar;
    char confirmacion;

    indiceAModificar = buscarPorId(array,limite,id);
    if(indiceAModificar>=0)
    {
        printf("\nDesea cambiar el estado de la publicacion? Ingrese S para SI y N para NO: \n");
        fflush(stdin);
        scanf("%c",&confirmacion);
        if(confirmacion!='n')
        {
            retorno = 0;
            array[indiceAModificar].estado=ACTIVA;
        }
    }
    return retorno;
}
int publ_alta(Publicacion* arrayP,int limite,
              Cliente* clientes, int lenClientes)
{
    int retorno = -1;
    int i;
    char aviso[50];
    int idCliente;
    int posCliente;
    int rubro;

    if(limite > 0 && arrayP != NULL)
    {
        i = buscarLugarLibre(arrayP,limite);
        if(i >= 0)
        {
            getValidInt("\nIngrese el ID: ","\nNumero no valido\n",&idCliente,0,999999,2);
            posCliente = cliente_buscarPorId(clientes,lenClientes,idCliente);
            if(posCliente>=0)
            {
                getValidInt("\nIngrese el numero de rubro: ","\nNumero no valido\n",&rubro,0,200,2);
                getValidString("\nIngrese el texto del aviso: ","\nTexto no valido\n","\nEl maximo es 50\n",aviso,64,2);
                arrayP[i].rubro = rubro;
                arrayP[i].idCliente = idCliente;
                strcpy(arrayP[i].cuit,clientes[posCliente].cuit);
                strcpy(arrayP[i].aviso,aviso);
                arrayP[i].isEmpty=0;
                arrayP[i].idPublicacion = proximoId();
                arrayP[i].estado = ACTIVA;
            }
        }
        else
        {
            retorno = -2;
        }
    }
    return retorno;
}

static int buscarLugarLibre(Publicacion* array,int limite)
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


static int buscarPorId(Publicacion* array,int limite, int id)
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

int publ_altaForzada(Publicacion* arrayP,int limite,
              Cliente* clientes, int lenClientes,
              int idCliente,int rubro,char* aviso)
{
    int retorno = -1;
    int i;
    int posCliente;
    if(limite > 0 && arrayP != NULL)
    {
        i = buscarLugarLibre(arrayP,limite);
        if(i >= 0)
        {
            posCliente = cliente_buscarPorId(clientes,lenClientes,idCliente);
            if(posCliente>=0)
            {
                arrayP[i].rubro = rubro;
                strcpy(arrayP[i].aviso,aviso);
                arrayP[i].idCliente = idCliente;
                strcpy(arrayP[i].cuit,clientes[posCliente].cuit);
                arrayP[i].isEmpty=0;
                arrayP[i].estado=ACTIVA;
                arrayP[i].idPublicacion = proximoId();
            }
        }
        retorno = 0;
    }
    return retorno;
}









