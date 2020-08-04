#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void reverse(char* s){
    int i=0;
    int j=strlen(s)-1;
    while(i<j){
        char temp = s[i];
        s[i]= s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

void getDecimal(char* s, int* i1){
    int i=0;
    *i1=0;
    while(s[i]!='.' && s[i]!='\0'){
        i++;
    }
    if(s[i]=='.'){
        *i1 = i;
    }
}

void getnonDecimal(char* s, int* i1){
    int i=0;
    *i1=0;
    while(s[i]!='.' && s[i]!='\0'){
        i++;
    }
    *i1=i;
}


int greaterThan(char* s11, char*s22){
    int* d1 = (int*) malloc(sizeof(int));
    int* d2 = (int*) malloc(sizeof(int));

    getnonDecimal(s11,d1);
    getnonDecimal(s22,d2);
    int diff = *d1 - *d2;
    if(diff>0){
        return 1;
    }
    if(diff<0){
        return 0;
    }
    free(d1);
    free(d2);
    int i=0;
    while(i<strlen(s11) && i<strlen(s22)){
        if(s11[i]>s22[i]){
            return 1;
        }
        if(s11[i]<s22[i]){
            return 0;
        }
    }
    if(i<strlen(s11)){
        return 1;
    }
    return 0;
}

void parse(char* s){
    // 00000000213.1231     ->  213.1231
    // -000123123.123       -> -123123.123
    // .123123              ->  0.123123
    // 000000.123210000000  ->  0.12321
    // -0.123               -> -0.123



}