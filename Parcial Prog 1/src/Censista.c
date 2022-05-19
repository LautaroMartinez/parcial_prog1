#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CensistaAux.h"
#include "Censista.h"
#include "ZoneAux.h"
#include "Zone.h"
#include "Date.h"
#include "Address.h"
#include "Utilities.h"

#define INACTIVO 0
#define ACTIVO 1
#define LIBERADO 2

#define PENDIENTE  0
#define FINALIZADO 1

void initCensistaArray(Censista censistaList[], int len) {
	for (int i = 0; i < len; ++i) {
        censistaList[i].state = INACTIVO;
        censistaList[i].is_empty = 1;
	}
}

void addCensistas(Censista *censista, int *globalId) {
    censista->id = *globalId;
    getString(censista->name, 21, "Ingrese el Nombre: ", "");
    getString(censista->last_name, 21, "Ingrese el Apellido: ", "");
    censista->date_of_birth = getDate("");
    censista->age = getAge(censista->date_of_birth);
    censista->address = getAddress("Ingrese la Direccion");
    censista->state = ACTIVO;
    censista->is_empty = 0;
    (*globalId)++;

    printf("Se ingreso correctamente el censista\n");
    system("pause");
}

void modifyCensista(Censista censistaList[], int len){
    int censistaIndex = findCensistaById(censistaList, len, -1);
    int loop_menu = 1;

    if (censistaIndex != -1) {
        do {
            switch(modifyMenu(censistaList[censistaIndex])) {
                case 1: ;
                    getString(censistaList[censistaIndex].name, 21, "Ingrese el Nombre: ", "");
                    break;
                case 2: ;
                    getString(censistaList[censistaIndex].last_name, 21, "Ingrese el Apellido: ", "");
                    break;
                case 3: ;
                    censistaList[censistaIndex].date_of_birth = getDate("");
                    break;
                case 4: ;
                    censistaList[censistaIndex].address = getAddress("Ingrese la Direccion");
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
    } else {
        printf("Volviendo a Menu\n");
        system("pause");
    }
}

void removeCensista(Censista censistaList[], int censistaLen, Zone zoneList[], int zoneLen){
    int censistaIndex = findCensistaById(censistaList, censistaLen, -1);
    
    if (censistaIndex != 1) {
        if (censistaList[censistaIndex].state == ACTIVO) {
            int zoneIndex = findZoneByCensistaId(censistaList[censistaIndex].id, zoneList, zoneLen);
            printf("El censista %s %s paso a estar inactivo\n", 
                censistaList[censistaIndex].name, censistaList[censistaIndex].last_name);
            censistaList[censistaIndex].state = INACTIVO;
            zoneList[zoneIndex].id_censista = -1;
            system("pause");    
        } else {
            printf("Censista %s %s dado de baja con exito\n", 
                censistaList[censistaIndex].name, censistaList[censistaIndex].last_name);
            censistaList[censistaIndex].is_empty = 1;
            system("pause");
        }
    } else {
        printf("Volviendo a Menu\n");
        system("pause");
    }
}

void showCensistasMenu(Censista censistaList[], int len, Zone zoneList[], int zoneLen) {
    int loop_menu = 1;
    do {
        switch(reportsMenu()) {
            case 1: ;
                showCensistas(censistaList, len, 1);
                break;
            case 2: ;
                showCensistas(censistaList, len, 0);
                break;
            case 3:
                showCensistasBy4Locations(censistaList, len, zoneList, zoneLen);
                break;
            case 4:
                showCensistasWithMostCensados(censistaList, len, zoneList, zoneLen);
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

// Zone Fn

void assignZone(Zone zoneList[], int zoneLen, Censista censistaList[], int censistaLen) {
    int zoneIndex;
    int censistaIndex;

    zoneIndex = findZoneById(zoneList, zoneLen);
    if (zoneIndex != -1) {
        if (zoneList[zoneIndex].id_censista != -1) {
            printf("Error: Esta zona ya fue asignada\n");
            if (yesOrNo("Quiere volver a intentear? (Y/N): ", "")) {
                assignZone(zoneList, zoneLen, censistaList, censistaLen);
            } else {
                printf("Volviendo al Menu\n");
                system("pause");
            }
        } else {
            censistaIndex = findCensistaById(censistaList, censistaLen, -1);
            if (censistaIndex != -1) {
                zoneList[zoneIndex].id_censista = censistaList[censistaIndex].id;
                censistaList[censistaIndex].state = ACTIVO;

                printf("Se asigno %s %s a la zona %i\n", 
                    censistaList[censistaIndex].name, censistaList[censistaIndex].last_name, zoneList[zoneIndex].id);
                system("pause");
            } else {
                printf("Volviendo al Menu\n");
                system("pause");
            }
        }
    } else {
        printf("Volviendo al Menu\n");
        system("pause");
    }
}

void loadZone(Zone zoneList[], int zoneLen, Censista censistaList[], int censistaLen) {
    int zoneIndex = findZoneById(zoneList, zoneLen);
    if (zoneIndex != -1) {
        if (zoneList[zoneIndex].id_censista != -1  && zoneList[zoneIndex].state == PENDIENTE) {
            int censistaIndex = findCensistaById(censistaList, censistaLen, zoneList[zoneIndex].id_censista);
            if (censistaIndex != -1) {
                zoneList[zoneIndex].censados_in_place = getNumber(0, 1000, "Ingrese la cantidad de censados in situ: ", "");
                zoneList[zoneIndex].censados_virtual = getNumber(0, 1000, "Ingrese la cantidad de censados que completaron el formulario virtual : ", "");
                zoneList[zoneIndex].censados_absent  = getNumber(0, 1000, "Ingrese la cantidad de ausentes: ", "");

                censistaList[censistaIndex].state = LIBERADO;
                zoneList[zoneIndex].state = FINALIZADO;

                printf("Se libero a %s %s y la zona %i fue finalizada\n", 
                    censistaList[censistaIndex].name, censistaList[censistaIndex].last_name, zoneList[zoneIndex].id);
                system("pause");
            } else {
                printf("No se encontro al censista asignado a esta zona\n");
                printf("Volviendo al Menu\n");
                system("pause");
            }
        } else if (zoneList[zoneIndex].id_censista == -1) {
            printf("Error: Esta zona no tiene censista\n");
            if (yesOrNo("Quiere cargar otra zona? (Y/N): ", "")) {
                loadZone(zoneList, zoneLen, censistaList, censistaLen);
            } else {
                printf("Volviendo al Menu\n");
                system("pause");
            }
        } else {
            printf("Error: Esta zona ya fue censada\n");
            if (yesOrNo("Quiere cargar otra zona? (Y/N): ", "")) {
                loadZone(zoneList, zoneLen, censistaList, censistaLen);
            } else {
                printf("Volviendo al Menu\n");
                system("pause");
            }
        }
    } else {
        printf("Volviendo al Menu\n");
        system("pause");
    }
}

void showZonesMenu(Zone zoneList[], int len, Censista censistaList[], int censistaLen,
               Location locationList[], int locationLen) {
    int loop_menu = 1;
    do {
        switch(zoneReportsMenu()) {
            case 1: ;
                showZones(zoneList, len, censistaList, censistaLen, locationList, locationLen);
                break;
            case 2: ;
                showZonesByActiveCensista(zoneList, len, censistaList, censistaLen);
                break;
            case 3: ;
                showZoneWithMostAbscents(zoneList, len, locationList, locationLen);
                break;
            case 4:
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