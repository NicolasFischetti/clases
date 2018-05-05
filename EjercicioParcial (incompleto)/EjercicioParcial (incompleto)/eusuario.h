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

int user_init(eUsuario* array,int tam);
int user_mostrar(eUsuario* array,int tam, int id);
int user_modificar(eUsuario* array, int tam);
int user_alta(eUsuario* array,int tam,int id);
int user_baja(eUsuario *array,int tam,int id);
int user_buscarLibre(eUsuario *array,int tam);
int usuario_buscarPorId(eUsuario* array,int tam, int id);

#endif // PRODUCTO_H_INCLUDED

