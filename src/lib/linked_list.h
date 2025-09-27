#pragma once
#include "../graphics/graphics.h"

typedef struct linked_list {
	POINT cell;
	struct linked_list* next;
} LinkedList;

LinkedList* init_linked_list(POINT initial_value);
void add_to_linked_list(LinkedList** head, POINT new_value);
void clear_linked_list(LinkedList* head);
