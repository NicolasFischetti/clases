#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "publicacion.h"
#include "usuario.h"
#include "utn.h"


static int proximoId();
static int buscarLugarLibre(Publicacion* array,int limite);

/** \brief
 * \param array Publicacion*
 * \param limite int
 * \return int
 *
 */
int publicacion_init(Publicacion* array,int limite)
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

int publicacion_mostrarDebug(Publicacion* array, Usuario* usuarios,int limite, int limite_usuarios)
{
    int i;
    int retorno=-1;
    int indiceUsuario;
    if(limite>0)
    {
        for(i=0;i<limite;i++)
        {
            retorno = 0;
            indiceUsuario = usuario_buscarPorId(usuarios, limite_usuarios, array[i].idUsuario);
            printf("\n\n");
            printf("ID:%d - Nombre: %s - Precio: %g - Vendidos: %d - Stock: %d - Usuario: %s\n", array[i].idPublicacion,
                       array[i].nombre, array[i].precio, array[i].cantidadVendida, array[i].stock,
                       usuarios[indiceUsuario].nombre);
        }
    }
    return retorno;
}

int publicacion_mostrarPorIdUsuario(Publicacion* array, int limite, int idUsuario)
{
    int i;
    int retorno=-1;
    if(limite>0)
    {
        for(i=0;i<limite;i++)
        {
            retorno = 0;
            if(!array[i].isEmpty && array[i].idUsuario==idUsuario)
            {
                printf("ID:%d - Nombre: %s - Precio: %g - Vendidos: %d - Stock: %d\n", array[i].idPublicacion,
                       array[i].nombre, array[i].precio, array[i].cantidadVendida, array[i].stock);
            }
        }
    }
    return retorno;
}

int publicacion_mostrar(Publicacion* array, Usuario* usuarios,int limite, int limite_usuarios)
{
    int i;
    int retorno=-1;
    int indiceUsuario;
    if(limite>0)
    {
        for(i=0;i<limite;i++)
        {
            retorno = 0;
            if(!array[i].isEmpty)
            {
                indiceUsuario = usuario_buscarPorId(usuarios, limite_usuarios, array[i].idUsuario);
                printf("ID:%d - Nombre: %s - Precio: %g - Vendidos: %d - Stock: %d - Usuario: %s\n", array[i].idPublicacion,
                       array[i].nombre, array[i].precio, array[i].cantidadVendida, array[i].stock,
                       usuarios[indiceUsuario].nombre);
            }
        }
    }
    return retorno;
}

int publicacion_alta(Publicacion* array, Usuario* usuarios,int limite, int limiteUsuarios)
{
    int retorno = -1;
    int i, stock, idUsuario;
    float precio;
    char nombre[50];
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidInt("\nId del usuario? ","\nEso no es un id",&idUsuario,0,1000,2))
            {
                if(usuario_buscarPorId(usuarios, limiteUsuarios, idUsuario)>=0)
                {
                    if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",nombre,40,2))
                    {
                        if(!getValidFloat("\nPrecio?", "\nEso no es un precio", &precio,0,1000000,2))
                        {
                            if(!getValidInt("\nStock?", "\nEso no es un stock", &stock,0,10000,2))
                            {
                                retorno = 0;
                                array[i].idUsuario = idUsuario;
                                strcpy(array[i].nombre,nombre);
                                array[i].precio = precio;
                                array[i].stock = stock;
                                array[i].cantidadVendida = 0;
                                                    //------------------------------
                                                    //------------------------------
                                array[i].idPublicacion = proximoId();
                                array[i].isEmpty = 0;

                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        retorno = -3;
    }
    return retorno;
}

int publicacion_bajaPorIdUsuario(Publicacion* array, int limite, int idUsuario)
{
    int retorno = 0;
    int i;
    for(i=0;i<limite;i++)
    {
        if(!array[i].isEmpty && array[i].idUsuario==idUsuario)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}

int publicacion_baja(Publicacion* array,int limite, int id)
{
    int retorno = 0;
    int indiceAEliminar = publicacion_buscarPorId(array, limite, id);
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




int publicacion_modificacion(Publicacion* array,int limite, int id)
{
    int retorno = -1;
    int indiceAModificar;
    float precio;
    int stock;
    indiceAModificar = publicacion_buscarPorId(array, limite, id);
    if(indiceAModificar>=0)
    {
        if(!getValidFloat("\nPrecio? ","\nEso no es un precio",&precio,0,100000,2))
        {
            if(!getValidInt("\nStock? ","\nEso no es un stock",&stock,0,1000,2))
            {
                retorno=0;
                array[indiceAModificar].precio = precio;
                array[indiceAModificar].stock = stock;
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

int publicacion_ordenar(Publicacion* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Publicacion auxiliarEstructura;

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


static int proximoId()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}


int publicacion_buscarPorId(Publicacion* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idPublicacion==id)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int publicacion_comprar(Publicacion* publicaciones, Usuario* usuarios, int limite_pub, int limite_user, int idPublicacion)
{
    int retorno=-1;
    int indiceAComprar, indiceUsuario;
    int calificacion;
    indiceAComprar = publicacion_buscarPorId(publicaciones, limite_pub, idPublicacion);
    if(indiceAComprar>=0)
    {
        if(publicaciones[indiceAComprar].stock>0)
        {
            if(!getValidInt("\nCalificacion", "No es una calificacion", &calificacion, 0, 10,1))
            {
                publicaciones[indiceAComprar].stock--;
                publicaciones[indiceAComprar].cantidadVendida++;
                indiceUsuario = usuario_buscarPorId(usuarios, limite_user, publicaciones[indiceAComprar].idUsuario);
                usuarios[indiceUsuario].calificacionAcum+=calificacion;
                usuarios[indiceUsuario].cantidadVentas++;
                retorno =0;
            }
        }
    }
    return retorno;
}

int publicacion_altaForzada(Publicacion* array,int limite,int idUsuario,char* nombre,float precio, int stock)
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
            array[i].idUsuario=idUsuario;
            array[i].precio = precio;
            array[i].stock = stock;
            array[i].cantidadVendida=0;
            //------------------------------
            //------------------------------
            array[i].idPublicacion = proximoId();
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}
