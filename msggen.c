#include <stdlib.h>

#define MSGS_NUM 10

int type_range = 4;
int message_range = 5;
char type_map[] = {'I', 'W', 'E', 'F'};
char* messages[] = {
	"Could not open file!",
	"Incorrect input!",
	"DISK FULL",
	"System timeout.",
	"Generic error message"
	};

char genrandtype() {
	int ind = rand() % type_range;
	return type_map[ind];
}

char* genrandmsg() {
	int ind = rand() % message_range;
	return messages[ind];
}
