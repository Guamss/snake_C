#include "map.h"
#include "const.h"
#include "gui.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int no_apple_in_map = 1;
int score = 0;

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
	if (no_apple_in_map) {
		int is_pos_illegal = 1;
		while (is_pos_illegal) {
			srand(time(NULL)); // generate seed
			int random_x = rand() % GRID_WIDTH;
			int random_y = rand() % GRID_HEIGHT;
			if (map[random_x][random_y] != SNAKE) {
				map[random_x][random_y] = APPLE;
				is_pos_illegal = 0;
				no_apple_in_map = 0;
			}
		}
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

void move_snake(LinkedList** snake, int** map, int where_snake_is_going) {
    POINT last_snake_pos = (*snake)->cell;

    switch(where_snake_is_going) {
        case UP:
            (*snake)->cell.y++;
            break;
        case DOWN:
            (*snake)->cell.y--;
            break;
        case RIGHT:
            (*snake)->cell.x++;
            break;
        case LEFT:
            (*snake)->cell.x--;
            break;
        default:
            (*snake)->cell.x++;
    }

    // collisions
    if ((*snake)->cell.x >= GRID_WIDTH || (*snake)->cell.y >= GRID_HEIGHT ||
        (*snake)->cell.x < 0 || (*snake)->cell.y < 0) {
		show_game_end_screen(score);
    }
    if (map[(*snake)->cell.x][(*snake)->cell.y] == SNAKE) {
		show_game_end_screen(score);
    }

    int ate_apple = (map[(*snake)->cell.x][(*snake)->cell.y] == APPLE);

    map[(*snake)->cell.x][(*snake)->cell.y] = SNAKE;

    LinkedList* current = (*snake)->next;
    POINT temp_pos;
    while (current) {
        temp_pos = current->cell;
        current->cell = last_snake_pos;
        map[last_snake_pos.x][last_snake_pos.y] = SNAKE;
        last_snake_pos = temp_pos;
        current = current->next;
    }

    if (ate_apple) {
        score++;
        no_apple_in_map = 1;
        add_to_linked_list(snake, last_snake_pos);
    } else {
        map[last_snake_pos.x][last_snake_pos.y] = NOTHING;
    }

    update_map(map);
}
