#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "log.h"

void help() {
	printf("Logging utility usage\n");
	printf("\n");
	printf("[logfile]\tSet the filename to output logging messages to.\n");
	printf("[-t sec]\tSet the average time in seconds to output logging messages.\n");
	printf("[-h]\tShow this help dialogue.\n");
	printf("\n");
}

int main(int argc, char** argv) {
	char* exe_name = argv[0];
	int out_sec = 0;
	char* log_file = NULL;
	int option;
	// Get flag arguments with getopt
	while ((option = getopt(argc, argv, "ht:")) != -1) {
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
					fprintf(stderr, "%s: Error: %s is not a valid integer.", exe_name, optarg);
					return EXIT_FAILURE;
				}
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
			fprintf(stderr, "%s: Error: Got more than one logfile name (%s) passed.\n", exe_name, argv[optind]);
		}
	}

	// Temp print out TODO: logging functionality
	printf("out_sec: %d\n", out_sec);
	if (log_file != NULL) printf("log_file: %s\n", log_file);
	
	char* file;
	int addresult, saveresult;

	addresult = addmsg('a', "hello world");
	file = getlog();
	saveresult = savelog("filename");
	clearlog();
	printf("%d, %s, %d", addresult, file, saveresult);
	
	return EXIT_SUCCESS;
}
