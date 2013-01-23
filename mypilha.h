#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct tPilha{ int topo;
                       char * p;
                       int tm;
                     }pilha;

bool initPilha(pilha * pil, int tm);
bool isCheia(pilha pil);
bool push(pilha * pil, char value);
bool pop(pilha * pil, char * value);
bool freePilha(pilha * pil);

bool initPilha(pilha * pil, int tm){
    char * p;
    p = (char *) malloc(tm * sizeof(char));

    if(p == NULL)
        return false;

    pil->topo = -1;
    pil->p = p;
    pil->tm = tm;
    return true;
}

bool isCheia(pilha pil){
    if(pil.topo == pil.tm -1)
        return true;

    return false;
}

bool push(pilha * pil, char value){
    if(isCheia(*pil))
        return false;

    pil->p[pil->topo++] = value;

    return true;
}

bool pop(pilha * pil, char * value){
    if(pil->topo == -1)
        return false;

    * value = pil->p[--pil->topo];

    return true;
}

bool freePilha(pilha * pil){
    free(pil);
    return true;
}

