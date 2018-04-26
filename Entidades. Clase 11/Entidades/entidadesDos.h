#ifndef ENTIDADESDOS_H_INCLUDED
#define ENTIDADESDOS_H_INCLUDED
int entidadDos_init(eUsuario* cuentas,int tam);
int entidadDos_buscarLibre(eUsuario* cuentas, int tam);
int entidadDos_alta(eUsuario* cuentas,int tam,int id);
int entidadDos_modificar(eUsuario *cuentas, int tam);
int entidadDos_baja(eUsuario* cuentas,int tam,int id);

#endif // ENTIDADESDOS_H_INCLUDED
