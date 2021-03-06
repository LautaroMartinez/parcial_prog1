#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CensistaAux.h"
#include "Censista.h"
#include "Utilities.h"
#include "ZoneAux.h"
#include "Zone.h"

#define INACTIVO 0
#define ACTIVO 1
#define LIBERADO 2

#define PENDIENTE  0
#define FINALIZADO 1

int findCensistaById(Censista censistaList[], int len, int idToFind) {
    int foundFlag = 0;
    int i = 0;

    if (idToFind == -1) {
        idToFind = getNumber(1, 10000, "Ingrese ID del Censista: ", "");
    }

    while(foundFlag == 0 && i < len){

        if (censistaList[i].is_empty == 0 && censistaList[i].id == idToFind) {
            foundFlag = 1;
        } else {
            foundFlag = 0;
        }
        i++;
    }

    if (foundFlag) {
        i--;
        return i;
    } else {
        printf("ERROR: No se Encotro ese ID\n");
        if (yesOrNo("Quiere volver a intentear? (Y/N): ", "")) {
            return findCensistaById(censistaList, len, -1);
        } else {
            return -1;
        }
    }
}

int menu() {
    int opt;

    printf("**** MENU CENSISTAS ****\n");
    printf("1- Nuevo Censista\n");
    printf("2- Editar Censista\n");
    printf("3- Borrar Censista\n");
    printf("4- Mostrar Censistas\n");
    printf("5- Generar Censistas\n");
    printf("**** MENU ZONA ****\n");
    printf("6- Nueva Zona\n");
    printf("7- Asignar Zonas\n");
    printf("8- Cargar Zona\n");
    printf("9- Mostrar Zonas\n");
    printf("10- Generar Zonas\n");
    printf("**** MENU ZONA ****\n");
    printf("11- Salir\n");
    printf("Opcion: ");
    fflush(stdin);
    scanf("%d", &opt);

    return opt;
}

int modifyMenu(Censista censista) {
    int opt;

    printf("**** EDICION DE -%s %s- ****\n", censista.name, censista.last_name);
    printf("1- Editar Nombre\n");
    printf("2- Editar Apellido\n");
    printf("3- Editar Fecha de Nacimiento\n");
    printf("4- Editar Direccion\n");
    printf("5- Salir\n");
    printf("Opcion: ");
    fflush(stdin);
    scanf("%d", &opt);

    return opt;
}

int reportsMenu() {
    int opt;

    printf("**** INFORMES ****\n");
    printf("1- Apellido y Edad (ASC)\n");
    printf("2- Apellido y Edad (DEC)\n");
    printf("3- Censistas en Localidades Predefinidas\n");
    printf("4- Censista con mas censados\n");
    printf("5- Salir\n");
    printf("Opcion: ");
    fflush(stdin);
    scanf("%d", &opt);

    return opt;
}

int getEmptyCensistaIndex(Censista censistaList[], int len) {
    int foundFlag = 0;
    int i = -1;

    while(foundFlag == 0 && i < len){
        i++;
        foundFlag = censistaList[i].is_empty;
    }

    if (foundFlag == 1 && i != len) {
        return i;
    } else {
        return -1;
    }
}

int getNotEmptyCensistaIndex(Censista censistaList[], int len) {
    int foundFlag = 0;
    int i = -1;

    while(foundFlag == 0 && i < len){
        i++;
        foundFlag = !censistaList[i].is_empty;
    }

    if (foundFlag == 1 && i != len) {
        return i;
    } else {
        return -1;
    }
}


void showCensistas(Censista censistaList[], int len, int order) {
    Censista auxCensista;
    int orderFlag = 0;
    int breakFlag = 0;
    int i; 
    int j;

    for(i = 0; i < len; i++) {
        for(j = 0; j < len-i-1; j++) {
            orderFlag = 0;
            if (censistaList[j].is_empty == 0) {
                if (order) {
                    if (strcmp(censistaList[j].last_name,censistaList[j+1].last_name) > 0 ||
                       (strcmp(censistaList[j].last_name,censistaList[j+1].last_name) == 0 && 
                        censistaList[j].age > censistaList[j+1].age)) {
                        orderFlag = 1;
                    } else {
                        orderFlag = 0;
                    }
                } else {
                    if (strcmp(censistaList[j].last_name,censistaList[j+1].last_name) < 0 ||
                       (strcmp(censistaList[j].last_name,censistaList[j+1].last_name) == 0 && 
                        censistaList[j].age < censistaList[j+1].age)) {
                        orderFlag = 1;
                    } else {
                        orderFlag = 0;
                    }
                }
                if(orderFlag) {
                    auxCensista = censistaList[j];
                    censistaList[j] = censistaList[j+1];
                    censistaList[j+1] = auxCensista;
                    breakFlag = 1;
                } 
            }
        }

        if(breakFlag == 0) {
            break;
        }
    }
    
    printf("**** Censistas ordenados por Apellido y Edad: ****\n");
    char stateAux[75];
    for(i = 0; i < len; i++) {
        if (censistaList[i].is_empty == 0) {
            if (i > 0) {
                printf("---\n");
            }
            printf("Nombre: %s, %s - Anios: %i\n", censistaList[i].last_name, censistaList[i].name, censistaList[i].age);
            printf("Fecha de Nacimiento: %i/%i/%i - Direccion: %s %i \n", censistaList[i].date_of_birth.day, censistaList[i].date_of_birth.month, 
                censistaList[i].date_of_birth.year, censistaList[i].address.street, censistaList[i].address.number);
            switch (censistaList[i].state) {
                case INACTIVO:
                    strcpy(stateAux, "INACTIVO");
                    break;
                case ACTIVO:
                    strcpy(stateAux, "ACTIVO");
                    break;
                case LIBERADO:
                    strcpy(stateAux, "LIBERADO");
                    break;
            }
            printf("Estado: %s\n", stateAux); 
        }
    }
    printf("**** Fin ****\n");
    system("pause");
}

