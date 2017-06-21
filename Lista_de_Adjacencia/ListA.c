#include <stdio.h>
#include <stdlib.h>
#include "ListA.h"
#include "filagrafo.h"


Grafo *cria_grafo(int n){

if(n<=0){
    return NULL;
}

Grafo *G;

G=malloc(sizeof(Grafo));
if(G==NULL){
    free(G);
    return NULL;
}

G->qtde_vertices=n;
G->qtde_arestas=0;

G->grau=calloc(n,sizeof(int));
if(G->grau==NULL){
    free(G->grau);
    free(G);
    return NULL;
}
G->aresta=calloc(n,sizeof(No));
int i;
for(i=0;i<G->qtde_vertices;i++){
    G->aresta[i]=NULL;
}
if(G->aresta==NULL){
    free(G->aresta);
    free(G->grau);
    free(G);
    return NULL;
}

return G;

}


int insere_aresta(Grafo *G,int v1,int v2,int peso){

    if(G==NULL || (v1<0 || v2<0)){
        return -1;
    }

    No *aux;

        aux=G->aresta[v1];
        while(aux!=NULL && aux->vertice!=v2){
           aux=aux->prox;
        }
       if(aux!=NULL){
        return 0;
       }

    No *novo=malloc(sizeof(No));
    if(novo!=NULL){
        novo->vertice=v2;
        novo->peso=peso;
        novo->prox=G->aresta[v1];
        G->aresta[v1]=novo;
    }

    G->qtde_arestas++;
    G->grau[v1]++;
    G->grau[v2]++;
    return 1;
    }

int insere_arestaN(Grafo *G,int v1,int v2,int peso){
    if(G==NULL || (v1<0 || v2<0)){
        return -1;
    }

    No *aux;

        aux=G->aresta[v1];
        while(aux!=NULL && aux->vertice!=v2){
           aux=aux->prox;
        }
       if(aux!=NULL){
        return 0;
       }

    No *novo=malloc(sizeof(No));
    if(novo!=NULL){
        novo->vertice=v2;
        novo->peso=peso;
        novo->prox=G->aresta[v1];
        G->aresta[v1]=novo;
    }

    G->qtde_arestas++;
    G->grau[v1]++;
    G->grau[v2]++;

    No *aux2;

        aux2=G->aresta[v2];
        while(aux2!=NULL && aux2->vertice!=v1){
           aux2=aux2->prox;
        }
       if(aux2!=NULL){
        return 0;
       }

    No *novo1=malloc(sizeof(No));
    if(novo1!=NULL){
        novo1->vertice=v1;
        novo1->peso=peso;
        novo1->prox=G->aresta[v2];
        G->aresta[v2]=novo1;
    }

    return 1;
    }


void mostra_grafo(Grafo *G){
if(G==NULL){
    printf("Grafo n�o existe");
}
else if(G->qtde_arestas==0){
    printf("Grafo Vazio");
}
No *aux;
int i;
for(i=0;i<=G->qtde_vertices;i++){
aux=G->aresta[i];
while(aux!=NULL){
    printf("Vertice [%d]:  %d Peso:%d   ",i,aux->vertice,aux->peso);
    aux=aux->prox;
}
printf("\n\n");

}

}


int verifica_aresta(Grafo *G,int v1,int v2){
if(G==NULL || (v1<0 || v2<0)){
    return -1;
}
No *aux;
aux=G->aresta[v1];
while(aux!=NULL && aux->vertice!=v2){
    aux=aux->prox;
}
if(aux==NULL){
    return 0;
}

return 1;
}


int remove_aresta(Grafo *G,int v1,int v2){
   if(G==NULL || (v1<0 || v2<0)){
      return -1;
}

No *aux;
aux=G->aresta[v1];
while(aux!=NULL && aux->vertice!=v2){
    aux=aux->prox;
}
if(aux==NULL){
    return 0;
}

No *aux1,*ant;

ant=NULL;
aux1=G->aresta[v1];

while(aux1->vertice!=v2){
    ant=aux1;
    aux1=aux1->prox;

}
ant->prox=aux1->prox;
free(aux1);
G->qtde_arestas--;
G->grau[v1]--;
G->grau[v2]--;

return 1;
}

