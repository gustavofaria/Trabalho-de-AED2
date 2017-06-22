#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

struct no{
    int vertice;
    int peso[4];
    struct no *prox;
};
typedef struct no No;

struct grafo{
    int qtde_vertices, qtde_arestas;
    int *grau;
    No**aresta;
};

typedef struct grafo Grafo;

Grafo *cria_grafo(int n);
int insere_aresta(Grafo *G,int v1,int v2,int peso);
int insere_arestaN(Grafo *G,int v1,int v2,int peso);
void mostra_grafo(Grafo *G);
int verifica_aresta(Grafo *G,int v1,int v2);
int remove_aresta(Grafo *G,int v1,int v2);
int remove_arestaN(Grafo *G,int v1,int v2);
int consulta_aresta(Grafo *G,int v1,int v2,int *peso);
void libera_grafo(Grafo **G);
void mostra_adjacentes(Grafo *G,int v);
void busca_profundidade(Grafo *G,int v,int *visitados);
void DPS(Grafo *G,int v);
void busca_largura(Grafo *G,int v);
#endif // LISTA_H_INCLUDED
