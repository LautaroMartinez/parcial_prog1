#include "Censista.h"
#include "Zone.h"

#ifndef MOCKDATA_H
#define MOCKDATA_H

#endif /* MOCKDATA_H */

/// @brief Verifica que entren una cantidad de Censistas en el array
///
/// @param censistaList
/// @param len
/// @param qty
/// @return
int checkCQtyAvailable(Censista censistaList[], int len, int qty);

/// @brief Verifica que entren una cantidad de Zonas en el array
///
/// @param zoneList
/// @param len
/// @param qty
/// @return
int checkZQtyAvailable(Zone zoneList[], int len, int qty);

/// @brief Crea Censistas con datos Mock
///
/// @param censistaList
/// @param len
/// @param globalId
void mockCensistas(Censista censistaList[], int len, int* globalId);

/// @brief Crea Zonas con datos Mock
///
/// @param zoneList
/// @param len
/// @param globalId
/// @param locationLen
void mockZones(Zone zoneList[], int len, int* globalId, int locationLen);
