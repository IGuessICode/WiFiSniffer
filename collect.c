#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "quit.h"
#include "collect.h"

struct network networks[MAX];
static int position = 0;

//creating all the file pointers
/*void create_file_pointers(){
    for (int i = 0; i < 21; i++) {
        char path[] = "./cells/info_cell_";
        strcat(path, i);
        strcat(path, ".txt");
        FILE *fpi = fopen(path, "r");
    }
}*/

void wificollector_collect(void) {

    char input[STR], file[STR];

    do {

        char path[STR] = "./cells/";
        int repetitions = 0;

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

        fopen(path, "r");

        for (int i = 0; i < repetitions; i++) {
            printf("Network read from %s (added to position %d of the array)\n", file, position);

            fscanf(fp, "Cell %i\n", &networks[position].cell);
            printf("%i\n", networks[position].cell);

            fscanf(fp, "Address: %s\n", (char *) &networks[position].address);
            printf("%s\n", networks[position].address);

            fscanf(fp, "ESSID:%s\n", (char *) &networks[position].essid);
            printf("%s\n", networks[position].essid);

            fscanf(fp, "Mode:%s\n", (char *) &networks[position].mode);
            printf("%s\n", networks[position].mode);

            fscanf(fp, "Channel:%i\n", &networks[position].channel);
            printf("%i\n", networks[position].channel);

            fscanf(fp, "Encryption key:%s\n", (char *) &networks[position].encryption_key);
            printf("%s\n", networks[position].encryption_key);

            fscanf(fp, "Quality=%s\n", (char *) &networks[position].quality);
            printf("%s\n", networks[position].quality);

            fscanf(fp, "Frequency:%f\n", &networks[position].frequency);
            printf("%f\n", networks[position].frequency);

            fscanf(fp, "Signal level=%i dBm\n", &networks[position].signal_level);
            printf("%i\n", networks[position].signal_level);

            position++;
        }

        fclose(fp);
        reset(file);
        reset(path);
        //chdir(".."); //Changing the current working directory to the previous directory

        do {
            printf("Do you want to add another access point? [y/N]: ");
            reset(quit);
            fgets(quit, STR, stdin);

        } while (quit[0] != 'y' && quit[0] != 'Y' && quit[0] != 'n' && quit[0] != 'N');

    } while (quit[0] != 'n' && quit[0] != 'N');
}