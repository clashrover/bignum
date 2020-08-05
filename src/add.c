#include <stdio.h>
#include <stdlib.h>
#include "bignum.h"
#include <string.h>

int add(char* s1, char* s2, char* s3){
    if(s1==NULL || s2 == NULL){
        return 1;
    }
    char* s11 = (char*)malloc((strlen(s1)+1)*sizeof(char));
    char* s22 = (char*)malloc((strlen(s2)+1)*sizeof(char));
    strcpy(s11,s1);
    strcpy(s22,s2);
    reverse(s11);
    reverse(s22);

    int* d1 = (int*) malloc(sizeof(int));
    int* d2 = (int*) malloc(sizeof(int));

    getDecimal(s11,d1);
    getDecimal(s22,d2);
    int i=0;
    int diff = *d1 - *d2;
    if(diff<0){
        char* temp = s11;
        s11= s22;
        s22= temp;
        diff = -1*diff;
        int temp1 = *d1;
        *d1 = *d2;
        *d2 = temp1;
    }
    while(i<diff){
        s3[i] = s11[i];
        i++;
    }
    
    
    int carry=0;
    int j=0;
    while(i<*d1){
        int r=(s11[i]-'0') + (s22[j]-'0') + carry;
        s3[i] = r%10 + '0';
        carry = r/10;
        i++;
        j++;
    }
    
    
    if(i>0){
        s3[i] = '.';
        i++;
    }
    if(j>0){
        j++;
    }
    while(i < strlen(s1) && j<strlen(s2)){
        int r=(s11[i]-'0') + (s22[j]-'0') + carry;
        s3[i] = r%10 + '0';
        carry = r/10;
        i++;
        j++;
    }
    
    
    while(i<strlen(s1)){
        int r = (s11[i]-'0') +carry;
        s3[i] = r%10 + '0';
        carry = r/10;
        i++;
    }
    
    
    while(j<strlen(s2)){
        int r = (s22[j]-'0')+carry;
        s3[i] = r%10 + '0';
        carry = r/10;
        j++;
        i++;
    }
    while(carry !=0){
        s3[i] = carry%10 + '0';
        carry = carry/10;
        i++;
    }
    s3[i] = '\0';
    reverse(s3);

    free(s11);
    free(s22);
    free(d1);
    free(d2);
    return 0;

}