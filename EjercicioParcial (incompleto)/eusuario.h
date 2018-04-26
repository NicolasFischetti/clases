#ifndef EUSUARIO_H_INCLUDED
#define EUSUARIO_H_INCLUDED

typedef struct
{
    char cuentas[20];
    char password[20];
    int idUsuario;
    int isEmpty;

}eUsuario;

void user_init(eUsuario* cuentas,int tam);
void user_mostrar(eUsuario* cuentas,int tam);
int user_modificar(eUsuario* cuentas, int tam);
int user_alta(eUsuario* cuentas,int tam,int id);
int user_baja(eUsuario *cuentas,int tam,int id);
int user_buscarLibre(eUsuario *cuentas,int tam);


#endif // PRODUCTO_H_INCLUDED


#endif // EUSUARIO_H_INCLUDED
