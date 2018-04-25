#ifndef EUSUARIO_H_INCLUDED
#define EUSUARIO_H_INCLUDED

typedef struct
{
    char nombre[20];
    char apellido[20];
    char password[20];
    int idUsuario;
    int isEmpty;

}eUsuario;

int user_init(eUsuario[],int tam);
void user_mostrar(eUsuario[],int tam);
int user_modificar(eUsuario[], int tam);
int user_alta(eUsuario[],int tam,int id);
int user_baja(eUsuario[],int tam,int id);
int buscarLibre(eUsuario[],int tam);


#endif // PRODUCTO_H_INCLUDED


#endif // EUSUARIO_H_INCLUDED
