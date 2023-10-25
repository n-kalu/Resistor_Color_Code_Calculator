#ifndef CALCULATE_H
#define CALCULATE_H

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int calculation(int *n);
void clearBuffer();
char *removeEmptyCharacters(char *coll);

extern char bu[100];
extern char *colBuff;
extern int lenB;

void clearBuffer();
char *removeEmptyCharacters(char *coll);
int calculation(int *n);


#endif