#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Utilities.h"

int getNumber(int min, int max, char displayMsg[], char warningMsg[]) {
    char warning_str[75];
    char auxNum[75];
    int num;
    char found = '\0';

    if (strlen(warningMsg)) {
        printf("%s", warningMsg);
    }

    printf("%s", displayMsg);
    fflush(stdin);
    scanf("%s", auxNum);

    checkIsAllNumber(&found, auxNum);

    if (found != '\0') {
        strcpy(warning_str, "ERROR: Ingreso un caracter erroneo (");
        addCharToString(warning_str, &found);
        strcat(warning_str, ") vuelva a intentarlo\n");

        return getNumber(min, max, displayMsg, warning_str);
    } else {
        num = atof(auxNum);
    }

    if (num < min) {
        getWarningMsg(warning_str, min, "minimo valor");
        return getNumber(min, max, displayMsg, warning_str);
    }

    if (num > max) {
        getWarningMsg(warning_str, max, "maximo valor");
        return getNumber(min, max, displayMsg, warning_str);
    }

    return num;
}

float getFloat(int min, int max, char displayMsg[], char warningMsg[]) {
    char warning_str[75];
    char auxFloat[75];
    float flt;
    char found = '\0';

    if (strlen(warningMsg)) {
        printf("%s", warningMsg);
    }

    printf("%s", displayMsg);
    fflush(stdin);
    scanf("%s", auxFloat);

    checkIsNumbersWithDot(&found, auxFloat);

    if (found != '\0') {
        strcpy(warning_str, "ERROR: Ingreso un caracter erroneo (");
        addCharToString(warning_str, &found);
        strcat(warning_str, ") vuelva a intentarlo\n");

        return getFloat(min, max, displayMsg, warning_str);
    } else {
        flt = atof(auxFloat);
    }

    if (flt < min) {
        getWarningMsg(warning_str, min, "minimo valor");
        return getFloat(min, max, displayMsg, warning_str);
    }

    if (flt > max) {
        getWarningMsg(warning_str, max, "maximo valor");
        return getFloat(min, max, displayMsg, warning_str);
    }

    return flt;
}

void getString(char string[], int max, char displayMsg[], char warningMsg[]) {
    char warning_str[75];
    char auxStr[75];
    char found = '\0';

    if (strlen(warningMsg)) {
        printf("%s", warningMsg);
    }

    printf("%s", displayMsg);
    fflush(stdin);
    scanf("%s", auxStr);

    checkIsAllLetters(&found, auxStr);

    if (found != '\0') {
        strcpy(warning_str, "ERROR: Ingreso un caracter erroneo (");
        addCharToString(warning_str, &found);
        strcat(warning_str, ") vuelva a intentarlo\n");

        getString(string, max, displayMsg, warning_str);
    } else if (strlen(auxStr) > max) {
        getWarningMsg(warning_str, max, "tamanio maximo");
        getString(string, max, displayMsg, warning_str); 
    } else {
        strcpy(string, auxStr);
    }
}

int yesOrNo(char displayMsg[], char warningMsg[]) {
    char auxRes[75];

    if (strlen(warningMsg)) {
        printf("%s", warningMsg);
    }

    printf("%s", displayMsg);
    fflush(stdin);
    scanf("%s", auxRes);

    if (strlen(auxRes) != 1) {
        return yesOrNo(displayMsg, "ERROR: Ingreso muchos caracteres\n");
    } else {
        if (auxRes[0] == 'y' || auxRes[0] == 'Y') {
            return 1;
        } else if(auxRes[0] == 'n' || auxRes[0] == 'N') {
            return 0;
        } else {
            return yesOrNo(displayMsg, "ERROR: Opcion erronea (Y/N): \n");
        }
    }
}

//AuxFN

void getWarningMsg(char warning_str[], int value, char text[]){
    strcpy(warning_str, "ERROR: El ");
    strcat(warning_str, text);
    strcat(warning_str, " posible es ");
    addNumToString(warning_str, value);
    strcat(warning_str, " vuelva a intentarlo\n");
}

void addNumToString(char base_str[], int num) {
    char number_str[10];
    sprintf(number_str, "%d", num);
    strcat(base_str, number_str);
}

void addCharToString(char base_str[], char *ch) {
    char chToStr[2];
    chToStr[1] = '\0';
    chToStr[0] = *ch;
    strcat(base_str, chToStr);
}

//CheckFn

void checkIsAllLetters(char *found, char stringArray[]){
    int foundFlag = 0;
    int i = 0;

    while(i < strlen(stringArray) && foundFlag == 0){
        if (!((stringArray[i] >= 'a' && stringArray[i] <= 'z')
           || (stringArray[i] >= 'A' && stringArray[i] <= 'Z'))) {
            foundFlag = 1;
        } else {
            foundFlag = 0;
        }
        i++;
    }

    if (foundFlag) {
        i--;
        *found = stringArray[i];
    }
}

void checkIsAllNumber(char *found, char stringArray[]){
    int foundFlag = 0;
    int i = 0;

    while(i < strlen(stringArray) && foundFlag == 0){
        if (!((stringArray[i] >= '0' && stringArray[i] <= '9'))) {
            foundFlag = 1;
        } else {
            foundFlag = 0;
        }
        i++;
    }

    if (foundFlag) {
        i--;
        *found = stringArray[i];
    }
}

void checkIsNumbersWithDot(char *found, char stringArray[]){
    int foundFlag = 0;
    int i = 0;
    int dotCounter = 0;

    while(i < strlen(stringArray) && foundFlag == 0 && dotCounter < 2){
        if (i == 0) {
            if (!((stringArray[i] >= '0' && stringArray[i] <= '9'))) {
                foundFlag = 1;
            } else {
                foundFlag = 0;
            }
        } else {
            if (stringArray[i] == '.') {
                dotCounter++;
            } else {
                if (!((stringArray[i] >= '0' && stringArray[i] <= '9'))) {
                    foundFlag = 1;
                } else {
                    foundFlag = 0;
                }
            }
        }
        i++;
    }

    if (foundFlag) {
        i--;
        *found = stringArray[i];
    } else if (dotCounter > 1) {
        *found = '.';
    }
}
