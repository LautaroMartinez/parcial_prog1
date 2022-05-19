#include "Date.h"
#include "Zone.h"
#include "Address.h"

#ifndef CENSISTA_H
#define CENSISTA_H

typedef struct MyCensista {
    int id;
    char name[21];
    char last_name[21];
    int age;
    Date date_of_birth;
    Address address;
    int state;
    int is_empty;
} Censista;

#endif /* CENSISTA_H */

/// @brief Inicializa el listado de Censistas
///
/// @param censistaList
/// @param len
void initCensistaArray(Censista censistaList[], int len);

/// @brief Agrega un nuevo Censista
///
/// @param censista
/// @param globalId
void addCensistas(Censista *censista, int *globalId);

/// @brief Edita un Censista por Id
///
/// @param censistaList
/// @param len
void modifyCensista(Censista censistaList[], int len);

/// @brief Da de baja un Censista por Id
///
/// @param censistaList
/// @param censistaLen
/// @param zoneList
/// @param zoneLen
void removeCensista(Censista censistaList[], int censistaLen, Zone zoneList[], int zoneLen);

/// @brief Muestra el menu de informes de Censistas
///
/// @param censistaList
/// @param len
void showCensistasMenu(Censista censistaList[], int len, Zone zoneList[], int zoneLen);

/// @brief Asigna un Censista a una Zona
///
/// @param zoneList
/// @param zoneLen
/// @param censistaList
/// @param censistaLen
void assignZone(Zone zoneList[], int zoneLen, Censista censistaList[], int censistaLen);

/// @brief Carga los datos de una Zona
///
/// @param zoneList
/// @param zoneLen
/// @param censistaList
/// @param censistaLen
void loadZone(Zone zoneList[], int zoneLen, Censista censistaList[], int censistaLen);


void showZonesMenu(Zone zoneList[], int len, Censista censistaList[], int censistaLen,
               Location locationList[], int locationLen);