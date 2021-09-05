#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "log.h"
#include "log.c"

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

