#include "estrcutraempleado.h"
#define CANT 5

int emp_init(Empleado* arrayEmpleados,int sizeArray)
{
    int i;
    for (i=0; i < CANT; i++)
    {
        arrayEmpleado[i].isEmpty= 1;
    }
    return 0;
}
int emp_mostrar(Empleado* arrayEmpleados,int sizeArray)
{
    int i;
    for (i=0; i < CANT; i++)
    {
       if (arrayEmpleado[i].isEmpty)
    }
}
int emp_alta(Empleado* arrayEmpleados,int sizeArray,int id)
{
    int i;
    int posicion= buscarLibre(arrayEmpleado, CANT);

        if (buscarLibre!=1)
        {
            printf("Ingrese su nombre\n"
            scanf("%s", Empleado[posicion].nombre);
            printf("Ingrese su apellido\n"
            scanf("%s", Empleado[posicion].apellido);
        }
    }
}
int emp_baja(Empleado* arrayEmpleados,int sizeArray,int id)
{
        printf("Ingrese su id: %d", Empleado[i].idEmpleado);
}
int buscarLibre(Empleado* arrayEmpleados,int sizeArray)
{
    int posLibre = -1;
    int i;

    for(i=0, i < CANT, i++)
    {
        if (Empleado.isEmpty[i]=1)
        {
            posLibre= 1
            break;
        }
    }
    return i;
}

// Luego hay que ordenarlos por nombre


/*#include "empleado.h"
#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
void emp_init(Empleado* arrayEmpleados,int sizeArray)
{
    int i;
    for(i = 0; i < sizeArray; i++)
    {
        arrayEmpleados[i].isEmpty = 0;
    }
}
int emp_alta(Empleado *arrayEmpleados,int sizeArray,int id)
{
    int empty;
    empty = buscarLibre(arrayEmpleados, sizeArray);
    if(empty >= 0)
    {
        do
        {
            getString("Ingrese su nombre\n", arrayEmpleados[empty].nombre);
        }while(esString(arrayEmpleados[empty].nombre) != 0);
        do
        {
            getString("Ingrese su apellido\n", arrayEmpleados[empty].apellido);
        }while(esString(arrayEmpleados[empty].apellido) != 0);
            arrayEmpleados[empty].idEmpleado = id;
            arrayEmpleados[empty].isEmpty = 1;
    }
    else
        printf("No hay lugar");
}
int emp_mostrar(Empleado* arrayEmpleados,int sizeArray)
{
    int i;
    for(i = 0; i < sizeArray; i++)
    {
        if(arrayEmpleados[i].isEmpty != 0)
        {
            printf("Nombre %s ", arrayEmpleados[i].nombre);
            printf("Apellido %s ", arrayEmpleados[i].apellido);
            printf("ID %d \n", arrayEmpleados[i].idEmpleado);
        }
    }
}
int emp_baja(Empleado* arrayEmpleados,int sizeArray)
{
    int idobtenido;
    int i;
    int retorno = -1;
    getInt("Ingrese el Id \n", "Id no valido \n", 3, 10000, 0, &idobtenido);
    for(i = 0; i < sizeArray; i++)
    {
        if(arrayEmpleados[i].idEmpleado == idobtenido)
        {
            retorno = 0;
            arrayEmpleados[i].isEmpty = 0;
            break;
        }
    }
    return retorno;
}
int emp_ordenar(Empleado* arrayEmpleados, int sizeArray)
{
	Empleado auxiliar[50];
    int j, i;
	for(i = 1; i < sizeArray; i++)
    {
        if(arrayEmpleados[i].isEmpty == 1)
        {
            auxiliar[i] = arrayEmpleados[i];
            j = i;
            while(j > 0 && strcmp(auxiliar[i].apellido, arrayEmpleados[j - 1].apellido) && arrayEmpleados[j-1].isEmpty == 1 && arrayEmpleados[j].isEmpty == 1)
            {
                arrayEmpleados[j] = arrayEmpleados[j - 1];
                j--;
            }
            arrayEmpleados[j] = auxiliar[i];
        }
	}
    return 0;
}*/
