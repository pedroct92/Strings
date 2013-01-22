#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mystring.h"

int main(){
    char strPadrao1[] = "bel doces";
    string str1, str2, str3;

    initString(&str1);
    printf("INIT: inicio[%p] Fim[%p] len[%d]\n", str1.inicio, str1.ultimo, str1.len);

    initString(&str2);
    printf("INIT: inicio[%p] Fim[%p] len[%d]\n", str2.inicio, str2.ultimo, str2.len);

    initString(&str3);
    printf("INIT: inicio[%p] Fim[%p] len[%d]\n", str3.inicio, str3.ultimo, str3.len);

    printf("\n\n<<<-----------createString---------------->>>\n");
    createString(&str1, strPadrao1);
    printStringFrente(str1);

    printf("\n\n<<<-----------copyString---------------->>>\n");
    copyString(&str1, &str2);
    printStringFrente(str2);

    printf("\n\n<<<-----------equalString---------------->>>\n");
    if(equalString(str1, str2))
        printf("String 1 igual a String 2");
    else
        printf("Strings diferentes ");

    printf("\n\n<<<-----------lenPalavras---------------->>>\n");
    printf("QTD: [%d] ",lenPalavras(str1));

    printf("\n\n<<<-----------concat--------------------->>>\n");
    concat(str1, str2, &str3);
    printStringFrente(str3);

    printf("\n\n<<<-----------inverterLetras------------->>>\n");
    inverterLetras(&str1);
    printStringFrente(str1);

    printf("\n\n<<<----------inverterPalavras------------>>>\n");
    inverterPalavras(&str1);
    printStringFrente(str1);

    printf("\n\n<<<--------inverterLetrasPalavras-------->>>\n");
    inverterLetrasPalavras(&str1);
    printStringFrente(str1);

    return 0;
}
