#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED

typedef struct
{

    char nombreProd[30];
    int idProducto;
    int isEmpty;
    int idUsuario;
    float precioProd;
    int stockProd;

}ePublicacion;

int producto_baja(ePublicacion* articulos, int tam, int id);
int producto_modificar(ePublicacion* articulos, int tam);
int producto_alta(ePublicacion* articulos, int tam);
int producto_buscarLibre(ePublicacion* articulos, int tam);
int producto_init(ePublicacion* articulos,int tam);
int producto_buscarPorId(ePublicacion* productos,int tam, int id);

#endif // PUBLICACION_H_INCLUDED
