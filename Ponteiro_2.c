#include <stdio.h>
 #include <locale.h>

 main() {
 setlocale(LC_ALL, "Portuguese");

 double *p = (double*) malloc(sizeof(double) * 10);

 if (p == NULL) {
 printf("Memória Insuficiente!"); }

 *p = 9.5;

 printf("\nEndereço do 1o. Byte: %d", p);
 printf("\nValor double armazenado: %f", *p);
 free(p);

}
