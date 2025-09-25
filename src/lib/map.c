#include "map.h"
#include "const.h"
#include "gui.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int** init_game_map(int width, int height) {
    int** map = malloc(width * sizeof(int*));
    for (int i = 0; i < width; i++) {
        map[i] = malloc(height * sizeof(int));
        for (int j = 0; j < height; j++) {
            map[i][j] = NOTHING;
        }
    }
    return map;
}

void clear_game_map(int** map, int width, int height) {
	for (int i=0; i<width; i++) {
		free(map[i]);
	}
	free(map);
}

void spawn_apple(int** map) {
	srand(time(NULL)); // generate seed
	
	int random_x = rand() % GRID_WIDTH;
	int random_y = rand() % GRID_HEIGHT;
	map[random_x][random_y] = APPLE;
	
	update_map(map);
}
