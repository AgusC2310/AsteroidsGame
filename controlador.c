#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <stdlib.h>

void print_mat (uint8_t mat[16][16]);
void clear_mat (uint8_t mat[16][16]);

int main (void)
{
	uint8_t matriz[16][16];
	clear_mat(matriz);
	print_mat(matriz);
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
