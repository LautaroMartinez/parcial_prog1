#include "Address.h"

#ifndef ZONE_H
#define ZONE_H

typedef struct MyZone{
    int id;
    char streets[4][21];
    int id_location;
    int id_censista;
    int state;
    int is_empty;
    int censados_in_place;
    int censados_virtual;
    int censados_absent;
} Zone;

#endif /* ZONE_H */

/// @brief Inicializa las Zonas
///
/// @param zoneList
/// @param len
void initZoneArray(Zone zoneList[], int len);

/// @brief Crea una nueva Zona
///
/// @param zone
/// @param locationList
/// @param locationLen
/// @param globalId
void addZone(Zone *zone , Location locationList[], int locationLen, int *globalId);
