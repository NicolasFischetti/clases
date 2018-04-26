int entidadDos_init(eUsuario* cuentas,int tam)
{
    int i;
    for (i=0; i < tam; i++)
    {
        eUsuario[i].isEmpty= 1;
    }
    return 0;
}

int entidadDos_buscarLibre(eUsuario* cuentas, int tam)
{
    int i;
    int posicionLibre= -1;
    for (i=0; i<tam; i++)
    {
        if(eUsuario[i].isEmpty==0)
        {
             posicionLibre= i;
             break;
        }
        return i;
    }
}
int entidadDos_alta(eUsuario* cuentas,int tam,int id)
{
    int i;
    int posicion= buscarLibre(eUsuario, tam);

        if (posicion != -1)
        {
            do
			{
				eUsuario[posicion].idUsuario= idTotalUsuarios;
				getString("\n Ingrese nombre de cuenta", eUsuario[posicion].cuentas);
				fflush(stdin);
				gets(eUsuario[posicion].cuentas);
			}while (esString(eUsuario[posicion].cuentas) = 1)

			do
			{
				 getString("\n Ingrese el password", eUsuario[posicion].password );
		       fflush(stdin);
			    gets(eUsuario[posicion].password);

			}while(esString(eUsuario[posicion].password) = 1);

        }
}

int entidadDos_modificar(eUsuario *cuentas, int tam)
{
    user_mostrar(eUsuario,tam);
    getString(\n" Ingrese el id del usuario que desee modificar", eUsuario.idUsuario);
    fflush(stdin);
    gets(eUsuario.idUsuario);
     do
    {
        printf("Seleccione que campo desea modificar :\n1. cuentas\n2. password\n3. Salir");
        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                getString("\n Ingrese nombre de cuenta nuevo", eUsuario[idUsuario].cuentas);
                scanf("%s",&nombreNuevo);
                eUsuario[idUsuario].cuentas = nombreNuevo;
            case 2:
                 getString("\n Ingrese el password nuevo", eUsuario[idUsuario].password );
                scanf("%s",&passwordNuevo);
                eUsuario[idUsuario].password = passwordNuevo;
                break;
        }
    }while(opcion!=3);
}

int entidadDos_baja(eUsuario* cuentas,int tam,int id)
{
	user_mostrar(eUsuario,tam);
    int i;
    int id;
    getString("\Ingrese el id del producto para dar de baja: \n", id);
    scanf("%d", &id);
    for (i=0; i<tam; i++)
    {
        if(id==eUsuario[i].idUsuario)
        {
            eUsuario[i].isEmpty=0;
			break;
        }
    }
}
