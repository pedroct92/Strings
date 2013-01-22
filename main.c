#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mystring.h"

int main(){
    char strPadrao1[] = "pedro coelho torres";
    string str1, str2, str3;

    initString(&str1);
    printf("INIT: inicio[%p] Fim[%p] len[%d]\n", str1.inicio, str1.ultimo, str1.len);

    initString(&str2);
    printf("INIT: inicio[%p] Fim[%p] len[%d]\n", str2.inicio, str2.ultimo, str2.len);

    initString(&str3);
    printf("INIT: inicio[%p] Fim[%p] len[%d]\n", str3.inicio, str3.ultimo, str3.len);

    createString(&str1, strPadrao1);
    printf("CREATESTRING: qtd [%d] \n", str1.len);
    printStringFrente(str1);

    printf("\nCOPY_STRING: ");
    copyString(&str1, &str2);
    printStringFrente(str2);

    if(equalString(str1, str2))
        printf("\n equalString \nString 1 igual a String 2");
    else
        printf("\n equalString \nStrings diferentes ");

    printf("\nQTD PALAVRAS: [%d] ",lenPalavras(str1));

    printf("\nCONCAT: %d\n", concat(str1, str2, &str3));
    printStringFrente(str3);

    printf("\n<<<-------------------------------------->>>\n");
    inverterLetras(&str1);
    printStringFrente(str1);

    printf("\n<<<-------------------------------------->>>\n");
    inverterPalavras(&str1);
    printStringFrente(str1);


    return 0;
}
