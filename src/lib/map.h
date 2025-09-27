#pragma once
#include "linked_list.h"

int** init_game_map(int width, int height);
void clear_game_map(int** map, int width, int height);
void spawn_apple(int** map);
LinkedList* spawn_snake(int** map);
void move_snake(LinkedList** snake, int** map, int where_snake_is_going);
