#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include <limits.h>

Fila* cria_fila(int n){

Fila *f;
f=malloc(n*sizeof(Node));

if(f==NULL){
    return NULL;
}
f->size=0;
f->primeiro=NULL;
f->ultimo=NULL;

return f;
}

void insere_fila(Fila *f,int n){

Node *novo;
novo=malloc(sizeof(Node));

if(f->size==0){
    novo->dado=n;
    f->primeiro=novo;
    f->ultimo=novo;
    novo->prox=NULL;
    f->size++;
}else{

Node *aux2;

aux2=f->primeiro;
while(aux2->prox!=NULL){
    aux2=aux2->prox;
}

novo->dado=n;
aux2->prox=novo;
novo->prox=NULL;
f->ultimo=novo;
f->size++;

}

}

void mostra_fila(Fila *f){

Node *aux;
aux=f->primeiro;

while(aux!=NULL){
    printf(" %d ",aux->dado);
    aux=aux->prox;
}

printf("\n\n");
printf(" %d ",f->size);


}

int remove_fila(Fila *f){

    if(f->size==1){
        Node *aux;
        aux=f->primeiro;
        f->primeiro=NULL;
        f->ultimo=NULL;
        f->size--;
        return aux->dado;
    }else{
    Node *aux;
    aux=f->primeiro;
    f->primeiro=f->primeiro->prox;
    f->size--;
    return aux->dado;
}
}

