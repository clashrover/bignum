#ifndef BIGNUM_H
#define BIGNUM_H

int bignum_add(char* s1, char*s2 , char*s3);
int bignum_subt(char* s1, char*s2 , char*s3);
int add(char* s1, char* s2, char* s3);
int subt(char* s1, char* s2, char* s3);

void reverse(char* s);
int greaterThan(char* s11, char*s22);
void getDecimal(char* s, int* i1);

void parse(char* s);

#endif