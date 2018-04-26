#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED

typedef struct
{
   
    char nombreProducto[30];
    int idProducto;
    int isEmpty;
    int idUsuario;
    float precioProd;
    int stockProd;

}ePublicacion;

int producto_baja(eUsuario* cuentas,ePublicacion* articulos, int tam,int idP);
int producto_modificar(eUsuario* cuentas,ePublicacion* articulos, int tam);
int producto_alta(eUsuario* cuentas,ePublicacion* articulos, int tam);
int producto_buscarLibre(ePublicacion* articulos, int tam);
int producto_init(ePublicacion* articulos,int tam);

#endif // PUBLICACION_H_INCLUDED
