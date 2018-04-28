#ifndef ABONADO_H_INCLUDED
#define ABONADO_H_INCLUDED
typedef struct
{
    char nombre[50];
    char apellido[50];
    int numero;
    int idAbonado;
    int isEmpty;
}Abonado;
#endif // ABONADO_H_INCLUDED

int abonado_init(Abonado* array,int limite);
int abonado_buscarPorId(Abonado* array,int limite, int id);
int abonado_baja(Abonado* array,int limite, int id);

//-----------------------------------------------------------
int abonado_mostrar(Abonado* array,int limite); //*
int abonado_mostrarDebug(Abonado* array,int limite);//*
int abonado_alta(Abonado* array,int limite);//*
int abonado_modificacion(Abonado* array,int limite, int id);//*
int abonado_ordenar(Abonado* array,int limite, int orden);



