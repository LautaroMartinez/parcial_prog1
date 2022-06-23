#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

void parsePassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);
void parsePassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);
