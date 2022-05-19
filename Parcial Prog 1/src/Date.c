#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Utilities.h"
#include "Date.h"

Date getDate(char warningMsg[]){
    Date auxDate;
    char warning_str[75];

    char foundDay = '\0';
    char foundMonth = '\0';
    char foundYear = '\0';

    char auxDay[10];
    char auxMonth[10];
    char auxYear[10];

    if (strlen(warningMsg)) {
        printf("%s", warningMsg);
    }

    printf("Ingrese la fecha de nacimiento\n");
    printf("Dia: ");
    fflush(stdin);
	scanf("%s", auxDay);
    printf("Mes: ");
    fflush(stdin);
	scanf("%s", auxMonth);
    printf("Anio: ");
    fflush(stdin);
	scanf("%s", auxYear);

    checkIsAllNumber(&foundDay, auxDay);
    checkIsAllNumber(&foundMonth, auxMonth);
    checkIsAllNumber(&foundYear, auxYear);

    if (foundDay != '\0') {
        strcpy(warning_str, "ERROR: Ingreso un caracter erroneo en el dia (");
        addCharToString(warning_str, &foundDay);
        strcat(warning_str, ") vuelva a intentarlo\n");

        return getDate(warning_str);
    } else if (foundMonth != '\0') {
        strcpy(warning_str, "ERROR: Ingreso un caracter erroneo en el mes (");
        addCharToString(warning_str, &foundMonth);
        strcat(warning_str, ") vuelva a intentarlo\n");

        return getDate(warning_str);
    } else if (foundYear != '\0') {
        strcpy(warning_str, "ERROR: Ingreso un caracter erroneo en el anio (");
        addCharToString(warning_str, &foundYear);
        strcat(warning_str, ") vuelva a intentarlo\n");

        return getDate(warning_str);
    } else {
    	auxDate.day = atof(auxDay);
		auxDate.month = atof(auxMonth);
		auxDate.year = atof(auxYear);
    
	    if (validateDate(auxDate) == 0) {
	    	return getDate("ERROR: La fecha es invalida vuelva a intentarlo\n");
	    } else if(auxDate.year > 2002) {
	    	return getDate("ERROR: No puede ser menor de 18 vuelva a intentarlo\n");
	    } else if(auxDate.year <= 1900) {
	    	return getDate("ERROR: El anio ingresado es muy chico vuelva a intentarlo\n");
	    } else {
	    	return auxDate;
	    }
    }
}

int getAge(Date date){
	return 2022 - date.year;
}

//AuxFn

int validateDate(Date date) {
    int isValid = 0;

    if (date.day <= 31 && date.day >= 1 && date.month >= 1 && date.month <= 12) {
        switch (date.month) {
            case  1 :
            case  3 :
            case  5 :
            case  7 :
            case  8 :
            case 10 :
            case 12 :
                if (date.day >= 1 && date.day <= 31){
                    isValid = 1;
                }
                break;
            case  4 :
            case  6 :
            case  9 :
            case 11 :
                if (date.day >= 1 && date.day <= 30) {
                    isValid = 1;
                }
                break;

            case  2 :
                if ((date.year % 4 == 0 && date.year % 100 != 0) || date.year % 400 == 0) {
                    if (date.day >= 1 && date.day <= 29) {
                        isValid = 1;
                    }
                } else {
                    if (date.day >= 1 && date.day <= 28) {
                        isValid = 1;
                    }
                }
                break;
        }
    }

    return isValid;
}
