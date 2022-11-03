#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quit.h"
#include "collect.h"

static int position = 0;

void wificollector_collect(struct network **networks) {

    char input[STR], file[STR];

    do {

        char path[STR] = "./cells/";
        int repetitions = 0;
        int doubled;

        do {
            printf("What cell do you want to collect? (1 - 21): ");
            fgets(input, STR, stdin);

            if (atoi(input) < 1 || atoi(input) > 21) {
                printf("Please introduce a valid cell number.\n\n");

            } else {
                for (int i = 0; i < 21; i++) {
                    doubled = 0;

                    if (networks[i]->cell == atoi(input)) {
                        printf("This cell has already been collected.\n\n");
                        doubled = 1;
                        break;
                    }
                }
            }

        } while (atoi(input) < 1 || atoi(input) > 21 || doubled != 0);


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
            printf("Error opening file \n\n");
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

            fscanf(fp, "Cell %i\n", &networks[position]->cell);
            printf("%i ", networks[position]->cell);

            fscanf(fp, "Address: %s\n", networks[position]->address);
            printf("%s ", networks[position]->address);

            fscanf(fp, "ESSID:%[^\n]\n", networks[position]->essid);
            printf("%s ", networks[position]->essid);

            fscanf(fp, "Mode:%s\n", networks[position]->mode);
            printf("%s ", networks[position]->mode);

            fscanf(fp, "Channel:%i\n", &networks[position]->channel);
            printf("%i ", networks[position]->channel);

            fscanf(fp, "Encryption key:%s\n", networks[position]->encryption_key);
            printf("%s ", networks[position]->encryption_key);

            fscanf(fp, "Quality=%i", &networks[position]->quality[0]);
            fscanf(fp, "/%i\n", &networks[position]->quality[1]);
            printf("%i/%i ", networks[position]->quality[0], networks[position]->quality[1]);

            fscanf(fp, "Frequency:%f GHz\n", &networks[position]->frequency);
            printf("%f ", networks[position]->frequency);

            fscanf(fp, "Signal level=%i dBm\n", &networks[position]->signal_level);
            printf("%i\n\n", networks[position]->signal_level);

            position++;

            //Resizing the dynamic array, adding 5 position
            if (position % SIZE == 0) {
                int times_resized = position / SIZE;
                printf("(Allocating another %d positions to the dynamic array)\n", SIZE);
                networks = realloc(networks, sizeof(network) * SIZE * (times_resized + 1 ));
            }

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

int size_of_networks() {
    return position;
}