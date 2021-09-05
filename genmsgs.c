#include <stdlib.h>
#include <stdio.h>

#define MSGS_NUM 10

int main() {
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
	// Generates the messages.txt for input for the driver
	FILE* out_fileptr = fopen("messages.txt", "w");
	if (out_fileptr == NULL) {
		printf("File couldn't be opened.\n");
		return EXIT_FAILURE;
	}
	
	int msg_type, msg_num;
	for (int i = 0; i < MSGS_NUM; i++) {
		msg_type = rand() % type_range;
		msg_num = rand() % 
		fprintf(out_fileptr, "%c %s\n", type_map[msg_type], messages[msg_type]);
	}
	fclose(out_fileptr);
		 
	return EXIT_SUCCESS;
}
