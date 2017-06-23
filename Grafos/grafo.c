    #include <stdio.h>
    #include <stdlib.h>

    #include "grafo.h"
    #include "fila.h"
    #include <limits.h>

    struct aresta{
        int peso[4];
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

        if((G->aresta[v1][v2].peso[0]!=0)||(G->aresta[v1][v2].peso[1]!=0)||(G->aresta[v1][v2].peso[2]!=0)||(G->aresta[v1][v2].peso[3]!=0)){
            return 0;
        }

        G->aresta[v1][v2].peso[0] = capacidade;
        G->aresta[v1][v2].peso[1] = custo;
        G->aresta[v1][v2].peso[2] = delay;
        G->aresta[v1][v2].peso[3] = trafego;


        G->qtd_are++;
        G->grau[v1]++;
        G->grau[v2]++;

        return 1;
    }

    int insere_arestaN(Grafo *G,int v1,int v2, int capacidade, int custo, int delay, int trafego){
        if(G==NULL || (v1<0 || v1<0)){
            return -1;
        }

        if((G->aresta[v1][v2].peso[0]!=0)||(G->aresta[v1][v2].peso[1]!=0)||(G->aresta[v1][v2].peso[2]!=0)||(G->aresta[v1][v2].peso[3]!=0)){
            return 0;
        }

        if((G->aresta[v2][v1].peso[0]!=0)||(G->aresta[v2][v1].peso[1]!=0)||(G->aresta[v2][v1].peso[2]!=0)||(G->aresta[v2][v1].peso[3]!=0)){
            return 0;
        }

        G->aresta[v1][v2].peso[0] = capacidade;
        G->aresta[v1][v2].peso[1] = custo;
        G->aresta[v1][v2].peso[2] = delay;
        G->aresta[v1][v2].peso[3] = trafego;
        G->qtd_are++;
        G->grau[v1]++;
        G->grau[v2]++;

        G->aresta[v2][v1].peso[0] = capacidade;
        G->aresta[v2][v1].peso[1] = custo;
        G->aresta[v2][v1].peso[2] = delay;
        G->aresta[v2][v1].peso[3] = trafego;


        return 1;
    }

    void mostra_matriz(Grafo *G){
        if(G==NULL){
            printf("ERRO!!!");
        }else{
        int i=0,j=0;
        for(i=0;i<G->qtd_ver;i++){
           for(j=0;j<G->qtd_ver;j++){

                printf("   [%d][%d]:(%d,%d,%d,%d)   ",i,j,G->aresta[i][j].peso[0],G->aresta[i][j].peso[1],G->aresta[i][j].peso[2], G->aresta[i][j].peso[3] );

           }
        printf("\n");
        }
        }
    }

    int verifica_aresta(Grafo *G,int v1,int v2){
        if(G==NULL || (v1<=0 || v1<=0)){
            return -1;
        }

        if(G->aresta[v1][v2].peso[0]||G->aresta[v1][v2].peso[1]||G->aresta[v1][v2].peso[2]||G->aresta[v1][v2].peso[3]){
            return 1;
        }

    return 0;
    }


    int remove_aresta(Grafo *G,int v1,int v2){
        if(G==NULL || (v1<0 || v1<0)){
            return -1;
        }

     if(!(G->aresta[v2][v1].peso[0]||G->aresta[v2][v1].peso[1]||G->aresta[v2][v1].peso[2]||G->aresta[v2][v1].peso[3])){
            return 0;
        }

        G->aresta[v1][v2].peso[0] = 0;
        G->aresta[v1][v2].peso[1] = 0;
        G->aresta[v1][v2].peso[2] = 0;
        G->aresta[v1][v2].peso[3] = 0;
        G->grau[v1]--;
        G->grau[v2]--;

        return 1;
    }

    int remove_arestaN(Grafo *G,int v1,int v2){
        if(G==NULL || (v1<0 || v1<0)){
            return -1;
        }

      if(G->aresta[v1][v2].peso[0]||G->aresta[v1][v2].peso[1]||G->aresta[v1][v2].peso[2]||G->aresta[v1][v2].peso[3]){
            return 0;
        }
      if(G->aresta[v2][v1].peso[0]||G->aresta[v2][v1].peso[1]||G->aresta[v2][v1].peso[2]||G->aresta[v2][v1].peso[3]){
            return 0;
        }


        G->aresta[v1][v2].peso[0] = 0;
        G->aresta[v1][v2].peso[1] = 0;
        G->aresta[v1][v2].peso[2] = 0;
        G->aresta[v1][v2].peso[3] = 0;
        G->grau[v1]--;
        G->grau[v2]--;


        G->aresta[v2][v1].peso[0] = 0;
        G->aresta[v2][v1].peso[1] = 0;
        G->aresta[v2][v1].peso[2] = 0;
        G->aresta[v2][v1].peso[3] = 0;

        return 1;
    }

    int consulta_aresta(Grafo *G,int v1,int v2,int *capacidade, int*custo, int *delay, int *trafego){
         if(G==NULL || (v1<=0 || v1<=0)){
            return -1;
        }

     if(!(G->aresta[v1][v2].peso[0]||G->aresta[v1][v2].peso[1]||G->aresta[v1][v2].peso[2]||G->aresta[v1][v2].peso[3])){
            return 0;
        }

        *capacidade = G->aresta[v1][v2].peso[0];
        *custo = G->aresta[v1][v2].peso[1];
        *delay = G->aresta[v1][v2].peso[2];
        *trafego = G->aresta[v1][v2].peso[3];

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
     if(((G->aresta[v][i].peso[0])||(G->aresta[v][i].peso[1])||(G->aresta[v][i].peso[2])||(G->aresta[v][i].peso[3]))){
                printf("   [%d][%d]:(%d,%d,%d,%d)   ",v,i,G->aresta[v][i].peso[0],G->aresta[v][i].peso[1],G->aresta[v][i].peso[2], G->aresta[v][i].peso[3] );
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

                fprintf(arq,"   [%d][%d]:(%d,%d,%d,%d)   \n",i,j,G->aresta[i][j].peso[0],G->aresta[i][j].peso[1],G->aresta[i][j].peso[2], G->aresta[i][j].peso[3] );

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
        if(G->aresta[vet][i].peso[0]||G->aresta[vet][i].peso[1]||G->aresta[vet][i].peso[2]||G->aresta[vet][i].peso[3]){
            if(visitados[i]==0){
                visitados[i]=1;
                printf(" %d ",i);
                insere_fila(f,i);
            }
            }
        }
      }






    }

    int *Dijkstra(Grafo *G,int v0){
    int*Distancias=malloc(G->qtd_ver*sizeof(int));
    int*Visitados=calloc(G->qtd_ver,sizeof(int));
    int j,i,k,menor,h=0,aux;

    Visitados[v0]=1;
    for(i=0; i<G->qtd_ver; i++)
    {
        Distancias[i]=99999;
    }
    Distancias[v0]=0;
    for(i=0; i<G->qtd_ver; i++)
    {
        if(G->aresta[v0][i]!=0)
        {
            Distancias[i]=G->aresta[v0][i];
        }
    }
    int q;
    for(k=2; k<G->qtd_ver; k++)
    {
        for(q=0;q<G->qtd_ver;q++){
        if(Distancias[q]==99999){
            printf(" Infinito ");
        }else
        printf(" %d ",Distancias[q]);
        }
        printf("\n");
        aux=Distancias[h];
        menor=h;
        for(i=0; i<G->qtd_ver; i++)
        {


            if(aux>Distancias[i] && Visitados[i]!=1)
            {
                aux=Distancias[i];
                menor=i;
            }
        }
        Visitados[menor]=1;
        for(j=0; j<G->qtd_ver; j++)
        {
            if(G->aresta[menor][j]!=0)
            {
                int D=Distancias[menor]+G->aresta[menor][j];
                if(D<Distancias[j])
                {
                    Distancias[j]=D;
                }
            }
        }
    h++;
    }

    return Distancias;
}



    */
