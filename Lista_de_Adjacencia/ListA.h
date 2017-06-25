#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED


typedef struct no No;

typedef struct grafo Grafo;

Grafo *cria_grafo(int n);
int insere_aresta(Grafo *G,int v1,int v2,int capacidade, int custo, int delay, int trafego);
int insere_arestaN(Grafo *G,int v1,int v2,int capacidade, int custo, int delay, int trafego);
void mostra_grafo(Grafo *G);
int verifica_aresta(Grafo *G,int v1,int v2);
int remove_aresta(Grafo *G,int v1,int v2);
int remove_arestaN(Grafo *G,int v1,int v2);
int consulta_aresta(Grafo *G,int v1,int v2,int *capacidade, int * custo, int *delay, int * trafego);
void libera_grafo(Grafo **G);
void mostra_adjacentes(Grafo *G,int v);
void imprime_grafo(Grafo *G);
Grafo *le_grafo();
void busca_profundidadeN(Grafo *G,int v,int *visitados, int metrica);
void DPSN(Grafo *G,int v,int vfi,int metrica,int tamanho);
void busca_larguraN(Grafo *G,int v);
int numVertices(Grafo *G);
int grauVertice(Grafo *G,int v);
int ehAdjacente(Grafo *G,int v1,int v2);
int *DijkstraN(Grafo *G,int v0,int metrica);

#endif // LISTA_H_INCLUDED
