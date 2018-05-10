#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED
int getInt(char* mensaje);
float getFloat(char* mensaje);
char getChar(char* mensaje);

char getNumeroAleatorio(int desde , int hasta, int iniciar);

int esNumerico(char *str) ;
int esTelefono(char *str);
int esAlfaNumerico(char *str);
int esSoloLetras(char *str);
int esNumericoFlotante(char str[]);
int esPassword(char str[]);
int esCuilt(char str[]);
int esDireccion(char str[]);

void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);
int getValidEmail(char requestMessage[],char errorMessage[],char input[], int attemps);
int getValidPassword(char requestMessage[],char errorMessage[],char input[], int maxLenght,int attemps);
int getValidDireccion(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps);
int getValidCuilt(char requestMessage[],char errorMessage[],char input[], int maxLenght,int attemps);


int getValidString(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps);
int getValidInt(char requestMessage[],char errorMessage[], int* input,int lowLimit, int hiLimit,int attemps);
int getValidFloat(char requestMessage[],char errorMessage[], float* input,float lowLimit, float hiLimit,int attemps);

char intToString(int);

void clearStdin(void);
void pause(void);
void clearScreen(void);


#endif // BIBLIOTECA_H_INCLUDED
////////////////////////////////////////////////////////////////////////////////////

/*#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED
#include "usuario.h"
typedef struct
{
    char nombre[50];
    int idUsuario;
    int stock;
    float precio;
    int cantidadVendida;
    //------------
    int idPublicacion;
    int isEmpty;
}Publicacion;


int publicacion_init(Publicacion* array,int limite);
int publicacion_mostrar(Publicacion* array, Usuario* usuarios,int limite, int limite_usuarios);
int publicacion_mostrarDebug(Publicacion* array, Usuario* usuarios,int limite, int limite_usuarios);
int publicacion_mostrarPorIdUsuario(Publicacion* array, int limite, int idUsuario);
int publicacion_alta(Publicacion* array, Usuario* usuarios,int limite, int limiteUsuarios);
int publicacion_baja(Publicacion* array,int limite, int id);
int publicacion_modificacion(Publicacion* array,int limite, int id);
int publicacion_ordenar(Publicacion* array,int limite, int orden);
int publicacion_buscarPorId(Publicacion* array,int limite, int id);
int publicacion_bajaPorIdUsuario(Publicacion* array, int limite, int idUsuario);
int publicacion_comprar(Publicacion* publicaciones, Usuario* usuarios, int limite_pub, int limite_user, int idPublicacion);
int publicacion_altaForzada(Publicacion* array,int limite,int idUsuario,char* nombre,float precio, int stock);


#endif // PUBLICACION_H_INCLUDED

#ifndef EUSUARIO_H_INCLUDED
#define EUSUARIO_H_INCLUDED

typedef struct
{
    char nombre[50];
    char apellido[50];
    char password[50];
    int idUsuario;
    int isEmpty;
    int calificacionAcum;
    int cantidadVentas;
}eUsuario;

int usuario_init(eUsuario* array,int tam);
int usuario_mostrar(eUsuario* array,int tam);
int usuario_modificacion(eUsuario* array, int tam, int id);
int usuario_alta(eUsuario* array,int tam);
int usuario_baja(eUsuario *array,int tam,int id);
int usuario_buscarPorId(eUsuario* array,int tam, int id);
int usuario_ordenar(eUsuario* array,int tam, int orden);

#endif // PRODUCTO_H_INCLUDED
