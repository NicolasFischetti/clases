#include "eusuario.h"
#include "publicacion.h"

int user_init(eUsuario,int tam)
{
    int i;
    for (i=0; i < tam; i++)
    {
        eUsuario[i].isEmpty= 1;
    }
    return 0;
}

int buscarLibre(eUsuario[], int tam)
{
    int i;
    int posicionLibre= -1;
    for (i=0; i<tam; i++)
    {
        if(eUsuario[i].isEmpty==0)
        {
             posicionLibre= i;
             break;
        }
        return i;
    }
}
int user_alta(eUsuario[],int tam,int id)
{
    int i;
    int posicion= buscarLibre(eUsuario, tam);

        if (posicion != -1)
        {
            eUsuario[posicion].idUsuario= proxId;
            printf("\n Ingrese nombre de usuario ");
            fflush(stdin);
            gets(eUsuario[posicion].nombre);
            printf("\ Ingrese el apellido del usuario ");
            fflush(stdin);
            gets(eUsuario[posicion].apellido);
            printf("\n Ingrese el password" );
            fflush(stdin);
            gets(eUsuario[posicion].password);
            eUsuario[posicion].isEmpty=1;
            break;
        }
}

int user_modificar(eUsuario[], int tam)
{
    user_mostrar(eUsuario,tam);
    printf(\n" Ingrese el id del usuario que desee modificar:);
    fflush(stdin);
    gets(eUsuario.idUsuario);
     do
    {
        printf("Seleccione que campo desea modificar :\n1. nombre\n2. apellido\n3. password\n4. Salir");
        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                printf("\n Ingrese un nombre nuevo\n");
                scanf("%s",&nombreNuevo);
                eUsuario[idProducto].nombre = nombreNuevo;
                break;
            case 2:
                printf("\n Ingrese un nuevo apellido");
                scanf("%s",&descripcionNueva);
                eUsuario[idProducto].apellido = apellidoNuevo;
                break;
            case 3:
                printf("\n Ingrese un nuevo password");
                scanf("%s",&passwordNuevo);
                eUsuario[idProducto].password = passwordNuevo;
                break;
        }
    }while(opcion!=4);
}

int user_baja(eUsuario[],int tam,int id);
{
    int i;
    int id;
    printf("\Ingrese el id del producto para dar de baja: \n");
    scanf("%d", &id);
    for (i=0; i<tam; i++)
    {
        if(id==eUsuario[i].idUsuario)
        {
            eUsuario[i].isEmpty=0;
        }
    }
}

void user_mostrar(eUsuario[],int tam)
{
    int i;
    for (i=0;i<tam;i++)
    {
        if(eUsuario[i].estado==1)
        {
            printf("%20s %20s %20s %5d\n", nombre[i], apellido[i], password[i], idUsuario[i];
        }
    }
}


