#include <stdlib.h>
#include "log.h"

#define MSGS_NUM 10

int message_range = 5;
char* messages[] = {
	"Could not open file!",
	"Incorrect input!",
	"DISK FULL",
	"System timeout.",
	"Generic error message"
	};

char genrandtype() {
	int ind = rand() % msgtypes_size;
	return msg_types[ind];
}

char genfataltype() {
	int ind = rand() % fataltypes_size;
	return fatal_types[ind];
}

char* genrandmsg() {
	int ind = rand() % message_range;
	return messages[ind];
}
