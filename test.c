#include <stdio.h>
#include <stdlib.h>
#include "bignum.h"
#include <string.h>

int main(){
    char* s1 = (char*) malloc(51*sizeof(char));
    char* s2 = (char*) malloc(51*sizeof(char));
    // char* s3 = (char*) malloc(22*sizeof(char));
    int i=1;
    while(i<51){
        s1[i-1]=(5*i)%9+'0';
        s2[i-1]='9';
        i++;
    }
    s1[i-1]='\0';
    s2[i-1]='\0';
    s1[5]='.';
    printf("arg1     :   %s\n",s1);
    printf("arg2     :   %s\n",s2);
    printf("compare s1 and s2 - %d\n",greaterThan(s1,s2));
    // if(add(s1,s2,s3)!=0){
    //     perror("error in Add");
    // }
    // printf("sum      :   %s\n",s3);
    char* s4 = (char*) malloc((strlen(s1)+strlen(s2)+1)*sizeof(char));
    if(subt(s1,s2,s4)!=0){
        perror("error in SUBT");
    }
    printf("diff     :   %s\n",s4);
    free(s1);
    free(s2);
}