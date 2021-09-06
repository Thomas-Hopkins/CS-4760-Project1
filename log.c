#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "log.h"

list_log* headptr = NULL;
list_log* tailptr = NULL;
int listlog_size = 0;

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
	new_item->item.string = (char *)new_item + sizeof(list_log);
	
	// Copy the string into the item
	strcpy(new_item->item.string, msg);
	
	// set list ptrs 
	if (headptr == NULL) {
		headptr = new_item;
	} else {
		tailptr->next = new_item;
	}

	tailptr = new_item;
	listlog_size++;
	return 0;
}

char* getlog() {
	// TODO: allocate enough space for a string containing all log messages and return it return NULL upon failure
	char* log = (char*)malloc(sizeof(char*) * listlog_size);
	if (log == NULL) return NULL; // Could not allocate memory
	list_log* listlog_item = tailptr;
	data_t curritem;
	
	for (int i = 0; i < listlog_size; i++) {
		curritem = listlog_item->item;
		strncat(log, curritem.string, sizeof(char*) * listlog_size);
		listlog_item = listlog_item->next;
	}

	return log;
}

int savelog(char* filename) {
	// TODO: save logged messages to specified file
	FILE* file_log = fopen(filename, "w");
	list_log* curr = tailptr;
	time_t tm;
	struct tm* tp;

	while (curr != NULL) {
		tp = localtime(& curr->item.time);
		fprintf(file_log, "%.2d:%.2d:%.2d :: %c :: %s", tp->tm_hour, tp->tm_min, tp->tm_sec, curr->item.type, curr->item.string); 
		curr = curr->next;
	}
	fclose(file_log);
	
	return 0;
}

void clearlog() {
	// TODO: release all storage for the list
	while (listlog_size != 0) {
		list_log* tmp = tailptr;
		tailptr = tailptr->next;
		free(tmp);
		tmp = NULL;
		listlog_size--;
	}
}

