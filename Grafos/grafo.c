    #include <stdio.h>
    #include <stdlib.h>

    #include "grafo.h"
    #include "fila.h"
    #include <limits.h>
    
    struct aresta{
        int capacidade;
        int custo;
        int delay;
        int trafego;
    };

    struct grafo{
        int qtd_ver,qtd_are;
        int *grau;
        Aresta **aresta;
    };


    Grafo* cria_grafo(int n_ver){
        int i,k;
        if(n_ver<=0){
            return NULL;
        }

        Grafo *G;
        G=malloc(sizeof(struct grafo));
        if(G==NULL){
            return NULL;
        }else{


        G->qtd_ver=n_ver;
        G->qtd_are=0;


        G->grau=malloc(G->qtd_ver*sizeof(int));
        if (G->grau == NULL) {
            free (G);
            return NULL;
        }

        G->aresta=malloc(G->qtd_ver*sizeof(Aresta*));
            if (G->aresta == NULL) {
            free(G->grau);  free(G);  return NULL;
        }
        for(i=0;i<G->qtd_ver;i++){
            G->aresta[i]=calloc(G->qtd_ver,sizeof(Aresta));
        
                if (G->aresta[i]== NULL) {
                  for (k=0; k < i; k++) free(G->aresta[k]);
                  free(G->aresta);  free(G->grau);  free(G);  return NULL;
             }
        }
        return G;
    }
        }

    int insere_aresta(Grafo *G,int v1,int v2, int capacidade, int custo, int delay, int trafego){
        if(G==NULL || (v1<0 || v1<0)){
            return -1;
        }

        if((G->aresta[v1][v2].capacidade!=0)||(G->aresta[v1][v2].custo!=0)||(G->aresta[v1][v2].delay!=0)||(G->aresta[v1][v2].trafego!=0)){
            return 0;
        }

        G->aresta[v1][v2].capacidade = capacidade;
        G->aresta[v1][v2].custo = custo;
        G->aresta[v1][v2].delay = delay;
        G->aresta[v1][v2].trafego = trafego;


        G->qtd_are++;
        G->grau[v1]++;
        G->grau[v2]++;

        return 1;
    }

    int insere_arestaN(Grafo *G,int v1,int v2, int capacidade, int custo, int delay, int trafego){
        if(G==NULL || (v1<0 || v1<0)){
            return -1;
        }

        if((G->aresta[v1][v2].capacidade!=0)||(G->aresta[v1][v2].custo!=0)||(G->aresta[v1][v2].delay!=0)||(G->aresta[v1][v2].trafego!=0)){
            return 0;
        }

        if((G->aresta[v2][v1].capacidade!=0)||(G->aresta[v2][v1].custo!=0)||(G->aresta[v2][v1].delay!=0)||(G->aresta[v2][v1].trafego!=0)){
            return 0;
        }

        G->aresta[v1][v2].capacidade = capacidade;
        G->aresta[v1][v2].custo = custo;
        G->aresta[v1][v2].delay = delay;
        G->aresta[v1][v2].trafego = trafego;
        G->qtd_are++;
        G->grau[v1]++;
        G->grau[v2]++;

        G->aresta[v2][v1].capacidade = capacidade;
        G->aresta[v2][v1].custo = custo;
        G->aresta[v2][v1].delay = delay;
        G->aresta[v2][v1].trafego = trafego;


        return 1;
    }

    void mostra_matriz(Grafo *G){
        if(G==NULL){
            printf("ERRO!!!");
        }else{
        int i=0,j=0;
        for(i=0;i<G->qtd_ver;i++){
           for(j=0;j<G->qtd_ver;j++){

                printf("   [%d][%d]:(%d,%d,%d,%d)   ",i,j,G->aresta[i][j].capacidade,G->aresta[i][j].custo,G->aresta[i][j].delay, G->aresta[i][j].trafego );

           }
        printf("\n");
        }
        }
    }

    int verifica_aresta(Grafo *G,int v1,int v2){
        if(G==NULL || (v1<=0 || v1<=0)){
            return -1;
        }

        if(G->aresta[v1][v2].capacidade||G->aresta[v1][v2].custo||G->aresta[v1][v2].delay||G->aresta[v1][v2].trafego){
            return 1;
        }

    return 0;
    }


    int remove_aresta(Grafo *G,int v1,int v2){
        if(G==NULL || (v1<0 || v1<0)){
            return -1;
        }

     if(!(G->aresta[v2][v1].capacidade||G->aresta[v2][v1].custo||G->aresta[v2][v1].delay||G->aresta[v2][v1].trafego)){
            return 0;
        }

        G->aresta[v1][v2].capacidade = 0;
        G->aresta[v1][v2].custo = 0;
        G->aresta[v1][v2].delay = 0;
        G->aresta[v1][v2].trafego = 0;
        G->grau[v1]--;
        G->grau[v2]--;

        return 1;
    }

    int remove_arestaN(Grafo *G,int v1,int v2){
        if(G==NULL || (v1<0 || v1<0)){
            return -1;
        }

      if(G->aresta[v1][v2].capacidade||G->aresta[v1][v2].custo||G->aresta[v1][v2].delay||G->aresta[v1][v2].trafego){
            return 0;
        }
      if(G->aresta[v2][v1].capacidade||G->aresta[v2][v1].custo||G->aresta[v2][v1].delay||G->aresta[v2][v1].trafego){
            return 0;
        }


        G->aresta[v1][v2].capacidade = 0;
        G->aresta[v1][v2].custo = 0;
        G->aresta[v1][v2].delay = 0;
        G->aresta[v1][v2].trafego = 0;
        G->grau[v1]--;
        G->grau[v2]--;


        G->aresta[v2][v1].capacidade = 0;
        G->aresta[v2][v1].custo = 0;
        G->aresta[v2][v1].delay = 0;
        G->aresta[v2][v1].trafego = 0;

        return 1;
    }

    int consulta_aresta(Grafo *G,int v1,int v2,int *capacidade, int*custo, int *delay, int *trafego){
         if(G==NULL || (v1<=0 || v1<=0)){
            return -1;
        }

     if(!(G->aresta[v1][v2].capacidade||G->aresta[v1][v2].custo||G->aresta[v1][v2].delay||G->aresta[v1][v2].trafego)){
            return 0;
        }

        *capacidade = G->aresta[v1][v2].capacidade;
        *custo = G->aresta[v1][v2].custo;
        *delay = G->aresta[v1][v2].delay;
        *trafego = G->aresta[v1][v2].trafego;

        return 1;
    }

    void libera_grafo(Grafo **G){
        int i;
        for(i=0;i<(*G)->qtd_are;i++){
            free((*G)->aresta[i]);
        }

        free((*G)->aresta);
        free((*G)->grau);
        free(*G);
        *G=NULL;
    }


    void mostra_adjacentes(Grafo *G,int v){
        if(G==NULL || v<0){
        printf("ERRO!!!");
        }else{

        int i;
        for(i=0;i<G->qtd_ver;i++){
     if(((G->aresta[v][i].capacidade)||(G->aresta[v][i].custo)||(G->aresta[v][i].delay)||(G->aresta[v][i].trafego))){
                printf("   [%d][%d]:(%d,%d,%d,%d)   ",v,i,G->aresta[v][i].capacidade,G->aresta[v][i].custo,G->aresta[v][i].delay, G->aresta[v][i].trafego );
            }
        }
        }
    }
    void mostra_grafo(Grafo *G)
    {
               if(G==NULL){
          printf("Grafo Inesistente");
        }

        else if(G->qtd_are==0){
            fprintf(stdout,"Grafo Vazio");
        }
        else{
        int i;
        for(i=0;i<G->qtd_ver;i++){
            printf("Vertice %d: \n",i);
            mostra_adjacentes(G,i);
        }
        }
        }
    void imprime_grafo(Grafo *G)
    {
        int i, j;
        FILE *arq;
        arq = fopen("teste.grafo","w");
        fprintf(arq,"%d\n", G->qtd_ver);

        for(i=0;i<G->qtd_ver;i++){
           for(j=0;j<G->qtd_ver;j++){

                fprintf(arq,"   [%d][%d]:(%d,%d,%d,%d)   \n",i,j,G->aresta[i][j].capacidade,G->aresta[i][j].custo,G->aresta[i][j].delay, G->aresta[i][j].trafego );

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
        fscanf(arq,"%c",&capacidade);
        fscanf(arq,"%c",&capacidade);
        while(1)
        {
            if(fscanf(arq,"   [%d][%d]:(%d,%d,%d,%d)   \nq", &inicial, &final, &capacidade, &custo, &delay, &trafego)==EOF) return G;
 /*           fscanf(arq," %d ", &capacidade);
            fscanf(arq," %d ", &custo);
            fscanf(arq," %d ", &delay);
            fscanf(arq," %d ", &trafego);
 */
            insere_aresta(G,inicial,final,capacidade,custo,delay,trafego);
        
        }
    }
    /*

        }



    void busca_profundidade_aux(Grafo *G,int v,int *visitado){
    visitado[v]=1;

    printf(" %d ",v);

    int i;
    for(i=0;i<G->qtd_ver;i++){
        if(visitado[i]==0){
            busca_profundidade(G,i,visitado);
        }
    }

    }

    void DFS(Grafo *G,int v){
    int *visitado;
    visitado=calloc(G->qtd_ver,sizeof(int));
    busca_profundidade(G,v,visitado);

    }

    void busca_largura(Grafo *G,int v){
      int *visitados;
      int vet,i;
      visitados=calloc(G->qtd_ver,sizeof(int));
      Fila *f;
      f=cria_fila(G->qtd_ver);
      visitados[v]=1;
      printf(" %d ",v);
      insere_fila(f,v);
      while(f->primeiro!=NULL){
        vet=remove_fila(f);
        for(i=0;i<G->qtd_ver;i++){
        if(G->aresta[vet][i].capacidade||G->aresta[vet][i].custo||G->aresta[vet][i].delay||G->aresta[vet][i].trafego){
            if(visitados[i]==0){
                visitados[i]=1;
                printf(" %d ",i);
                insere_fila(f,i);
            }
            }
        }
      }






    }

    int Dijkstra(Grafo *G,int v0,int *Menores){


    int *Visita,i;
    Visita=calloc(G->qtd_ver,sizeof(int));
    Menores=malloc(G->qtd_ver*sizeof(int));
    Visita[v0]=1;

    for(i=0;i<G->qtd_ver;i++){
        Menores[i]=999999;
    }
    Menores[0]=0;

    for(i=0;i<G->qtd_ver;i++){
        if(G->aresta[v0][i]!=0)
        Menores[i]=G->aresta[v0][i];
    }
    int k,menor,ind,j;
    for(k=1;k<G->qtd_ver;k++){
    for(i=0;i<G->qtd_ver;i++){
    menor=Menores[i];
    if(Menores[i+1]<menor){
        menor=Menores[i+1];
        ind=i;
    }
    }
    Visita[ind]=1;


    for(j=0;j<G->qtd_ver;j++){
     int d;
     d=(Menores[ind]+G->aresta[ind][j]);
     if(d<Menores[j]){
        Menores[j]=d;
     }
    }
    }



     printf("\n\n\n");
    for(i=0;i<G->qtd_ver;i++){
        if(Menores[i]==999999){
        printf(" infinito ");
        }else
        printf(" %d  ",Menores[i]);
       // printf(" %d  ",Visita[i]);
    }
    return 1;

    }


    */
