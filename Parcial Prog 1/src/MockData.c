#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Utilities.h"
#include "MockData.h"
#include "Censista.h"
#include "Date.h"
#include "Address.h"

#define INACTIVO 0
#define PENDIENTE 0

char nameMockArray[10][21] = {
    "Sallyann",
    "Ody",
    "Vinni",
    "Livy",
    "Lyndsay",
    "Yetta",
    "Brandi",
    "Lemmie",
    "Celestyn",
    "Darrelle"
};

char lastNameMockArray[10][21] = {
    "Bernaert",
    "Herrieven",
    "Stibbs",
    "Shorland",
    "Godlonton",
    "Hoofe",
    "Allmen",
    "Ridolfo",
    "Lassey",
    "Giacomasso"
};

Date dateMockArray[10] = {
    {26,10,1998},
    {10,1,1993},
    {4,11,1998},
    {8,4,1993},
    {22,6,1995},
    {8,11,1997},
    {2,2,1999},
    {11,10,2000},
    {18,4,1993},
    {9,12,1997}
};

Address addressMockArray[10] = {
    {"Ilene",424},
    {"Algoma",939},
    {"Clarendon",2122},
    {"Westport",1234},
    {"Gulseth",184},
    {"Redwing",557},
    {"Troy",8356},
    {"Bluejay",50},
    {"American",888},
    {"Hayes",3842}
};

char streetsMockArray[20][21] = {
    "Portage",
    "Duke",
    "High Crossing",
    "Knutson",
    "Calypso",
    "Graceland",
    "Del Mar",
    "Meadow Valley",
    "Maywood",
    "8th",
    "Montana",
    "Karstens",
    "Eagan",
    "Waywood",
    "Springview",
    "Mariners Cove",
    "Lindbergh",
    "Mitchell",
    "Mitchell",
    "Park Meadow"
};

// Functions

int checkCQtyAvailable(Censista censistaList[], int len, int qty) {
    int emptyCounter = 0;
    int i = 0;

    while(i < len && emptyCounter < qty) {
        if (censistaList[i].is_empty) {
            emptyCounter++;
        }
        i++;
    }

    if (emptyCounter == qty) {
        return 1;
    } else {
        printf("No hay lugar suficiente para crear %i Censistas\n", qty);
        return 0;
    }
}


int checkZQtyAvailable(Zone zoneList[], int len, int qty) {
    int emptyCounter = 0;
    int i = 0;

    while(i < len && emptyCounter < qty) {
        if (zoneList[i].is_empty) {
            emptyCounter++;
        }
        i++;
    }

    if (emptyCounter == qty) {
        return 1;
    } else {
        printf("No hay lugar suficiente para crear %i Zonas\n", qty);
        return 0;
    }
}

void mockCensistas(Censista censistaList[], int len, int* globalId){
    int qty = getNumber(0, len, "Ingrese la cantidad de Censistas a generar: ", "");
    if (checkCQtyAvailable(censistaList, len, qty)) {
        for(int i = 0; i < qty; i++) {
            censistaList[i].id = *globalId;
            strcpy(censistaList[i].name, nameMockArray[rand() % 10]);
            strcpy(censistaList[i].last_name, lastNameMockArray[rand() % 10]);
            censistaList[i].date_of_birth = dateMockArray[rand() % 10];
            censistaList[i].address = addressMockArray[rand() % 10];
            censistaList[i].age = getAge(censistaList[i].date_of_birth);
            censistaList[i].state = INACTIVO;
            censistaList[i].is_empty = 0;
            (*globalId)++;
        }
        printf("Censistas generados correctamente!\n");
        system("pause");
    } else {
        printf("Volviendo a Menu\n");
        system("pause");
    } 
}

void mockZones(Zone zoneList[], int len, int* globalId, int locationLen){
    int qty = getNumber(0, len, "Ingrese la cantidad de Zonas a generar: ", "");
    if (checkZQtyAvailable(zoneList, len, qty)) {
        for(int i = 0; i < qty; i++) {
            zoneList[i].id = *globalId;
            for (int j = 0; j < 4; ++j) {
                strcpy(zoneList[i].streets[j], streetsMockArray[rand() % 20]);
            }
            zoneList[i].id_location = (rand() % locationLen) + 1;
            zoneList[i].state = PENDIENTE;
            zoneList[i].is_empty = 0;
            (*globalId)++;
        }
        printf("Zonas generadas correctamente!\n");
        system("pause");
    } else {
        printf("Volviendo a Menu\n");
        system("pause");
    } 
}
