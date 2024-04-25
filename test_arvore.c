#include "arvore.c"

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