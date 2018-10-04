#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "biblioteca.h"
#include "publicacion.h"


/** \brief Imprime la cantidad de rubros de una publicacion
 *
 * \param arrayP Publicacion* Estructura pasada por referencia
 * \param limite int Longitud de la estructura
 * \param rubro int Numero del rubro pasado por referencia
 * \return int 0 Si encontro el numero de rubro y -1 si no fue asi
 *
 */
int cantidadRubros(Publicacion *arrayP, int limite, int rubro)
{
    int i;
    int retorno=-1;
    int cantPublicaciones=0;

    if(limite > 0 && arrayP != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(rubro==arrayP[i].rubro)
            {
                retorno=0;
                cantPublicaciones++;
            }
        }
        printf("\nLa cantidad de publicaciones del rubro es: %d",cantPublicaciones);
    }
    return retorno;
}

int rubroConMasPublicaciones(Publicacion *arrayP, int limite, int rubro)
{
    int i;
    int retorno=-1;
    return retorno;
}
int rubroConMenosPublicaciones(Publicacion *arrayP, int limite, int rubro)
{
    int i;
    int retorno=-1;
    return retorno;
}
