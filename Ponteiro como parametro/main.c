#include <stdio.h>
#include <stdlib.h>

int main()
{
   float *number = (float*)malloc(sizeof(float));

   *number = 10;

   printf("Valor que number referencia: %f\n", *number);
   modificaNumero(number);
   printf("Valor alterado: %.2f\n", *number);
}

void modificaNumero(float *number){
    *number = *number * 100;
}
