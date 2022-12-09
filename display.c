#include <stdio.h>
#include <stdlib.h>
#include "nodelib.h"
#include "quit.h"
#include "collect.h"
#include "display.h"

void print(struct network networks) {
	printf("%i %s %s %s %i %s %i/%i %f %i \n",
	networks.cell, networks.address, networks.essid,
	networks.mode, networks.channel, networks.encryption_key,
	networks.quality[0], networks.quality[1], networks.frequency, networks.signal_level);
}

void wificollector_display(Node *head) {
    char input[STR];
    int n, printed;

    do {

        do {
            printf("Indicate the number of the cell for which you want to know "
                   "its information (1 - 21): ");
            fgets(input, STR, stdin);
            n = atoi(input);
        } while (n < 1 || n > 21);

        printed = print_node(n, head);

        if (printed == 0) { //error: information has not been added before
            fprintf( stderr, "%s\n", "The information requested has not been added yet.");
        }

        do {
            printf("\nDo you want to print the information of another cell? [y/N]: ");
            reset(quit);
            fgets(quit, STR, stdin);

        } while (quit[0] != 'y' && quit[0] != 'Y' && quit[0] != 'n' && quit[0] != 'N');

    } while (quit[0] != 'n' && quit[0] != 'N');
}

void wificollector_display_all(Node *head) {
	for (int n = 1; n < 22; n++) {
		print_node(n, head);
	}
}
