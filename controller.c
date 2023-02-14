#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <stdlib.h>
#include "controller.h"
#include "model.h"

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
	
	clearGameMatrix(matrix);
	introduceShip(&ship, matrix);
	//print_mat(matrix);
	printShip(ship.shape);
	
	for(int i=0; i<4; i++){
	rotateMatClockwise(ship.shape);
	printShip(ship.shape);
	}

	insertAsteroid(3);
	insertAsteroid(5);

	
	//clear_mat(matrix);
	//(&ship, matrix);
	//print_mat(matrix);
	
	return 0;

}

void clearGameMatrix (uint8_t mat[][16])
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

void printGameMatrix (uint8_t mat[16][16])
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
				break;
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
	initializeAsteroid(size, newAster);
	if(AsterList.firstAsteroid == NULL){
		AsterList.firstAsteroid = newAster;
		AsterList.size=1;
	}
	else{
		asteroid_t * currentAsteroid= AsterList.firstAsteroid;
		while(currentAsteroid->nextAster != NULL){
			currentAsteroid = currentAsteroid->nextAster;
		}
		currentAsteroid->nextAster= newAster;
		newAster->prevAster = currentAsteroid;
	}
}

void freeAsteroid(asteroid_t* asteroid){
	if(asteroid == NULL){
		fprintf(stderr, "NULL pointer when destroying asteroid object");
	}
	else{
	freeAsteroidShape(asteroid);
	free(asteroid);
	}
}


void updateAsteroids (void){

}

void initializeAsteroid(uint8_t size, asteroid_t* asteroid){
	bool flag;
	asteroid->acelx=0;
	asteroid->acely=0;
	asteroid->direction= rand()%9;	//random direction for the enum (0 to 8)
	asteroid->nextAster= NULL;
	asteroid->prevAster= NULL;
	asteroid->size = size;
	asteroid->velx=0;
	asteroid->vely=0;
	flag = allocateAsteroidShape(asteroid);
	if(!flag){	//only if dynamic memory is successfully allocated
		copyAsteroidShape( size, asteroid);
	}
	//position random initialization
	if(rand()%2)		//random decision on which of the four sides of the screen the asteroid spawns
	{
		asteroid->posx=rand()%17000;	//anywhere on the x-axis
		if(rand()%2){
			asteroid->posy= 0;			//on the top of the display 
		}
		else{
			asteroid->posy= 17000;			//on the bottom of the display 			
		}
	}

	else
	{
		asteroid->posy=rand()%17000;	//anywhere on the y-axis
			if(rand()%2){
				asteroid->posx= 0;			//on the left side of the display 
			}
			else{
				asteroid->posx= 17000;			//on the right side of the display 			
			}
	}

}

void copyAsteroidShape (uint8_t size, asteroid_t* asteroid)
{
	int i,j;
	switch (size)
	{
	case 2:
		for(i=0;i<size;i++){
			for(j=0;j<size; j++){
				asteroid->shape[i][j]=XSAsteroid[i][j];
			}
		}
		break;

	case 3:
		for(i=0;i<size;i++){
			for(j=0;j<size; j++){
				asteroid->shape[i][j]=SAsteroid[i][j];
			}
		}
		break;

	case 4:
		for(i=0;i<size;i++){
			for(j=0;j<size; j++){
				asteroid->shape[i][j]=MAsteroid[i][j];
			}
		}
		break;

	case 5:
		for(i=0;i<size;i++){
			for(j=0;j<size; j++){
				asteroid->shape[i][j]=LAsteroid[i][j];
			}
		}
		break;

	case 6:
		for(i=0;i<size;i++){
			for(j=0;j<size; j++){
				asteroid->shape[i][j]=XLAsteroid[i][j];
			}
		}
		break;
	
	default:
		printf("Size does not match with a legal value");
		break;
	}
}