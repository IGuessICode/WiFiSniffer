// Submission 1 ver.
// Litterbox coding

// LIBRARIES
#include <stdio.h>
#include <stdlib.h> // lib for I/O

// HEADER FILES
#include "functions.h"

// CONSTANTS
#define MAX_LENGTH_ARRAY 200
#define MAX_LENGTH_STR 81 // 80 char + \0

// main
int main() {
	// Menu display
	char option[2];
	
	printf("[2022] SUCEM S.L. Wifi Collector\n\n [ 1]wificollector_quit\n [ 2]wificollector_collect\n [ 3]wificollector_show_data_one_network\n [ 4]wificollector_select_best\n [ 5]wificollector_select_worst\n [ 6]wificollector_delete_net\n [ 7]wificollector_sort\n [ 8]wificollector_export\n [ 9]wificollector_import\n [10]wificollector_display\n [11]wificollector_display_all\n\n");
	do {
		printf("Option: \n");
		scanf("%s", option);
		if (option != "1" && option != "2" && option != "3" && option != "4" && option != "5" && option != "6" && option != "7" && option != "8" && option != "9" && option != "10" && option != "11") {
			printf("Please introduce a valid option.");
		}

	}while (option != "1" && option != "2" && option != "3" && option != "4" && option != "5" && option != "6" && option != "7" && option != "8" && option != "9" && option != "10" && option != "11");

	switch (option) {
		case "1": wificollector_quit; break;
		case "2": wificollector_collect(); break;
		case "10": wificollector_display(); break;
		case "11": wificollector_display_all(); break;
		default: break;
	}
	
	// PROBLEM: Repeat the menu once again after option is executed.

	return 0;
}

// functions -  Do they need to be declared before they are used or smt?
//	void wificollector_quit()
//	void wificollector_collect()
//	void wificollector_display()
//	void wificollector_display_all()
