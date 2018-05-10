#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "biblioteca.h"


/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getFloat(char* mensaje)
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char* mensaje)
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char* mensaje)
{
    char auxiliar;
    printf("%s",mensaje);
    clearStdin();
    scanf("%c",&auxiliar);
    return auxiliar;
}
/**
 * \brief Genera un número aleatorio
 * \param desde Número aleatorio mínimo
 * \param hasta Número aleatorio máximo
 * \param iniciar Indica si se trata del primer número solicitado 1 indica que si
 * \return retorna el número aleatorio generado
 *
 */
char getNumeroAleatorio(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}


/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (i == 0 && str[i] == '-')
       {
           i++;
           continue;

       }
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if (i == 0 && str[i] == '-')
       {
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;

       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esDireccion(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esEmail(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9') && (str[i] !='@') && (str[i] != '.'))
           return 0;
       i++;
   }
   return 1;
}

int esCuilt(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if (i >= 0 && str[i] == '-')
       {
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;

       i++;
   }
   return 1;
}

int esPassword(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}

int getValidCuilt(char requestMessage[],char errorMessage[],char input[], int maxLenght,int attemps)
{
    int i;
    int retorno=-1;
    char auxCuilt[50];
    char buffer[1000];

    for(i=0;i<attemps;i++)
    {
        getString(requestMessage, auxCuilt);
         if (!esCuilt(auxCuilt))
        {
            printf ("%s",errorMessage);
            continue;
        }


        retorno=0;
        strcpy(input,buffer);
        
        break;
    }
    return retorno;
}

int getValidDireccion(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps)
{
    int i;
    int retorno=-1;
    char direccion[50];

    for(i=0;i<attemps;i++)
    {
        if (!esDireccion(direccion))
        {
            printf ("%s",errorMessage);
            continue;
        }

        retorno=0;
        strcpy(input,direccion);
        break;
    }
    return retorno;
}
int getValidPassword(char requestMessage[],char errorMessage[],char input[], int maxLenght,int attemps)
{
    int i;
    int retorno=-1;
    char buffer[1024];
    char auxPassword[50];

    getString(requestMessage, auxPassword);

    for(i=0;i<attemps;i++)
    {
        if (!esPassword(auxPassword))
        {
            printf ("%s",errorMessage);
            continue;
        }
        retorno=0;
        strcpy(input,buffer);
        break;
    }

    return retorno;
}

int getValidEmail(char requestMessage[],char errorMessage[],char input[], int attemps)
{
    int i;
    int retorno=-1;
    char auxEmail[50];

    for(i=0;i<attemps;i++)
    {
        getString(requestMessage,auxEmail);

        if(!esNumerico(auxEmail)) {
            printf ("%s", errorMessage);
            continue;
        }
        if(!esEmail(auxEmail)) {
            printf ("%s", errorMessage);
            continue;
        }
        retorno=0;
        strcpy(input,auxEmail);
        break;
    }
    return retorno;
}


int getValidDni(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int attemps)
{
    int maxLenght = 20;
    int i;
    int retorno=-1;
    char dni[maxLenght];

    for(i=0;i<attemps;i++)
    {
        getString(requestMessage,dni);

        if(strlen(dni) >= maxLenght)
        {
            printf ("%s", errorMessageLenght);
            continue;
        }
        if(!esNumerico(dni)) {
            printf ("%s", errorMessage);
            continue;
        }

        retorno=0;
        strcpy(input,dni);
        break;
    }
    return retorno;
}






/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    clearStdin();
    scanf ("%[^\n]s", input);
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Es el limite inferior aceptado
 * \param lowLimit Es el limite superior aceptado
 * \param input puntero al lugar donde se cargará el numero ingresado
 * \param attemps indica la cantidad de reintentos ante un error
 * \return 0 si consiguio el Numero -1 si no
 *
 */
int getValidInt(char requestMessage[],char errorMessage[], int* input,int lowLimit, int hiLimit,int attemps)
{
    char auxStr[256];
    int auxInt, i, retorno = -1;

    for(i=0;i<attemps;i++)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s",errorMessage);
            break;
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("%s",errorMessage);
            continue;

        }
        *input = auxInt;
        retorno = 0;
        break;

    }
    return retorno;

}


