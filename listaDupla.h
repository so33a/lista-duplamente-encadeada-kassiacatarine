#ifndef ATIVIDADE_H_INCLUDED
#define ATIVIDADE_H_INCLUDED

typedef struct node * link;
struct node {
  int item;
  link next;
  link prev;
};

typedef struct {
   link head;
   link z;
} * ListaDupla;

ListaDupla inicializa();
link novoNo (int item, link prev, link next);
link buscar(ListaDupla l, int item);
void insereDepois (ListaDupla l, link x, link t);
void insereAntes (ListaDupla l, link x, link t);
link removeNo (link x);
void imprime (ListaDupla l);
void imprimeReverso (ListaDupla l);
void destroiLista (ListaDupla l);
link procuraMenor (ListaDupla l);
void trocaNo(ListaDupla l, link A, link B);
void ordena (ListaDupla l);


#endif // ATIVIDADE_H_INCLUDED
