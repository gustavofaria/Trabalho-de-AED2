#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "fila.h"
#include <limits.h>

int main()
{

Grafo *G1;
G1=cria_grafo(8);

insere_aresta(G1,0,1,20,03,04,666);
insere_aresta(G1,1,0,20,666,20,20);
insere_aresta(G1,0,3,80,80,80,80);
insere_aresta(G1,0,6,90,900,90,90);
insere_aresta(G1,1,5,10,10,10,10);
insere_aresta(G1,5,2,10,10,10,10);
insere_aresta(G1,5,3,40,40,40,40);
insere_aresta(G1,2,5,50,50,50,50);
insere_aresta(G1,2,7,20,20,20,20);
insere_aresta(G1,2,3,10,10,10,10);
insere_aresta(G1,3,6,20,20,20,20);
insere_aresta(G1,6,0,20,20,20,20);
insere_aresta(G1,4,6,30,30,30,30);
insere_aresta(G1,4,1,50,50,50,50);

//imprime_grafo(G1);


//G1 = le_grafo();
//mostra_adjacentes(G1,2);
printf("\n\n");

int x,v,v1,v2,v0,vf;
int *A,*visitado;

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

switch(x){

    case 1:printf("%d",numVertices(G1));
           break;

    case 2:printf("\n ESCREVA O VERTICE QUE DESEJA:\n");
           printf("v: ");
           scanf("%d",&v);
    printf("%d",grauVertice(G1,v));
    break;

    case 3:printf("ESCREVA OS VERTICES QUE VOCE DESEJA:\n");
           printf("v1: ");
           scanf("%d",&v1);
           printf("v2: ");
           scanf("%d",&v2);
           if(ehAdjacente(G1,v1,v2)==1){
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


// int s;
    //Dijkstra(G1,0,&s);
/*remove_arestaN(G1,0,1);
mostra_matriz(G1);
insere_arestaN(G1,0,1,20);
printf("\n\n");
mostra_matriz(G1);
printf("\n\n");
*/

//busca_largura(G1,0);
//DFS(G1,0);
   /* printf("\n\n\n");
    remove_aresta(G1,1,1);
    remove_aresta(G1,2,3);
    mostra_matriz(G1);

    printf("%d\n",verifica_aresta(G1,1,1));
    printf("%d\n\n",verifica_aresta(G1,3,2));

    int x;
    consulta_aresta(G1,1,2,&x);
    printf("%d\n",x);
    //mostra_adjacentes(G1,1);
    mostra_grafo(G1);

    libera_grafo(&G1);
*/



    return 0;
}