/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error de tipo
 * \param errorMessageLenght Es el mensaje a ser mostrado en caso de error de longitud
 * \param input Array donde se cargará el texto ingresado
 * \param maxLenght int Longitud maxima del texto ingresado
 * \param attemps indica la cantidad de reintentos ante un error
 * \return 0 si consiguio el String -1 si no
 *
 */
int getValidString(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps)
{
    int i;
    int retorno=-1;
    char buffer[1024];

    for(i=0;i<attemps;i++)
    {
        if (!getStringLetras(requestMessage,buffer))
        {
            printf ("%s",errorMessage);
            continue;
        }
        if(strlen(buffer) >= maxLenght)
        {
            printf ("%s",errorMessageLenght);
            continue;

        }
        retorno=0;
        strcpy(input,buffer);
        break;
    }
    return retorno;
}

/**
 * \brief Solicita un numero flotante al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Es el limite inferior aceptado
 * \param lowLimit Es el limite superior aceptado
 * \param input puntero al lugar donde se cargará el numero ingresado
 * \param attemps indica la cantidad de reintentos ante un error
 * \return 0 si consiguio el Numero -1 si no
 *
 */
int getValidFloat(char requestMessage[],char errorMessage[], float* input,float lowLimit, float hiLimit,int attemps)
{
    char auxStr[256];
    int i, retorno = -1;
    float auxInt;

    for(i=0;i<attemps;i++)
    {
        if (!getStringNumerosFlotantes(requestMessage,auxStr))
        {
            printf ("%s",errorMessage);
            break;
            continue;

        }
        auxInt = atof(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("%s",errorMessage);
            continue;

        }
        *input = auxInt;
        retorno = 0;
        break;

    }
    return retorno;

}


/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void clearStdin(void)
{
    setbuf(stdin,NULL);
}

/**
 * \brief Hace una pausa, similar al system("pause")
 * \param -
 * \return -
 *
 */
void pause(void)
{
    getChar("");
}

/**
 * \brief Hace un clear, similar al system("clear")
 * \param -
 * \return -
 *
 */
void clearScreen(void)
{
    system("clear"); //system("cls");
}

char intToString(int parm) {
    char str[12];
    sprintf(str, "%d", parm);

    return str;
}

///////////////////////////////////////////////////////////////////////////////////

/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "publicacion.h"
#include "usuario.h"
#include "utn.h"


static int proximoId();
static int buscarLugarLibre(Publicacion* array,int limite);

int publicacion_init(Publicacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}

int publicacion_mostrarDebug(Publicacion* array, Usuario* usuarios,int limite, int limite_usuarios)
{
    int i;
    int retorno=-1;
    int indiceUsuario;
    if(limite>0)
    {
        for(i=0;i<limite;i++)
        {
            retorno = 0;
            indiceUsuario = usuario_buscarPorId(usuarios, limite_usuarios, array[i].idUsuario);
            printf("\n\n");
            printf("ID:%d - Nombre: %s - Precio: %g - Vendidos: %d - Stock: %d - Usuario: %s\n", array[i].idPublicacion,
                       array[i].nombre, array[i].precio, array[i].cantidadVendida, array[i].stock,
                       usuarios[indiceUsuario].nombre);
        }
    }
    return retorno;
}

int publicacion_mostrarPorIdUsuario(Publicacion* array, int limite, int idUsuario)
{
    int i;
    int retorno=-1;
    if(limite>0)
    {
        for(i=0;i<limite;i++)
        {
            retorno = 0;
            if(!array[i].isEmpty && array[i].idUsuario==idUsuario)
            {
                printf("ID:%d - Nombre: %s - Precio: %g - Vendidos: %d - Stock: %d\n", array[i].idPublicacion,
                       array[i].nombre, array[i].precio, array[i].cantidadVendida, array[i].stock);
            }
        }
    }
    return retorno;
}

