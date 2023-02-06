#ifndef SHAPES_H
#define SHAPES_H
#define SHIPSIZE 6
#include <stdint.h>

 
typedef struct {
    uint8_t shape[SHIPSIZE][SHIPSIZE];
    uint16_t posx; //x position of the top left element of the matrix
    uint16_t posy;//y position of the top left element of the matrix
    uint16_t velx; //x velocity of the top left element of the matrix
    uint16_t vely;  //y velocity of the top left element of the matrix
    
} ship_t;




#endif
