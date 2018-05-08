#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "utn.h"
#include "eusuario.h"
#include "publicacion.h"
#define MAX_USERS 100
#define MAX_PRODUCTOS 100
#define MAX_COMPRAS 10000



int main()
{
    eUsuario array[MAX_USERS];
    ePublicacion productos[MAX_PRODUCTOS];
    int menu;
    int auxiliarId;



    usuario_init(array,MAX_USERS);
    producto_init(productos,MAX_PRODUCTOS);

    do
    {
        getValidInt("\n1.Alta Abonado\n2.Baja Abonado\n3.Modificar Abonado\n4.Mostrar Abonado\n5.Ordenar\n6.Alta publicacion\n7.Modificacion publiacion\n8.Fin publicacion\n9.Compra de producto\n10.Motivo con mas reclamos \n11. Promedio con mas reclamos\n12. Mostrar productos\n13.Salir\n","\nNo valida\n",&menu,1,12,1);
        switch(menu)
        {
            case 1:
                usuario_alta(array,MAX_USERS);
                break;
            case 2:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,100,2);
                usuario_baja(array,MAX_USERS, auxiliarId);
                break;
            case 3:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,100,2);
                usuario_modificacion(array,MAX_USERS, auxiliarId);
                break;
            case 4:
                usuario_mostrar(array,MAX_USERS);
                break;
            case 5:
                usuario_ordenar(array,MAX_USERS,0);
                break;
            case 6:
                getValidInt("ID de usuario?","\nNumero valida\n",&auxiliarId,0,200,2);
                producto_alta(productos, MAX_PRODUCTOS);
                break;
            case 7:
                getValidInt("ID de usuario?","\nNumero valida\n",&auxiliarId,0,200,2);
                 producto_modificacion(productos, MAX_PRODUCTOS, auxiliarId);
                break;
            case 8:
                getValidInt("ID de usuario?","\nNumero valida\n",&auxiliarId,0,200,2);
                producto_baja(productos, MAX_PRODUCTOS, auxiliarId);
                break;
            case 9:
                 producto_mostrar(productos,MAX_PRODUCTOS);
                 getValidString("\n Ingrese el id del producto\n", "Error\n", "Demasiado largo\n", &auxiliarId, 200, 2);
                break;
            case 10:

                break;
            case 11:

                break;
            case 12:
                producto_mostrar(productos,MAX_PRODUCTOS);
                break;
            case 13:
                break;
        }

    }while(menu != 13);

    return 0;
}
