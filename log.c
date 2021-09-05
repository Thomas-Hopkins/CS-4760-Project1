#include <stdlib.h>
#include "log.h"

typedef struct list_struct {
	data_t item;
	struct list_struct* next;
} list_log;

static list_log* headptr = NULL;
static list_log* tailptr = NULL;
static int listlog_size = 0;
