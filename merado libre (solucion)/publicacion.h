#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED
#include "usuario.h"
typedef struct
{
    char nombre[50];
    int idUsuario;
    int stock;
    float precio;
    int cantidadVendida;
    //------------
    int idPublicacion;
    int isEmpty;
}Publicacion;


int publicacion_init(Publicacion* array,int limite);
int publicacion_mostrar(Publicacion* array, Usuario* usuarios,int limite, int limite_usuarios);
int publicacion_mostrarDebug(Publicacion* array, Usuario* usuarios,int limite, int limite_usuarios);
int publicacion_mostrarPorIdUsuario(Publicacion* array, int limite, int idUsuario);
int publicacion_alta(Publicacion* array, Usuario* usuarios,int limite, int limiteUsuarios);
int publicacion_baja(Publicacion* array,int limite, int id);
int publicacion_modificacion(Publicacion* array,int limite, int id);
int publicacion_ordenar(Publicacion* array,int limite, int orden);
int publicacion_buscarPorId(Publicacion* array,int limite, int id);
int publicacion_bajaPorIdUsuario(Publicacion* array, int limite, int idUsuario);
int publicacion_comprar(Publicacion* publicaciones, Usuario* usuarios, int limite_pub, int limite_user, int idPublicacion);
int publicacion_altaForzada(Publicacion* array,int limite,int idUsuario,char* nombre,float precio, int stock);


#endif // PUBLICACION_H_INCLUDED
