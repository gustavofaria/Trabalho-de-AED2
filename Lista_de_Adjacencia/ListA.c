    #include <stdio.h>
    #include <stdlib.h>
    #include "ListA.h"
    #include "filagrafo.h"


struct no{
    int vertice;
    int peso[4];
    struct no *prox;
};

struct grafo{
    int qtde_vertices, qtde_arestas;
    int *grau;
    No**aresta;
};
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


    int insere_aresta(Grafo *G,int v1,int v2,int capacidade, int custo, int delay, int trafego){

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
            novo->peso[0] = capacidade;
            novo->peso[1] = custo;
            novo->peso[2] = delay;
            novo->peso[3] = trafego;

            novo->prox=G->aresta[v1];
            G->aresta[v1]=novo;
        }

        G->qtde_arestas++;
        G->grau[v1]++;
        G->grau[v2]++;
        return 1;
        }

        int insere_arestaN(Grafo *G,int v1,int v2,int capacidade, int custo, int delay, int trafego){
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
            novo->peso[0] = capacidade;
            novo->peso[1] = custo;
            novo->peso[2] = delay;
            novo->peso[3] = trafego;
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
            novo1->peso[0] = capacidade;
            novo1->peso[1] = custo;
            novo1->peso[2] = delay;
            novo1->peso[3] = trafego;            novo1->prox=G->aresta[v2];
            G->aresta[v2]=novo1;
        }

        return 1;
        }


    void mostra_grafo(Grafo *G){
    if(G==NULL){
        printf("Grafo não existe");
    }
    else if(G->qtde_arestas==0){
        printf("Grafo Vazio");
    }
    No *aux;
    int i;
    for(i=0;i<=G->qtde_vertices;i++){
    aux=G->aresta[i];
    while(aux!=NULL){
        printf("Vertice [%d]:  %d Pesos:(%d,%d,%d,%d)   ",i,aux->vertice,aux->peso[0],aux->peso[1],aux->peso[2],aux->peso[3]);
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


    int consulta_aresta(Grafo *G,int v1,int v2,int *capacidade, int * custo, int *delay, int * trafego)
    {

    if(G==NULL || (v1<0 || v2<0)){
        return -1;
    }

    No *aux;
    aux=G->aresta[v1];
    while(aux!=NULL && aux->vertice!=v2)
    {
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

    *capacidade = aux->peso[0];
    *custo = aux->peso[1];
    *delay = aux->peso[2];
    *trafego = aux->peso[3];

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
        printf("O vertice não possui adjacentes");
    }
    else{
        while(aux!=NULL){
            printf("  V -> %d = (%d,%d,%d,%d),",aux->vertice,aux->peso[0],aux->peso[1],aux->peso[2],aux->peso[3]);
            aux=aux->prox;
        }

    }

    }

    }

void imprime_grafo(Grafo *G)
{
    int i;
    FILE *arq;
    arq = fopen("teste.grafo","w");
    fprintf(arq,"%d\n", G->qtde_vertices);

    No *aux;
    i=G->qtde_vertices;
    while(i--)
    {
        aux=G->aresta[i];
        while(aux!=NULL)
        {
            fprintf(arq,"   [%d][%d]:(%d,%d,%d,%d)   \n",i,aux->vertice,aux->peso[0],aux->peso[1],aux->peso[2],aux->peso[3]);
            aux=aux->prox;
        }
    }
    fclose(arq);
}
    Grafo *le_grafo()
        {
            Grafo *G;
            FILE * arq;
            int tam, inicial, final, capacidade, custo, delay, trafego;

            arq = fopen("teste.grafo","r");
            fscanf(arq,"%d",&tam);
            G = cria_grafo(tam);
            //fscanf(arq,"%c",&capacidade);
            //fscanf(arq,"%c",&capacidade);
            while(1)
            {
                if(fscanf(arq,"   [%d][%d]:(%d,%d,%d,%d)   \nq", &inicial, &final, &capacidade, &custo, &delay, &trafego)==EOF) break;
                insere_aresta(G,inicial,final,capacidade,custo,delay,trafego);
            }
            fclose(arq);
            return G;
        }

    void busca_profundidadeN(Grafo *G,int v,int *visitados, int metrica){

    visitados[v]=1;

    printf("  %d  ",v);

    No *aux;
    aux=G->aresta[v];


    while(aux!=NULL){
        if(visitados[aux->vertice]==0){
        busca_profundidade(G,aux->vertice,visitados, metrica);
        }
        aux=aux->prox;
    }

    }


    void DPSN(Grafo *G,int v){

    int *visitados;

    visitados=calloc(G->qtde_vertices,sizeof(int));

    busca_profundidade(G,v,visitados);

    }

    void busca_larguraN(Grafo *G,int v){

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

    int *DijkstraN(Grafo *G,int v0)
{
    int*Distancias=malloc(G->qtde_vertices*sizeof(int));
    int*Visitados=calloc(G->qtde_vertices,sizeof(int));
    int i,k,menor,h=0,aux;
    No *aux2;

    Visitados[v0]=1;
    for(i=0; i<G->qtde_vertices; i++)
    {
        Distancias[i]=99999;
    }
    Distancias[v0]=0;
    aux2=G->aresta[v0];
    while(aux2!=NULL){

            Distancias[aux2->vertice]=aux2->peso;

    aux2=aux2->prox;
    }
    int q;
    for(k=2; k<G->qtde_vertices; k++)
    {
        printf("\n");
        aux=Distancias[h];
        menor=h;
        for(i=0; i<G->qtde_vertices; i++)
        {


            if(aux>Distancias[i] && Visitados[i]!=1)
            {
                aux=Distancias[i];
                menor=i;
            }
        }
        Visitados[menor]=1;
        aux2=G->aresta[menor];
        while(aux2!=NULL){

                int D=Distancias[menor]+aux2->peso;
                if(D<Distancias[aux2->vertice])
                {
                    Distancias[aux2->vertice]=D;
                }
        aux2=aux2->prox;
        }
    h++;
    }



    return Distancias;
}

int numVertices(Grafo *G){
return G->qtde_vertices;
}

int grauVertice(Grafo *G,int v){
return G->grau[v];
}

int ehAdjacente(Grafo *G,int v1,int v2){
return verifica_aresta(G,v1,v2);
}