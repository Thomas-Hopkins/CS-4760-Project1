#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "log.h"

char* getlog() {
	// TODO: Fix returned memory not being valid
	long unsigned int memsize = 0;
	list_log* listlog_item = headptr;
	data_t curritem;
	
	// Calculate needed memory space by adding all string item sizes
	for (int i = 0; i < listlog_size; i++) {	
		curritem = listlog_item->item;
		printf("char size:%ld, stringlen:%ld, shouldbe:%ld\n", sizeof(char), strlen(curritem.string), sizeof(char) * strlen(curritem.string));
		memsize += sizeof(char) * strlen(curritem.string);
		listlog_item = listlog_item->next;
	}

	// Try to allocate the memory
	char* log = (char*)malloc(memsize);
	if (log == NULL) return NULL; // Could not allocate memory

	// Reset item to head and append all log messages for return 
	listlog_item = headptr;
	for (int i = 0; i < listlog_size; i++) {
		strncat(log, curritem.string, sizeof(char) * strlen(curritem.string));
		listlog_item = listlog_item->next;
	}

	return log;
}

