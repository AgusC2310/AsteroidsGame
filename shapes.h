#ifndef SHAPES_H
#define SHAPES_H
#define SHIPSIZE 3
#include <stdint.h>

typedef struct {
    uint8_t size;
    uint8_t shape[SHIPSIZE][SHIPSIZE];
    uint16_t posx;
    uint16_t posy;
    uint16_t velx;
    uint16_t vely;
    
} ship_t;




#endif
