#include <stdio.h>
#include <stdlib.h>
#include "atividade.h"
#include "atividade2.c"


int main () {
  ListaDupla l = inicializa();
  link aux, aux2;
  int menor;

  insereDepois(l, l->head, novoNo(33,NULL, NULL));
  insereDepois(l, l->head, aux= novoNo(12, NULL, NULL));
  aux2 = novoNo(2, NULL, NULL);
  insereDepois(l,aux,aux2);
  aux = novoNo(42, NULL, NULL);
  insereDepois(l, aux2, aux);
  imprime(l);
  imprimeReverso(l);
  aux = procuraMenor (l);
  printf("\nMenor: %d\n", *aux);
  printf("\nAntes de ordenar\n");
  imprime(l);
  ordena(l);
  printf("Ordenado\n");
  imprime(l);
  printf("Ordenado");
  printf ("\nremovendo %d \n", aux2->item);
  if((aux2 = buscar(l, 21) ) != NULL)
    removeNo(aux2);
  imprime(l);
  destroiLista(l);

  return 0;
}