int remove_arestaN(Grafo *G,int v1,int v2){
   if(G==NULL || (v1<0 || v2<0)){
      return -1;
}

No *aux;
aux=G->aresta[v1];
while(aux!=NULL && aux->vertice!=v2){
    aux=aux->prox;
}
if(aux==NULL){
    return 0;
}else{
No *aux1,*ant;

ant=NULL;
aux1=G->aresta[v1];

while(aux1->vertice!=v2){
    ant=aux1;
    aux1=aux1->prox;

}
ant->prox=aux1->prox;
free(aux1);
G->qtde_arestas--;
G->grau[v1]--;
G->grau[v2]--;
}

No *aux0;
aux0=G->aresta[v2];
while(aux0!=NULL && aux0->vertice!=v1){
    aux0=aux0->prox;
}
if(aux0==NULL){
    return 0;
}

No *aux2,*ant2;

ant2=NULL;
aux2=G->aresta[v2];

while(aux2->vertice!=v1){
    ant2=aux2;
    aux2=aux2->prox;

}
ant2->prox=aux2->prox;
free(aux2);

return 1;
}


int consulta_aresta(Grafo *G,int v1,int v2,int *peso){

if(G==NULL || (v1<0 || v2<0)){
    return -1;
}

No *aux;
aux=G->aresta[v1];
while(aux!=NULL && aux->vertice!=v2){
    aux=aux->prox;
}
if(aux==NULL){
    return 0;
}

No *aux1;
aux1=G->aresta[v1];
while(aux1->vertice!=v2){
    aux1=aux1->prox;
}

*peso=aux1->peso;

return 1;
}


void libera_grafo(Grafo **G){
if((*G)!=NULL){
   int i;
   No *aux,*ant;
   for(i=0;i<(*G)->qtde_vertices;i++){
    aux=(*G)->aresta[i];
    ant=NULL;
    while(aux!=NULL){
        ant=aux;
        aux=aux->prox;
        free(ant);
    }
   }

   free((*G)->grau);
   free(*G);
   *G=NULL;
}


}

void mostra_adjacentes(Grafo *G,int v){
if(G!=NULL && v>0){

No *aux;
aux=G->aresta[v];
if(aux==NULL){
    printf("O vertice n�o possui adjacentes");
}
else{
    while(aux!=NULL){
        printf("  V -> %d = %d,",aux->vertice,aux->peso);
        aux=aux->prox;
    }

}

}

}

void busca_profundidade(Grafo *G,int v,int *visitados){

visitados[v]=1;

printf("  %d  ",v);

No *aux;
aux=G->aresta[v];


while(aux!=NULL){
    if(visitados[aux->vertice]==0){
    busca_profundidade(G,aux->vertice,visitados);
    }
    aux=aux->prox;
}

}


void DPS(Grafo *G,int v){

int *visitados;

visitados=calloc(G->qtde_vertices,sizeof(int));

busca_profundidade(G,v,visitados);

}

void busca_largura(Grafo *G,int v){

int *visitados;
int vet=0;
visitados=calloc(G->qtde_vertices,sizeof(int));

Fila *f;
f=cria_fila(G->qtde_vertices);

visitados[v]=1;

printf("  %d ",v);

insere_fila(f,v);
while(f->primeiro!=NULL){
   vet=remove_fila(f);
No *aux;
aux=G->aresta[vet];

while(aux!=NULL){
    if(visitados[aux->vertice]==0){
        visitados[aux->vertice]=1;
        printf("%d ",aux->vertice);
        insere_fila(f,aux->vertice);
    }
aux=aux->prox;
}

}

}


