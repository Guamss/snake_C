#include "gui.h"
#include "../graphics/graphics.h"
#include "./const.h"

void init_grid(int** map) {
    POINT pos1;
    POINT pos2;

    int offset_x = (WINDOW_WIDTH  - (GRID_WIDTH  * CELL_WIDTH))  / 3;
    int offset_y = (WINDOW_HEIGHT - (GRID_HEIGHT * CELL_WIDTH)) / 2;

    for (int i = 0; i < GRID_WIDTH; i++) {
        for (int j = 0; j < GRID_HEIGHT; j++) {
            pos1.x = offset_x + i * CELL_WIDTH;
            pos1.y = offset_y + j * CELL_WIDTH;
            pos2.x = pos1.x + CELL_WIDTH;
            pos2.y = pos1.y + CELL_WIDTH;

            draw_rectangle(pos1, pos2, blanc);
        }
    }
}

