#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

enum ASD {CACA, HOLA};
typedef int8_t (*event_listener)(void);
int8_t func1 (void);
char* assignStr(char * str);
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
    char * MyStr= assignStr("Hello");
    printf("%s\n",MyStr);
    printf("\n%d\n", CACA);
    event_listener ev = func1;
    int numRet= ev();
    printf("Return num = %d\n",numRet);
    return 0;
}

char* assignStr(char * str){
    char* ptr = malloc(sizeof(char*));
    ptr = str;
    return ptr;
}

int8_t func1 (void){
    printf("\n Hola Mundo!!!!\n");
    return 100;
}