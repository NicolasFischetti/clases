#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "biblioteca.h"
#include "publicacion.h"
#include "informar.h"

#define QTYC 100
#define QTYP 1000

int main()
{
    Cliente clientes[QTYC];
    Publicacion publicaciones[QTYP];
    int menu;
    int auxiliarRubro;
    int auxiliarId;

    cliente_init(clientes,QTYC);
    publ_init(publicaciones,QTYP);

    cliente_altaForzada(clientes,QTYC,"Ezequiel","Hoyos","20-39267310-6");
    cliente_altaForzada(clientes,QTYC,"Alvaro","Perez","24-39267860-9");
    cliente_altaForzada(clientes,QTYC,"Juan","Garcia","26-38267815-9");
    cliente_altaForzada(clientes,QTYC,"Pablo","Fernandez","27-38654815-9");

    publ_altaForzada(publicaciones,QTYP,clientes,QTYC,0,4,"Memoria RAM");
    publ_altaForzada(publicaciones,QTYP,clientes,QTYC,0,4,"CPU Nueva");
    publ_altaForzada(publicaciones,QTYP,clientes,QTYC,0,4,"Tarjeta Grafica");
    publ_altaForzada(publicaciones,QTYP,clientes,QTYC,0,4,"Cuadernos");

    do
    {
        getValidInt("\nMenu de opciones\n1. Dar de alta un cliente\n2. Modificar\n3. Dar de baja un cliente\n4. Publicar aviso\n5. Pausar publicacion\n6. Reanudar publicacion\n7. Imprimir clientes\n8. Imprimir publicaciones\n9. Imprimir cantidad de publicaciones de un rubro\n10. Salir\nIngrese la opcion deseada: ","\nNo valida\n",&menu,1,10,1);
        switch(menu)
        {
            case 1:
                cliente_alta(clientes,QTYC);
                break;
            case 2:
                getValidInt("\nIngrese el ID: ","\nNumero no valido\n",&auxiliarId,0,200,2);
                cliente_modificacion(clientes,QTYC,auxiliarId);
                break;
            case 3:
                getValidInt("\nIngrese el ID: ","\nNumero no valido\n",&auxiliarId,0,200,2);
                cliente_baja(clientes,QTYC,auxiliarId);
                break;
            case 4:
                publ_alta(publicaciones,QTYP,clientes,QTYC);
                break;
            case 5:
                getValidInt("\nIngrese el ID de la publicacion: ","\nNumero no valido\n",&auxiliarId,0,200,2);
                publ_pausar(publicaciones,QTYP, auxiliarId);
                break;
            case 6:
                getValidInt("\nIngrese el ID de la publicacion: ","\nNumero no valido\n",&auxiliarId,0,200,2);
                publ_reanudar(publicaciones,QTYP, auxiliarId);
                break;
            case 7:
                cliente_mostrar(clientes,QTYC);
                break;
            case 8:
                publ_mostrar(publicaciones,QTYP);
                break;
            case 9:
                getValidInt("\nIngrese el numero de rubro: ","\nNumero no valido\n",&auxiliarRubro,0,200,2);
                cantidadRubros(publicaciones,QTYP,auxiliarRubro);
            break;
        }
    }while(menu != 10);

    return 0;
}
