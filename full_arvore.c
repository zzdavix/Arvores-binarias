#include <stdio.h>
#include <stdlib.h>

// structs de nó e de árvore
typedef struct arvno ArvNo;
struct arvno{
    char info;
    ArvNo* esq;
    ArvNo* dir;
};

typedef struct arv Arv;
struct arv{
    ArvNo* raiz;
};

// função de criação do nó
ArvNo* arv_criano (char c, ArvNo* esq, ArvNo* dir){
    ArvNo* p = (ArvNo*)malloc(sizeof(ArvNo));
    p->info = c;
    p->esq = esq;
    p->dir = dir;
    return p;
}

// função de criação do tipo abstrato
Arv* arv_cria (ArvNo* r){
    Arv* a = (Arv*)malloc(sizeof(Arv));
    a->raiz = r;
    return a;
}

// função recursiva para impressão da árvore
static void imprime (ArvNo* r){
    printf("<");
    if (r != NULL){
        printf("%c", r->info); /* mostra informação */
        imprime(r->esq); /* imprime sae */
        imprime(r->dir); /* imprime sad */
    }
    printf(">");
}

// função que imprime a árvore
void arv_imprime (Arv* a){
    imprime(a->raiz); /* imprime recursivamente a partir da raiz */
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
static int pertence (ArvNo* r, char c){
    if (r == NULL){
        return 0; 
    }
    else if (c==r->info){
       return 1;
    }
    else if (pertence(r->esq, c)){
        return 1;
    }
    else if (pertence (r->dir, c)){
        return 1;
    }
}

int arv_pertence (Arv* a, char c){
    return pertence(a->raiz, c);
}

// função recursiva de busca do caráctere 
static ArvNo* busca (ArvNo* r, char c){
    if (r == NULL){
        return NULL;
    }
    else if (c==r->info){
        return r;
    }
    else{
        ArvNo* p = busca(r->esq, c);
        if (p != NULL){
            return p;
        }
        else{
            return busca(r->dir, c);
        }
    }
}

// função que busca o caráctere
ArvNo* arv_busca (Arv* a, char c){
    return busca(a->raiz, c);
}



int main(){
Arv* a = arv_cria(
    arv_criano('a',
        arv_criano('b', NULL,
            arv_criano('d', NULL, NULL)),
        arv_criano('c', 
            arv_criano('e', NULL, NULL),
            arv_criano('f', NULL, NULL))
    )
);

arv_imprime(a);

return 0;
}
