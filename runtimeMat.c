#include <stdio.h>
#include <stdlib.h>

int main (void){
     int i;
    for(i=0; i<5; i++){
        printf("%d\n",i);
        if(i==3)
        {
            for(;i>=0;i--)
            {
            printf("Liberando %d\n",i);
            
            }
            break;
        }
    }   
    printf("fuera del for\n");
    // int ** myMat = malloc(5*sizeof(int *));
    // for(i=0; i<5; i++){
    //     myMat[i]=malloc(5*sizeof(int));
    // }
    // for(i=0;i<5;i++){
    //     for(j=0;j<5;j++){
    //         myMat[i][j]=5;
    //         printf("%d",myMat[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    return 0;
}