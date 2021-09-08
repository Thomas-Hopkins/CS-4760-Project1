#ifndef LOG_H
#define LOG_H
#include <time.h>

typedef struct data_struct {
	time_t time; // Time stamp
	char type; // Message type (I/W/E/F)
	char* string; // Message string
} data_t;

typedef struct list_struct {
	data_t item;
	struct list_struct* next;
} list_log;

extern list_log* headptr;
extern list_log* tailptr;
extern int listlog_size;

int addmsg(const char type, const char* msg);
void clearlog();
char* getlog();
int savelog(char* filename);

#endif
