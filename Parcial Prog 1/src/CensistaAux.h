#include "Censista.h"

#ifndef CENSISTAAUX_H
#define CENSISTAAUX_H

#endif /* CENSISTAAUX_H */

/// @brief Busca un Censista por Id
///
/// @param censistaList
/// @param len
/// @param idToFind
/// @return
int findCensistaById(Censista censistaList[], int len, int idToFind);

/// @brief Busca un Index vacio del listado de Censistas
///
/// @param censistaList
/// @param len
/// @return
int getEmptyCensistaIndex(Censista censistaList[], int len);

/// @brief Busca un Index no vaio del listado de Censistas
///
/// @param censistaList
/// @param len
/// @return
int getNotEmptyCensistaIndex(Censista censistaList[], int len);

/// @brief Lista los Censistas con ordenamiento
///
/// @param censistaList
/// @param len
/// @param order
void showCensistas(Censista censistaList[], int len, int order);

void showCensistasBy4Locations(Censista censistaList[], int len, Zone zoneList[], int zoneLen);

void showCensistasWithMostCensados(Censista censistaList[], int len, Zone zoneList[], int zoneLen);

void showCensosByCensistaAndZone(Censista censistaList[], int len, Zone zoneList[], int zoneLen);

/// @brief Menu principal
///
/// @return
int menu();

/// @brief Menu de edicion
///
/// @param censista
/// @return
int modifyMenu(Censista censista);

/// @brief Menu de informes de Censistas
///
/// @return
int reportsMenu();
