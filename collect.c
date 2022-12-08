#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodelib.h"
#include "quit.h"
#include "collect.h"

static int position = 0;

void wificollector_collect(Node **head_ptr) {
    char input[STR], file[STR];

    do {

        char path[STR] = "./cells/";
        int repetitions = 0;
	// int doubled;

        do {
            printf("What cell do you want to collect? (1 - 21): ");
            fgets(input, STR, stdin);

            if (atoi(input) < 1 || atoi(input) > 21) {
                printf("Please introduce a valid cell number.\n\n");

            } /* else {
                for (int i = 0; i < 21; i++) {
                    doubled = 0;

                    if (networks[i].cell == atoi(input)) {
                        printf("This cell has already been collected.\n\n");
                        doubled = 1;
                        break;
                    }
                }
            } */            //COMENTED AS REQUESTED BY TEACHER

        } while (atoi(input) < 1 || atoi(input) > 21); // (atoi(input) < 1 || atoi(input) > 21 || doubled != 0);


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

	network tmp;

        for (int i = 0; i < repetitions; i++) {
            printf("Data read from %s (added to position %d of the array)\n", file, position);

            fscanf(fp, "Cell %i\n", &tmp.cell);
            printf("%i ", tmp.cell);

            fscanf(fp, "Address: %s\n", tmp.address);
            printf("%s ", tmp.address);

            fscanf(fp, "ESSID:%[^\n]\n", tmp.essid);
            printf("%s ", tmp.essid);

            fscanf(fp, "Mode:%s\n", tmp.mode);
            printf("%s ", tmp.mode);

            fscanf(fp, "Channel:%i\n", &tmp.channel);
            printf("%i ", tmp.channel);

            fscanf(fp, "Encryption key:%s\n", tmp.encryption_key);
            printf("%s ", tmp.encryption_key);

            fscanf(fp, "Quality=%i", &tmp.quality[0]);
            fscanf(fp, "/%i\n", &tmp.quality[1]);
            printf("%i/%i ", tmp.quality[0], tmp.quality[1]);

            fscanf(fp, "Frequency:%f GHz\n", &tmp.frequency);
            printf("%f ", tmp.frequency);

            fscanf(fp, "Signal level=%i dBm\n", &tmp.signal_level);
            printf("%i\n\n", tmp.signal_level);

            position++;

	    // Node creation and linkage
	    Node *new_node = create_node(tmp);
	    append(head_ptr, new_node);

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
