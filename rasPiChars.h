
#ifndef _RPI_CHARS_H_
#define _RPI_CHARS_H_

#include <stdint.h>

typedef uint8_t rpi_char_t[5]; // 5 byte array


// hecho a manopla con https://maxpromer.github.io/LCD-Character-Creator/
//credits to  Rafael Dalzotto https://github.com/Rafdal. Gracias Rafa de dio mucha fiaca hacer las letras de 0 ;) 


static const rpi_char_t UNKNOWN_ = {
    0x1F,
    0x1F,
    0x1F,
    0x1F,
    0x1F
};

static const rpi_char_t unknown_ = {
    0x1C,
    0x1C,
    0x1C,
    0x1C,
    0x1C
};

// 5 x 3

static const rpi_char_t ascii_0_z[] = {
    {
        0x08,
        0x14,
        0x14,
        0x14,
        0x08
    }, // 0
    {
        0x08,
        0x18,
        0x08,
        0x08,
        0x1C
    }, // 1
    {
        0x1C,
        0x14,
        0x04,
        0x08,
        0x1C
    }, // 2
    {
        0x18,
        0x04,
        0x08,
        0x04,
        0x18
    }, // 3
    {
        0x14,
        0x14,
        0x1C,
        0x04,
        0x04
    }, // 4
    {
        0x1C,
        0x10,
        0x1C,
        0x04,
        0x1C
    }, // 5
    {
        0x1C,
        0x10,
        0x1C,
        0x14,
        0x1C
    }, // 6
    {
        0x1C,
        0x04,
        0x04,
        0x04,
        0x04
    }, // 7
    {
        0x1C,
        0x14,
        0x1C,
        0x14,
        0x1C
    }, // 8
    {
        0x1C,
        0x14,
        0x1C,
        0x04,
        0x04
    }, // 9
    {
        0x00,
        0x08,
        0x00, 
        0x08,
        0x00

    }, // :
    {
        0x00,
        0x08,
        0x00,
        0x08,
        0x08
    }, // ;
    {
        0x04,
        0x08,
        0x10,
        0x08,
        0x04
    }, // <
    {
        0x00,
        0x1C,
        0x00, 
        0x1C,
        0x00 
    }, // =
    {
        0x10,
        0x08,
        0x04,
        0x08,
        0x10
    }, // >
    {
        0x1C,
        0x14,
        0x04,
        0x08,
        0x08
    }, // ?
    {
        0x1C,
        0x1C,
        0x14,
        0x1C,
        0x18
    }, // @
    {
        0x08,
        0x14,
        0x1C,
        0x14,
        0x14
    }, // A
    {
        0x18,
        0x14,
        0x18,
        0x14,
        0x18
    }, // B
    {
        0x0C,
        0x10,
        0x10,
        0x10,
        0x0C
    }, // C
    {
        0x18,
        0x14,
        0x14,
        0x14,
        0x18
    }, // D
    {
        0x1C,
        0x10,
        0x1C,
        0x10,
        0x1C
    }, // E
    {
        0x1C,
        0x10,
        0x1C,
        0x10,
        0x10
    }, // F
    {
        0x0C,
        0x10,
        0x14,
        0x14,
        0x0C
    }, // G
    {
        0x14,
        0x14,
        0x1C,
        0x14,
        0x14
    }, // H
    {
        0x1C,
        0x08,
        0x08,
        0x08,
        0x1C
    }, // I
    {
        0x04,
        0x04,
        0x04,
        0x14,
        0x1C
    }, // J
    {
        0x14,
        0x14,
        0x18,
        0x14,
        0x14
    }, // K
    {
        0x10,
        0x10,
        0x10,
        0x10,
        0x1C
    }, // L
    {
        0x14,
        0x1C,
        0x14,
        0x14,
        0x14
    }, // M
    {
        0x18,
        0x14,
        0x14,
        0x14,
        0x14
    }, // N
    {
        0x1C,
        0x14,
        0x14,
        0x14,
        0x1C
    }, // O
    {
        0x1C,
        0x14,
        0x1C,
        0x10,
        0x10
    }, // P
    {
        0x1C,
        0x14,
        0x14,
        0x1C,
        0x04
    }, // Q
    {
        0x1C,
        0x14,
        0x18,
        0x14,
        0x14
    }, // R
    {
        0x0C,
        0x10,
        0x08,
        0x04,
        0x18
    }, // S
    {
        0x1C,
        0x08,
        0x08,
        0x08,
        0x08
    }, // T
    {
        0x14,
        0x14,
        0x14,
        0x14,
        0x1C
    }, // U

    {
        0x14,
        0x14,
        0x14,
        0x08,
        0x08
    }, // V
    {
        0x00,
        0x14,
        0x1C,
        0x1C,
        0x14
    }, // W
    {
        0x14,
        0x14,
        0x08,
        0x14,
        0x14
    }, // X
    {
        0x14,
        0x14,
        0x08,
        0x08,
        0x08
    }, // Y
    {
        0x1C,
        0x04,
        0x08,
        0x10,
        0x1C
    }, // Z
};

#endif