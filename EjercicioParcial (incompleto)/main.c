#include <stdio.h>
#include <stdlib.h>
#include "parcial.h"
#include "string.h"
#include "lib.h"
#define MAX_USERS 100
#define MAX_PRODUCTOS 100
#define MAX_COMPRAS 10000

int main()
{
	usuario cuentas[MAX_USERS];
    producto articulos[MAX_PRODUCTOS];
	user_init(cuantas, MAX_USERS);
    producto_init(articulos, MAX_PRODUCTOS);
	int respuesta;
    int opcion;
    int log;
    int idUTotalUsuarios=0;
    char nombreUsuario[25];
    char password[10];

	 do
    {
        printf("1) Crear cuenta\n");
        printf("2) Conectar\n");
        printf("3) Salir\n");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            usr_alta(cuantas, MAX_USERS, idUsuarios);
            idUTotalUsuarios=0++;
			break;
        case 2:
            getString("Ingrese el usuario\n", nombreUsuario);
            getString("Ingrese la password\n", password);
            if(login(&nombreUsuario, &password, cuantas, MAX_USERS)==0)
            {
                log = 1;
            }
            else
                printf("Datos invalidos\n");
				 break;

        }

    }while(respuesta != 3);
    return 0;
}
