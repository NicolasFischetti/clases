#ifndef ABONADO_H_INCLUDED
#define ABONADO_H_INCLUDED
typedef struct
{
    char nombre[50];
    char apellido[50];
    int numero;
    //------------
    int idAbonados;
    int isEmpty;
}Abonados;
#endif // FANTASMA_H_INCLUDED

int abonados_init(Abonados* array,int limite);
int abonados_buscarPorId(Abonados* array,int limite, int id);
int abonados_baja(Abonados* array,int limite, int id);

int abonados_mostrar(Abonados* array,int limite);
int abonados_mostrarDebug(Abonados* array,int limite);
int abonados_alta(Abonados* array,int limite);
int abonados_modificacion(Abonados* array,int limite, int id);
int abonados_ordenar(Abonados* array,int limite, int orden);



