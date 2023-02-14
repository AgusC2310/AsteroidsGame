#include <stdio.h>
#include <stdint.h>
#include "shapes.h"
#include "model.h"

void printAsteroid (asteroid_t* asteroid){
    int i,j;
    for(i=0;i<asteroid->size; i++)
    {
        for(j=0;j<asteroid->size;j++)
        {
            if(asteroid->shape[i][j])
            {
            Public_Game_Matrix[i+asteroid->posx][j+asteroid->posy]= asteroid->shape[i][j];
            }
        }
    }
    
}