
#include <stdio.h>
#include <stdlib.h>

float sumar(float x, float y)
{
    float resultado;
    resultado= x+y;
    return resultado;
}
float restar(float x, float y)
{
    float resultado;
    resultado= x-y;
    return resultado;
}
float dividir(float x, float y)
{
    float resultado;
    resultado= x/y;
    if (y == 0)
    {
        printf("La division no es valida, intentelo de nuevo...\n");
    }
    else
    {

    }
    return resultado;
}
float multiplicar(float x, float y)
{
    float resultado;
    resultado= x*y;
    return resultado;
}
float factoriar(float x)
{
    float resultado;
    if (x==1)
    {
        return 1;
    }
    resultado= x * factoriar(x-1);
    return (resultado);
}
