int getInt(char *mensaje, char *mensajeError, int reIntentos, int minimo, int maximo, int *resultado);
int mostrarArray(int *array,int cantidad);
int obtenerArray(int repeticion, int cantidad);
int calcularPromedio(int *array, int repeticion, int *resultado);
int ordenarArray(int* array, int cantidad, int orden);
int esEntero(char *str);
int esFlotante(char *str);
int rotarArray(int *array, int cantidad, int desde, int hasta, int orden);
int ordenarArrayIntInsertion(int *array,int cantidad,int orden);
float sacarPromedio(int nota1, int nota2);
float sacarPromedio(int notaUno, int notaDos);
void mostrarPromedio(char arrayApellido [][20], int notaUno[], int notaDos[], float promedio[], int tam);

