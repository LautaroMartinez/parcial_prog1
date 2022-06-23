#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ctype.h"
#include "LinkedList.h"
#include "Passenger.h"
#include "Controller.h"
#include "Utilities.h"
#include "Parser.h"

void addPassengers(LinkedList* passengerList, int *globalId) {
    Passenger* newPassenger;
    int id;
    char name[21];
    char last_name[21];
    float price;
    char flight_code[7];
    int passenger_type;
    int flight_status;

    newPassenger = passenger_init_new();

    id = *globalId;
    getString(name, 21, "Ingrese el Nombre: ", "");
    getString(last_name, 21, "Ingrese el Apellido: ", "");
    price = getFloat(0, 10000, "Ingrese el Precio: ", "");
    getString(flight_code, 7, "Ingrese el Codigo de Vuelo: ", "");
    passenger_type = getNumber(1, 3, "Ingrese el Tipo de Pasajero (1-FirstClass, 2-ExecutiveClass, 3-EconomyClass): ", "");
    flight_status = getNumber(1, 4, "Ingrese el Status (1-Aterrizado, 2-En Horario, 3-En Vuelo, 4-Demorado): ", "");
    (*globalId)++;

    set_id(newPassenger, id);
    set_name(newPassenger, name);
    set_last_name(newPassenger, last_name);
    set_price(newPassenger, price);
    set_flight_code(newPassenger, flight_code);
    set_passenger_type(newPassenger, passenger_type);
    set_flight_status(newPassenger, flight_status);

    ll_add(passengerList, newPassenger);

    printf("Se ingreso correctamente el pasajero\n");
    system("pause");
}

void modifyPassenger(LinkedList* passengerList){
    Passenger* foundPassenger = findPassengerById(passengerList);
    char name[21];
    char last_name[21];
    float price;
    char flight_code[7];
    int passenger_type;
    int flight_status;
    int loop_menu = 1;

    if (foundPassenger != NULL) {
        do {
            switch(modifyMenu(foundPassenger)) {
                case 1: ;
                    getString(name, 21, "Ingrese el Nombre: ", "");
                    set_name(foundPassenger, name);
                    break;
                case 2: ;
                    getString(last_name, 21, "Ingrese el Apellido: ", "");
                    set_last_name(foundPassenger, last_name);
                    break;
                case 3: ;
                    price = getFloat(0, 10000, "Ingrese el Precio: ", "");
                    set_price(foundPassenger, price);
                    break;
                case 4: ;
                    getString(flight_code, 7, "Ingrese el Codigo de Vuelo: ", "");
                    set_flight_code(foundPassenger, flight_code);
                    break;
                case 5: ;
                    passenger_type = getNumber(0, 10, "Ingrese el Tipo de Pasajero (1-FirstClass, 2-ExecutiveClass, 3-EconomyClass): ", "");
                    set_passenger_type(foundPassenger, passenger_type);
                    break;
                case 6: ;
                    flight_status = getNumber(0, 1000, "Ingrese el Status (1-Aterrizado, 2-En Horario, 3-En Vuelo, 4-Demorado): ", "");
                    set_flight_status(foundPassenger, flight_status);
                    break;
                case 7:
                    printf("Volviendo a Menu\n");
                    system("pause");
                    loop_menu = 0;
                    break;
                default:
                    printf("Opcion invalida\n");
                    system("pause");
            }
        } while(loop_menu);
    } else {
        printf("Volviendo a Menu\n");
        system("pause");
    }
}

void removePassenger(LinkedList* passengerList){
    Passenger* passenger;
    passenger = findPassengerById(passengerList);

    printf("Pasajero -%s %s- dado de baja con exito\n", get_name(passenger), get_last_name(passenger));
    free(passenger);
    system("pause");
}

void listPassenger(LinkedList* passengerList) {
    Passenger* auxPassenger = NULL;

    if(passengerList != NULL) {
        int len = ll_len(passengerList);
        printf("**** Pasajeros por Nombre, Apellido y Tipo: ****\n");
        for(int i = 0; i < len; i++) {
            auxPassenger = ll_get(passengerList, i);
            printf("- %s %s, %s\n", get_name(auxPassenger), get_last_name(auxPassenger), get_passenger_type(auxPassenger));
        }
        printf("**** Fin ****\n");
    }
}

void sortPassengers(LinkedList* passengerList) {
    int loop_menu = 1;
    do {
        switch (reportsMenu()) {
            case 1:
                ll_sort(passengerList, compareFirstName, 1);
                listPassenger(passengerList);
                break;
            case 2:
                ll_sort(passengerList, compareFirstName, 0);
                listPassenger(passengerList);
                break;
            case 3:
                ll_sort(passengerList, compareLastName, 1);
                listPassenger(passengerList);
                break;
            case 4:
                ll_sort(passengerList, compareLastName, 0);
                listPassenger(passengerList);
                break;
            case 6:
                showFirstClass(passengerList);
                break;
            case 5:
                printf("Volviendo a Menu\n");
                system("pause");
                loop_menu = 0;
                break;
            default:
                printf("Opcion invalida\n");
                system("pause");
        }
    } while(loop_menu);
}

