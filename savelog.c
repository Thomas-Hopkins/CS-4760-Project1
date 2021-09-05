#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "log.h"
#include "log.c"

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
