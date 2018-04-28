#ifndef LLAMADAS_H_INCLUDED
#define LLAMADAS_H_INCLUDED
typedef struct
{
    int idAbonado;
    char motivo[50];
    int idEstado;
    int tiempo;
    //------------
    int idLlamada;
    int isEmpty;
}Llamadas;
#endif // FANTASMA_H_INCLUDED

int llamadas_init(Llamadas* array,int limite);
int llamadas_buscarPorId(Llamadas* array,int limite, int id);
int llamadas_baja(Llamadas* array,int limite, int id);

int llamadas_mostrar(Llamadas* array,int limite);
int llamadas_mostrarDebug(Llamadas* array,int limite);
int llamadas_alta(Llamadas* array,int limite);
int llamadas_modificacion(Llamadas* array,int limite, int id);
int llamadas_ordenar(Llamadas* array,int limite, int orden);



