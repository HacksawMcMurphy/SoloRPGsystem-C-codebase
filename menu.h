#ifndef MENU_H
#define MENU_H

#include "world.h"

void display_main_menu(World *currentWorld);
int get_menu_choice(void);
void options_menu(void);
void live_mode(World *world);
void edit_mode(World *world);
void load_world_menu(World *world);

#endif