Passenger* findPassengerById(LinkedList* passengerList) {
    Passenger* auxPassenger = NULL;
    int foundFlag = 0;
    int idToFind;
    int i = 0;

    idToFind = getNumber(1, 10000, "Ingrese ID del Pasajero: ", "");

    while(foundFlag == 0 && i < ll_len(passengerList)){

        auxPassenger = (Passenger*) ll_get(passengerList, i);
        if (get_id(auxPassenger) == idToFind) {
            foundFlag = 1;
        } else {
            foundFlag = 0;
        }
        i++;
    }

    if (foundFlag) {
        return auxPassenger;
    } else {
        printf("ERROR: No se Encotro ese ID, intente denuevo\n");
        return findPassengerById(passengerList);
    }
}

void loadFromText(LinkedList* passengerList, char* path) {
    FILE* newFile;
    newFile = fopen(path, "r");

    if (newFile != NULL) {
        parsePassengerFromText(newFile, passengerList);
        printf("Se cargo el archivo correctamente\n");
    } else {
        printf("Error al abrir el archivo\n");
    }

    fclose(newFile);
}

void loadFromBinary(LinkedList* passengerList, char* path) {
    FILE* newFile;
    newFile = fopen(path, "rb");

    if(newFile != NULL) {
        parsePassengerFromBinary(newFile, passengerList);
        printf("Se cargo el archivo correctamente\n");
    } else {
        printf("Error al abrir el archivo\n");    
    }

    fclose(newFile);
}

void saveAsText(LinkedList* passengerList, char* path) {
    FILE* file;
    int id;
    char name[21];
    char last_name[21];
    float price;
    char flight_code[7];
    char passenger_type[21];
    char flight_status[21];
    int len;

    file = fopen(path, "w");
    Passenger* auxPassenger = NULL;

    if (file != NULL) {
        len = ll_len(passengerList);

        for (int i = 0; i < len; i++) {
            auxPassenger = ll_get(passengerList, i);

            id = get_id(auxPassenger);
            strcpy(name, get_name(auxPassenger));
            strcpy(last_name, get_last_name(auxPassenger));
            price = get_price(auxPassenger);
            strcpy(flight_code, get_flight_code(auxPassenger));
            strcpy(passenger_type, get_passenger_type(auxPassenger));
            strcpy(flight_status, get_flight_status(auxPassenger));

            fprintf(file,"%d,%s,%s,%f,%s,%s,%s\n", 
                id, name, last_name, price, flight_code, passenger_type, flight_status);
        }
        printf("Se guardo el archivo correctamente\n");
    } else {
        printf("Error al abrir el archivo\n");    
    }

    fclose(file);
}

void saveAsBinary(LinkedList* passengerList, char* path) {
    FILE* file;
    Passenger* auxPassenger;
    int len;

    file = fopen(path, "wb");
    
    if (file != NULL) {
        len = ll_len(passengerList);

        for (int i = 0; i < len; i++) {
            auxPassenger = ll_get(passengerList, i);
            fwrite(auxPassenger, sizeof(Passenger), 1, file);
        }
        printf("Se guardo el archivo correctamente\n");
    } else {
        printf("Error al abrir el archivo\n");    
    }

    fclose(file);
}

int compareFirstName(void* a, void* b) {
    char nameA[40];
    char nameB[40];
    
    if(a != NULL && b != NULL){
        strcpy(nameA, ((Passenger*)a)->name);
        strcpy(nameB, ((Passenger*)b)->name);
        return strcmp(nameA, nameB);
    }

    return 0;
}

int compareLastName(void* a, void* b) {
    char nameA[40];
    char nameB[40];
    
    if(a != NULL && b != NULL){
        strcpy(nameA, ((Passenger*)a)->last_name);
        strcpy(nameB, ((Passenger*)b)->last_name);
        return strcmp(nameA, nameB);
    }

    return 0;
}

int isFirstClass(void* a) {
    return ((Passenger*)a)->passenger_type == 1;
}

void showFirstClass(LinkedList* passengerList) {
    printf("**** Pasajeros en First Class: ****\n");
    ll_show_with_condition(passengerList, isFirstClass);
    printf("**** Fin ****\n");
    system("pause");
}

int modifyMenu(Passenger* passenger) {
    int opt;
    char name[21];
    char last_name[21];

    strcpy(name, get_name(passenger));
    strcpy(last_name, get_last_name(passenger));

    printf("**** EDICION DE -%s %s- ****\n", name, last_name);
    printf("1- Editar Nombre\n");
    printf("2- Editar Apellido\n");
    printf("3- Editar Precio\n");
    printf("4- Editar Codigo de Vuelo\n");
    printf("5- Editar Tipo\n");
    printf("6- Editar Status de Vuelo\n");
    printf("7- Salir\n");
    printf("Opcion: ");
    fflush(stdin);
    scanf("%d", &opt);

    return opt;
}

int reportsMenu() {
    int opt;

    printf("**** INFORMES ****\n");
    printf("1- Nombre (ASC)\n");
    printf("2- Nombre (DEC)\n");
    printf("3- Apellido (ASC)\n");
    printf("4- Apellido (DEC)\n");
    printf("5- Todos los de FirstClass\n");
    printf("6- Salir\n");
    printf("Opcion: ");
    fflush(stdin);
    scanf("%d", &opt);

    return opt;
}