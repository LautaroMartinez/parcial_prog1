#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"
#include "LinkedList.h"

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#endif /* CONTROLLER_H_ */

void addPassengers(LinkedList* passengerList, int *globalId);
void modifyPassenger(LinkedList* passengerList);
void removePassenger(LinkedList* passengerList);
void listPassenger(LinkedList* passengerList);
void sortPassengers(LinkedList* passengerList);
void loadFromText(LinkedList* linkedList, char* path);
void loadFromBinary(LinkedList* linkedList, char* path);
void saveAsBinary(LinkedList* linkedList, char* path);
void saveAsText(LinkedList* linkedList, char* path);
Passenger* findPassengerById(LinkedList* passengerList);
int modifyMenu(Passenger* passenger);
int reportsMenu();
int compareFirstName(void* a, void* b);
int compareLastName(void* a, void* b);

int isFirstClass(void* a);
int isExecutiveClass(void* a);
int isEconomyClass(void* a);
void countByPassType(LinkedList* passengerList);

int hasFlightCode(void* a, char param[]);
void makeflightCodeFile(LinkedList* passengerList);

void initPassengerMiles(LinkedList* passengerList);
void calculateMiles(void* a);