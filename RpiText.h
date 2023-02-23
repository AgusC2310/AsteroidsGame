#ifndef RPI_TEXT_H
#define RPI_TEXT_H

#include <stdint.h>
#include <stdio.h>

#define TEXT_HEIGHT 5
#define TEXT_WIDTH 4
typedef struct 
{
    uint8_t * textMatrix[TEXT_HEIGHT];
    uint16_t size;
}rpiTextBlock_t;


#endif