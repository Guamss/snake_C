#include <stdio.h>
#include "gui.h"
#include "../graphics/graphics.h"
#include "./const.h"

const int GRID_OFFSET_X = (WINDOW_WIDTH  - (GRID_WIDTH  * CELL_WIDTH))  / 3;
const int GRID_OFFSET_Y = (WINDOW_HEIGHT - (GRID_HEIGHT * CELL_WIDTH)) / 2;

void draw_rectangle_in_grid(int x, int y, int** map, int type) {
	POINT pos1;
    POINT pos2;
    
    pos1.x = (GRID_OFFSET_X + x * CELL_WIDTH) + 1;
    pos1.y = (GRID_OFFSET_Y + y * CELL_WIDTH) + 1;
    pos2.x = pos1.x + CELL_WIDTH - 2;
    pos2.y = pos1.y + CELL_WIDTH - 2;
	
	switch(type) {
		case APPLE:
			draw_fill_rectangle(pos1, pos2, rouge);
			break;
		case SNAKE:
			draw_fill_rectangle(pos1, pos2, vertclair);
			break;
		case NOTHING:
			draw_fill_rectangle(pos1, pos2, noir);
			break;
		default:
			draw_fill_rectangle(pos1, pos2, noir);
	}
}

void init_grid(int** map) {
	
	// dessine la grille
	POINT top_left_point_of_grid;
	POINT bottom_right_point_of_grid;
	top_left_point_of_grid.x = GRID_OFFSET_X;
	top_left_point_of_grid.y = GRID_OFFSET_Y;
	bottom_right_point_of_grid.x = top_left_point_of_grid.x + (CELL_WIDTH * GRID_WIDTH);
	bottom_right_point_of_grid.y = top_left_point_of_grid.y + (CELL_WIDTH * GRID_HEIGHT);
		
	draw_rectangle(top_left_point_of_grid, bottom_right_point_of_grid, blanc);
	
    for (int i = 0; i < GRID_WIDTH; i++) {
        for (int j = 0; j < GRID_HEIGHT; j++) {
            draw_rectangle_in_grid(i, j, map, NOTHING);
        }
    }
}

void show_start_screen() {
	POINT pos = { WINDOW_WIDTH/4, WINDOW_HEIGHT/2 };
	aff_pol("CLIQUEZ pour commencer le jeu", 24, pos, blanc);
	wait_clic();
	fill_screen(noir);
}

void show_game_end_screen(int score) {
	fill_screen(noir);
	POINT pos1 = { WINDOW_WIDTH/3, WINDOW_HEIGHT/2 };
	
	char message[256];
	snprintf(message, sizeof(message), "Votre score est : %i", score); 

	aff_pol(message, 24, pos1, blanc);
	POINT pos2 = { WINDOW_WIDTH/5, pos1.y-50 };
	aff_pol("Cliquez sur ECHAP pour quitter le jeu.", 24, pos2, blanc);
	wait_escape();
	
}

void update_map(int** map) {
    
    for (int i=0; i< GRID_WIDTH; i++) {
		for (int j=0; j < GRID_HEIGHT; j++) {
			draw_rectangle_in_grid(i, j, map, map[i][j]);
		}
	}
}

