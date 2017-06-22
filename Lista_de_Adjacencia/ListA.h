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
void busca_profundidade(Grafo *G,int v,int *visitados);
void DPS(Grafo *G,int v);
void busca_largura(Grafo *G,int v);
#endif // LISTA_H_INCLUDED