void showCensistasBy4Locations(Censista censistaList[], int len, Zone zoneList[], int zoneLen) {
    Censista auxCensista;
    int breakFlag = 0;
    int zoneIndex;
    int i; 
    int j;

    for(i = 0; i < len; i++) {
        for(j = 0; j < len-i-1; j++) {
            if (censistaList[j].is_empty == 0) {
                if(strcmp(censistaList[j].last_name,censistaList[j+1].last_name) > 0 ||
                  (strcmp(censistaList[j].last_name,censistaList[j+1].last_name) == 0 && 
                   censistaList[j].name > censistaList[j+1].name)) {
                    auxCensista = censistaList[j];
                    censistaList[j] = censistaList[j+1];
                    censistaList[j+1] = auxCensista;
                    breakFlag = 1;
                } 
            }
        }

        if(breakFlag == 0) {
            break;
        }
    }
    
    printf("**** Censistas ordenados por Apellido y Nombre: ****\n");
    char stateAux[75];
    for(i = 0; i < len; i++) {
        if (censistaList[i].is_empty == 0) {

            zoneIndex = findZoneByCensistaId(censistaList[i].id, zoneList, zoneLen);

            if (zoneIndex != -1 && (zoneList[zoneIndex].id_location == 1 || zoneList[zoneIndex].id_location == 2 ||
                zoneList[zoneIndex].id_location == 3 || zoneList[zoneIndex].id_location == 4)) {
                
                printf("---\n");
                printf("Nombre: %s, %s - Anios: %i\n", censistaList[i].last_name, censistaList[i].name, censistaList[i].age);
                printf("Fecha de Nacimiento: %i/%i/%i - Direccion: %s %i \n", censistaList[i].date_of_birth.day, censistaList[i].date_of_birth.month, 
                    censistaList[i].date_of_birth.year, censistaList[i].address.street, censistaList[i].address.number);
                switch (censistaList[i].state) {
                    case INACTIVO:
                        strcpy(stateAux, "INACTIVO");
                        break;
                    case ACTIVO:
                        strcpy(stateAux, "ACTIVO");
                        break;
                    case LIBERADO:
                        strcpy(stateAux, "LIBERADO");
                        break;
                }
                printf("Estado: %s\n", stateAux); 

            }

        }
    }
    printf("**** Fin ****\n");
    system("pause");
}

void showCensistasWithMostCensados(Censista censistaList[], int len, Zone zoneList[], int zoneLen) {
    int censistWithMostCensadosId;
    int auxCurrentMax = -1;
    int auxMaxComparator;

    for (int i = 0; i < zoneLen; ++i) {
        if (zoneList[i].state == FINALIZADO) {
            auxMaxComparator = zoneList[i].censados_virtual + zoneList[i].censados_in_place;
            if (auxMaxComparator > auxCurrentMax) {
                auxCurrentMax = auxMaxComparator;
                censistWithMostCensadosId = zoneList[i].id_censista;
            }
        }
    }

    if (auxCurrentMax != -1) {
        int censistaIndex = findCensistaById(censistaList, len, censistWithMostCensadosId);
        printf("Censista con mas censos: %s %s (%i censados)\n", censistaList[censistaIndex].name, 
            censistaList[censistaIndex].last_name, auxCurrentMax);
        system("pause");
    } else {
        printf("No hay Zonas con datos cargados\n");
        system("pause");
    }
}

void showCensosByCensistaAndZone(Censista censistaList[], int len, Zone zoneList[], int zoneLen) {
    int censosByCensista[len];
    int zonasByCensista[len];
    int locationWithMostAbscentId;

    for (int i = 0; i < len; ++i) {
        censosByCensista[censistaList[i].id] = 0;
        zonasByCensista[censistaList[i].id] = 0;
    }

    for (int j = 0; j < len; ++j) {
        if (zoneList[j].state == FINALIZADO) {
            censosByCensista[zoneList[j].id_censista] = censosByCensista[zoneList[j].id_censista] + zoneList[j].censados_in_place + zoneList[j].censados_virtual;
            zonasByCensista[zoneList[j].id_censista]++;
        }
    }

    for (int i = 0; i < len; ++i) {
        if (censosByCensista[censistaList[i].id] != 0) {
            printf("Censista: %s (%i personas/zona)\n", censosByCensista[censistaList[i].id].name, censosByCensista[censistaList[i].id]/zonasByCensista[censistaList[i].id]);
        }
    }
}
