#include "map.h"
#include "const.h"
#include "gui.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int no_apple_in_map = 1;
int score = 0;
POINT last_snake_pos = {0, 0);

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
	
	// TODO : parcourir la lst pour supprimer les cases où se situe le 
	// serpent de la grille sur une copie de celle-ci et faire le tirage du fruit
	
	if (no_apple_in_map) {	
		srand(time(NULL)); // generate seed
		int random_x = rand() % GRID_WIDTH;
		int random_y = rand() % GRID_HEIGHT;
		map[random_x][random_y] = APPLE;
		no_apple_in_map = 0;
		update_map(map);
	}
}

LinkedList* spawn_snake(int** map) {
	map[0][GRID_HEIGHT - 1] = SNAKE;
	POINT snake_initial_pos;
	snake_initial_pos.x = 0;
	snake_initial_pos.y = GRID_HEIGHT - 1;
	
	update_map(map);
	
	return init_linked_list(snake_initial_pos);
}

void update_snake(LinkedList* snake) {
	
}

void move_snake(LinkedList* snake, int** map, int where_snake_is_going) {
	map[snake->cell.x][snake->cell.y] = NOTHING;	
	last_snake_pos.x = snake->cell.x;
	last_snake_pos.y = snake->cell.y;
	
	switch(where_snake_is_going) {
		case UP:
			snake->cell.y++;
			break;
		case DOWN:
			snake->cell.y--;
			break;
		case RIGHT:
			snake->cell.x++;
			break;
		case LEFT:
			snake->cell.x--;
			break;
		default:
			snake->cell.x++;
	}
	if (snake->cell.x >= GRID_WIDTH || snake->cell.y >= GRID_HEIGHT || snake->cell.x < 0 || snake->cell.y < 0) {
		printf("tu as perdu !\n");
		exit(0);
	}
	if (map[snake->cell.x][snake->cell.y] == SNAKE) {
		printf("tu as perdu !\n");
		exit(0);
	}
	if (map[snake->cell.x][snake->cell.y] == APPLE) {
		score++;
		no_apple_in_map = 1;
		// augmenter la taille du bestio
		add_to_linked_list(snake, last_snake_pos);
		update_snake(snake);
	}
	map[snake->cell.x][snake->cell.y] = SNAKE;
	update_map(map);
	
}
