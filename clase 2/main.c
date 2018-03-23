#include <stdio.h>
#include <stdlib.h>
#define  CANTIDAD 5
int main()
{
    int numero;
    int acumulador;
    int contador;
    int mayorNumero;
    int minimoNumero;
    // int flag= 0;
    for( contador = 1 ; contador <= CANTIDAD ; contador++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numero);
        acumulador=acumulador+numero;

        while(numero <= 0)
        {
            //con el do, esto lo puedo dejar de repetir, siempre entra lo primero
             printf("Ingrese su numero nuevamente: ");
            scanf("%d", &numero);
        }

        if (contador == 1) // flag== 0; estructura de control que funciona una sola vez
        {
             mayorNumero= numero;
            minimoNumero=numero;
            //flag=1;
        }
        else if (mayorNumero < numero)
        {
            mayorNumero=numero;
        }
        else if (minimoNumero > numero)
        {
            minimoNumero=numero;
        }
    }
    printf("Su promedio es: %.2f\n", (float)acumulador / contador);
    printf("Su numero mayor es: %d\n", mayorNumero);
    printf("Su numero menor es: %d\n", minimoNumero);
}
