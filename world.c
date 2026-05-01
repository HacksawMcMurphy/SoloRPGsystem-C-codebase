#include <stdio.h>
#include <string.h>
#include "world.h"

void load_world(World *world, const char *filename) {
    FILE *file = fopen(filename, "r");
    
    if (file != NULL) {
        fgets(world->name, WORLD_NAME_LENGTH, file);
        
        // Remove trailing newline
        int len = strlen(world->name);
        if (len > 0 && world->name[len - 1] == '\n') {
            world->name[len - 1] = '\0';
        }
        
        world->isLoaded = 1;
        fclose(file);
    } else {
        printf("Error: Could not open file '%s'\n", filename);
        strcpy(world->name, "Error: File Not Found");
        world->isLoaded = 0;
    }
}

void save_world(World *world, const char *filename) {
    FILE *file = fopen(filename, "w");
    
    if (file != NULL) {
        fprintf(file, "%s\n", world->name);
        fclose(file);
        printf("World saved to '%s'\n", filename);
    } else {
        printf("Error: Could not save to file '%s'\n", filename);
    }
}
