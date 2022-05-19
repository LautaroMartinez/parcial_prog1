#ifndef ADDRESS_H
#define ADDRESS_H

typedef struct MyAddress {
    char street[21];
    int number;
} Address;

typedef struct MyLocation {
    int id;
    char name[21];
} Location;

#endif /* ADDRESS_H */

/// @brief Input para Address
///
/// @param displayMsg
/// @return
Address getAddress(char displayMsg[]);

/// @brief Busca Location por Id
///
/// @param locationList
/// @param locationLen
/// @param locationId
/// @return
int findLocationById(Location locationList[], int locationLen, int locationId);
