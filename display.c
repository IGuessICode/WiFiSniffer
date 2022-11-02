#include <stdio.h>
#include <stdlib.h>
#include "quit.h"
#include "collect.h"
#include "display.h"

int print(int n, struct network *networks) {
    int printed = 0;

    for (int i = 0; i < size_of_networks(); i++) {

        if (networks[i].cell == n) {
            printf("%i %s %s %s %i %s %i4/%i %f %i \n",
                   networks[i].cell, networks[i].address, networks[i].essid,
                   networks[i].mode, networks[i].channel, networks[i].encryption_key,
                   networks[i].quality[0], networks[i].quality[1], networks[i].frequency, networks[i].signal_level);
            printed++;
        }
    }
    return printed;
}


void wificollector_display(struct network *networks) {

    char input[STR];
    int n, printed;

    do {

        do {
            printf("Indicate the number of the cell for which you want to know "
                   "its information (1 - 21): ");
            fgets(input, STR, stdin);
            n = atoi(input);
        } while (n < 1 || n > 21);

        printed = print(n, networks);

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


void wificollector_display_all(struct network *networks) {

    for (int n = 1; n < 22; n++) {
        print(n, networks);
        //int printed = print(n, networks);

        /*
        if (printed == 0) { //error: information has not been added before
            fprintf(stderr, "%s\n", "No information has been added yet.");
            break;
        }
        */
    }

}