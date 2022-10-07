#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "collect.h"
#include "functions.h"

struct network networks[MAX];

void wificollector_collect(void) {

    char input[STR], file[STR], quit[STR];
    char path[STR] = "./cells/";
    static int position = 0;


    do {

        do {
            printf("What cell do you want to collect? (1 - 21): ");
            fgets(input, STR, stdin);
            if (atoi(input) < 1 || atoi(input) > 21) {
                printf("Please introduce a valid cell number. \n");
            }
        } while (atoi(input) < 1 || atoi(input) > 21);

        input[strlen(input)-1] = '.';
        strcpy(file, "info_cell_");
        strcat(file, input);
        strcat(file, "txt");

        reset(input);

        printf("Network read from %s (added to position %d of the array)\n", file, position);
        strcat(path, file);

        FILE *fp = fopen(path, "r");
        if (fp == NULL) {
            printf("Error opening file \n");
        } else {

                fscanf(fp, "Cell %i\n", &networks[position].cell);
                printf("%i\n", networks[position].cell);

                fscanf(fp, "Address: %s\n", &networks[position].address);
                printf("%s\n", networks[position].address);

                fscanf(fp, "ESSID:%s\n", &networks[position].essid);
                printf("%s\n", networks[position].essid);

                fscanf(fp, "Mode:%s\n", &networks[position].mode);
                printf("%s\n", networks[position].mode);

                fscanf(fp, "Channel:%i\n", &networks[position].channel);
                printf("%i\n", networks[position].channel);

                fscanf(fp, "Encryption key:%s\n", &networks[position].encryption_key);
                printf("%s\n", networks[position].encryption_key);

                fscanf(fp, "Quality=%s\n", &networks[position].quality);
                printf("%s\n", networks[position].quality);

                fscanf(fp, "Frequency:%f\n", &networks[position].frequency);
                printf("%f\n", networks[position].frequency);

                fscanf(fp, "Signal level=-%i\n", &networks[position].signal_level);
                printf("-%i\n", networks[position].signal_level);

                position++;

        }
        fclose(fp);

        reset(path);

        do {
            printf("Do you want to add another access point? [y/N]: ");
            reset(quit);
            fgets(quit, STR, stdin);

        } while (quit[0] != 'y' && quit[0] != 'Y' && quit[0] != 'n' && quit[0] != 'N');

    } while (quit[0] != 'n' && quit[0] != 'N');
}
