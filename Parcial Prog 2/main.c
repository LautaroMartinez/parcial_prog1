#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "Utilities.h"

int menu();
int fileMenu();

int main(void) {
    setbuf(stdout, NULL);

    LinkedList* passengerList = ll_newLinkedList();

    int loop_menu = 1;
    int global_id = 1;

    do {
        switch(menu()) {
            case 1: ;
                addPassengers(passengerList, &global_id);
                break;
            case 2: ;
                if(!ll_isEmpty(passengerList)) {
                    modifyPassenger(passengerList);
                } else {
                    printf("No hay pasajeros para modificar\n");
                    system("pause");
                }
                break;
            case 3: ;
               if(!ll_isEmpty(passengerList)) {
                    removePassenger(passengerList);
                } else {
                    printf("No hay pasajeros para borrar\n");
                    system("pause");
                }
                break;
            case 4:
                if(!ll_isEmpty(passengerList)) {
                    sortPassengers(passengerList);
                } else {
                    printf("No hay pasajeros para mostrar\n");
                    system("pause");
                }
                break;
            case 5:
                if(!ll_isEmpty(passengerList)) {
                    int save_file_loop_menu = 1;
                    do {
                        switch(fileMenu()) {
                            case 1: 
                                saveAsText(passengerList, "data-export.csv");
                                save_file_loop_menu = 0;
                                break;
                            case 2: 
                                saveAsBinary(passengerList, "data.bin");
                                break;
                                save_file_loop_menu = 0;
                            case 3:
                                printf("Salir");
                                save_file_loop_menu = 0;
                                break;
                            default:
                                printf("Opcion invalida\n");
                                system("pause");
                                break;
                        }
                    } while(save_file_loop_menu);
                } else {
                    printf("No hay pasajeros para guardar\n");
                    system("pause");
                }
                break;
            case 6: ;
                int load_file_loop_menu = 1;
                do {
                    switch(fileMenu()) {
                        case 1: 
                            loadFromText(passengerList, "data.csv");
                            load_file_loop_menu = 0;
                            break;
                        case 2: 
                            loadFromBinary(passengerList, "data.bin");
                            load_file_loop_menu = 0;
                            break;
                        case 3:
                            printf("Salir");
                            load_file_loop_menu = 0;
                            break;
                        default:
                            printf("Opcion invalida\n");
                            system("pause");
                            break;
                    }
                } while(load_file_loop_menu);
                break;
            case 7:
                printf("Salir");
                loop_menu = 0;
                break;
            default:
                printf("Opcion invalida\n");
                system("pause");
                break;
        }
    } while(loop_menu);

    return EXIT_SUCCESS;

}

int menu() {
    int opt;

    printf("**** PASAJEROS ****\n");
    printf("1- Nuevo Pasajero\n");
    printf("2- Editar Pasajero\n");
    printf("3- Borrar Pasajero\n");
    printf("4- Informes\n");
    printf("5- Guardar Pasajeros en Archivo\n");
    printf("6- Cargar Pasajeros de Archivo\n");
    printf("7- Salir\n");
    printf("Opcion: ");
    fflush(stdin);
    scanf("%d", &opt);

    return opt;
}

int fileMenu() {
    int opt;

    printf("**** ARCHIVOS ****\n");
    printf("1- Texto\n");
    printf("2- Binario\n");
    printf("3- Salir\n");
    printf("Opcion: ");
    fflush(stdin);
    scanf("%d", &opt);

    return opt;   
}
