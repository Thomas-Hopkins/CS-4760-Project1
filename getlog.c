#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "log.h"
#include "log.c"

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
