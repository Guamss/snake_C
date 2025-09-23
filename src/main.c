#include "./graphics/graphics.h"
#include "./lib/linked_list.h"
#include "./lib/map.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 1400

int main() {
	POINT test;
	test.x = 0;
	test.y = 0;
	LinkedList *lc = init_linked_list(test);
	add_to_linked_list(&lc, test);
	
	init_graphics(WINDOW_WIDTH, WINDOW_HEIGHT);
	wait_escape();
	return 0;
}
