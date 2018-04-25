#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED

typedef struct
{
    int idCompra;
    int idProducto;
    int idUsuario;
    char nombreProd[20]
    int precioProd;
    int stockProd;

}ePublicacion;

int producto_modificar(ePublicacion[], int tam);
int producto_alta(ePublicacion[],int tam,int idP);
int producto_baja(ePublicacion[],int tam,int idP);




#endif // PUBLICACION_H_INCLUDED
