#include <stdio.h>
#include <stdlib.h>

int main()
{

   int valor[3]= {6, 4, 5};
    char tipo[][3]= {"Juan","Maria","Pedro"};
   int i;
   int j;
   int max;

   max = 0;

   for (i = 0; i < 3; i++)
      if (valor[i] > max)
         max = valor[i];

   for (i = max; i > 0; i--){
      for (j = 0; j < 3; j++)
         if (valor[j] >= i)
            printf(" *");
         else
            printf("  ");

      putchar('\n');
   }

   return 0;
}

void imprimir_grafico(int valor[], int num_valores)
{
   int valorDos[] = {1, 3, 9, 7, 5};

   imprimir_grafico(valor, 5);

   return 0;
}
int buscar_maximo(double valores[], int num_valores)
{
	int maximo_pos = 0;
	for (int i = 1; i < num_valores; i++) {
		if (valores[i] > valores[maximo_pos]) {
			maximo_pos = i;
		}
	}
	return maximo_pos;
}
