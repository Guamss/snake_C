#include "../graphics/graphics.h"
#include "linked_list.h"

LinkedList* init_linked_list(POINT initial_value) {
	LinkedList* lc = malloc(sizeof(LinkedList));
	lc->cell = initial_value;
	lc->next = NULL;
	
	return lc;
}

void add_to_linked_list(LinkedList** head, POINT new_value) {
    LinkedList* new_node = malloc(sizeof(LinkedList));
    new_node->cell = new_value;
    new_node->next = *head;
    *head = new_node;
}


void clear_linked_list(LinkedList* head) {
    LinkedList* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}
