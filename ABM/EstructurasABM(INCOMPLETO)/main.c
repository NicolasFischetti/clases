#include <stdio.h>
#include <stdlib.h>
#define tam 10


int main()
{
    int opcion;

    do
    {
        printf("1. Cargar\n2. Mostrar\n3. Ordenar\n4. Borrar\n5. Modificar\n6. Mostrar Lista\n9. Salir");
        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                ingresarProducto(arrayEmpleado,tam);
                break;
            case 2:
                mostrarUnProducto(arrayEmpleado,tam);
                break;
            case 3:
                ordenarProductos(arrayEmpleado,tam);
                break;
            case 4:
                borrarProducto(arrayEmpleado,tam);
                break;
            case 5:
                modificarProducto(arrayEmpleado,tam);
                break;
            case 6:
                mostrarListaDeProductos(arrayEmpleado,tam);
                break;    
        }

        system("pause");
        system("cls");
    }
    while(opcion!=9);

    return 0;
}
