#ifndef EUSUARIO_H_INCLUDED
#define EUSUARIO_H_INCLUDED

typedef struct
{
    char nombre[50];
    char apellido[50];
    char password[50];
    int idUsuario;
    int isEmpty;

}eUsuario;

int usuario_init(eUsuario* array,int tam);
int usuario_mostrar(eUsuario* array,int tam);
int usuario_modificacion(eUsuario* array, int tam, int id);
int usuario_alta(eUsuario* array,int tam);
int usuario_baja(eUsuario *array,int tam,int id);
int usuario_buscarPorId(eUsuario* array,int tam, int id);
int usuario_ordenar(eUsuario* array,int tam, int orden);

#endif // PRODUCTO_H_INCLUDED

