#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

void parsePassengerFromText(FILE* file , LinkedList* passengerList) {
    Passenger* newPassenger;
    int readCounter;
    char buffer[7][128];

    if(file != NULL && passengerList != NULL) {
        do {
            readCounter = fscanf(file,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5],buffer[6]);
            
            if(readCounter < 7) { 
                printf("La data del archivo es erronea\n");
                break; 
            } else {
                newPassenger = passenger_init_new();

                set_id(newPassenger, atoi(buffer[0]));
                set_name(newPassenger, buffer[1]);
                set_last_name(newPassenger, buffer[2]);
                set_price(newPassenger, atof(buffer[3]));
                set_flight_code(newPassenger, buffer[4]);
                set_passenger_type(newPassenger, atoi(buffer[5]));
                set_flight_status(newPassenger, atoi(buffer[6]));

                ll_add(passengerList, newPassenger);
            }
        } while(!feof(file));
    } else {
        printf("Error leyendo el archivo\n");
        system("pause");
    }
    fclose(file);
}

void parsePassengerFromBinary(FILE* file , LinkedList* passengerList) {
    int readCounter; 
    Passenger* newPassenger;

    if(file != NULL && passengerList != NULL) {
        do {
            newPassenger = passenger_init_new();
            readCounter = fread(newPassenger,sizeof(Passenger),1,file);

            if( newPassenger != NULL && readCounter == 1) {
                ll_add(passengerList,newPassenger);
            }
        }
        while(!feof(file));
    }

    fclose(file);
}