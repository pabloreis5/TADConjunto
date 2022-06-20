#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"


int main(void) {

  TConjunto conj1, conj2;
  int tamanho;;

  FCVazio(&conj1);
  FCVazio(&conj2);


  printf("Qual tamanho do conjunto 1? ");
  scanf("%d", &tamanho);
  CLeitura(&conj1, tamanho);
  CImprime(&conj1);

  printf("Qual tamanho do conjunto 2? ");
  scanf("%d", &tamanho);
  CLeitura(&conj2, tamanho);
  CImprime(&conj2);

  UniaoConjuntos(&conj1, &conj2);
  CImprime(&conj1);
  CImprime(&conj2);
  //IntersecaoConj(&conj1, &conj2);

  return 0;
}
