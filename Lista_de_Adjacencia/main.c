#include <stdio.h>
#include <stdlib.h>
#include "ListA.h"
#include "filagrafo.h"

int main()
{

Grafo *G;

G=cria_grafo(5);
insere_aresta(G,0,2,2,2,2,2);
insere_aresta(G,2,0,2,2,2,2);
insere_aresta(G,0,1,1,1,1,1);
insere_aresta(G,1,2,5,5,5,5);
insere_aresta(G,1,4,4,4,4,4);
insere_aresta(G,1,3,3,3,3,3);
insere_aresta(G,1,0,2,2,2,2);
insere_aresta(G,2,4,4,4,4,4);
insere_aresta(G,2,0,3,3,3,3);
insere_aresta(G,2,1,2,2,2,2);
insere_aresta(G,3,5,3,3,3,3);
insere_aresta(G,3,4,2,2,2,2);
insere_aresta(G,3,1,5,5,5,5);
insere_aresta(G,4,3,2,2,2,2);
insere_aresta(G,4,2,5,2+3,5,5);
insere_aresta(G,4,1,4,5,5,5);
insere_aresta(G,5,3,3,3,3,3);

//int a;

imprime_grafo(G);
mostra_grafo(G);
printf("\n\n");
remove_arestaN(G,0,2);
mostra_grafo(G);
printf("\n\n");
insere_arestaN(G,0,2,2,2,2,2);
mostra_grafo(G);

//busca_largura(G,0);

/*a=verifica_aresta(G,1,3);
printf("%d\n",a);
mostra_adjacentes(G,1);

printf("\n\n");

printf("%d\n",remove_aresta(G,1,1));

mostra_grafo(G);
a=verifica_aresta(G,1,1);
printf("%d\n",a);

int peso=0;

consulta_aresta(G,3,3,&peso);

printf("Peso da aresta: %d\n ",peso);

mostra_adjacentes(G,1);

printf("\n\n");

DPS(G,0);

libera_grafo(&G);
*/

/*Fila *f;
int v[5];

f=cria_fila(5);

insere_fila(f,2);
insere_fila(f,3);
insere_fila(f,5);
insere_fila(f,6);
insere_fila(f,7);

mostra_fila(f);
printf("\n\n\n-----");

v[0]=remove_fila(f);
v[1]=remove_fila(f);
v[2]=remove_fila(f);
v[3]=remove_fila(f);
v[4]=remove_fila(f);

int i;

for(i=0;i<5;i++){
    printf(" %d ",v[i]);
}

mostra_fila(f);
*/
    return 0;
}
