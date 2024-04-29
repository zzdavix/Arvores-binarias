#include <stdio.h>
#include <stdlib.h>


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

Arv* abb_cria (void){
    Arv* a = (Arv*)malloc(sizeof(Arv));
    a->raiz = NULL;
    return a;
}

ArvNo* insere (ArvNo* r, int v){
    if (r == NULL){
        r = (ArvNo*)malloc(sizeof(ArvNo));
        r->info = v;
        r->esq = NULL;
        r->dir = NULL;
    }
    else if (r->info > v){
        r->esq = insere(r->esq, v);
    }
    else if (r->info < v){
        r->dir = insere(r->dir, v);
    }
    return r;
}

void abb_insere (Arv* a, int v){
    a->raiz = insere(a->raiz, v);
}

void imprime (ArvNo* r){
    if (r != NULL){
        imprime(r->esq);
        printf("%d ", r->info);
        imprime(r->dir);
    }
}

void abb_imprime (Arv* a){
    imprime(a->raiz);
}

void libera (ArvNo* r){
    if (r != NULL){
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

void abb_libera (Arv* a){
    if (a != NULL){
        libera(a->raiz);
        free(a);
    }
}

ArvNo* busca (ArvNo* r, int v){
    if (r == NULL){
        return NULL;
    }
    else if (r->info == v){
        return r;
    }
    else if (r->info > v){
        return busca(r->esq, v);
    }
    else if (r->info < v){
        return busca(r->dir, v);
    }
}

ArvNo* abb_busca (Arv* a, int v){
    busca(a->raiz, v);
}

int max2 (int a, int b){
    if(a > b){
        return a;
    }
    else {
        return b;
    }
}

int altura (ArvNo* r){
    if (r == NULL){
        return -1;
    }
    else{
        return 1 + max2(altura(r->esq), altura(r->dir));
    }
}

int abb_altura (Arv* a){
    return altura(a->raiz);
}

ArvNo* retira (ArvNo* r, int v){
    if (r == NULL){
        return NULL;
    }
    else if (r->info > v){
        r->esq = retira(r->esq, v);
    }
    else if (r->info < v){
        r->dir = retira(r->dir, v);
    }
    else{
        if (r->esq == NULL && r->dir == NULL){
            free(r);
            r = NULL;
        }
        else if (r->esq == NULL){
            ArvNo* t = r;
            r = r->dir;
            free (t);
        }
        else if (r->dir == NULL){
            ArvNo* t = r;
            r = r->esq;
            free(t);
        }
        else{
            ArvNo* t = r->esq;
            while (t->dir != NULL){
                t = t->dir;
            }
            r->info = t->info;
            t->info = v;
            r->esq = retira(r->esq, v);
        }
    }
    return r;
}

Arv* abb_retira (Arv* a, int v){
    a->raiz = retira(a->raiz, v); 
}

// Exercícios: 
// 1) 
int pares (ArvNo* r){
    if (r == NULL){
        return 0;
    }
    int npares = 0;
    if(r->info % 2 == 0){
        npares++;
    }
    npares = npares + pares(r->esq);
    npares = npares + pares(r->dir);
    return npares;
}

int abb_pares (Arv* a){
    return pares(a->raiz);
}
    
// 2)
int folhas (ArvNo* r){
    if (r == NULL){
        return 0;
    }
    int nfolhas = 0;
    if (r-> esq == NULL && r->dir == NULL){
        nfolhas++;
    }
    nfolhas = nfolhas + folhas(r->esq);
    nfolhas = nfolhas + folhas(r->dir);
    return nfolhas;
}

int abb_folhas (Arv* a){
    return folhas(a->raiz);
}

// 3)
int um_filho (ArvNo* r){
    if (r == NULL){
        return 0;
    }
    if (r->esq == NULL && r->dir == NULL){
        return 0;
    }
    else if (r->esq == NULL || r->dir == NULL){
        return 1;
    }
    else{
        return um_filho(r->esq) + um_filho(r->dir);
    }
}

int abb_um_filho (Arv* a){
    return um_filho(a->raiz);
}

int main(){
    Arv* a = abb_cria();
    abb_insere(a, 35);
    abb_insere(a, 22);
    abb_insere(a, 600);
    abb_insere(a, 43);
    abb_insere(a, 210);
    abb_insere(a, 17);

    printf("----- Árvore -----\n");
    abb_imprime(a);
    printf("\n\n");

    printf("O número de pares é: %d", abb_pares(a));
    printf("\nO número de folhas é: %d", abb_folhas(a));
    printf("\nO número de filhos é: %d", abb_um_filho(a));

   

    abb_libera(a);


    return 0;
}