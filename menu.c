#include "menu.h"
#include "defs.h"

static event_listener GetUserInput=NULL;
static bool menuState=true;         //Boolean value to know when to close the menu during the execution of runMenu 
static option_action UpdateDisplay;

menu_t* initializeMenu (char* Name){
    menu_t* menu = malloc(sizeof(menu_t));
    if(menu==NULL){
        fprintf(stderr, "ERROR ALLOCATING MEMORY IN MENU!\n");
    }
    menu->name = Name;
    menu->Size=0;
    menu->currentOption=0;
    return menu;
}
void addOption(menu_t *menu, option_action callback, char * OptionName){
    menu->optionNames[menu->Size]=OptionName;
    menu->OptionActions[menu->Size]=callback;
    menu->Size++;
}

void addEventListener (event_listener ev){
    GetUserInput = ev;
}

void closeMenu(void){
    menuState =false;
}

void runMenu (menu_t* menu){
    int8_t move = GetUserInput();
    if((GetUserInput!= NULL) &&(menu != NULL))
    {
        menuState = true;
        while(menuState){
            switch (move)
            {
            case UP:
                if(menu->currentOption == 0){
                    menu->currentOption = menu->Size -1;
                }
                else{
                    menu->currentOption++;
                }
                break;

            case DOWN:
            if(menu->currentOption == (menu->Size -1))
                menu->currentOption = 0;
            else
                menu->currentOption--;
                break;
            
            case BUTTON:
                menu->OptionActions[menu->currentOption]();

                break;
            default:
                break;
            }
        if(UpdateDisplay!=NULL)
            UpdateDisplay();
        
        }
    }
}
