int getInt(char *mensaje, char *mensajeError, int reIntentos, int minimo, int maximo, int *resultado)
{
    char buffer[4096];
    long auxiliarLong;
    int retorno=-1;
    do
    {
        reIntentos--;
        printf("%s", mensaje);
        scanf("%4095s",buffer);
        if(esEntero(buffer)==1)
        {
            auxiliarLong=atol(buffer);
            if(auxiliarLong>=minimo && auxiliarLong<=maximo)
            {
                  retorno=0;
                  *resultado=(int)auxiliarLong;
                  break;
            }
            else if(auxiliarLong<minimo)
            {
                  retorno=-1;
            }
            else
            {
                  retorno=-2;
            }
        }
        else
        {
            retorno=-3;
        }
        printf("%s", mensajeError);
    }while(reIntentos>=0);
    return retorno;
}
int obtenerArray(int *array, int repeticion)
{
    int i;
    int auxiliar;
    for(i=0; i<repeticion; i++)
    {
        getInt("Ingrese un numero:\n", "\nFuera del rango\n", 3, 0, 100, &auxiliar);
        array[i]=auxiliar;
    }
}

int mostrarArray(int *array,int cantidad)
{
    int retorno=-1;
    int i;
    if(cantidad>0)
    {
        retorno=0;
        for(i=0;i<cantidad;i++)
        {
            printf("\n%d",array[i]);
        }
    }
    return retorno;
}
int calcularPromedio(int *array, int cantidad, int *resultado)
{
    int retorno=-1;
    int i;
    int suma=0;
    int promedio;
    if(cantidad>0)
    {
        retorno=0;
        for(i=0;i<cantidad;i++)
        {
            suma=suma+array[i];
        }
        promedio=suma/cantidad;
        *resultado=promedio;
    }
    return retorno;
}

int ordenarArray(int* array, int cantidad, int orden)
{
    int i;
    int auxiliar;
    int flagSwap;

    do
    {
        flagSwap=0;
        for(i=0;i<cantidad-1;i++)
        {
            if(array[i] > array[i+1] && orden == 0 || (array[i] < array[i+1] && orden==1))
            {
                auxiliar = array[i];
                array[i] = array[i+1];
                array[i+1] = auxiliar;
                flagSwap=1;
            }
        }
    }while(flagSwap);
    return 0;
}
int esEntero(char *str)
{
    int i;
    for(i=0;str[i] !='\0';i++)
    {
        if(str[i] > '9' || str[i] < '0')
            return 0;
    }
    return 1;
}
int esFlotante(char *str)
{
    int i=0;
    int contadorPuntos=0;
    while(str[i] !='\0')
    {
        while(str[i]=='.')
        {
            contadorPuntos++;
        }
        if(contadorPuntos==1 && str[i] > '9' || str[i] < '0')
        {
            return 0;
        }
        i++;
    }
    return 1;
}
int rotarArray(int *array, int cantidad, int desde, int hasta, int orden)
{
    int i;
    int auxiliar;
    if(desde>0 && desde<=hasta && hasta<=cantidad-1 && (orden==0))
    {
        auxiliar=array[desde-1];
        for(i=desde-1;i<hasta;i++)
        {
            array[i]=array[i+1];
        }
        array[hasta]=auxiliar;
    }
    if ((desde>0 && desde<=hasta && hasta<cantidad) && (orden==1))
    {
        auxiliar=array[desde+1];
        for(i=hasta+1;i>desde;i--)
        {
            array[i]=array[i-1];
        }
        array[desde]=auxiliar;
    }
    return 0;
}

int ordenarArrayIntInsertion(int *array,int cantidad,int orden)
{
	int auxiliar;
    int j, i;

	for(i = 1; i < cantidad; i++) {
		auxiliar = array[i];
		j = i;
		while(j > 0 && auxiliar < array[j - 1])
        {
			array[j] = array[j - 1];
			j--;
		}
		array[j] = auxiliar;
	}
    return 0;
}
float sacarPromedio(int notaUno, int notaDos)
{
    float retorno;
    retorno= (float) (notaUno + notaDos) / 2;
    return retorno;
}

void mostrarPromedio(char arrayApellido [][20], int notaUno[], int notaDos[], float promedio[], int tam)
{
    int i;
    for (i=0; i < tam; i++)
    {
        promedio[i]= sacarPromedio(notaUno[i], notaDos[i]);
        printf("\n nota uno: %d", notaUno[i]);
        printf("\n nota dos: %d", notaDos[i]);
        printf("\n promedio: %.2f", promedio[i]);
        printf("\n apellido: %s", arrayApellido[i]);
     }
}

int ordenarArray(int* array, int* tam, int* orden)
{
    int i;
    int auxiliar;
    int flagSwap;

    do
    {
        flagSwap=0;
        for(i=0;i<tam-1;i++)
        {
            if(array[i] > array[i+1] && orden == 0 || (array[i] < array[i+1] && orden==1))
            {
                auxiliar = array[i];
                array[i] = array[i+1];
                array[i+1] = auxiliar;
                flagSwap=1;
            }
        }
    }while(flagSwap);
    return 0;
}
