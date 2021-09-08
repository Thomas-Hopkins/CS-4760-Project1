#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "log.h"

int savelog(char* filename) {
	// Open file for append and setup time and pointer to list log
	FILE* file_log = fopen(filename, "a");
	list_log* curr = headptr;
	time_t tm;
	struct tm* tp;

	// Iterate over the log list until we reach the ending nullptr
	while (curr != NULL) {
		// get time in proper format and print formatted string to file
		tp = localtime(& curr->item.time);
		fprintf(file_log, "%.2d:%.2d:%.2d :: %c :: %s\n", tp->tm_hour, tp->tm_min, tp->tm_sec, curr->item.type, curr->item.string); 
		curr = curr->next;
	}
	fclose(file_log);
	
	return 0;
}

