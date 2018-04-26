#ifndef ENTIDADESTRES_H_INCLUDED
#define ENTIDADESTRES_H_INCLUDED
int entidadTres_init(eUsuario* cuentas,int tam);
int entidadTres_buscarLibre(eUsuario* cuentas, int tam);
int entidadTres_alta(eUsuario* cuentas,int tam,int id);
int entidadTres_modificar(eUsuario *cuentas, int tam);
int entidadTres_baja(eUsuario* cuentas,int tam,int id);
#endif // ENTIDADESTRES_H_INCLUDED
