#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Passenger.h"

Passenger* passenger_init_new() {
    Passenger* newPassenger = (Passenger*) malloc(sizeof(Passenger));

    newPassenger->id = 0;
    strcpy(newPassenger->name, " ");
    strcpy(newPassenger->last_name, " ");
    newPassenger->price = 0;
    strcpy(newPassenger->flight_code, " ");
    newPassenger->passenger_type = 0;
    newPassenger->flight_status = 0;

    return newPassenger;
}

void passenger_delete(Passenger* passenger){
    if(passenger != NULL) { free(passenger); }
}

void set_id(Passenger* passenger, int id) {
    passenger->id = id;
}

void set_name(Passenger* passenger, char* name) {
	strcpy(passenger->name, name);
}

void set_last_name(Passenger* passenger, char* last_name) {
	strcpy(passenger->last_name, last_name);
}

void set_price(Passenger* passenger, float price) {
    passenger->price = price;
}

void set_flight_code(Passenger* passenger, char* flight_code) {
	strcpy(passenger->flight_code, flight_code);
}

void set_passenger_type(Passenger* passenger, int passenger_type) {
    passenger->passenger_type = passenger_type;
}

void set_flight_status(Passenger* passenger, int flight_status) {
    passenger->flight_status = flight_status;
}

void set_miles(Passenger* passenger, int miles) {
    passenger->miles = miles;
}

int get_id(Passenger* passenger) {
    return passenger->id;
}

char* get_name(Passenger* passenger) {
    return passenger->name;
}

char* get_last_name(Passenger* passenger) {
    return passenger->last_name;
}

float get_price(Passenger* passenger) {
    return passenger->price;
}

char* get_flight_code(Passenger* passenger) {
    return passenger->flight_code;
}

char* get_passenger_type(Passenger* passenger) {
    switch(passenger->passenger_type) {
        case 1: 
            return "FirstClass";
            break;
        case 2: 
            return "ExecutiveClass";
            break;
        case 3:
            return "EconomyClass";
            break;
        default:
            return "Error";
            break;
    }
}

char* get_flight_status(Passenger* passenger) {
    switch(passenger->flight_status) {
        case 1: 
            return "Aterrizado";
            break;
        case 2: 
            return "En Horario";
            break;
        case 3:
            return "En Vuelo";
            break;
        case 4:
            return "Demorado";
            break;
        default:
            return "Error";
            break;
    }
}

int get_miles(Passenger* passenger) {
    return passenger->miles;
}