#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CensistaAux.h"
#include "Censista.h"
#include "Utilities.h"
#include "Zone.h"
#include "ZoneAux.h"
#include "Address.h"

#define PENDIENTE  0
#define FINALIZADO 1

#define INACTIVO 0
#define ACTIVO   1
#define LIBERADO 2

void initZoneArray(Zone zoneList[], int len) {
    for (int i = 0; i < len; ++i) {
        zoneList[i].is_empty = 1;
        zoneList[i].id_censista = -1;
    }
}

void addZone(Zone *zone , Location locationList[], int locationLen, int *globalId) {
    char streetDisplay[75];
    int locationAux;

    for (int i = 0; i < 4; ++i) {
        strcpy(streetDisplay, "Ingrese una calle (");
        addNumToString(streetDisplay, (i+1));
        strcat(streetDisplay, "/4): ");
        getString(zone->streets[i], 21, streetDisplay, "");
    }

    printf("Seleccione la Localidad: \n");
    for (int j = 0; j < locationLen; ++j) {
        printf("-%i %s \n", j, locationList[j].name);
    }

    locationAux = getNumber(0, (locationLen-1), "Seleccion: ", "");
    zone->id_location = locationList[locationAux].id;

    zone->id = *globalId;
    zone->state = PENDIENTE;
    zone->is_empty = 0;
    (*globalId)++;

    printf("Se ingreso correctamente la zona\n");
    system("pause");
}