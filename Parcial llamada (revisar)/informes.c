#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "abonado.h"
#include "llamada.h"
#include "informes.h"

int abonadoConMasReclamos(Llamada* array,int limite)
{
	int indice = -1;
	indice = llamada_ordenar_id(Llamada* array,int limite);
	int Posicion_Con_Mas_llamadas;
	int Aux_ID = 0;
	int contador_de_llamadas = 1;
	int contador = 1;
	if(indice = 0)
        {
        	for(i=0;i<limite-1;i++)
            {
            	if(array[i].idLlamada == array[i+1].idLlamada)
            	{
            		contador_de_llamadas ++;
            		if(contador == 1 || contador_de_llamadas > contador)
            		{
            			contador = contador_de_llamadas;
            			Aux_ID = array[i].idLlamada;
            		}
            	}
            	else
            	{
            		contador_de_llamadas = 1;
            	}
            }
		}
	printf("\n[DEBUG] %s - %s - %d - %d - %d",array[Aux_ID].nombre,array[Aux_ID].apellido);  
	return array[Aux_ID].idLlamada;
}

int ReclamoMasRealizado(Llamada* array,int limite)
{
	int indice = -1;
	indice = llamada_ordenar_id(Llamada* array,int limite);
	int Aux_ID = 0;
	int contador_de_llamadas = 1;
	int contador = 1;
	if(indice = 0)
        {
        	for(i=0;i<limite-1;i++)
            {
            	if(array[i].idMotivo == array[i+1].idMotivo)
            	{
            		contador_de_llamadas ++;
            		if(contador == 1 || contador_de_llamadas > contador)
            		{
            			contador = contador_de_llamadas;
            			Aux_ID = array[i].idMotivo;
            		}
            	}
            	else
            	{
            		contador_de_llamadas = 1;
            	}
            }
		}
	printf("\n[DEBUG] %s - %s - %d - %d - %d",array[Aux_ID].idMotivo);  
	return array[Aux_ID].idMotivo;
}

int ReclamoMasTiempo(Llamada* array,int limite)
{
	int indice = -1;
	indice = llamada_ordenar_id(Llamada* array,int limite);
	int Aux_ID = 0;
	int contador_de_llamadas = 1;
	int contador = 1;

	int AUX_Tiempo_Total = 0;
	float promedio = 0;
	float promedio_maximo =0;
	if(indice = 0)
        {
        	for(i=0;i<limite-1;i++)
            {
            	if(array[i].idMotivo == array[i+1].idMotivo)
            	{
            		contador_de_llamadas ++;
            		AUX_Tiempo_Total = AUX_Tiempo_Total + array[i].tiempo + array[i+1].tiempo;
            		promedio = AUX_Tiempo_Total / contador_de_llamadas;
            		if (promedio_maximo = 0 || promedio_maximo < promedio)
            		{
            			promedio_maximo = promedio;
            			Aux_ID = array[i].idMotivo;
            		}
            	}
            	else
            	{
            		contador_de_llamadas = 1;
            		AUX_Tiempo_Total = 0;
            		if(array[i].idMotivo != array[i-1].idMotivo)
            		{
            			AUX_Tiempo_Total = AUX_Tiempo_Total + array[i].tiempo;
            			promedio = AUX_Tiempo_Total / contador_de_llamadas;
            			if (promedio_maximo = 0 || promedio_maximo < promedio)
            			{
            				promedio_maximo = promedio;
            				Aux_ID = array[i].idMotivo;
            				AUX_Tiempo_Total = 0;
            			}
            		}
            	}
            }
		}
	printf("\n[DEBUG] %s - %s - %d - %d - %d",array[Aux_ID].idMotivo);  
	return array[Aux_ID].idMotivo;
}