#include <stdio.h>
#include <stdlib.h>
#include "quit.h"
#include "collect.h"
#include "select.h"
#include "display.h"

int main() {

    debug("This is a debug message\n");

    char input[STR];
    int option;
    //Assign memory
    network *networks = (network *) malloc(SIZE * sizeof(network));

    do {
        printf("\n[2022] SUCEM S.L. Wifi Collector \n \n");

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
            reset(input);
        } while (option < 1 || option > 11);

        switch (option) {

            case 1: wificollector_quit(); break;

            case 2: wificollector_collect(networks); break;

            case 4: wificollector_select_best(networks); break;

            case 5: wificollector_select_worst(networks); break;

            case 10: wificollector_display(networks); break;

            case 11: wificollector_display_all(networks); break;

            default: break;
        }

    } while (quit[0] != 'y' && quit[0] != 'Y');

    //Free assigned memory
    free(networks);

    return 0;
}
