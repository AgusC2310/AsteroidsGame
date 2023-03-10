#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <stdint.h>
#include "shapes.h"

/************************************************************PROTOTYPES******************************************************************************/
void print_mat (uint8_t mat[16][16]);
void clearGameMatrix (uint8_t mat[16][16]);
void initializeShip (ship_t * sh);
void copyCustomShip (ship_t * sh);
void introduceShip (ship_t *sh, uint8_t mat[16][16]);
void rotateMatClockwise (uint8_t mat[][SHIPSIZE]);
void transposeMat (uint8_t mat[][SHIPSIZE]);
void clearShip (uint8_t mat[SHIPSIZE][SHIPSIZE]);
void printShip (uint8_t mat[SHIPSIZE][SHIPSIZE]);
int allocateAsteroidShape(asteroid_t* asteroid);
void freeAsteroidShape(asteroid_t* asteroid);
void insertAsteroid(uint8_t size);
void initializeAsteroid(uint8_t size, asteroid_t* asteroid);
void updateAsteroids (void);
void freeAsteroid(asteroid_t* asteroid);
void freeAsteroidList(void);
void printAsteroid(asteroid_t * asteroid);
void copyAsteroidShape (uint8_t size, asteroid_t* asteroid);
/*****************************************************************************************************************************************************/

#define BASICGRAVITY 90

#endif