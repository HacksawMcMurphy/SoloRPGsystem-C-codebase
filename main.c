#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "world.h"

int main(void) {
    World currentWorld = {0};
    
    // Initialize with a default world name
    strcpy(currentWorld.name, "Untitled World");
    currentWorld.isLoaded = 0;
    
    int running = 1;
    
    printf("=== Welcome to Solo RPG/Life Sim System ===\n\n");
    
    while (running) {
        display_main_menu(&currentWorld);
        int choice = get_menu_choice();
        
        switch (choice) {
            case 1:
                live_mode(&currentWorld);
                break;
            case 2:
                edit_mode(&currentWorld);
                break;
            case 3:
                load_world_menu(&currentWorld);
                break;
            case 4:
                options_menu();
                break;
            case 5:
                running = 0;
                printf("Thank you for playing! Goodbye.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                getchar();
        }
    }
    
    return 0;
}
