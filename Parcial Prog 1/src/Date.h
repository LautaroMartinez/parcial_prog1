#ifndef DATE_H
#define DATE_H

typedef struct MyDate {
    int day;
    int month;
    int year;
} Date;

#endif /* DATE_H */

/// @brief Input de Fecha
///
/// @param warningMsg
/// @return
Date getDate(char warningMsg[]);

/// @brief Devuelve la edad por el anio
///
/// @param date
/// @return
int getAge(Date date);

/// @brief Valida una fecha
///
/// @param date
/// @return
int validateDate(Date date);
