#include <stdio.h>
#include <stdlib.h>
#include "quit.h"
#include "collect.h"
#include "display.h"

extern struct network *networks;

int print(int n) {
    int printed = 0;

    for (int i = 0; i < sizeof(networks); i++) {
        network *pointer = &networks[i];

        if (pointer->cell == n) {
            printf("%i %s %s %s %i %s %s %f %i \n",
                   pointer->cell, pointer->address, pointer->essid,
                   pointer->mode, pointer->channel, pointer->encryption_key,
                   pointer->quality, pointer->frequency, pointer->signal_level);
            printed++;
        }
    }
    return printed;
}


void wificollector_display() {

    char input[STR];
    int n, printed;

    do {

        do {
            printf("Indicate the number of the cell for which you want to know "
                   "its information (1 - 21): ");
            fgets(input, STR, stdin);
            n = atoi(input);
        } while (n < 1 || n > 21);

        printed = print(n);

        if (printed == 0) { //error: information has not been added before
            fprintf( stderr, "%s\n", "The information requested has not been added yet.");
        }

        do {
            printf("Do you want to print the information of another cell? [y/N]: ");
            reset(quit);
            fgets(quit, STR, stdin);

        } while (quit[0] != 'y' && quit[0] != 'Y' && quit[0] != 'n' && quit[0] != 'N');

    } while (quit[0] != 'n' && quit[0] != 'N');

}


void wificollector_display_all() {

    for (int n = 1; n < 22; n++) {
        print(n);
    }

}