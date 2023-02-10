#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <stdlib.h>
#include "controlador.h"
#include "modelo.h"

static const uint8_t normalShip[SHIPSIZE][SHIPSIZE]= {{0,1,0},{1,1,1},{0,0,0}};
static const uint8_t diagonalShip[SHIPSIZE][SHIPSIZE]= {{0,1,1},{0,0,1},{0,0,0}};
static const uint8_t XSAsteroid[XSMALL][XSMALL]={{1,1},{1,1}};
static const uint8_t SAsteroid[SMALL][SMALL]={{1,1,1},{1,0,1},{1,1,1}};
static const uint8_t MAsteroid[MEDIUM][MEDIUM]={{0,0,1,0},{1,1,0,1},{1,0,0,1},{0,1,1,0}};
static const uint8_t LAsteroid[LARGE][LARGE]={{0,1,1,0,0},{1,0,0,1,0},{1,0,0,1,0},{1,1,1,0,1},{0,0,1,1,0}};
static const uint8_t XLAsteroid[XLARGE][XLARGE]={{0,1,1,0,0},{1,0,0,1,0},{1,0,0,1,0},{1,1,1,0,1},{0,0,1,1,0}};

static uint8_t updateTime_ms;
int main (void)
{
	uint8_t matrix[16][16];
	ship_t ship;
	initializeShip(&ship);
	ship.posx=4;
	ship.posy= 4;
	
	clear_mat(matrix);
	introduceShip(&ship, matrix);
	//print_mat(matrix);
	printShip(ship.shape);
	
	for(int i=0; i<4; i++){
	rotateMatClockwise(ship.shape);
	printShip(ship.shape);
	}
	//clear_mat(matrix);
	//(&ship, matrix);
	//print_mat(matrix);
	
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

void clearShip (uint8_t mat[SHIPSIZE][SHIPSIZE]){
	int i,j;
	for(i=0; i<SHIPSIZE; i++){
		for(j=0; j<SHIPSIZE; j++){
			mat[i][j]=0;
		}
	}
}

void printShip (uint8_t mat[SHIPSIZE][SHIPSIZE]){
	int i,j;
	printf("\n");
	for(i=0; i<SHIPSIZE; i++){
		for(j=0; j<SHIPSIZE; j++){
			printf("%d",mat[i][j]);
		}
		printf("\n");
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
			sh->shape[i][j]= diagonalShip[i][j];
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

void rotateMatAntiClockwise (uint8_t mat[][SHIPSIZE]){
	transposeMat(mat);	//first transpose matrix
	int j;
	uint8_t auxValue;
	for(j=0; j<SHIPSIZE; j++){
		auxValue = mat[0][j];
		mat[0][j] = mat[SHIPSIZE-1][j];
		mat[SHIPSIZE-1][j]= auxValue;
	}

}

void rotateMatClockwise (uint8_t mat[][SHIPSIZE]){
	transposeMat(mat);	//first transpose matrix
	int j;
	uint8_t auxValue;
	for(j=0; j<SHIPSIZE; j++){
		auxValue = mat[j][0];
		mat[j][0] = mat[j][SHIPSIZE-1];
		mat[j][SHIPSIZE-1]= auxValue;
	}

}

void transposeMat ( uint8_t mat[][SHIPSIZE]){
	int i,j;
	uint8_t auxValue;
	for(i=0; i<SHIPSIZE; i++)
	{
		for(j=i; j<SHIPSIZE; j++)
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

int allocateAsteroidShape(asteroid_t* asteroid)
{
	int i,j;
	bool status= true;
    asteroid->shape = malloc(asteroid->size*sizeof(uint8_t *));
	if(asteroid->shape== NULL)
	{
		fprintf(stderr, "Error allocating Asteroid memory!");
		free(asteroid->shape);
		status = false;
	}
	if(status)
	{
		for(i=0; i<5; i++)
		{
			asteroid->shape[i]=malloc(asteroid->size*sizeof(uint8_t));
			if(asteroid->shape[i]==NULL)
			{
				for(;i>=0;i--)
				{
					free(asteroid->shape[i]);
				}
				free(asteroid->shape);
				status= false;
			}
		}
	}
	if(status)
	{
		for(i=0;i<asteroid->size;i++)
		{
			for(j=0;j<asteroid->size;j++)
			{
				asteroid->shape[i][j]=asteroid->size;
			}
		}
	}
	
	return status -1;	//0 if true, -1 if false.
}

void freeAsteroidShape(asteroid_t* asteroid)
{
	int i;
	for(i=0;i<asteroid->size;i++)
		{
			free(asteroid->shape[i]);
		}
	free(asteroid->shape);
}

void insertAsteroid(uint8_t size){
	asteroid_t * newAster = (asteroid_t *)malloc(sizeof(asteroid_t));

	if(AsterListHeaderNode == NULL){

	}
}

void updateAsteroids (void){

}

void initializeAsteroid(uint8_t size, asteroid_t* asteroid){
	asteroid->acelx=0;
	asteroid->acely=0;
	asteroid->direction= rand()%9;	//random direction for the enum (0 to 8)
	asteroid->nextAster= NULL;
	asteroid->prevAster= NULL;
	if(rand()%2)		//random decision on which of the four sides of the screen the asteroid spawns
	{
	asteroid->posx=rand()%17000;	//
	
	}
}