int publicacion_mostrar(Publicacion* array, Usuario* usuarios,int limite, int limite_usuarios)
{
    int i;
    int retorno=-1;
    int indiceUsuario;
    if(limite>0)
    {
        for(i=0;i<limite;i++)
        {
            retorno = 0;
            if(!array[i].isEmpty)
            {
                indiceUsuario = usuario_buscarPorId(usuarios, limite_usuarios, array[i].idUsuario);
                printf("ID:%d - Nombre: %s - Precio: %g - Vendidos: %d - Stock: %d - Usuario: %s\n", array[i].idPublicacion,
                       array[i].nombre, array[i].precio, array[i].cantidadVendida, array[i].stock,
                       usuarios[indiceUsuario].nombre);
            }
        }
    }
    return retorno;
}

int publicacion_alta(Publicacion* array, Usuario* usuarios,int limite, int limiteUsuarios)
{
    int retorno = -1;
    int i, stock, idUsuario;
    float precio;
    char nombre[50];
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidInt("\nId del usuario? ","\nEso no es un id",&idUsuario,0,1000,2))
            {
                if(usuario_buscarPorId(usuarios, limiteUsuarios, idUsuario)>=0)
                {
                    if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",nombre,40,2))
                    {
                        if(!getValidFloat("\nPrecio?", "\nEso no es un precio", &precio,0,1000000,2))
                        {
                            if(!getValidInt("\nStock?", "\nEso no es un stock", &stock,0,10000,2))
                            {
                                retorno = 0;
                                array[i].idUsuario = idUsuario;
                                strcpy(array[i].nombre,nombre);
                                array[i].precio = precio;
                                array[i].stock = stock;
                                array[i].cantidadVendida = 0;
                                                    //------------------------------
                                                    //------------------------------
                                array[i].idPublicacion = proximoId();
                                array[i].isEmpty = 0;

                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        retorno = -3;
    }
    return retorno;
}

int publicacion_bajaPorIdUsuario(Publicacion* array, int limite, int idUsuario)
{
    int retorno = 0;
    int i;
    for(i=0;i<limite;i++)
    {
        if(!array[i].isEmpty && array[i].idUsuario==idUsuario)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}

int publicacion_baja(Publicacion* array,int limite, int id)
{
    int retorno = 0;
    int indiceAEliminar = publicacion_buscarPorId(array, limite, id);
    if(indiceAEliminar>0)
    {
        array[indiceAEliminar].isEmpty = 1;
    }
    else
    {
        retorno=indiceAEliminar;
    }
    return retorno;
}




int publicacion_modificacion(Publicacion* array,int limite, int id)
{
    int retorno = -1;
    int indiceAModificar;
    float precio;
    int stock;
    indiceAModificar = publicacion_buscarPorId(array, limite, id);
    if(indiceAModificar>=0)
    {
        if(!getValidFloat("\nPrecio? ","\nEso no es un precio",&precio,0,100000,2))
        {
            if(!getValidInt("\nStock? ","\nEso no es un stock",&stock,0,1000,2))
            {
                retorno=0;
                array[indiceAModificar].precio = precio;
                array[indiceAModificar].stock = stock;
            }
            else
            {
                retorno=-3;
            }
        }
        else
        {
            retorno = -2;
        }
    }
    return retorno;
}

int publicacion_ordenar(Publicacion* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Publicacion auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && !orden)) //******
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

static int buscarLugarLibre(Publicacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


static int proximoId()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}


int publicacion_buscarPorId(Publicacion* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idPublicacion==id)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int publicacion_comprar(Publicacion* publicaciones, Usuario* usuarios, int limite_pub, int limite_user, int idPublicacion)
{
    int retorno=-1;
    int indiceAComprar, indiceUsuario;
    int calificacion;
    indiceAComprar = publicacion_buscarPorId(publicaciones, limite_pub, idPublicacion);
    if(indiceAComprar>=0)
    {
        if(publicaciones[indiceAComprar].stock>0)
        {
            if(!getValidInt("\nCalificacion", "No es una calificacion", &calificacion, 0, 10,1))
            {
                publicaciones[indiceAComprar].stock--;
                publicaciones[indiceAComprar].cantidadVendida++;
                indiceUsuario = usuario_buscarPorId(usuarios, limite_user, publicaciones[indiceAComprar].idUsuario);
                usuarios[indiceUsuario].calificacionAcum+=calificacion;
                usuarios[indiceUsuario].cantidadVentas++;
                retorno =0;
            }
        }
    }
    return retorno;
}

int publicacion_altaForzada(Publicacion* array,int limite,int idUsuario,char* nombre,float precio, int stock)
{
    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(array[i].nombre,nombre);
            array[i].idUsuario=idUsuario;
            array[i].precio = precio;
            array[i].stock = stock;
            array[i].cantidadVendida=0;
            //------------------------------
            //------------------------------
            array[i].idPublicacion = proximoId();
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eusuario.h"
#include "utn.h"

static int buscarLugarLibre(eUsuario* array,int tam);
static int proximoId();

int usuario_init(eUsuario* array,int tam)
{
    int retorno = -1;
    int i;
    if(tam > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<tam;i++)
        {
            array[i].isEmpty = 0;
        }
    }
    return retorno;
}

static int buscarLugarLibre(eUsuario* array,int tam)
{
    int retorno = -1;
    int i;
    if(tam > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<tam;i++)
        {
            if(array[i].isEmpty == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int usuario_alta(eUsuario* array,int tam)
{
    int retorno = -1;
    char nombre[50];
    char apellido[50];
    char password[50];
    int id;
    int indice;
     indice = buscarLugarLibre(array,tam);
    if(tam > 0 && array != NULL)
    {
        retorno = -2;

        if(indice >= 0)
        {
             id = proximoId();
            retorno = -3;
            if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))
            {
                if(!getValidString("Apellido?","Error","Overflow", apellido,50,2))
                {
                    if(!getValidPassword("Password?","Error",password,50,2))
                    {
                        retorno = 0;
                        array[indice].calificacionAcum = 0;
                        array[indice].cantidadVentas = 0;
                        strcpy(array[indice].nombre,nombre);
                        strcpy(array[indice].apellido,apellido);
                         strcpy(array[indice].password,password);

                        array[indice].idUsuario = id;
                        array[indice].isEmpty = 1;
                    }
                }
            }
        }
    }
    return retorno;
}

int usuario_modificacion(eUsuario* array,int tam, int id)
{
    int retorno = -1;
    int indice;
    char nombre[50];
    char apellido[50];
    char password[50];

    indice = usuario_buscarPorId(array,tam,id);
    if(indice >= 0)
    {
        retorno = -2;

        if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))
            {
                if(!getValidString("Apellido?","Error","Overflow", apellido,50,2))
                {
                    if(!getValidPassword("password?","Error", password,50,2))
                    {
                    retorno = 0;

                    strcpy(array[indice].nombre,nombre);
                    strcpy(array[indice].apellido,apellido);
                    strcpy(array[indice].password,password);
                }
            }
    }
    return retorno;
    }
}

int usuario_baja(eUsuario* array,int tam, int id)
{

    int retorno = -1;
    int indice;
    indice = usuario_buscarPorId(array,tam,id);
    if(indice >= 0)
    {
        retorno = 0;
        array[indice].isEmpty = 0;
    }
    return retorno;
}

int usuario_mostrar(eUsuario* array,int tam)
{
    int retorno = -1;
    int i;
    if(tam > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<tam;i++)
        {
            if(array[i].isEmpty == 1)
            {
               printf("\n %s - %s - %d - %d",array[i].nombre,array[i].apellido,array[i].idUsuario,array[i].isEmpty);
            }
        }
    }
    return retorno;

    }

    int usuario_ordenar(eUsuario* array,int tam, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    eUsuario auxiliar;

    if(tam > 0 && array != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<tam-1;i++)
            {
                    if(array[i].isEmpty == 1 && array[i+1].isEmpty == 1 )
                    {
                        if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && !orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && orden)) //<------------
                        {
                            auxiliar = array[i];
                            array[i] = array[i+1];
                            array[i+1] = auxiliar;
                            flagSwap = 1;
                        }
                    }
            }
        }while(flagSwap);
    }

    return retorno;
}
int usuario_buscarPorId(eUsuario* array,int tam, int id)
{
    int retorno = -1;
    int i;
    if(array > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<tam;i++)
        {
            if(array[i].isEmpty == 1 && array[i].idUsuario == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
static int proximoId()
{
    static int ultimoId = -1;
    ultimoId++;
    return ultimoId;
}
int calificacionUsuario(eUsuario* array, int tam)
{
    int retorno = -1;
    int i;
    float promedio;
    if(tam > 0 && array != NULL)
    {
        retorno = -1;
        for(i=0;i<tam;i++)
        {
            if(array[i].isEmpty == 1)
            {
              if (array[i].cantidadVentas != 0)
              {
                  promedio= array[i].calificacionAcum / array[i].cantidadVentas;
                  printf("\n La calificacion total es: %.2f y el nombre es: %s ", promedio, array[i].nombre);
                  retorno = 0;
              }
              else{
                 promedio= 0;
              }


            }
        }
    }
    return retorno;
}

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "utn.h"
#include "eusuario.h"
#include "publicacion.h"
#define MAX_USERS 100
#define MAX_PRODUCTOS 100
#define MAX_COMPRAS 10000



int main()
{
    eUsuario array[MAX_USERS];
    ePublicacion productos[MAX_PRODUCTOS];
    int menu;
    int auxiliarId;



    usuario_init(array,MAX_USERS);
    producto_init(productos,MAX_PRODUCTOS);

    do
    {
        getValidInt("\n1.Alta Abonado\n2.Baja Abonado\n3.Modificar Abonado\n4.Mostrar Abonado\n5.Ordenar\n6.Alta publicacion\n7.Modificacion publiacion\n8.Fin publicacion\n9.Compra de producto\n10.Motivo con mas reclamos \n11. Promedio con mas reclamos\n12. Mostrar productos\n13.Salir\n","\nNo valida\n",&menu,1,12,1);
        switch(menu)
        {
            case 1:
                usuario_alta(array,MAX_USERS);
                break;
            case 2:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,100,2);
                usuario_baja(array,MAX_USERS, auxiliarId);
                break;
            case 3:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,100,2);
                usuario_modificacion(array,MAX_USERS, auxiliarId);
                break;
            case 4:
                usuario_mostrar(array,MAX_USERS);
                break;
            case 5:
                usuario_ordenar(array,MAX_USERS,0);
                break;
            case 6:
                getValidInt("ID de usuario?","\nNumero valida\n",&auxiliarId,0,200,2);
                producto_alta(productos, MAX_PRODUCTOS);
                break;
            case 7:
                getValidInt("ID de usuario?","\nNumero valida\n",&auxiliarId,0,200,2);
                 producto_modificacion(productos, MAX_PRODUCTOS, auxiliarId);
                break;
            case 8:
                getValidInt("ID de usuario?","\nNumero valida\n",&auxiliarId,0,200,2);
                producto_baja(productos, MAX_PRODUCTOS, auxiliarId);
                break;
            case 9:
                 producto_mostrar(productos,MAX_PRODUCTOS);
                 getValidString("\n Ingrese el id del producto\n", "Error\n", "Demasiado largo\n", &auxiliarId, 200, 2);
                break;
            case 10:

                break;
            case 11:

                break;
            case 12:
                producto_mostrar(productos,MAX_PRODUCTOS);
                break;
            case 13:
                break;
        }

    }while(menu != 13);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "abonado.h"
#include "llamada.h"
#include "informes.h"


int abonadoConMasReclamos(Llamada* arrayLlamadas,int limiteLlamadas,Abonado* arrayAbonados, int limiteAbonado)
{
    int i;
    int flagSwap;
    Abonado resultado[limiteAbonado];
    int cantidadLlamadas[limiteAbonado];

    Abonado auxiliarAbonado;
    int auxiliarCantidadLlamadas;

    // Limpiamos la cantidad de llamadas para empezar a funcionar
    for (i=0;i<limiteAbonado;i++)
        cantidadLlamadas[i] = 0;

    // Recorremos las llamadas para computarlas en los abonados
    for (i=0;i<limiteLlamadas;i++) {
        if(arrayLlamadas[i].isEmpty == 0)
        cantidadLlamadas[arrayLlamadas[i].idAbonado]++;
    }

    // Copiamos el array original de Abonados sobre el de Resultados, para aplicar sobre este ultimo la burbuja
    for(i=0; i<limiteAbonado;i++) {
        resultado[i] = arrayAbonados[i];
    }

    // Aplicamos el metodo de la burbuja sobre el array de Resultado
    do
    {
        flagSwap = 0;
        for(i=0;i<limiteAbonado-1;i++)
        {
            if(resultado[i].isEmpty == OCUPADO && resultado[i+1].isEmpty == OCUPADO )
            {
                if(cantidadLlamadas[i]< cantidadLlamadas[i+1])
                {
                    auxiliarAbonado = resultado[i];
                    resultado[i] = resultado[i+1];
                    resultado[i+1] = auxiliarAbonado;

                    auxiliarCantidadLlamadas = cantidadLlamadas[i];
                    cantidadLlamadas[i] = cantidadLlamadas[i+1];
                    cantidadLlamadas[i+1] = auxiliarCantidadLlamadas;

                    flagSwap = 1;
                }
            }
        }
    } while(flagSwap);

    // Mostramos el resultado del informe
    for(i=0;i<limiteAbonado;i++)
    {
        if(!resultado[i].isEmpty)
            printf("\n[DEBUG] %s - %s - %d - %d - %d - Cantidad de llamados: %d",resultado[i].nombre,resultado[i].apellido,resultado[i].numero,resultado[i].idAbonado,resultado[i].isEmpty, cantidadLlamadas[i]);
    }

    return 0;
}

int motivoConMasReclamos(Llamada* arrayLlamadas, int limiteLlamadas) {
    int i;
    int flagSwap;

    int resultado[CANTIDAD_TIPOS] = {FALLA_3G, FALLA_LTE, FALLA_EQUIPO};
    int cantidadLlamadas[CANTIDAD_TIPOS];

    int auxiliarResultado;
    int auxiliarCantidadLlamadas;

    // Limpiamos la cantidad de llamadas para empezar a funcionar
    for (i=0;i < CANTIDAD_TIPOS;i++)
        cantidadLlamadas[i] = 0;

    // Recorremos las llamadas para computarlas en los motivos
    for (i=0;i<limiteLlamadas;i++) {
        if(arrayLlamadas[i].isEmpty == 0)
            cantidadLlamadas[arrayLlamadas[i].idMotivo]++;
    }

    // Aplicamos el metodo de la burbuja sobre el array de Resultado
    do
    {
        flagSwap = 0;
        for(i=0; i < CANTIDAD_TIPOS - 1; i++)
        {
            if(cantidadLlamadas[i]< cantidadLlamadas[i+1])
            {
                auxiliarResultado = resultado[i];
                resultado[i] = resultado[i+1];
                resultado[i+1] = auxiliarResultado;

                auxiliarCantidadLlamadas = cantidadLlamadas[i];
                cantidadLlamadas[i] = cantidadLlamadas[i+1];
                cantidadLlamadas[i+1] = auxiliarCantidadLlamadas;

                flagSwap = 1;
            }
        }
    } while(flagSwap);

    // Mostramos que tiene mayor cantidad de llamados del informe
    printf("\n%d - Cantidad de llamados: %d",resultado[0], cantidadLlamadas[0]);

    return 0;
}

int promedioMotivoConMasReclamos(Llamada* arrayLlamadas ,int limiteLlamadas) {
    int i;
    int flagSwap;

    int resultado[CANTIDAD_TIPOS] = {FALLA_3G, FALLA_LTE, FALLA_EQUIPO};
    int cantidadLlamadas[CANTIDAD_TIPOS];
    int tiempoDeLlamadas[CANTIDAD_TIPOS];
    int promedioDeLlamadas[CANTIDAD_TIPOS];

    int auxiliarResultado;
    int auxiliarPromedioLlamadas;

    // Limpiamos la cantidad de llamadas para empezar a funcionar
    for (i=0;i < CANTIDAD_TIPOS;i++) {
        cantidadLlamadas[i] = 0;
        tiempoDeLlamadas[i] = 0;
        promedioDeLlamadas[i] = 0;
    }

    // Recorremos las llamadas para computarlas en los motivos
    for (i=0;i<limiteLlamadas;i++) {
        if(arrayLlamadas[i].isEmpty == 0) {
            cantidadLlamadas[arrayLlamadas[i].idMotivo]++;
            tiempoDeLlamadas[arrayLlamadas[i].idMotivo] += arrayLlamadas[i].tiempo;
        }
    }

    // Recorremos los tipos de llamada para calcular el promedio de tiempo
    for (i=0;i<CANTIDAD_TIPOS;i++) {
        promedioDeLlamadas[i] = tiempoDeLlamadas[i] / cantidadLlamadas[i];
    }

    // Aplicamos el metodo de la burbuja sobre el array de Resultado
    do
    {
        flagSwap = 0;
        for(i=0; i < CANTIDAD_TIPOS - 1; i++)
        {
            if(promedioDeLlamadas[i]< promedioDeLlamadas[i+1])
            {
                auxiliarResultado = resultado[i];
                resultado[i] = resultado[i+1];
                resultado[i+1] = auxiliarResultado;

                auxiliarPromedioLlamadas = promedioDeLlamadas[i];
                promedioDeLlamadas[i] = promedioDeLlamadas[i+1];
                promedioDeLlamadas[i+1] = auxiliarPromedioLlamadas;

                flagSwap = 1;
            }
        }
    } while(flagSwap);

    // Mostramos el resultado del informe
    for(i=0;i<CANTIDAD_TIPOS;i++)
        printf("\n%d - Promedio de tiempo llamados: %d minutos", resultado[i], promedioDeLlamadas[i]);

    return 0;
}

int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit)
{
    int retorno = -1;
    int i;
    int indexPantalla;
    if(limite > 0 && arrayC != NULL)
    {
        for(i=0; i<limite;i++)
        {
            if(!arrayC[i].isEmpty && !strcmp(arrayC[i].cuit,cuit))
            {
                indexPantalla = pantalla_buscarPorId(pantallas,lenPantallas,arrayC[i].idPantalla);
                printf("\n\nCuit: %s - Unitario: %.2f - Total: %.2f - Dias: %d\n",
                                    arrayC[i].cuit,
                                    pantallas[indexPantalla].precio,
                                    (arrayC[i].dias * pantallas[indexPantalla].precio),
                                    arrayC[i].dias );
            }
        }

        retorno = 0;
    }
    return retorno;
}

int informar_ListarContrataciones(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;
    int i;
    int indexPantalla;
    if(limite > 0 && arrayC != NULL)
    {
        for(i=0; i<limite;i++)
        {
                if(!arrayC[i].isEmpty)
                {
                    indexPantalla = pantalla_buscarPorId(pantallas,lenPantallas,arrayC[i].idPantalla);
                    printf("\nCuit: %s - Nombre: %s - Video: %s - Dias: %d\n",
                                        arrayC[i].cuit,
                                        pantallas[indexPantalla].nombre,
                                        arrayC[i].archivo,
                                        arrayC[i].dias );
                }


        }

        retorno = 0;
    }
    return retorno;
}


int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;
    int i;
    //int indexPantalla;
    char ultimoCuit[50];

    cont_ordenarCuit(arrayC,limite,0);
    strcpy(ultimoCuit,"");
    if(limite > 0 && arrayC != NULL)
    {
        for(i=0; i<limite;i++)
        {
                if(!arrayC[i].isEmpty)
                {
                    if(strcmp(ultimoCuit,arrayC[i].cuit) != 0)
                    {
                        printf("\nCuit: %s", arrayC[i].cuit);
                        strcpy(ultimoCuit,arrayC[i].cuit);
                    }


                    //indexPantalla = pantalla_buscarPorId(pantallas,lenPantallas,arrayC[i].idPantalla);
                    /*printf("\nCuit: %s - Nombre: %s - Video: %s - Dias: %d\n",
                                        arrayC[i].cuit,
                                        pantallas[indexPantalla].nombre,
                                        arrayC[i].archivo,
                                        arrayC[i].dias );

                }


        }

        retorno = 0;
    }
    return retorno;
}

int informar_ClientesYContraciones(Pantalla *array, Contratacion *arrayC, int lenPantallas, int limite)
{
    int retorno=-1;
    int i;
    char cuit[50];
    if(limite > 0 && arrayC != NULL && lenPantallas > 0 && array !=NULL)
    {
        retorno=0;
        for(i=0;i<arrayC;i++)
        {
            strcpy(arrayC[i].cuit,cuit);
            cantContrataciones(arrayC,limite,&cuit);
        }
        //informar_ConsultaFacturacion(arrayC,limite,array,lenPantallas,cuit);

    }
    return retorno;
}
int cantContrataciones(Contratacion *arrayC, int limite, char *cuit)
{
    int i;
    int contador=0;
    int retorno=-1;
    if(limite > 0 && arrayC != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!arrayC[i].isEmpty)
            {
                if(strcmp(arrayC[i].cuit,cuit)==0)
                {
                    contador++;
                }
            }
        }
    }
    return retorno;
}
int listarPantallas(Pantalla *pantallas, int lenPantallas)
{
    int i;
    int retorno=-1;

    if(lenPantallas > 0 && pantallas != NULL)
    {
        retorno = 0;
        for(i=0;i<lenPantallas;i++)
        {
            if(!pantallas[i].isEmpty && pantallas[i].precio<=1000)
                printf("%d - %s - %s - %.2f - %d\n",pantallas[i].idPantalla,pantallas[i].nombre,pantallas[i].direccion,pantallas[i].precio,pantallas[i].tipo);
        }
    }
    return retorno;
}

int main()
{
    Pantalla array[QTY];
    Contratacion contrataciones[LEN_CONT];
    int menu;
    int auxiliarId;

    pantalla_init(array,QTY);
    cont_init(contrataciones,LEN_CONT);

    pantalla_altaForzada(array,QTY,"Wilde","Las Flores 50",50,0);
    pantalla_altaForzada(array,QTY,"Avellaneda","Belgrano 250",2000,0);
    pantalla_altaForzada(array,QTY,"Bernal","Cerrito 300",3000,0);
    pantalla_altaForzada(array,QTY,"Quilmes","Lavalle 450",1000,1);
    pantalla_altaForzada(array,QTY,"Berazategui","Mitre 150",5000,1);

    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,0,"video.avi","20911911915",100);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,0,"video1.avi","20911911915",400);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,0,"video2.avi","30911911915",300);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,2,"video3.avi","30911911915",400);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,2,"video4.avi","40911911915",500);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,2,"video5.avi","40911911915",600);

    informar_ConsultaFacturacion(contrataciones,LEN_CONT,array,QTY,"20911911915");
    informar_ListarContrataciones(contrataciones,LEN_CONT,array,QTY);
    informar_ListarCantidadContratacionesImporte(contrataciones,LEN_CONT,array,QTY);


    do
    {
        getValidInt("\n\n1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.Ordenar\n6.Mostrar Debug\n7.Contratar\n8.Listar todas los clientes y contrataciones\n9.Listar pantallas con precio menor a 1000\n10.Salir\n","\nNo valida\n",&menu,1,10,1);
        switch(menu)
        {
            case 1:
                pantalla_alta(array,QTY);
                break;
            case 2:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                pantalla_baja(array,QTY,auxiliarId);
                break;
            case 3:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                pantalla_modificacion(array,QTY,auxiliarId);
                break;
            case 4:
                pantalla_mostrar(array,QTY);
                cont_mostrar(contrataciones,LEN_CONT);
                break;
            case 5:
                cont_ordenarCuit(contrataciones,LEN_CONT,0);
                pantalla_ordenar(array,QTY,0);
                break;
            case 6:
                pantalla_mostrarDebug(array,QTY);

                break;
            case 7:
                cont_alta(contrataciones,LEN_CONT,array,QTY);
                break;
            case 8:
                informar_ClientesYContraciones(array,contrataciones, QTY, LEN_CONT);
                break;
            case 9:
                listarPantallas(array, QTY);
                break;



        }

    }while(menu != 9);

    return 0;
}*/
