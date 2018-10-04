#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED
typedef struct
{
    int idCliente;
    int idPublicacion;
    int rubro;
    int estado;
    char cuit[30];
    char aviso[64];
    //------------
    int isEmpty;
}Publicacion;

#include "cliente.h"


int publ_init(Publicacion* array,int limite);
int publ_mostrar(Publicacion* array,int limite);
int publ_alta(Publicacion* arrayP,int limite,
              Cliente* clientes, int lenClientes);
int publ_pausar(Publicacion* array,int limite, int id);
int publ_reanudar(Publicacion* array,int limite, int id);
int publ_altaForzada(Publicacion* arrayP,int limite,
              Cliente* clientes, int lenClientes,
              int idCliente,int rubro,char* aviso);
#endif // PUBLICACION_H_INCLUDED


