#include <stdio.h>
#include <stdlib.h>
#include "bignum.h"
#include <string.h>



int subt(char* s1, char* s2, char* s3){
    if(s1==NULL || s2 == NULL){
        return 1;
    }
    char* s11 = (char*)malloc((strlen(s1)+1)*sizeof(char));
    char* s22 = (char*)malloc((strlen(s2)+1)*sizeof(char));
    strcpy(s11,s1);
    strcpy(s22,s2);
    int rev = greaterThan(s11,s22);
    if(rev==0){
        char* temp = s11;
        s11= s22;
        s22= temp;
    }
    reverse(s11);
    reverse(s22);
    printf("rev1 %s\n",s11);
    printf("rev2 %s\n",s22);
    int* d1 = (int*) malloc(sizeof(int));
    int* d2 = (int*) malloc(sizeof(int));

    getDecimal(s11,d1);
    getDecimal(s22,d2);
    int k=0;
    int diff = *d1 - *d2;
    int carry=0;
    if(diff<0){
        while(k<abs(diff)){
            int r1=0;
            r1-=carry;
            int r2=s22[k]-'0';
            if(r1<r2){
                carry=1;
            }else{
                carry = 0;
            }
            r1+= 10*carry;
            r1=r1-r2;
            s3[k] = r1+'0';
            k++;
        }
    }else{
        while(k<diff){
            int r1=s11[k]-'0';
            r1-=carry;
            int r2=0;
            if(r1<r2){
                carry=1;
            }else{
                carry = 0;
            }
            r1+= 10*carry;
            r1=r1-r2;
            s3[k] = r1+'0';
            k++;
        }
    }
    s3[k]='\0';
    printf("%s\n",s3);
    int j=0;
    int i=0;
    if(diff<0){
        j=k;
    }
    if(diff>0){
        i=k;
    }
    while(i<*d1){
        int r1=s11[i]-'0';
        r1-=carry;
        int r2=s22[j]-'0';
        if(r1<r2){
            carry=1;
        }else{
            carry = 0;
        }
        r1+= 10*carry;
        r1=r1-r2;
        s3[k] = r1+'0';
        i++;
        j++;
        k++;
    }
    if(k>0){
        s3[k]='.';
        k++;
    }
    if(j>0){
        j++;
    }
    if(i>0){
        i++;
    }
    
    s3[k]='\0';
    printf("%s\n",s3);
    while(i<strlen(s1) && j<strlen(s2)){
        int r1=s11[i]-'0';
        r1-=carry;
        int r2=s22[j]-'0';
        if(r1<r2){
            carry=1;
        }else{
            carry = 0;
        }
        r1+= 10*carry;
        r1=r1-r2;
        s3[k] = r1+'0';
        i++;
        j++;
        k++;
    }
    s3[k]='\0';
    printf("%s\n",s3);
    while(i<strlen(s11)){
        int r1=s11[i]-'0';
        r1-=carry;
        int r2=0;
        if(r1<r2){
            carry=1;
        }else{
            carry = 0;
        }
        r1+= 10*carry;
        r1=r1-r2;
        s3[k] = r1+'0';
        i++;
        k++;
    }
    if(rev == 0){
        s3[k]='-';
        k++;
    }
    s3[k]='\0';
    reverse(s3);

    free(s11);
    free(s22);
    free(d1);
    free(d2);
    return 0;

}