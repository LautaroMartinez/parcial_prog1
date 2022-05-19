#ifndef UTILITIES_H
#define UTILITIES_H

#endif /* UTILITIES_H */

/// @brief Input de Numero
///
/// @param min
/// @param max
/// @param displayMsg
/// @param warningMsg
/// @return
int getNumber(int min, int max, char displayMsg[], char warningMsg[]);

/// @brief Input de Float
///
/// @param min
/// @param max
/// @param displayMsg
/// @param warningMsg
/// @return
float getFloat(int min, int max, char displayMsg[], char warningMsg[]);

/// @brief Input de String
///
/// @param string
/// @param max
/// @param displayMsg
/// @param warningMsg
void getString(char string[], int max, char displayMsg[], char warningMsg[]);

/// @brief Input de Y/N
///
/// @param displayMsg
/// @param warningMsg
/// @return
int yesOrNo(char displayMsg[], char warningMsg[]);

/// @brief Funcion Auxiliar para mensaje de error
///
/// @param warning_str
/// @param value
/// @param text
void getWarningMsg(char warning_str[], int value, char text[]);

/// @brief Busca un Char en un String
///
/// @param found
/// @param stringArray
void findCharArray(char *found, char stringArray[]);

/// @brief Verifica que un string tenga solo letras
///
/// @param found
/// @param stringArray
void checkIsAllLetters(char *found, char stringArray[]);

/// @brief Verifica que un string tenga solo numeros
///
/// @param found
/// @param stringArray
void checkIsAllNumber(char *found, char stringArray[]);

/// @brief Verifica que un string tenga solo numeros con coma
///
/// @param found
/// @param stringArray
void checkIsNumbersWithDot(char *found, char stringArray[]);

/// @brief Agrega un Numero a un String
///
/// @param base_str
/// @param num
void addNumToString(char base_str[], int num);

/// @brief Agrega un Char a un String
///
/// @param base_str
/// @param ch
void addCharToString(char base_str[], char *ch);
