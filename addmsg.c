#include <errno.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "log.h"
#include "log.c"

int addmsg(const char type, const char* msg) {
	// Declare the new item and it's size
	list_t* new_item;
	int item_size;

	// Initialize the item size
	item_size = sizeof(list_t) + strlen(msg) + 1;

	// Attempt to allocate space for the new item
	if ((new_item = (list_t *)(malloc(item_size))) ==  NULL) {
		// Failed to add new item
		return -1;
	}
	
	// Set item's data members
	new_item->item.time = time(NULL);
	new_item->item.type = type;
	new_item->item.string = (char *)new_item + sizeof(list_t);
	
	// Copy the string into the item
	strcpy(new_item->item.string, msg);
	
	// set list ptrs 
	if (headptr == NULL) {
		headptr = new_item;
	} else {
		tailptr->next = new_item;
	}

	tailptr = new_item;
	return 0;
}
