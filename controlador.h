#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <stdint.h>
#include "shapes.h"

/************************************************************PROTOTYPES******************************************************************************/
void print_mat (uint8_t mat[16][16]);
void clear_mat (uint8_t mat[16][16]);
void initializeShip (ship_t * sh);
void copyCustomShip (ship_t * sh);
void introduceShip (ship_t *sh, uint8_t mat[16][16]);
void rotateMatClockwise (uint8_t mat[][SHIPSIZE]);
void transposeMat (uint8_t mat[][SHIPSIZE]);
void clearShip (uint8_t mat[SHIPSIZE][SHIPSIZE]);
void printShip (uint8_t mat[SHIPSIZE][SHIPSIZE]);
int allocateAsteroidShape(asteroid_t* asteroid);
void freeAsteroid(asteroid_t* asteroid);
/*****************************************************************************************************************************************************/


#endif