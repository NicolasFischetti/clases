#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "abonado.h"
#include "llamada.h"
#include "informes.h"


int abonadoConMasReclamos(Llamada* arrayLlamadas,int limiteLlamadas,Abonado* arrayAbonados, int limiteAbonado)
{
	char rcla_abonadoNombre;
	char rcla_AbonadoApellido;
	int proximoReclamo;
	int adAbonado;
	retorno = -1;
	proxReclamo = proximoReclamo();

	if (limiteLlamadas > 0 || limiteLlamadas < 10) && (limiteAbonado > 0 || limiteAbonado < 10 ) 
			retorno= -2

			 arrayAbonados[limiteAbonado].nombre = rcla_abonadoNombre;
			strcpy(array[limiteAbonado].nombre,nombre);
			 arrayAbonados[limiteAbonado].apellido = rcla_AbonadoApellido;
            strcpy(array[limiteAbonado].apellido,apellido);
			arrayLlamadas[limiteLlamadas].idAbonado = proxReclamo;

			printf("\n %d - %s - %s ", arrayLlamadas[limiteLlamadas].idAbonado, arrayAbonados[limiteAbonados].nombre, arrayAbonados[limiteAbonado].apellido);
    return 0;
}

int proximoReclamo()
{
     int proxReclamo = -1;
    proxReclamo++;
    return proxReclamo;
})