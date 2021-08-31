#include <stdlib.h>
#include "log.h"

typedef struct list_struct {
	data_t item;
	struct list_struct* next;
} list_t;

static list_t* headptr = NULL;
static list_t* tailptr = NULL;
