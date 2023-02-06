#ifndef SHAPES_H
#define SHAPES_H


#define SHIPSIZE 3
#define ASTERSIZE
#include <stdint.h>

enum SHIP_DIRECTIONS {NORTH, NORTH_EAST, EAST, SOUTH_EAST, SOUTH, SOUTH_WEST, WEST, NORTH_WEST};
 
typedef struct {
    uint8_t shape[SHIPSIZE][SHIPSIZE];
    uint16_t posx; //x position of the top left element of the matrix
    uint16_t posy;//y position of the top left element of the matrix
    uint16_t velx; //x velocity of the top left element of the matrix
    uint16_t vely;  //y velocity of the top left element of the matrix
    uint16_t acelx; //x aceleration of the top left element of the matrix
    uint16_t acely; //y aceleration of the top left element of the matrix
    uint8_t direction;
    
} ship_t;

typedef struct {
    uint8_t shape[SHIPSIZE][SHIPSIZE];
    uint16_t posx; //x position of the top left element of the matrix
    uint16_t posy;//y position of the top left element of the matrix
    uint16_t velx; //x velocity of the top left element of the matrix
    uint16_t vely;  //y velocity of the top left element of the matrix
    uint16_t acelx; //x aceleration of the top left element of the matrix
    uint16_t acely; //y aceleration of the top left element of the matrix
    uint8_t direction;
    
} asteroid_t;



#endif
