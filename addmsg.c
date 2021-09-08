#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "log.h"

int addmsg(const char type, const char* msg) {
	// Declare the new item and it's size
	list_log* new_item;
	int item_size;

	// Initialize the item size
	item_size = sizeof(list_log) + strlen(msg) + 1;

	// Attempt to allocate space for the new item
	if ((new_item = (list_log *)(malloc(item_size))) ==  NULL) {
		// Failed to add new item
		return -1;
	}
	
	// Set item's data members
	new_item->item.time = time(NULL);
	new_item->item.type = type;
	new_item->item.string = (char *)malloc(strlen(msg) + 1);
	
	// Copy the string into the item
	strcpy(new_item->item.string, msg);
	
	// set list ptrs 
	if (headptr == NULL) {
		// First element, set the headptr and point it to tailptr
		headptr = new_item;
		headptr->next = tailptr;
	} else {
		// append this item to back of list
		tailptr->next = new_item;
	}
	// Advance tailptr to end of the list
	tailptr = new_item;
	listlog_size++;
	return 0;
}

