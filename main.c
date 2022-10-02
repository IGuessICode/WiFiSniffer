// Submission 1 ver.
// Litterbox coding

// LIBRARIES
#include <stdio.h>
#include <stdlib.h> // lib for I/O

// HEADER FILES
#include "headers.h"

// CONSTANTS
#define MAX_LENGTH_INPUT 2
#define MAX_LENGTH_ARRAY 200
#define MAX_LENGTH_STR 81 // 80 char + \0

// main
int main() {

    char input[MAX_LENGTH_INPUT];
    int option;

    do {
        printf("\n [2022] SUCEM S.L. Wifi Collector \n \n");

        printf("[ 1] wificollector_quit \n");
        printf("[ 2] wificollector_collect \n");
        printf("[ 3] wificollector_show_data_one_network \n");
        printf("[ 4] wificollector_select_best \n");
        printf("[ 5] wificollector_select_worst \n");
        printf("[ 6] wificollector_delete_net \n");
        printf("[ 7] wificollector_sort \n");
        printf("[ 8] wificollector_export \n");
        printf("[ 9] wificollector_import \n");
        printf("[10] wificollector_display \n");
        printf("[11] wificollector_display_all \n \n");

        do {
			printf("Option: ");
			fgets(input, STR, stdin);
			option = atoi(input);
			if (option < 1 || option > 11) {
				printf("Please introduce a valid option.");
			}
	    } while (option < 1 || option > 11);
        reset(input);

        switch (option) {

            case 1: wificollector_quit(); break;
            case 2: //wificollector_collect(); break;
            case 10: //wificollector_display(); break;
            case 11: //wificollector_display_all(); break;
            default:
                break;
        }

    } while (quit[0] != 'y' && quit[0] != 'Y');

    return 0;
}
