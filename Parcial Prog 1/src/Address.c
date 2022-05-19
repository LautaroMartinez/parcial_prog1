#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Utilities.h"
#include "Address.h"

Address getAddress(char displayMsg[]) {
	Address newAddress;

    printf("%s \n", displayMsg);
    getString(newAddress.street, 21, "Calle: ", "");
    newAddress.number = getNumber(0, 10000, "Altura: ", "");

    return newAddress;
}

int findLocationById(Location locationList[], int locationLen, int locationId) {
    int foundFlag = 0;
    int i = 0;

    while(foundFlag == 0 && i < locationLen){
        if (locationList[i].id == locationId) {
            foundFlag = 1;
        } else {
            foundFlag = 0;
        }
        i++;
    }

    if (foundFlag) {
        i--;
        return i;
    } else {
        return -1;
    }

}
