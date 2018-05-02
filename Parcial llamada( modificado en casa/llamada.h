#ifndef LLAMADA_H_INCLUDED
#define LLAMADA_H_INCLUDED

#define QTY 10
#define OCUPADO 0
#define LIBRE 1

#define CANTIDAD_TIPOS 3
#define FALLA_3G 0
#define FALLA_LTE 1
#define FALLA_EQUIPO 2

#define EN_CURSO 0
#define SOLUCIONADO 1
#define NO_SOLUCIONADO 2

typedef struct
{
    int idAbonado;
    int idMotivo;
    int idEstado;
    int tiempo;
    //------------
    int idLlamada;
    int isEmpty;
}Llamada;
#endif // LLAMADA_H_INCLUDED

int llamada_init(Llamada* array,int limite);
int llamada_buscarPorId(Llamada* array,int limite, int id);
int llamada_baja(Llamada* array,int limite, int id);

int llamada_mostrar(Llamada* array,int limite);
int llamada_mostrarDebug(Llamada* array,int limite);
int llamada_alta(Llamada* array,int limite);
int llamada_modificacion(Llamada* array,int limite, int id);
int llamada_ordenar(Llamada* array,int limite, int orden);



