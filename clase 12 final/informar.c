#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Contratacion.h"
#include "utn.h"
#include "Pantalla.h"


int informar_ConsultaFacturacion(Contratacion* arrayC,int limiteC,
              Pantalla* arrayP, int limiteP, char* cuit)
{
    //Se deberá ingresar el cuit del cliente y
    //listar el importe a pagar por cada contratación.
    int retorno = -1;
    int i;
    int indexPantalla;

    if(arrayC != NULL && arrayP != NULL && limiteC > 0 && limiteP > 0)
    {
        retorno = -2;
        for(i=0;i<limiteC;i++)
        {
            if(!arrayC[i].isEmpty && !strcmp(arrayC[i].cuit,cuit))
            {
                indexPantalla = pantalla_buscarPorId(arrayP,limiteP,arrayC[i].idPantalla);
                printf("\nID: %d - Valor: %.2f",

                       arrayC[i].id,
                       arrayC[i].dias*arrayP[indexPantalla].precio);
                retorno = 0;
            }
        }
    }

    return retorno;
}



int informar_ListarContrataciones(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;

    return retorno;
}


int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limiteC,
              Pantalla* arrayP, int limiteP)
{
    /*Lista de cada cliente con cantidad de contrataciones e importe
    a pagar por cada una.
    */


    int retorno = -1;
    int i;
    int indexPantalla;
    char ultimoCuit[50]="-";
    if(arrayC != NULL && arrayP != NULL && limiteC > 0 && limiteP > 0)
    {
        retorno = -2;
        cont_ordenarCuit(arrayC,limiteC,0);
        for(i=0;i<limiteC;i++)
        {
            if(!arrayC[i].isEmpty && strcmp(arrayC[i].cuit,ultimoCuit) != 0)
            {
                strcpy(ultimoCuit,arrayC[i].cuit);

                printf("\n\nINFO DEL CUIT - %s -",ultimoCuit);
                informar_ConsultaFacturacionTotal(arrayC,limiteC,arrayP,limiteP,ultimoCuit);
            }
        }
    }

    return retorno;
}


int informar_ConsultaFacturacionTotal(Contratacion* arrayC,int limiteC,
              Pantalla* arrayP, int limiteP, char* cuit)
{
    //Se deberá ingresar el cuit del cliente y
    //listar el importe a pagar por cada contratación.
    int retorno = -1;
    int i;
    int indexPantalla;
    int contador=0;
    float acumulador=0;

    if(arrayC != NULL && arrayP != NULL && limiteC > 0 && limiteP > 0)
    {
        retorno = -2;
        for(i=0;i<limiteC;i++)
        {
            if(!arrayC[i].isEmpty && !strcmp(arrayC[i].cuit,cuit))
            {
                indexPantalla = pantalla_buscarPorId(arrayP,limiteP,arrayC[i].idPantalla);

                contador++;
                acumulador += arrayC[i].dias*arrayP[indexPantalla].precio;
                retorno = 0;
            }
        }
    }

    printf("\nCantidad contrataciones: %d - Total: %.2f",

                       contador,
                       acumulador);
    return retorno;
}
