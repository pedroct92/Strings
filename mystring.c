#include <stdbool.h>
#include "mystring.h"
#include "mypilha.h"

bool initString(string * str){
    str->inicio = NULL;
    str->ultimo = NULL;
    str->len    = 0;
    return true;
}

bool createString(string * str, const char* strPadrao){
    clearString(str);
    initString(str);
    int len;
    for(len = 0; strPadrao[len] != 0; len++){
        if(!inserirChar(str, strPadrao[len]))
            return false;
    }

    return true;
}

bool copyString(string * str1, string * str2){
    caracter * pos;
    pos = str1->inicio;

    while(pos != NULL){
        if(!inserirChar(str2, pos->value))
            return false;

        pos = pos->prox;
    }
    return true;
}

bool equalString(string str1, string str2){
    caracter * pos1, * pos2;

    if(str1.len != str2.len)
        return false;

    pos1 = str1.inicio;
    pos2 = str2.inicio;

    while(pos1 != NULL && pos2 != NULL){
        if(pos1->value != pos2->value)
            return false;

        pos1 = pos1->prox;
        pos2 = pos2->prox;
    }

    return true;
}

int lenPalavras(string str){
    caracter * pos;
    int len = 1;

    if(str.len == 0)
        return 0;

    pos = str.inicio;

    while(pos != NULL){
        if(pos->value == ' ')
            len++;
        pos = pos->prox;
    }
    return len;
}

bool inverterLetras(string * str){
    caracter * pos, * aux;
    pilha pil;

    initPilha(&pil, str->len);

    pos = str->inicio;

    while(pos != NULL){
        push(&pil, pos->value);
        aux = pos;
        pos = pos->prox;
        free(aux);
    }

    initString(str);
    inserirPilhaEmString(&pil, str);
    freePilha(&pil);
    return true;
}

bool inverterPalavras(string * str){
    pilha pil;
    caracter * pos, * aux;
    string strAux;

    pos = str->inicio;

    if(!initString(&strAux))
        return false;

    if(!initPilha(&pil, str->len))
        return false;

    while(pos != NULL){

        if(pos->value != ' '){
            inserirChar(&strAux, pos->value);
        }else{

            if(!inverterLetras(&strAux))
                return false;

            inserirChar(&strAux, ' ');
            inserirStringEmPilha(strAux, &pil);

            if(!initString(&strAux))
                return false;
        }

        aux = pos;
        pos = pos->prox;
        free(aux);

        if(pos == NULL){
            if(!inverterLetras(&strAux))
                return false;

            inserirStringEmPilha(strAux, &pil);
        }
    }

    if(!initString(str))
        return false;

    inserirPilhaEmString(&pil, str);
    freePilha(&pil);
    return true;
}

bool inverterLetrasPalavras(string * str){
    pilha pil;
    caracter * pos, * aux;
    string strAux;

    pos = str->inicio;

    if(!initString(&strAux))
        return false;

    if(!initPilha(&pil, str->len))
        return false;

    while(pos != NULL){

        if(pos->value != ' '){
            inserirChar(&strAux, pos->value);
        }else{
            inserirChar(&strAux, ' ');
            inserirStringEmPilha(strAux, &pil);

            if(!initString(&strAux))
                return false;
        }

        aux = pos;
        pos = pos->prox;
        free(aux);

        if(pos == NULL)
            inserirStringEmPilha(strAux, &pil);
    }

    if(!initString(str))
        return false;

    inserirPilhaEmString(&pil, str);
    freePilha(&pil);
    inverterPalavras(str);
    return true;
}

bool intercarlarPalavras(string str1, string str2, string * novaString){
    caracter * pos, * pos2, * aux;
    string strAux;
    bool palavraInserida = false;

    if(!initString(&strAux))
        return false;

    if(!initString(novaString))
        return false;

    pos = str1.inicio;
    pos2 = str2.inicio;
    while(pos != NULL){

        if(pos->value != ' '){
            inserirChar(&strAux, pos->value);
        }else{
            inserirChar(&strAux, ' ');
            copyString(&strAux, novaString);
            palavraInserida = false;

            if(!initString(&strAux))
                return false;

            while(pos2 != NULL && !palavraInserida){

                if(pos2->value != ' '){
                    inserirChar(&strAux, pos2->value);
                }else{
                    copyString(&strAux, novaString);
                    inserirChar(novaString, ' ');

                    if(!initString(&strAux))
                        return false;

                    palavraInserida = true;
                }
                pos2 = pos2->prox;
            }
        }

        aux = pos;
        pos = pos->prox;

        if(pos == NULL)
            copyString(&strAux, novaString);
    }

    while(pos2 != NULL){
        inserirChar(novaString, pos2->value);
        pos2 = pos2->prox;
    }
    return true;
}

bool concat(string str1, string str2, string * novaString){
    if(!copyString(&str1, novaString))
        return false;

    if(!copyString(&str2, novaString))
        return false;

    return true;
}

bool inserirChar(string *str, char value){
    caracter * novo = (caracter *) malloc(sizeof(caracter));

    novo->value = value;
    novo->ante = str->ultimo;
    novo->prox = NULL;

    if(novo == NULL)
        return false;

    if(str->inicio == NULL){
        str->inicio = novo;
    }else{
        str->ultimo->prox = novo;
    }

    str->ultimo = novo;
    str->len++;
    return true;
}

bool clearString(string * str){
    caracter * pos, * aux;

    pos = str->inicio;

    while(pos != NULL){
        aux = pos;
        pos = pos->prox;
        free(aux);
    }
    return true;
}

bool inserirStringEmPilha(string str, pilha * pil){
    caracter * pos, * aux;

    pos = str.inicio;
    while(pos != NULL){
        if(!push(pil, pos->value))
            return false;

        aux = pos;
        pos = pos->prox;
        free(aux);
    }
    return true;
}

bool inserirPilhaEmString(pilha * pil, string * str){
    char ch;

    while(pop(pil, &ch)){
        if(!inserirChar(str, ch))
            return false;
    }
    return true;
}

void printStringFrente(string str){
    caracter * pos;
    pos = str.inicio;

    while(pos != NULL){
        printf("%c", pos->value);
        pos = pos->prox;
    }
}
void printStringTras(string str){
    caracter * pos;
    pos = str.ultimo;

    while(pos != NULL){
        printf("%c", pos->value);
        pos = pos->ante;
    }
}
