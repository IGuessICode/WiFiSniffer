#include <stdio.h>
#include <stdlib.h>
#include "display.h"
#include "collect.h"
#include "functions.h"

extern struct network networks[MAX];

void wificollector_display() {

    char input[STR], quit[STR];
    int n, printed;

    do {

        do {
            printf("Indicate the number of the cell for which you want to know "
                   "its information (1 - 21): ");
            fgets(input, STR, stdin);
            n = atoi(input);
        } while (n < 1 || n > 21);

        //print(networks, n);
        printed = 0;
        for (int i = 0; i < MAX; i++) {
            if (networks[i].cell == n) {
                printf("%i %s %s %s %i %s %s %f %i \n",
                       networks[i].cell, networks[i].address, networks[i].essid,
                       networks[i].mode, networks[i].channel, networks[i].encryption_key,
                       networks[i].quality, networks[i].frequency, networks[i].signal_level);
                printed++;
            }
        }

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

        //print(networks, n);
        for (int i = 0; i < MAX; i++) {
            if (networks[i].cell == n) {
                printf("%i %s %s %s %i %s %s %f %i \n",
                       networks[i].cell, networks[i].address, networks[i].essid,
                       networks[i].mode, networks[i].channel, networks[i].encryption_key,
                       networks[i].quality, networks[i].frequency, networks[i].signal_level);
            }
        }

    }

}

/*
void print(struct network networks[MAX], int n) {

    for (int i = 0; i < MAX; i++) {
        if (networks[i].cell == n) {
            printf("%i %s %s %s %i %s %s %f %i \n",
                   networks[i].cell, networks[i].address, networks[i].essid,
                   networks[i].mode, networks[i].channel, networks[i].encryption_key,
                   networks[i].quality, networks[i].frequency, networks[i].signal_level);
        }
    }
}*/