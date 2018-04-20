
#define ESTRCUTRAEMPLEADO_H_INCLUDED

typedef struct
{
    char nombre[50];
    char apellido[50];
    int idEmpleado;
    int isEmpty;
}Empleado;



int emp_init(Empleado* arrayEmpleados,int sizeArray);
int emp_mostrar(Empleado* arrayEmpleados,int sizeArray);
int emp_alta(Empleado* arrayEmpleados,int sizeArray,int id);
int emp_baja(Empleado* arrayEmpleados,int sizeArray,int id);
int buscarLibre(Empleado* arrayEmpleados,int sizeArray);



