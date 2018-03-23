#include <stdio.h>
#include <stdlib.h>
#define LETRAS 10

int main()
{
    char letra;
    int contador;
    int cantE = 0;
    int cantI = 0;
    int cantA = 0;
    int cantO = 0;
    int cantU = 0;

    for (contador = 0; contador < LETRAS; contador++)
    {
        printf("Ingrese su letra: \n");
        fflush(stdin);
        scanf("%c", &letra);
        letra=tolower(letra);

        switch(letra)
        {
            case 'a':
                    cantA++;
                    break;
            case 'e':
                    cantE++;
                    break;
            case 'i':
                    cantI++;
                    break;
            case 'o':
                    cantO++;
                    break;
            case 'u':
                    cantU++;
                    break;
            default:
                    break;

        }


    }

    printf("La cantidad de letras a es: d%, la cantidad de letras e es: %d, la cantidad de letras i es: %d, la cantidad de letras o es: %d, la cantidad de letras u es: %d", cantA, cantE, cantI, cantO, cantU);
    return 0;
}
