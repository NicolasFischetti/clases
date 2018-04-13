#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



#endif // FUNCIONES_H_INCLUDED

float sumar(float x, float y);
float restar(float x, float y);
float dividir(float x, float y);
float multiplicar(float x, float y);
float factoriar(float x);

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
        printf("La división es %.2f\n", resultado );
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
