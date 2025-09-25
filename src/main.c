#include "./graphics/graphics.h"
#include "./lib/linked_list.h"
#include "./lib/map.h"
#include "./lib/const.h"
#include "./lib/gui.h"

int main() {
	init_graphics(WINDOW_WIDTH, WINDOW_HEIGHT);
	int** map = init_game_map(GRID_WIDTH, GRID_HEIGHT);
	init_grid(map);
	
	spawn_apple(map);
	wait_escape();
	return 0;
}
