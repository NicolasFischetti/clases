#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "usuario.h"
#include "publicacion.h"
#include "utn.h"
#define LEN_USER 100
#define LEN_PUB 1000



int main()
{
    Usuario usuarios[LEN_USER];
    Publicacion publicaciones[LEN_PUB];

    int menu;
    int auxiliarId;

    publicacion_init(publicaciones, LEN_PUB);
    usuario_init(usuarios,LEN_USER);

    usuario_altaForzada(usuarios,LEN_USER,"Pedro","12345678");
    usuario_altaForzada(usuarios,LEN_USER,"Adrian","12345678");
    usuario_altaForzada(usuarios,LEN_USER,"Walter","12345678");
    usuario_altaForzada(usuarios,LEN_USER,"Liliana","12345678");

    publicacion_altaForzada(publicaciones,LEN_PUB,1, "Placa de video", 2000, 10);
    publicacion_altaForzada(publicaciones,LEN_PUB,1, "Memoria RAM", 900, 10);


    do
    {
        getValidInt("1.Alta Usuario\n2.Modificar usuario\n3.Baja Usuario\n4.Publicar Producto\n5.Modificar Publicacion\n6.Cancelar Publicacion\n7.Comprar Producto\n8.Listar Publicaciones de usuario\n9.Listar publicaciones\n10.Listar Usuarios\n11.Salir\n","\nNo valida\n",&menu,1,11,1);
        switch(menu)
        {
            case 1:
                usuario_alta(usuarios,LEN_USER);
                break;
            case 2:
                getValidInt("ID?\n","\nNumero valida\n",&auxiliarId,0,2000,2);
                usuario_modificacion(usuarios,LEN_USER,auxiliarId);
                break;
            case 3:
                getValidInt("ID?\n","\nNumero valida\n",&auxiliarId,0,2000,2);
                usuario_baja(usuarios,LEN_USER,auxiliarId);
                publicacion_bajaPorIdUsuario(publicaciones, LEN_PUB, auxiliarId);
                break;
            case 4:
                publicacion_alta(publicaciones, usuarios, LEN_PUB, LEN_USER);
                break;
            case 5:
                getValidInt("idUsuario?\n","\nNo es un id\n", &auxiliarId, 0, 1000,2);
                publicacion_mostrarPorIdUsuario(publicaciones, LEN_PUB, auxiliarId);
                getValidInt("idPublicacion?\n","\nNo es un id\n", &auxiliarId, 0, 1000,2);
                publicacion_modificacion(publicaciones, LEN_PUB, auxiliarId);
                break;
            case 6:
                getValidInt("idUsuario?\n","\nNo es un id\n", &auxiliarId, 0, 1000,2);
                publicacion_mostrarPorIdUsuario(publicaciones, LEN_PUB, auxiliarId);
                getValidInt("idPublicacion?\n","\nNo es un id\n", &auxiliarId, 0, 1000,2);
                publicacion_baja(publicaciones, LEN_PUB, auxiliarId);
                break;
            case 7:
                getValidInt("idPublicacion?\n","\nNo es un id\n", &auxiliarId, 0, 1000,2);
                publicacion_comprar(publicaciones, usuarios, LEN_PUB, LEN_USER, auxiliarId);
                break;
            case 8:
                getValidInt("idUsuario?\n","\nNo es un id\n", &auxiliarId, 0, 1000,2);
                publicacion_mostrarPorIdUsuario(publicaciones, LEN_PUB, auxiliarId);
                break;
            case 9:
                publicacion_mostrar(publicaciones, usuarios, LEN_PUB, LEN_USER);
                break;
            case 10:
                usuario_mostrar(usuarios, LEN_USER);
                break;
        }

    }while(menu != 11);

    return 0;
}
