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
