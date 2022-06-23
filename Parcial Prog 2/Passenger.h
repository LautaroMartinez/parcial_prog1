#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct {
	int id;
   char name[21];
   char last_name[21];
  float price;
   char flight_code[7];
    int passenger_type;
    int flight_status;
} Passenger;

#endif /* PASSENGER_H_ */

Passenger* passenger_init_new();
void passenger_delete();

void set_id(Passenger* this, int id);
void set_name(Passenger* this, char* name);
void set_last_name(Passenger* this, char* last_name);
void set_price(Passenger* this, float price);
void set_flight_code(Passenger* this, char* flight_code);
void set_passenger_type(Passenger* this, int passenger_type);
void set_flight_status(Passenger* this, int flight_status);

int   get_id(Passenger* this);
char* get_name(Passenger* this);
char* get_last_name(Passenger* this);
float get_price(Passenger* this);
char* get_flight_code(Passenger* this);
char* get_passenger_type(Passenger* this);
char* get_flight_status(Passenger* this);
