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

int x,v,v1,v2,v0,vf;
int *A,*visitado;
while(1){

printf("                                                ROTEAMENTO MULTICAST            ");
printf("\n\n               MENU \n\n");
printf("1: NUMERO DE VERTICES DO GRAFO\n");
printf("2: GRAU DE UM VERTICE ESCOLHIDO\n");
printf("3: ADJACENCIA ENTRE DOIS VERTICES ESCOLHIDOS\n");
printf("4: DIJKSTRA\n");
printf("5: BUSCA EM PROFUNDIDADE\n");
printf("6: BUSCA EM LARGURA\n");
printf("7: SAIR");

printf("\n SELECIONE UMA OPCAO: ");
scanf("%d",&x);
getchar();

switch(x){

    case 1:printf("%d",numVertices(G));
           break;

    case 2:printf("\n ESCREVA O VERTICE QUE DESEJA:\n");
           printf("v: ");
           scanf("%d",&v);
    printf("%d",grauVertice(G,v));
    break;

    case 3:printf("ESCREVA OS VERTICES QUE VOCE DESEJA:\n");
           printf("v1: ");
           scanf("%d",&v1);
           printf("v2: ");
           scanf("%d",&v2);
           if(ehAdjacente(G,v1,v2)==1){
            printf("EH ADJACENTE");
           }else{
           printf("NAO EH ADJACENTE");
           }
           break;

    case 4:printf("ESCREVA O VERTICE INICIAL:");
           scanf("%d",&v0);
           printf("\n");
           printf("ESCREVA  VERTICE FINAL:");
           scanf("%d",&vf);
          // DijkstraN(G1,v0,A,1,vf,10);
          break;

    case 5:printf("ESCREVA O VERTICE INICIAL:");
           scanf("%d",&v0);
           printf("\n");
           printf("ESCREVA O VERTICE FINAL:");
           scanf("%d",&vf);
         //  busca_profundidadeN(G1,v0,vf,visitado,1,2);
           break;

    case 6:printf("ESCREVA O VERTICE INICIAL:");
           scanf("%d",&v0);
           printf("\n");
           printf("ESCREVA O VERTICE FINAL:");
           scanf("%d",&vf);
//           busca_larguraN(G1,v0,vf,1,2);
           break;

    case 7: exit(1);

}
}

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
