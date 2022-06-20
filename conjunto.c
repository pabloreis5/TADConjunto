#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"

void FCVazio(TConjunto *conjunto){
    conjunto->first = (TNodo*) malloc(sizeof(TNodo));
    conjunto->last = conjunto->first;
    conjunto->first->prox = NULL;
}

int CVazio (TConjunto *conjunto){
    return (conjunto->first == conjunto->last);
}

void CInsere(TConjunto *conjunto, TDado *Item){
    conjunto->last->prox = (TNodo*) malloc(sizeof(TNodo));
    conjunto->last = conjunto->last->prox;
    conjunto->last->info = *Item;
    conjunto->last->prox = NULL;
}

void CLeitura(TConjunto *conjunto, int tam){
    printf("\n*Iniciando Leitura de Dados... \n");
    for(int i=0; i<tam; i++){
        TDado valor;
        printf("\t(%d) Qual elemento: ", i);
        scanf("%d", &valor.chave);
        CInsere(conjunto, &valor);
    }
}

void CImprime(TConjunto *conjunto){
    printf("\n*Imprimindo Dados...\n");
    TNodo *aux;
    aux = conjunto->first->prox;
    printf("\t");
    while(aux != NULL){
        printf(" %d |", aux->info.chave);
        aux = aux->prox;
    }
    printf("\n\n");

}

void UniaoConjuntos(TConjunto *conjunto, TConjunto *conjunto2){
    TConjunto *conjResult;
    TNodo *aux1, *aux2;
    int cont = 0;

    CImprime(conjunto);
    conjResult = conjunto;

    aux1 = conjResult->first->prox;
    aux2 = conjunto2->first->prox;

    while(aux2 != NULL){
        while(aux1 != NULL){
            if(aux1->info.chave == aux2->info.chave){
               cont++;
               aux1 = aux1->prox;
            }
            else{
                aux1 = aux1->prox;
            }
        }

        aux1 = conjResult->first->prox;
        if(cont >= 1){
            aux2 = aux2->prox;
        }
        else{
            CInsere(conjResult, &aux2->info);
            aux2 = aux2->prox;
        }
        cont=0;
    }

    printf("\n\n#### UNIAO DOS CONJUNTOS ####\n");
    CImprime(conjResult);
}

void IntersecaoConj(TConjunto *conjunto, TConjunto *conjunto2){
    TConjunto conjResult;
    TNodo *aux1, *aux2;

    FCVazio(&conjResult);
    aux1 = conjunto->first->prox;
    aux2 = conjunto2->first->prox;

    while(aux1 != NULL){
        while(aux2 != NULL){
            if(aux1->info.chave == aux2->info.chave){
                CInsere(&conjResult, &aux1->info);
                if(aux1->prox != NULL){
                    aux1 = aux1->prox;
                }
                else{
                    break;
                }
                aux2 = conjunto2->first->prox;
            }
            else{
                aux2 = aux2->prox;
            }
        }
        aux2 = conjunto2->first->prox;
        aux1 = aux1->prox;
    }

    printf("\n\n#### INTERSECAO DOS CONJUNTOS ####\n");
    CImprime(&conjResult);
}


