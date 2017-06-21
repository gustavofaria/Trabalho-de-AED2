#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "fila.h"
#include <limits.h>

int main()
{
Grafo *G1=malloc(sizeof(Grafo));
G1=cria_grafo(8);
insere_aresta(G1,0,1,20);
insere_aresta(G1,1,0,20);
insere_aresta(G1,0,3,80);
insere_aresta(G1,0,6,90);
insere_aresta(G1,1,5,10);
insere_aresta(G1,5,2,10);
insere_aresta(G1,5,3,40);
insere_aresta(G1,2,5,50);
insere_aresta(G1,2,7,20);
insere_aresta(G1,2,3,10);
insere_aresta(G1,3,6,20);
insere_aresta(G1,6,0,20);
insere_aresta(G1,4,6,30);
insere_aresta(G1,4,1,50);

mostra_matriz(G1);
printf("\n\n");
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
