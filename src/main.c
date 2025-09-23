#include "./graphics/graphics.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 1400

int main() {
	init_graphics(WINDOW_WIDTH, WINDOW_HEIGHT);
	wait_escape();
	return 0;
}
