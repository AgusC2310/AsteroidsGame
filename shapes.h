#ifndef SHAPES_H
#define SHAPES_H


#define SHIPSIZE 3
#include <stdint.h>
#include <stdbool.h>

enum ASTEROID_SIZES{XSMALL=2,SMALL, MEDIUM, LARGE, XLARGE};


enum SHIP_DIRECTIONS {NORTH, NORTH_EAST, EAST, SOUTH_EAST, SOUTH, SOUTH_WEST, WEST, NORTH_WEST};
 
typedef struct {
    uint8_t shape[SHIPSIZE][SHIPSIZE];
    int16_t posx; //x position of the top left element of the matrix
    int16_t posy;//y position of the top left element of the matrix
    int16_t velx; //x velocity of the top left element of the matrix
    int16_t vely;  //y velocity of the top left element of the matrix
    int16_t acelx; //x aceleration of the top left element of the matrix
    int16_t acely; //y aceleration of the top left element of the matrix
    uint8_t direction;  
} ship_t;

typedef struct asteroid_t {
    uint8_t** shape;
    uint8_t size;
    int16_t posx; //x position of the top left element of the matrix
    int16_t posy;//y position of the top left element of the matrix
    int16_t velx; //x velocity of the top left element of the matrix
    int16_t vely;  //y velocity of the top left element of the matrix
    int16_t acelx; //x aceleration of the top left element of the matrix
    int16_t acely; //y aceleration of the top left element of the matrix
    uint8_t direction;
    struct asteroid_t * nextAster;
    struct asteroid_t * prevAster;
} asteroid_t;

typedef struct{
    asteroid_t * firstAsteroid;
    uint16_t size;
}   asteroidList_t;

#endif
