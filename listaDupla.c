#include <stdio.h>
#include <stdlib.h>
#include "atividade.h"


link procuraMenor(ListaDupla l){
    link menor = l->head;
    link no = l->head;
    while(no != l->z){//Enquanto no for diferente do final ele continua
        if(no->item < menor->item){//Se o item do no for menor que o guardado no menor troca
        menor = no;
    }
    no = no->next;
    }
    return menor;//Retorna o menor encontrado
}

void trocaNo(ListaDupla l, link A, link B){
    link aux = B;


    A->next->prev = B;
    A->prev->next = B;
    A->next = B->next;
    A->prev = B->prev;
    B->prev->next = A;
    B->next->prev = A;
    B->next = aux->next;
    B->prev = aux->prev;

    free(aux);
}

void ordena(ListaDupla l){
    link t = l->head;
    int i;
    while(t != l->z){

        link menor = procuraMenor(l);
        if(t->item > menor->item){
            trocaNo(l, t, menor);
        }
        t = t->next;
    }
}

/*
void ordena(ListaDupla l){
  link aux = l->head;
  link aux2 = aux->next;
  for(aux = l->head; aux != l->head; aux = aux->next){//Estrutura do Selection Sort
    for(aux2 = aux->next; aux2 != l->z; aux2 = aux2->next){
      if(aux->item > aux2->item){//Se o item anterior for maior que o proximo, troca todos os lugares de ponteiros alterando-os de posição
        aux->next = aux2->next;
        aux2->next->prev = aux->next;
        aux2->prev = aux->prev;
        aux->prev->next = aux2->next;
        aux->prev = aux2->next;
        aux2->next = aux->prev;
      }
    }
  }
}
*/

link novoNo (int item, link prev, link next) {
  link aux = malloc(sizeof(struct node));
  if (aux == NULL) {
    printf ("Erro ao alocar um novo no\n");
    exit(-1);
  }
  aux->item = item;
  aux->prev = prev;
  aux->next = next;
  return aux;
}


ListaDupla inicializa() {
  ListaDupla aux;
  aux = malloc(sizeof *aux);
  aux->head = NULL;
  aux->z = novoNo(0, NULL, NULL);
  return aux;
}

void insereDepois (ListaDupla l, link x, link t) {
  if (x == NULL) {
    l->head = t;
    t->next = l->z;
    t->prev = l->z;
    l->z->prev = t;
    l->z->next = t;
  } else {
    t->next = x->next;
    t->prev = x;
    x->next = t;
    t->next->prev = t;
  }
}

link removeNo (link x) {
  x->prev->next = x->next;
  x->next->prev = x->prev;
  return x;
}
void imprimeReverso(ListaDupla l) {
  link t = l->z->prev;
  while ( t != l->z ) {
    printf ("%d ", t->item);
    t = t->prev;
  }
  printf("\n");
}


void imprime(ListaDupla l) {
  link t = l->head;
  while ( t != l->z ) {
    printf ("%d ", t->item);
    t = t->next;
  }
  printf("\n");
}

link buscar(ListaDupla l, int item) {
  link t = l->head;
  while ( t != l->z ) {
    if(t->item == item)
      return t;
    t = t->next;
  }
  return NULL;
}
/*
void insereAntes (ListaDupla l, link x, link t);
*/

void destroiLista(ListaDupla l) {
  link t = l->head;
  while (t != l->z) {
    l->head = t->next;
    l->z->next = t->next;
    l->head->prev = l->z;
    free(t);
    t = l->head;
  }
  free(t);
  free(l);
}
