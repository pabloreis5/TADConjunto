#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int chave;
}TDado;

typedef struct Nodo{
  TDado info;
  struct Nodo *prox;
}TNodo;

typedef struct{
  TNodo *first;
  TNodo *last;
}TConjunto;

int CVazio (TConjunto *conjunto);
void FCVazio(TConjunto *conjunto); //a
void CInsere(TConjunto *conjunto, TDado *Item);
void CLeitura(TConjunto *conjunto, int tam); //b
void CImprime(TConjunto *conjunto); //f
void UniaoConjuntos(TConjunto *conjunto, TConjunto *conjunto2);//c
void IntersecaoConj(TConjunto *conjunto, TConjunto *conjunto2); //d
void VerificaIgualdade(TConjunto *conjunto, TConjunto *conjunto2); //e


#endif
