#include <stdio.h>
#include <stdlib.h>

// structs de nó e de árvore
typedef struct arvno ArvNo;
struct arvno{
    int info;
    ArvNo* esq;
    ArvNo* dir;
};

typedef struct arv Arv;
struct arv{
    ArvNo* raiz;
};


// função de criação da árvore binária inicialmente vazia
Arv* abb_cria (void){
    Arv* a = (Arv*)malloc(sizeof(Arv));
    a->raiz = NULL;
    return a;
}

// função de inserção de elementos na árvore
ArvNo* insere (ArvNo* r, int v){
    if (r == NULL){
        r = (ArvNo*)malloc(sizeof(ArvNo));
        r->info = v;
        r->esq = NULL;
        r->dir = NULL;
    }
    else if (v < r->info){
        r->esq = insere(r->esq, v);
    }
    else{
        r->dir = insere(r->dir, v);
    }
    return r;
}

void abb_insere (Arv* a, int v){
    a->raiz = insere (a->raiz, v);
}

// função recursiva para impressão
void imprime (ArvNo* r){
    if (r != NULL){
        imprime (r->esq);
        printf("%d ", r->info);
        imprime(r->dir);
    }
}

// função de impressão
void abb_imprime (Arv* a){
    return imprime (a->raiz);
}

// função recursiva para liberação da árvore
static void libera (ArvNo* r){
    if( r != NULL){
        libera(r->esq); 
        libera(r->dir);
        free(r);
    }
}

// função que libera a árvore
void arv_libera (Arv* a){
    libera(a->raiz);
    free(a);
}

// função que verifica existência do caráctere
static int pertence (ArvNo* r, int v){
    if (r == NULL){
        return 0; 
    }
    else if (v==r->info){
       return 1;
    }
    else if (pertence(r->esq, v)){
        return 1;
    }
    else if (pertence (r->dir, v)){
        return 1;
    }
}

int arv_pertence (Arv* a, int v){
    return pertence(a->raiz, v);
}

// função recursiva de busca
static ArvNo* busca (ArvNo* r, int v){
    if (r == NULL){
        return NULL;
    }
    else if (r->info > v){
        return busca (r->esq, v);
    }
    else if (r->info < v){
        return busca (r->dir, v);
    }
    else{
        return r;
    }
}

// função de busca do elemento
ArvNo* abb_busca (Arv* a, int v){
    return busca (a->raiz, v);
}

// função que retorna o máximo entre 2 números inteiros
static int max2 (int a, int b){
    if (a>b){
        return a;
    }
    else{
        return b;
    }
}

// função recursiva que retorna a altura
static int altura (ArvNo* r){
    if (r==NULL){
        return -1;
    }
    else{
        return 1 + max2(altura(r->esq), altura(r->dir));
    }
}

// função que retorna a altura
int arv_altura (Arv* a){
    return altura(a->raiz);
}

int main(){
    Arv* a = abb_cria();
    abb_insere(a, 10);
    abb_insere(a, 20);
    abb_insere(a, 30);
    abb_insere(a, 40);
    abb_insere(a, 50);
    abb_insere(a, 60);

    abb_imprime(a);


}
