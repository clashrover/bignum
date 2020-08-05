#include <stdio.h>
#include <stdlib.h>
#include "bignum.h"
#include <string.h>

int bignum_add(char* s1, char*s2 , char*s3){
    if(s1==NULL || s2 == NULL){
        return 1;
    }
    char* s11=(char*)malloc((strlen(s1)+1)*sizeof(char));
    char* s22=(char*)malloc((strlen(s2)+1)*sizeof(char));
    strcpy(s11,s1);
    strcpy(s22,s2);
    parse(s11);
    parse(s22);
    int sign1=0;
    int sign2=0;
    if(s11[0]=='-'){
        sign1=1;
        int i=0;
        while(i<strlen(s11)){
            s11[i]=s11[i+1];
            i++;
        }
    }
    if(s22[0]=='-'){
        sign2=1;
        int i=0;
        while(i<strlen(s22)){
            s22[i]=s22[i+1];
            i++;
        }
    }
    if(sign1==0 && sign2==0){
        if(add(s11,s22,s3)!=0){
            perror("error in bignum_add -> add\n");
        }
    }
    if(sign1==1 && sign2==0){
        if(subt(s22,s11,s3)!=0){
            perror("error in bignum_add -> subt\n");
        }
    }
    if(sign1==0 && sign2==1){
        if(subt(s11,s22,s3)!=0){
            perror("error in bignum_add -> subt\n");
        }
    }
    if(sign1==1 && sign2==1){
        if(add(s11,s22,s3)!=0){
            perror("error in bignum_add -> add\n");
        }
        int i=strlen(s3)+1;
        while(i>0){
            s3[i]=s3[i-1];
            i--;
        }
        s3[0]='-';
    }
    free(s11);
    free(s22);
    return 0;
    
}

int bignum_subt(char* s1, char*s2 , char*s3){
    if(s1==NULL || s2 == NULL){
        return 1;
    }
    char* s11=(char*)malloc((strlen(s1)+1)*sizeof(char));
    char* s22=(char*)malloc((strlen(s2)+1)*sizeof(char));
    strcpy(s11,s1);
    strcpy(s22,s2);
    parse(s11);
    parse(s22);
    int sign1=0;
    int sign2=0;
    if(s11[0]=='-'){
        sign1=1;
        int i=0;
        while(i<strlen(s11)){
            s11[i]=s11[i+1];
            i++;
        }
    }
    if(s22[0]=='-'){
        sign2=1;
        int i=0;
        while(i<strlen(s22)){
            s22[i]=s22[i+1];
            i++;
        }
    }
    if(sign1==0 && sign2==0){
        if(subt(s11,s22,s3)!=0){
            perror("error in bignum_add -> add\n");
        }
    }
    if(sign1==1 && sign2==0){
        if(add(s22,s11,s3)!=0){
            perror("error in bignum_add -> subt\n");
        }
        int i=strlen(s3)+1;
        while(i>0){
            s3[i]=s3[i-1];
            i--;
        }
        s3[0]='-';
    }
    if(sign1==0 && sign2==1){
        if(add(s11,s22,s3)!=0){
            perror("error in bignum_add -> subt\n");
        }
    }
    if(sign1==1 && sign2==1){
        if(subt(s22,s11,s3)!=0){
            perror("error in bignum_add -> add\n");
        }
    }
    free(s11);
    free(s22);
    return 0;
    
}