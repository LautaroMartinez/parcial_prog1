#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Utilities.h"
#include "CensistaAux.h"
#include "Censista.h"
#include "ZoneAux.h"
#include "Zone.h"
#include "Address.h"

#define PENDIENTE  0
#define FINALIZADO 1

int getEmptyZoneIndex(Zone zoneList[], int len) {
    int foundFlag = 0;
    int i = -1;

    while(foundFlag == 0 && i < len){
        i++;
        foundFlag = zoneList[i].is_empty;
    }

    if (foundFlag == 1 && i != len) {
        return i;
    } else {
        return -1;
    }
}

int getNotEmptyZoneIndex(Zone zoneList[], int len) {
    int foundFlag = 0;
    int i = -1;

    while(foundFlag == 0 && i < len){
        i++;
        foundFlag = !zoneList[i].is_empty;
    }

    if (foundFlag == 1 && i != len) {
        return i;
    } else {
        return -1;
    }
}

int findZoneById(Zone zoneList[], int len) {
    int foundFlag = 0;
    int idToFind;
    int i = 0;

    idToFind = getNumber(1, 10000, "Ingrese ID de la Zona: ", "");

    while(foundFlag == 0 && i < len){

        if (zoneList[i].is_empty == 0 && zoneList[i].id == idToFind) {
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
            return findZoneById(zoneList, len);
        } else {
            return -1;
        }
    }
}

int findZoneByCensistaId(int censistaId, Zone zoneList[], int len) {
    int foundFlag = 0;
    int i = 0;

    while(foundFlag == 0 && i < len){
        if (zoneList[i].is_empty == 0 && zoneList[i].id_censista == censistaId) {
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
        return -1;
    }
}

void showZones(Zone zoneList[], int len, Censista censistaList[], int censistaLen,
               Location locationList[], int locationLen) {
    Zone assignedZoneList[len];
    int assignedCounter = 0;
    Zone pendingZoneList[len];
    int pendingCounter = 0;
    int locationIndex;
    int censistaIndex;

    for(int i = 0; i < len; i++) {
        if (zoneList[i].is_empty == 0) {
            if(zoneList[i].id_censista != -1){
                assignedZoneList[assignedCounter] = zoneList[i];
                assignedCounter++;
            } else {
                pendingZoneList[pendingCounter] = zoneList[i];
                pendingCounter++;
            }
        }
    }
    
    if (assignedCounter > 0) {
        printf("**** Zonas Asignadas: ****\n");
        for (int j = 0; j < assignedCounter; ++j) {
            censistaIndex = findCensistaById(censistaList, censistaLen, assignedZoneList[j].id_censista);
            locationIndex = findLocationById(locationList, locationLen, assignedZoneList[j].id_location);
            if (j > 0) {
                printf("---\n");
            }
            printf("Censista : %s, %s\n", censistaList[censistaIndex].name, censistaList[censistaIndex].last_name);
            printf("Localidad: %s | Calles: %s, %s, %s, %s\n", locationList[locationIndex].name, assignedZoneList[j].streets[0], 
                assignedZoneList[j].streets[1], assignedZoneList[j].streets[2], assignedZoneList[j].streets[3]);
            if (assignedZoneList[j].state == FINALIZADO) {
                printf("En Situ: %i, Virtuales: %i, Ausentes: %i\n", assignedZoneList[j].censados_in_place, 
                    assignedZoneList[j].censados_virtual, assignedZoneList[j].censados_absent); 
            }
        }
    }

    if (pendingCounter > 0) {
        printf("**** Zonas Sin Asignar: ****\n");
        for (int k = 0; k < pendingCounter; ++k) {
            locationIndex = findLocationById(locationList, locationLen, pendingZoneList[k].id_location);
            if (k > 0) {
                printf("---\n");
            }
            printf("Localidad: %s | Calles: %s, %s, %s, %s\n", locationList[locationIndex].name, pendingZoneList[k].streets[0], 
                pendingZoneList[k].streets[1], pendingZoneList[k].streets[2], pendingZoneList[k].streets[3]);
        }
    }

    printf("**** Fin ****\n");
    system("pause");
}
