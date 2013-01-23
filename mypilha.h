#ifndef MYPILHA_H
#define MYPILHA_H 1
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
#endif
