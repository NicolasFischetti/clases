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
