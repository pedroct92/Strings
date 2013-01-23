#ifndef MYSTRING_H
#define MYSTRING_H 1
#include <stdbool.h>
#include "mypilha.h"

typedef struct tCaracter{ char value;
                          struct tCaracter * prox;
                          struct tCaracter * ante;
                         }caracter;

typedef struct tString{ caracter * inicio;
                        caracter * ultimo;
                        int len;
                      } string;

bool initString(string * str);
bool createString(string * str, const char * strPadrao);
bool copyString(string * str1, string * str2);
bool equalString(string str1, string str2);
int  lenPalavras(string str);
bool inverterLetras(string * str);
bool inverterPalavras(string * str);
bool inverterLetrasPalavras(string * str);
bool intercarlarPalavras(string str1, string str2, string * novaString);
bool concat(string str1, string str2, string * novaString);

bool inserirChar(string *str, char value);
bool clearString(string * str);
bool inserirStringEmPilha(string str, pilha * pil);
bool inserirPilhaEmString(pilha * pil, string * str);
void printStringFrente(string str);
void printStringTras(string str);
#endif
