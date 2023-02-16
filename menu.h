#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef void option_action (void*);

typedef struct {
    char* name;         //menu name
    char** optionNames;    //menu options' names 
    option_action * OptionActions;  //array for the function to call for each option when selected
    uint8_t Size;   //number of options in total, will be initialized to 0
    uint8_t currentOption;  //for navigating the menu
} menu_t;

void initializeMenu (char* name);