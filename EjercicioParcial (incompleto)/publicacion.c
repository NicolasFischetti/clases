#include "eusuario.h"
#include "publicacion.h"
#include "funcionesGets.h"

int producto_init(ePublicacion* articulos,int tam)
{
    int i;
    for (i=0; i < tam; i++)
    {
        ePublicacion[i].isEmpty= 1;
    }
    return 0;
}

int producto_buscarLibre(ePublicacion* articulos, int tam)
{
    int i;
    int posicionLibre= -1;
    for (i=0; i<tam; i++)
    {
        if(ePublicacion[i].isEmpty==0)
        {
             posicionLibre= i;
             break;
        }
        return i;
    }
}


int producto_alta(eUsuario* cuentas,ePublicacion* articulos, int tam)
{
    user_mostrar(eUsuario,tam);
	int posicionP= buscarLibre(eUsuario, tam);
    getString("\nIngrese el id del usuario", eUsuario.idUsuario);
    fflush(stdin);
    gets(eUsuario.idUsuario);

        if (eUsuario.idUsuario != 1)
        {

			 do
			{
				
				getString("\n Ingrese nombre del producto", ePublicacion[posicionP].nombreProducto);
				fflush(stdin);
				gets(ePublicacion[posicionP].nombreProducto);
			}while (esString(ePublicacion[posicionP].nombreProducto) = 1)

			do
			{
				 getFloat("Ingrese el precio", "Stock invalido", 20, 1, 1000, &precio);
		       fflush(stdin);
			    gets(eProducto[posicionP].precioProd);
				ePublicacion[posicionP].precioProd= stock;
			}while(esString(eProducto[posicionP].precioProd) = 1);
			
			do
			{
				 getInt("Ingrese el stock", "Stock invalido", 20, 1, 100, &stock);
		       fflush(stdin);
			    gets(eUsuario[posicionP].stockProd);
				ePublicacion[posicionP].stockProd= stock;
    
			}while(esString(eUsuario[posicionP].stock) = 1);

			
        }
}

int producto_modificar(eUsuario* cuentas,ePublicacion* articulos, int tam)
{
    user_mostrar(eUsuario,tam);
     getString("\nIngrese el id del usuario que desee modificar", eUsuario.idUsuario);
    fflush(stdin);
    gets(eUsuario.idUsuario);

     do
    {
		listaProductos_mostrar(ePublicacion* articulos,int tam);
        printf("Seleccione que campo desea modificar :\n1. Precio producto\n2. Stock Producto \n3. Salir");
        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        { 
            case 1:
                getFloat("Ingrese el precio de producto nuevo", "Stock invalido", 20, 1, 1000, &precioNuevo);
                scanf("%s",&precioNuevo);
                eProducto[idProductos].precioProd = precioNuevo;
                break;
            case 2:
                getInt("Ingrese el stock", "Stock invalido", 20, 1, 100, &stockNuevo);
                scanf("%s",&stockNuevo);
                eProducto[idProductos].stockProd = stockNuevo;
                break;
        }
    }while(opcion!=3);
}

int producto_baja(eUsuario* cuentas,ePublicacion* articulos, int tam,int idP);
{
    int i;
    int idP;
	listaProductos_mostrar(eUsuario* cuentas, ePublicacion* articulos,int tam);
     getString("\nIngrese el id del usuario que desee dar de baja", eUsuario.idUsuario);
    fflush(stdin);
    gets(eUsuario.idUsuario);
    for (i=0; i<tam; i++)
    {
        if(idP==eUsuario[i].idUsuario)
        {
            ePublicacion[i].isEmpty=0;
        }
    }
}

void listaProductos_mostrar(eUsuario* cuentas, ePublicacion* articulos,int tam)
{
    int i;
	getString("\nIngrese el id del usuario que desee ver sus productos", eUsuario.idProductos);
	fflush(stdin);
	gets(eUsuario.idProducto);
    for (i=0;i<tam;i++)
    {
        if(eProducto[i].isEmpty==1)
        {
            printf("\n%20s \n%20s \n%f.2 \n%d \n%d", idProductos[i], nombreProducto[i], precioProd[i], idCantidadProductos[i], stockProd[i]);
			break;
        }
    }
}

