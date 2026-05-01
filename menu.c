#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void display_main_menu(World *currentWorld) {
    system("clear") || system("cls"); // Clear screen (Unix or Windows)
    
    printf("╔════════════════════════════════════════╗\n");
    printf("║   SOLO RPG/LIFE SIM SYSTEM - MAIN MENU   ║\n");
    printf("╚════════════════════════════════════════╝\n\n");
    
    printf("Currently Loaded World: ");
    if (currentWorld->isLoaded) {
        printf("[%s]\n\n", currentWorld->name);
    } else {
        printf("[None - Create or Load a World]\n\n");
    }
    
    printf("1. Live Mode\n");
    printf("2. Edit Mode\n");
    printf("3. Load World\n");
    printf("4. Options\n");
    printf("5. Exit\n\n");
    printf("Select an option (1-5): ");
}

int get_menu_choice(void) {
    int choice;
    if (scanf("%d", &choice) != 1) {
        choice = -1;
        while (getchar() != '\n'); // Clear invalid input buffer
    }
    return choice;
}

void options_menu(void) {
    system("clear") || system("cls");
    
    printf("╔════════════════════════════════════════╗\n");
    printf("║              OPTIONS MENU                ║\n");
    printf("╚════════════════════════════════════════╝\n\n");
    
    printf("1. Graphics Settings\n");
    printf("2. Audio Settings\n");
    printf("3. Gameplay Settings\n");
    printf("4. Back to Main Menu\n\n");
    printf("Select an option (1-4): ");
    
    int choice;
    if (scanf("%d", &choice) != 1) {
        choice = -1;
        while (getchar() != '\n');
    }
    
    switch (choice) {
        case 1:
            printf("\n[Graphics Settings - Not yet implemented]\n");
            break;
        case 2:
            printf("\n[Audio Settings - Not yet implemented]\n");
            break;
        case 3:
            printf("\n[Gameplay Settings - Not yet implemented]\n");
            break;
        case 4:
            return;
        default:
            printf("\nInvalid choice.\n");
    }
    
    printf("\nPress Enter to continue...\n");
    getchar();
    getchar();
}

void live_mode(World *world) {
    system("clear") || system("cls");
    
    printf("╔════════════════════════════════════════╗\n");
    printf("║              LIVE MODE                   ║\n");
    printf("╚════════════════════════════════════════╝\n\n");
    
    if (!world->isLoaded) {
        printf("No world loaded! Please load or create a world first.\n");
    } else {
        printf("World: %s\n", world->name);
        printf("[Live Mode - Simulation Features Coming Soon]\n");
    }
    
    printf("\nPress Enter to return to Main Menu...\n");
    getchar();
    getchar();
}

void edit_mode(World *world) {
    system("clear") || system("cls");
    
    printf("╔════════════════════════════════════════╗\n");
    printf("║              EDIT MODE                   ║\n");
    printf("╚════════════════════════════════════════╝\n\n");
    
    if (!world->isLoaded) {
        printf("No world loaded! Please load or create a world first.\n");
    } else {
        printf("Editing World: %s\n", world->name);
        printf("[Edit Mode - World Editor Features Coming Soon]\n");
    }
    
    printf("\nPress Enter to return to Main Menu...\n");
    getchar();
    getchar();
}

void load_world_menu(World *world) {
    system("clear") || system("cls");
    
    printf("╔════════════════════════════════════════╗\n");
    printf("║            LOAD WORLD MENU               ║\n");
    printf("╚════════════════════════════════════════╝\n\n");
    
    printf("1. Create New World\n");
    printf("2. Load Existing World\n");
    printf("3. Back to Main Menu\n\n");
    printf("Select an option (1-3): ");
    
    int choice;
    if (scanf("%d", &choice) != 1) {
        choice = -1;
        while (getchar() != '\n');
    }
    
    switch (choice) {
        case 1: {
            printf("\nEnter new world name: ");
            getchar(); // Consume newline
            fgets(world->name, WORLD_NAME_LENGTH, stdin);
            
            // Remove trailing newline
            int len = strlen(world->name);
            if (len > 0 && world->name[len - 1] == '\n') {
                world->name[len - 1] = '\0';
            }
            
            world->isLoaded = 1;
            printf("World '%s' created successfully!\n", world->name);
            break;
        }
        case 2: {
            printf("\nEnter world filename to load: ");
            char filename[WORLD_NAME_LENGTH];
            getchar(); // Consume newline
            fgets(filename, WORLD_NAME_LENGTH, stdin);
            
            // Remove trailing newline
            int len = strlen(filename);
            if (len > 0 && filename[len - 1] == '\n') {
                filename[len - 1] = '\0';
            }
            
            load_world(world, filename);
            printf("World loaded: %s\n", world->name);
            break;
        }
        case 3:
            return;
        default:
            printf("\nInvalid choice.\n");
    }
    
    printf("\nPress Enter to continue...\n");
    getchar();
    getchar();
}
