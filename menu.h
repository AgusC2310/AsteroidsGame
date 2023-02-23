#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef void (*option_action) (void);
typedef int8_t (*event_listener)(void);

typedef struct {
    char* name;         //menu name
    char** optionNames;    //menu options' names 
    option_action * OptionActions;  //array for the function to call for each option when selected
    uint8_t Size;   //number of options in total, will be initialized to 0
    uint8_t currentOption;  //for navigating the menu, from 0 to Size-1
} menu_t;

menu_t* initializeMenu (char* Name);

void addOption(menu_t *menu, option_action callback, char * OptionName);

void runMenu (menu_t* menu);

void addEventListener (event_listener ev);

void closeMenu(void);

#endif