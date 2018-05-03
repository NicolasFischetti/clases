
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[]);


/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni);
int abonado_init(EPersona* lista);
int persona_alta(EPersona* lista);
int persona_eliminar(EPersona* lista, int dni);
int persona_ordenar(EPersona* lista, int orden);

int getValidDni(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int attemps);
int getValidString(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps);
int getValidInt(char requestMessage[],char errorMessage[], int* input,int lowLimit, int hiLimit,int attemps);
int getStringNumeros(char mensaje[],char input[]);
void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);

int esSoloLetras(char str[]);
int esNumerico(char str[]);


