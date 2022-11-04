#include <stdio.h>
#include <stdlib.h>
#include "quit.h"

char quit[STR];

void reset (char string[STR]) {
    for (int i = 0; i < STR; ++i)
        string[i] = 0;
}

void wificollector_quit(void) {

    do {
        printf("Are you sure you want to quit? [y/N]: ");
        reset(quit);
        fgets(quit, STR, stdin);

        if (quit[0] == 'y' || quit[0] == 'Y') {
            printf("Goodbye!");
            exit(0);
        } else if (quit[0] == 'n' || quit[0] == 'N') {
            printf("Here we go again! \n");
            break;
        }
    } while (quit[0] != 'y' && quit[0] != 'Y' && quit[0] != 'n' && quit[0] != 'N');

}
