#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
typedef struct
{
    char nombre[50];
    char pass[50];
    int calificacionAcum;
    int cantidadVentas;
    //------------
    int idUsuario;
    int isEmpty;
}Usuario;


int usuario_init(Usuario* array,int limite);
int usuario_mostrar(Usuario* array,int limite);
int usuario_mostrarDebug(Usuario* array,int limite);
int usuario_alta(Usuario* array,int limite);
int usuario_baja(Usuario* array,int limite, int id);
int usuario_modificacion(Usuario* array,int limite, int id);
int usuario_ordenar(Usuario* array,int limite, int orden);
int usuario_buscarPorId(Usuario* array,int limite, int id);
int usuario_altaForzada(Usuario* array,int limite,char* nombre,char* pass);

#endif // PANTALLA_H_INCLUDED



