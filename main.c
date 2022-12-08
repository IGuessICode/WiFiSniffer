#include <stdio.h>
#include <stdlib.h>
#include "nodelib.h"
#include "quit.h"
#include "collect.h"
#include "select.h"
#include "display.h"

int main() {

    debug("This is a debug message\n");

    char input[STR];
    int option;
    // Initialize list
    Node *head = NULL;

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

            case 2: wificollector_collect(&head); break;

            case 4: print_by_quality(wificollector_select_best(head), head); break;

            case 5: print_by_quality(wificollector_select_worst(head), head); break;

            case 10: wificollector_display(head); break;

            //case 11: wificollector_display_all(networks); break;
	    case 11: print_list(head); break;

            default: break;
        }

    } while (quit[0] != 'y' && quit[0] != 'Y');

    //Free assigned memory
    clear_list(&head);

    return 0;
}
