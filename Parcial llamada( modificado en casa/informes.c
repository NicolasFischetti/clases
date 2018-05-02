#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "abonado.h"
#include "llamada.h"
#include "informes.h"


int abonadoConMasReclamos(Llamada* arrayLlamadas,int limiteLlamadas,Abonado* arrayAbonados, int limiteAbonado)
{
    int i;
    int flagSwap;
    Abonado resultado[limiteAbonado];
    int cantidadLlamadas[limiteAbonado];

    Abonado auxiliarAbonado;
    int auxiliarCantidadLlamadas;

    // Limpiamos la cantidad de llamadas para empezar a funcionar
    for (i=0;i<limiteAbonado;i++)
        cantidadLlamadas[i] = 0;

    // Recorremos las llamadas para computarlas en los abonados
    for (i=0;i<limiteLlamadas;i++) {
        if(arrayLlamadas[i].isEmpty == 0)
        cantidadLlamadas[arrayLlamadas[i].idAbonado]++;
    }

    // Copiamos el array original de Abonados sobre el de Resultados, para aplicar sobre este ultimo la burbuja
    for(i=0; i<limiteAbonado;i++) {
        resultado[i] = arrayAbonados[i];
    }

    // Aplicamos el metodo de la burbuja sobre el array de Resultado
    do
    {
        flagSwap = 0;
        for(i=0;i<limiteAbonado-1;i++)
        {
            if(resultado[i].isEmpty == OCUPADO && resultado[i+1].isEmpty == OCUPADO )
            {
                if(cantidadLlamadas[i]< cantidadLlamadas[i+1])
                {
                    auxiliarAbonado = resultado[i];
                    resultado[i] = resultado[i+1];
                    resultado[i+1] = auxiliarAbonado;

                    auxiliarCantidadLlamadas = cantidadLlamadas[i];
                    cantidadLlamadas[i] = cantidadLlamadas[i+1];
                    cantidadLlamadas[i+1] = auxiliarCantidadLlamadas;

                    flagSwap = 1;
                }
            }
        }
    } while(flagSwap);

    // Mostramos el resultado del informe
    for(i=0;i<limiteAbonado;i++)
    {
        if(!resultado[i].isEmpty)
            printf("\n[DEBUG] %s - %s - %d - %d - %d - Cantidad de llamados: %d",resultado[i].nombre,resultado[i].apellido,resultado[i].numero,resultado[i].idAbonado,resultado[i].isEmpty, cantidadLlamadas[i]);
    }

    return 0;
}

int motivoConMasReclamos(Llamada* arrayLlamadas, int limiteLlamadas) {
    int i;
    int flagSwap;

    int resultado[CANTIDAD_TIPOS] = {FALLA_3G, FALLA_LTE, FALLA_EQUIPO};
    int cantidadLlamadas[CANTIDAD_TIPOS];

    int auxiliarResultado;
    int auxiliarCantidadLlamadas;

    // Limpiamos la cantidad de llamadas para empezar a funcionar
    for (i=0;i < CANTIDAD_TIPOS;i++)
        cantidadLlamadas[i] = 0;

    // Recorremos las llamadas para computarlas en los motivos
    for (i=0;i<limiteLlamadas;i++) {
        if(arrayLlamadas[i].isEmpty == 0)
            cantidadLlamadas[arrayLlamadas[i].idMotivo]++;
    }

    // Aplicamos el metodo de la burbuja sobre el array de Resultado
    do
    {
        flagSwap = 0;
        for(i=0; i < CANTIDAD_TIPOS - 1; i++)
        {
            if(cantidadLlamadas[i]< cantidadLlamadas[i+1])
            {
                auxiliarResultado = resultado[i];
                resultado[i] = resultado[i+1];
                resultado[i+1] = auxiliarResultado;

                auxiliarCantidadLlamadas = cantidadLlamadas[i];
                cantidadLlamadas[i] = cantidadLlamadas[i+1];
                cantidadLlamadas[i+1] = auxiliarCantidadLlamadas;

                flagSwap = 1;
            }
        }
    } while(flagSwap);

    // Mostramos que tiene mayor cantidad de llamados del informe
    printf("\n%d - Cantidad de llamados: %d",resultado[0], cantidadLlamadas[0]);

    return 0;
}

int promedioMotivoConMasReclamos(Llamada* arrayLlamadas ,int limiteLlamadas) {
    int i;
    int flagSwap;

    int resultado[CANTIDAD_TIPOS] = {FALLA_3G, FALLA_LTE, FALLA_EQUIPO};
    int cantidadLlamadas[CANTIDAD_TIPOS];
    int tiempoDeLlamadas[CANTIDAD_TIPOS];
    int promedioDeLlamadas[CANTIDAD_TIPOS];

    int auxiliarResultado;
    int auxiliarPromedioLlamadas;

    // Limpiamos la cantidad de llamadas para empezar a funcionar
    for (i=0;i < CANTIDAD_TIPOS;i++) {
        cantidadLlamadas[i] = 0;
        tiempoDeLlamadas[i] = 0;
        promedioDeLlamadas[i] = 0;
    }

    // Recorremos las llamadas para computarlas en los motivos
    for (i=0;i<limiteLlamadas;i++) {
        if(arrayLlamadas[i].isEmpty == 0) {
            cantidadLlamadas[arrayLlamadas[i].idMotivo]++;
            tiempoDeLlamadas[arrayLlamadas[i].idMotivo] += arrayLlamadas[i].tiempo;
        }
    }

    // Recorremos los tipos de llamada para calcular el promedio de tiempo
    for (i=0;i<CANTIDAD_TIPOS;i++) {
        promedioDeLlamadas[i] = tiempoDeLlamadas[i] / cantidadLlamadas[i];
    }

    // Aplicamos el metodo de la burbuja sobre el array de Resultado
    do
    {
        flagSwap = 0;
        for(i=0; i < CANTIDAD_TIPOS - 1; i++)
        {
            if(promedioDeLlamadas[i]< promedioDeLlamadas[i+1])
            {
                auxiliarResultado = resultado[i];
                resultado[i] = resultado[i+1];
                resultado[i+1] = auxiliarResultado;

                auxiliarPromedioLlamadas = promedioDeLlamadas[i];
                promedioDeLlamadas[i] = promedioDeLlamadas[i+1];
                promedioDeLlamadas[i+1] = auxiliarPromedioLlamadas;

                flagSwap = 1;
            }
        }
    } while(flagSwap);

    // Mostramos el resultado del informe
    for(i=0;i<CANTIDAD_TIPOS;i++)
        printf("\n%d - Promedio de tiempo llamados: %d minutos", resultado[i], promedioDeLlamadas[i]);

    return 0;
}

