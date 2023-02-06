#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <stdlib.h>
#include "shapes.h"

/************************************************************PROTOTYPES******************************************************************************/
void print_mat (uint8_t mat[16][16]);
void clear_mat (uint8_t mat[16][16]);
void initializeShip (ship_t * sh);
void copyCustomShip (ship_t * sh);
void introduceShip (ship_t *sh, uint8_t mat[16][16]);
void rotateMatClockwise (uint8_t mat[][SHIPSIZE]);
void transposeMat (uint8_t mat[][SHIPSIZE]);
/*****************************************************************************************************************************************************/
uint8_t normalShip[SHIPSIZE][SHIPSIZE]= {{0,1,0},{1,1,1},{0,0,0}};
uint8_t diagonalShip[SHIPSIZE][SHIPSIZE]= {{1,0,1},{0,1,0},{0,0,1}};

int main (void)
{
	uint8_t matrix[16][16];
	ship_t ship;
	initializeShip(&ship);
	ship.posx=4;
	ship.posy= 4;
	
	clear_mat(matrix);
	introduceShip(&ship, matrix);
	print_mat(matrix);
	return 0;

}

void clear_mat (uint8_t mat[][16])
{
	int i,j;
	for(i=0; i<16; i++)
	{
		for(j=0; j<16; j++)
		{
			mat[i][j]=0;
		}
	}
}

void print_mat (uint8_t mat[16][16])
{
	int i,j;
	for(i=0; i<16; i++)
	{
		for(j=0; j<16; j++)
		{
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void initializeShip (ship_t * sh){
	sh->posx = 0;
	sh->posy = 0;
	copyCustomShip(sh);
	sh->velx =0;
	sh->vely = 0;
}

void copyCustomShip (ship_t * sh){
	for(int i=0; i<SHIPSIZE; i++)
	{
		for(int j=0; j<SHIPSIZE; j++)
		{
			sh->shape[i][j]= normalShip[i][j];
		}
	}
}

void introduceShip (ship_t *sh, uint8_t mat[16][16]){
	for(int i=0; i<SHIPSIZE; i++){
		for(int j=0; j< SHIPSIZE; j++){
			mat[i+sh->posx][j+sh->posy]= sh->shape[i][j];
		}
	}
}

void rotateMatClockwise (uint8_t mat[][SHIPSIZE]){

}

void transposeMat ( uint8_t mat[][SHIPSIZE]){
	int i,j;
	uint8_t auxValue;
	for(i=0; i<SHIPSIZE; i++)
	{
		for(j=0; j<SHIPSIZE; j++)
		{
			if(i!=j)
			{
				auxValue= mat[i][j];
				mat[i][j]=mat[j][i];
				mat[j][i]=auxValue;
			}
		}
	}

}