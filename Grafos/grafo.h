#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED


typedef struct aresta Aresta;

typedef struct grafo Grafo;

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
void imprime_grafo(Grafo *G);
 Grafo *le_grafo();
void busca_profundidade(Grafo *G,int v,int *visitado);
void DFS(Grafo *G,int v);
void busca_largura(Grafo *G,int v);
int *DijkstraN(Grafo *G,int v0,int *A,int metrica,int fim,int tamanho);
int numVertices(Grafo *G);
int grauVertice(Grafo *G,int v);
int ehAdjacente(Grafo *G,int v1,int v2);
void mostra_caminho(int Vini,int Vfim,int *A);
void busca_profundidadeN(Grafo *G,int v,int vfi,int *visitado,int metrica,int tamanho);
void DFSN(Grafo *G,int v,int vfi,int metrica,int tamanho);
void busca_larguraN(Grafo *G,int v,int vf,int tamanho,int metrica);
#endif // GRAFO_H_INCLUDED
