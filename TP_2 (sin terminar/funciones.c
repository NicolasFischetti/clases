#include "funciones.h"
#define limitePersonas 20
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int abonado_init(EPersona* lista)
{
    int retorno = -1;
    int i;
    if(limitePersonas > 0 && lista != NULL)
    {
        retorno = 0;
        for(i=0;i<limitePersonas;i++)
        {
            lista[i].estado = 0;
        }
    }
    return retorno;
}

int obtenerEspacioLibre(EPersona lista[])
{
    int retorno = -1;
    int i;
    if(limitePersonas > 0 && lista != NULL)
    {
        retorno = -2;
        for(i=0;i<limitePersonas;i++)
        {
            if(lista[i].estado == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int buscarPorDni(EPersona lista[], int dni)
{
    int retorno = -1;
    int i;
    if(limitePersonas > 0 && lista != NULL)
    {
        retorno = -2;
        for(i=0;i<limitePersonas;i++)
        {
            if(lista[i].estado == 1 && lista[i].dni == dni)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int persona_alta(EPersona* lista)
{
    int retorno = -1;
    char nombre[50];
    int dni;
    int edad;
    int indice;

    if(limitePersonas > 0 && lista != NULL)
    {
        retorno = -2;
        indice = obtenerEspacioLibre(lista);
        if(indice >= 0)
        {
            retorno = -3;
            if(!getValidString("Nombre?","Error","Nombre muy largo", nombre,50,2))
            {
                if(!getValidInt("Ingrese su edad","Error",&edad,0,100,2))
                {
                    if(!getValidInt("Ingrese su dni","Error",&dni,0, 1000000, 2))
                    {
                        retorno = 0;
                        strcpy(lista[indice].nombre,nombre);
                        lista[indice].dni = dni;
                        lista[indice].edad = edad;
                        lista[indice].estado = 1;
                    }
                }
            }
        }
    }
    return retorno;
}

int persona_eliminar(EPersona* lista, int dni)
{

    int retorno = -1;
    int indice;
    indice = buscarPorDni(lista,dni);
    if(indice >= 0)
    {
        retorno = 0;
        lista[indice].estado = 0;
    }
    return retorno;
}

int persona_ordenar(EPersona* lista, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    EPersona  auxiliarPersona;

    if(limitePersonas > 0 && lista != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limitePersonas-1;i++)
            {
                    if(lista[i].estado == 1 && lista[i+1].estado == 1 )
                    {
                        if((strcmp(lista[i].nombre,lista[i+1].nombre) > 0 && !orden) || (strcmp(lista[i].nombre,lista[i+1].nombre) < 0 && orden))
                        {
                            auxiliarPersona = lista[i];
                            lista[i] = lista[i+1];
                            lista[i+1] = auxiliarPersona;
                            flagSwap = 1;
                        }
                    }
            }
        }while(flagSwap);
    }

    return retorno;
}


int getValidString(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps)
{
    int i;
    int retorno=-1;
    char buffer[1024];

    for(i=0;i<attemps;i++)
    {
        if (!getStringLetras(requestMessage,buffer))
        {
            printf ("%s",errorMessage);
            continue;
        }
        if(strlen(buffer) >= maxLenght)
        {
            printf ("%s",errorMessageLenght);
            continue;

        }
        retorno=0;
        strcpy(input,buffer);
        break;
    }
    return retorno;
}

int getValidInt(char requestMessage[],char errorMessage[], int* input,int lowLimit, int hiLimit,int attemps)
{
    char auxStr[256];
    int auxInt, i, retorno = -1;

    for(i=0;i<attemps;i++)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s",errorMessage);
            break;
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("%s",errorMessage);
            continue;

        }
        *input = auxInt;
        retorno = 0;
        break;

    }
    return retorno;

}

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    clearStdin();
    scanf ("%[^\n]s", input);
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if (i == 0 && str[i] == '-')
       {
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;

       i++;
   }
   return 1;
}
