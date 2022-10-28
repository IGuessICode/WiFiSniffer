#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quit.h"
#include "collect.h"

static int position = 0;

void wificollector_collect(void) {

    char input[STR], file[STR];

    //Assign memory
    network *networks = calloc(SIZE, sizeof(network));

    do {

        char path[STR] = "./cells/";
        int repetitions = 0;

        do {
            printf("What cell do you want to collect? (1 - 21): ");
            fgets(input, STR, stdin);
            if (atoi(input) < 1 || atoi(input) > 21) {
                printf("Please introduce a valid cell number. \n");
            }
            /*for (int i = 0; i < MAX; i++) {
                int stored = 0;
                if (networks[i].cell == (atoi)*input) {
                     stored++;
                }
                if (stored > 0) {
                    printf("This cell has already been collected.");
                    input[0] = '2';
                    input[1] = '2';
                }
            }*/
        } while (atoi(input) < 1 || atoi(input) > 21);

        //Create a string for the path where the file is to be found
        input[strlen(input)-1] = '.';
        strcpy(file, "info_cell_");
        strcat(file, input);
        strcat(file, "txt");

        reset(input);
        strcat(path, file);

        //Determine the number of networks saved in a text file
        FILE *fp = fopen(path, "r");
        if (fp == NULL) {
            printf("Error opening file \n");
        } else {
            char line[STR];
            while (fgets(line, STR, fp)) {
                char *cell = strstr(line, "Cell");
                if (cell != NULL) {
                    repetitions++;
                }
            }
        }
        fclose(fp);

        //Reading and collecting the data
        fopen(path, "r");

        for (int i = 0; i < repetitions; i++) {
            printf("Data read from %s (added to position %d of the array)\n", file, position);

            fscanf(fp, "Cell %i\n", &networks[position].cell);
            printf("%i ", networks[position].cell);

            fscanf(fp, "Address: %s\n", (char *) &networks[position].address);
            printf("%s ", networks[position].address);

            fscanf(fp, "ESSID:%[^\n]\n", (char *) &networks[position].essid);
            printf("%s ", networks[position].essid);

            fscanf(fp, "Mode:%s\n", (char *) &networks[position].mode);
            printf("%s ", networks[position].mode);

            fscanf(fp, "Channel:%i\n", &networks[position].channel);
            printf("%i ", networks[position].channel);

            fscanf(fp, "Encryption key:%s\n", (char *) &networks[position].encryption_key);
            printf("%s ", networks[position].encryption_key);

            fscanf(fp, "Quality=%s\n", (char *) &networks[position].quality);
            printf("%s ", networks[position].quality);

            fscanf(fp, "Frequency:%f GHz\n", &networks[position].frequency);
            printf("%f ", networks[position].frequency);

            fscanf(fp, "Signal level=%i dBm\n", &networks[position].signal_level);
            printf("%i\n\n", networks[position].signal_level);

            position++;

            //Resizing the dynamic array, adding 5 position
            if (position%5 == 0)
                networks = realloc(networks, sizeof(networks) + 5);

        }

        fclose(fp);
        reset(file);
        reset(path);

        do {
            printf("Do you want to add another access point? [y/N]: ");
            reset(quit);
            fgets(quit, STR, stdin);

        } while (quit[0] != 'y' && quit[0] != 'Y' && quit[0] != 'n' && quit[0] != 'N');

    } while (quit[0] != 'n' && quit[0] != 'N');
}
