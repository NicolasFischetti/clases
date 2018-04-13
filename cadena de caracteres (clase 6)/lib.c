#include <stdio.h>
#include <stdlib.h>


/** \brief Muestra un mensaje pidiendo un entero, analizando la cantidad de intentos que quieras, y el rango
 *
 * \param char* mensaje mensaje que muestra para pedir el entero
 * \param char* error mensaje que muestra al no respetar lo pedido
 * \param int intentos cantidad de veces que puede intentarlo
 * \param int maximo numero entero maximo a ingresar
 * \param int minimo numero entero minimo a ingresar
 * \param int* resultado devuelve el numero entero ingresado y valido
 * \return int -2 overflow negativo, -1 overflow positivo, 0 todo correcto
 *
 */
int getInt(char *mensaje, char *error, int intentos, int maximo, int minimo, int *resultado)
{
    int auxiliarEntero;
    int retorno = -1;

    do
    {
        intentos--;
        printf("%s \n", mensaje);
        scanf("%d", &auxiliarEntero);
        if(auxiliarEntero >= minimo && auxiliarEntero <= maximo)
        {
            retorno = 0;
            *resultado = auxiliarEntero;
            break;
        }
        else
        {
            if(auxiliarEntero < minimo)
            {
                retorno = -2;
            }
            else
            {
                retorno = -1;
            }
        }
        printf("%s", error);
    }while(intentos >= 0);

    return retorno;
}

/** \brief Muestra un mensaje pidiendo un flotante, analizando la cantidad de intentos que quieras, y el rango
 *
 * \param char* mensaje mensaje que muestra para pedir el flotante
 * \param char* error mensaje que muestra al no respetar lo pedido
 * \param int intentos cantidad de veces que puede intentarlo
 * \param float maximo numero flotante maximo a ingresar
 * \param float minimo numero flotante minimo a ingresar
 * \param float* resultado devuelve el numero flotante ingresado y valido
 * \return int -2 overflow negativo, -1 overflow positivo, 0 todo correcto
 *
 */
float getFloat(char *mensaje, char *error, int intentos, float maximo, float minimo, float *resultado)
{
    int auxiliarFlotante;
    int retorno = -1;
    do
    {
        intentos--;
        printf("%s \n", mensaje);
        scanf("%d \n", &auxiliarFlotante);
        if(auxiliarFlotante >= minimo && auxiliarFlotante <= maximo)
        {
            retorno = 0;
            *resultado = auxiliarFlotante;
            break;
        }
        else
        {
            if(auxiliarFlotante < minimo)
            {
                retorno = -2;
            }
            else
            {
                retorno = -1;
            }
        }
        printf("%s", error);
    }while(intentos >= 0);
}

int mostrarArrayInt(int* array, int cantidad)
{
    int retorno = -1;
    int i;
    if (cantidad > 0)
    {
        retorno = 0;
        for (i=0;i<cantidad;i++)
        {
            printf("\n%d",array[i]);
        }
    }
    return retorno;
}
int ordenarArrayInt(int* array, int cantidad, int orden)
{
    int retorno = -1;
    int i,j;
    int auxiliar;
    if(cantidad > 0)
    {
        retorno = 0;
        for(i=0;i<cantidad-1;i++)
        {
            for(j=i+1;j<cantidad;j++)
            {
                if(array[i] > array[j] && orden == 0)
                {
                    auxiliar = array[j];
                    array[j] = array[i];
                    array[i] = auxiliar;
                }
                else if(array[i] < array[j] && orden == 1)
                {
                    auxiliar = array[j];
                    array[j] = array[i];
                    array[i] = auxiliar;
                }

            }
        }
    }
    return retorno;
}
int ordenarArrayIntMejorado(int* array, int cantidad, int orden)
{
    int auxiliar;
    int  i;
    int flagSwap;

        do
        {
            flagSwap =0;
            for(i=0;i<cantidad-1;i++)
            {
               if(array[i] > array[j] && orden == 0) || (array[i] < array[j] && orden == 1)
                {
                    auxiliar = array[j];
                    array[j] = array[i];
                    array[i] = auxiliar;
                    flagSwap= 1;
                }
            }
        }while (flagSwap);
}
int desplazarArray (int *array, int cantidad, int derecha, int izquierda, int orden)
{

    int a, b, i;
    int auxiliar;
    int retorno = -1;
    int flag = 1;
    //verificar que A no sea menor a 0
    // relacion entre A y b, B NO puede ser mas grande que el array (4), b puede ser igual a A.

        for (i = a-1; i < b; i++)
        {
            flag = 1;
            array[a]=array[a+1];
            array[a+1]=auxiliar;

            for (i = b+1; i > a; i--)
            {
                array[b] = array[b-1];
                array[b-1]= auxiliar;
            }


            if(array[a] < 0 || array[b] > 4)
            {
                flag = 0;
            }
        }
    }

int convertirNumeroEnteros(char *str)
{
    int i = 0;
    while (str[i] != 0) // '\0' con comillas
        if(str[i] > '9' || str [i] < '0')
        {
            return 0;
            i++;
        }
        return 1;
}

    int atoi (const char *str)
    {
        char str[CARACTERES];
        int numeroAuxiliar;
        printf("Ingrese su numero\n");
        gets(str);
        numeroAuxiliar= atoi(str);
        if (numeroAuxiliar > 0 && numeroAuxiliar < 4096)
        printf("Valor del string: %s, Valor del entero %d",str, numeroAuxiliar);
        return 0;
    }

    double atof(const char *str)
    {
        float numeroauxiliar;
        char str[MAXIMO_NUM];
        printf("Ingrese su numero\n");
        gets(str);
        numeroauxiliar = atof(str);
        printf("El valor del string es = %s, el valor del float es= %.2f\n", str, numeroauxiliar);
        return(0);
    }

    int ordenarArrays()
