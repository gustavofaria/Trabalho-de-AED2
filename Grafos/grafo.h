#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED


typedef struct grafo Grafo;

typedef struct aresta Aresta;

Grafo* cria_grafo(int n);
int insere_aresta(Grafo *G,int v1,int v2, int capacidade, int custo, int delay, int trafego);
int insere_arestaN(Grafo *G,int v1,int v2,int capacidade, int custo, int delay, int trafego);
void mostra_matriz(Grafo *G);
int verifica_aresta(Grafo *G,int v1,int v2);
int remove_aresta(Grafo *G,int v1,int v2);
int remove_arestaN(Grafo *G,int v1,int v2);
int consulta_aresta(Grafo *G,int v1,int v2,int *capacidade, int*custo, int *delay, int *trafego);
void libera_grafo(Grafo **G);
void mostra_adjacentes(Grafo *G,int v);
void mostra_grafo(Grafo *G);
void busca_profundidade(Grafo *G,int v,int *visitado);
void DFS(Grafo *G,int v);
void busca_largura(Grafo *G,int v);
int Dijkstra(Grafo *G,int v0,int *D);

#endif // GRAFO_H_INCLUDED
