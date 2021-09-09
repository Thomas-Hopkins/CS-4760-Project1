#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>
#include <errno.h>
#include "log.h"
#include "msggen.h"

void help() {
	printf("Logging utility usage\n");
	printf("\n");
	printf("[logfile]\tSet the filename to output logging messages to.\n");
	printf("[-t sec]\tSet the average time in seconds to output logging messages.\n");
	printf("[-f]\tGenerate a fatal logging message.\n");
	printf("[-h]\tShow this help dialogue.\n");
	printf("\n");
}

void waitavgsec(int sec) {
	int time = 0;
	if (sec != 0) time = rand() % (2*sec);
	sleep(time);
}

int main(int argc, char** argv) {
	int fatal = 0;
	char* exe_name = argv[0];
	int out_sec = 0;
	char* log_file = "messages.log";
	int option;
	// Get flag arguments with getopt
	while ((option = getopt(argc, argv, "hft:")) != -1) {
		switch(option) {
			case 'h':
				help();
				return EXIT_SUCCESS;
			case 't':
				out_sec = atoi(optarg);
				// Throw an error message if non int
				// assume non int if out_sec is zero, there is no strtoi in std C
				// and atoi does not produce error messages
				if (out_sec == 0) {
					errno = EINVAL;
					fprintf(stderr, "%s: ", exe_name);
					perror("Passed invalid integer for time");
					return EXIT_FAILURE;
				}
				break;
			case 'f':
				fatal = 1;
				break;		
			case '?':
				// getopt should handle stderr msgs
				return EXIT_FAILURE;
		}
	}
	// Get additional arguments that did not have a flag (logfile name)
	while (optind < argc) {
		log_file = argv[optind++];
		if (optind < argc) {
			errno = EINVAL;
			fprintf(stderr, "%s: ", exe_name);
			perror("Got more than one logfile passed");
		}
	}
	
	// Generate messages and send them to logging utility.
	// Wait specified time between messages.
	const int MSG_NUM = 5;
	for (int i = 0; i < MSG_NUM; i++) {
		char (*gentypeptr)(void); // function pointer to control what generator
		// Simulate a fatal log message if user passed -f arg
		if ((i + 1 == MSG_NUM) && (fatal > 0)) { 
			gentypeptr = &genfataltype;
		} else {
			gentypeptr = &genrandtype;
		}

		// Generate random message and add it		
		int ret_code = addmsg(gentypeptr(), genrandmsg());
		if (ret_code < 0) {
			fprintf(stderr, "%s: ", exe_name);
			perror("Failed to add log message");
		} 
		// addmsg must have encountered a fatal type message.
		else if (ret_code > 0) {
			savelog(log_file);
			fprintf(stderr, "%s: ", exe_name);
			perror("Fatal error encountered");
			exit(EXIT_FAILURE);
		}
		waitavgsec(out_sec);
	}
	
	// Save the log to file
	if (savelog(log_file) < 0) {
		fprintf(stderr, "%s: ", exe_name);
		perror("Failed to save log file");
	}
	
	// Get log string
	char* logstr;
	if ((logstr = getlog()) == NULL) {
		fprintf(stderr, "%s: ", exe_name);
		perror("Failed to get log messages");
	}
	//TODO: Fix thism from returning junk data
	printf("Log file:\n%s\n", logstr);
	
	clearlog();
	return EXIT_SUCCESS;
}
