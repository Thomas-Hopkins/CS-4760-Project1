#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "log.h"

const char msg_types[] = {'I', 'W', 'E'};
const char fatal_types[] = {'F'};
const int fataltypes_size = 1;
const int msgtypes_size = 3;

list_log* headptr = NULL;
list_log* tailptr = NULL;
int listlog_size = 0;

