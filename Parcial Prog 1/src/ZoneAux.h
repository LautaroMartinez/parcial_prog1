#include "Censista.h"
#include "Zone.h"

#ifndef ZONEAUX_H
#define ZONEAUX_H

#endif /* ZONEAUX_H */

/// @brief Busca un Index vacio del listado de Zonas
///
/// @param zoneList
/// @param len
/// @return
int getEmptyZoneIndex(Zone zoneList[], int len);

/// @brief Busca un Index no vacio del listado de Zonas
///
/// @param zoneList
/// @param len
/// @return
int getNotEmptyZoneIndex(Zone zoneList[], int len);

/// @brief Busca una Zona por Id
///
/// @param zoneList
/// @param len
/// @return
int findZoneById(Zone zoneList[], int len);

/// @brief Busca una Zona por Id de Censista
///
/// @param censistaId
/// @param zoneList
/// @param len
/// @return
int findZoneByCensistaId(int censistaId, Zone zoneList[], int len);

/// @brief Muestra un informe de las Zonas
///
/// @param zoneList
/// @param len
/// @param censistaList
/// @param censistaLen
/// @param locationList
/// @param locationLen
void showZones(Zone zoneList[], int len, Censista censistaList[], int censistaLen,
               Location locationList[], int locationLen);

void showZonesByActiveCensista(Zone zoneList[], int len, Censista censistaList[], int censistaLen);

void showZoneWithMostAbscents(Zone zoneList[], int len, Location locationList[], int locationLen);

int zoneReportsMenu();
