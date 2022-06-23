#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef UTILITIES_H_
#define UTILITIES_H_

#endif /* UTILITIES_H_ */

int getNumber(int min, int max, char displayMsg[], char warningMsg[]);
float getFloat(int min, int max, char displayMsg[], char warningMsg[]);
void getString(char string[], int max, char displayMsg[], char warningMsg[]);
int yesOrNo(char displayMsg[], char warningMsg[]);

void getWarningMsg(char warning_str[], int value, char text[]);
void findCharArray(char *found, char stringArray[]);

void checkIsAllLetters(char *found, char stringArray[]);
void checkIsAllNumber(char *found, char stringArray[]);
void checkIsNumbersWithDot(char *found, char stringArray[]);

void addNumToString(char base_str[], int num);
void addCharToString(char base_str[], char *ch);
