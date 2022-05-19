#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Censista.h"
#include "CensistaAux.h"
#include "Utilities.h"
#include "ZoneAux.h"
#include "Zone.h"
#include "Address.h"
#include "MockData.h"

#define LEN_CENSISTAS 100
#define LEN_ZONES 100
#define LEN_LOCATIONS 8

int main(void) {

    setbuf(stdout, NULL);

    Location locationList[LEN_LOCATIONS] = {
        {1, "Avellaneda"},
        {2, "Lanus"},
        {3, "Lomas de Zamora"},
        {4, "Banfield"},
        {5, "Boedo"},
        {6, "San Telmo"},
        {7, "Palermo"},
        {8, "Chacarita"}
    };
 
    Censista censistaList[LEN_CENSISTAS];
    Zone zoneList[LEN_ZONES];

    int loop_menu = 1;
    int zone_global_id = 1;
    int censista_global_id = 1;
    int any_index;
    int any_index_aux;
    int empty_index;

    initCensistaArray(censistaList, LEN_CENSISTAS);
    initZoneArray(zoneList, LEN_ZONES);

    do {
        switch(menu()) {
            case 1: ;
                empty_index = getEmptyCensistaIndex(censistaList, LEN_CENSISTAS);
                if(empty_index != -1) {
                    addCensistas(&censistaList[empty_index], &censista_global_id);
                } else {
                    printf("No se puede agregar mas censistas\n");
                    system("pause");
                }
                break;
            case 2: ;
                censistaList[0].is_empty = 0;
                any_index = getNotEmptyCensistaIndex(censistaList, LEN_CENSISTAS);
                if(any_index != -1) {
                    modifyCensista(censistaList,LEN_CENSISTAS);
                } else {
                    printf("No hay censistas para modificar\n");
                    system("pause");
                }
                break;
            case 3: ;
                any_index = getNotEmptyCensistaIndex(censistaList, LEN_CENSISTAS);
                if(any_index != -1) {
                    removeCensista(censistaList, LEN_CENSISTAS, zoneList, LEN_ZONES);
                } else {
                    printf("No hay censistas para dar de baja\n");
                    system("pause");
                }
                break;
            case 4: ;
                any_index = getNotEmptyCensistaIndex(censistaList, LEN_CENSISTAS);
                if(any_index != -1) {
                    showCensistasMenu(censistaList, LEN_CENSISTAS, zoneList, LEN_ZONES);
                } else {
                    printf("No hay censistas para mostrar\n");
                    system("pause");
                }
                break;
            case 5: ;
                empty_index = getEmptyCensistaIndex(censistaList, LEN_CENSISTAS);
                if(any_index != -1) {
                    mockCensistas(censistaList, LEN_CENSISTAS, &censista_global_id);
                } else {
                    printf("No se puede agregar mas censistas\n");
                    system("pause");
                }
                break;
            case 6: ;
                empty_index = getEmptyZoneIndex(zoneList, LEN_ZONES);
                if(empty_index != -1) {
                    addZone(&zoneList[empty_index], locationList, LEN_LOCATIONS, &zone_global_id);
                } else {
                    printf("No se puede agregar mas zonas\n");
                    system("pause");
                }
                break;
            case 7: ;
                any_index = getNotEmptyZoneIndex(zoneList, LEN_ZONES);
                any_index_aux = getNotEmptyCensistaIndex(censistaList, LEN_CENSISTAS);
                if(any_index != -1 && any_index_aux != -1) {
                    assignZone(zoneList, LEN_ZONES, censistaList, LEN_CENSISTAS);
                } else {
                    if (any_index == -1) {
                        printf("No hay zonas para asignar\n");
                        system("pause");
                    } else {
                        printf("Antes hay que crear censistas\n");
                        system("pause");
                    }
                }
                break;
            case 8: ;
                any_index = getNotEmptyZoneIndex(zoneList, LEN_ZONES);
                any_index_aux = getNotEmptyCensistaIndex(censistaList, LEN_CENSISTAS);
                if(any_index != -1 && any_index_aux != -1) {
                    loadZone(zoneList, LEN_ZONES, censistaList, LEN_CENSISTAS);
                } else {
                    if (any_index == -1) {
                        printf("No hay zonas para cargar\n");
                        system("pause");
                    } else {
                        printf("Antes hay que crear censistas\n");
                        system("pause");
                    }
                }
                break;
            case 9: ;
                any_index = getNotEmptyZoneIndex(zoneList, LEN_ZONES);
                if(any_index != -1) {
                    showZonesMenu(zoneList, LEN_ZONES, censistaList, LEN_CENSISTAS, locationList, LEN_LOCATIONS);
                } else {
                    printf("No hay zonas para mostrar\n");
                    system("pause");
                }
                break;
            case 10: ;
                empty_index = getEmptyZoneIndex(zoneList, LEN_ZONES);
                if(empty_index != -1) {
                    mockZones(zoneList, LEN_ZONES, &zone_global_id, LEN_LOCATIONS);
                } else {
                    printf("No se puede agregar mas zonas\n");
                    system("pause");
                }
                break;
            case 11:
                printf("Salir");
                loop_menu = 0;
                break;
            default:
                printf("opcion invalida\n");
                system("pause");
        }
    } while(loop_menu);

    return EXIT_SUCCESS;
}
