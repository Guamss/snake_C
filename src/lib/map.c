#include "map.h"
#include <stdlib.h>

int** init_game_map(int width, int height) {
    int** map = malloc(width * sizeof(int*));
    for (int i = 0; i < width; i++) {
        map[i] = malloc(height * sizeof(int));
        for (int j = 0; j < height; j++) {
            map[i][j] = 0;
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

