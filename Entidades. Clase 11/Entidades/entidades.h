#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

int entidad_init(eUsuario* cuentas,int tam);
int entidad_buscarLibre(eUsuario* cuentas, int tam);
int entidad_alta(eUsuario* cuentas,int tam,int id);
int entidad_modificar(eUsuario *cuentas, int tam);
int entidad_baja(eUsuario* cuentas,int tam,int id);
#endif // ENTIDADES_H_INCLUDED
