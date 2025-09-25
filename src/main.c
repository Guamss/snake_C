#include "./graphics/graphics.h"
#include "./lib/linked_list.h"
#include "./lib/map.h"
#include "./lib/const.h"
#include "./lib/gui.h"
#include <unistd.h>
#include <pthread.h>

int finished = 0;
int going = RIGHT;

void* key_event_loop(void* arg) {
	while (!finished) {
		POINT arrow = get_arrow();
		if (arrow.x < 0 && going != RIGHT) {
			// LEFT
			going = LEFT;
		} else if (arrow.x > 0 && going != LEFT) {
			// DROITE
			going = RIGHT;
		} else if (arrow.y < 0 && going != UP) {
			// BAS
			going = DOWN;
		} else if (arrow.y > 0 && going != DOWN) {
			// HAUT
			going = UP;
		}
	}
	return NULL;
}

int main() {
	init_graphics(WINDOW_WIDTH, WINDOW_HEIGHT);
	int** map = init_game_map(GRID_WIDTH, GRID_HEIGHT);
	init_grid(map);
	LinkedList* snake = spawn_snake(map);
	
	pthread_t key_event_thread;
	pthread_create(&key_event_thread, NULL, key_event_loop, NULL);
	
	while (!finished) {
		spawn_apple(map);
		usleep(250000); // O.25s
		move_snake(snake, map, going);
	}
	
	
	wait_escape();
	clear_game_map(map, GRID_WIDTH, GRID_HEIGHT);
	return 0;
}
