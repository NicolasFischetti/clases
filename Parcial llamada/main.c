#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "abonado.h"
#include "llamada.h"
#include "informes.h"
#include "utn.h"
#define QTY 100
#define QTY_LLAMADAS 1000

int main()
{
    Abonado array[QTY];
    Llamada arrayLlamadas[QTY];
    int menu;
    int auxiliarId;

    abonado_init(array,QTY);
    llamada_init(arrayLlamadas,QTY_LLAMADAS);
    do
    {
        getValidInt("\n1.Alta Abonado\n2.Baja Abonado\n3.Modificar Abonado\n4.Mostrar Abonado\n5.Ordenar\n6.Mostrar Llamada\n7.Nueva Llamada\n7.Fin Llamada\n9.Salir\n","\nNo valida\n",&menu,1,9,1);
        switch(menu)
        {
            case 1:
                abonado_alta(array,QTY);
                break;
            case 2:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                abonado_baja(array,QTY,auxiliarId);
                break;
            case 3:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                abonado_modificacion(array,QTY,auxiliarId);
                break;
            case 4:
                abonado_mostrar(array,QTY);
                break;
            case 5:
                abonado_ordenar(array,QTY,0);
                break;
            case 6:
                llamada_mostrar(arrayLlamadas,QTY_LLAMADAS);
                break;
            case 7:
                llamada_alta(arrayLlamadas,QTY_LLAMADAS);
                break;
            case 8:
                getValidInt("ID LLAMADA?","\nNumero valida\n",&auxiliarId,0,200,2);
                llamada_modificacion(arrayLlamadas,QTY_LLAMADAS,auxiliarId);
                break;
        }

    }while(menu != 9);

    return 0;
}
