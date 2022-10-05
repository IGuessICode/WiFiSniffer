#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "collect.h"
#include "wificollector.h"

void wificollector_collect(void) {

    char input[STR], file[STR], quit[STR];
    char path[STR] = "./cells/";
    static int position = 0;
    struct network networks[MAX];

    int cell;
    char address[STR];
    char essid[STR];
    char mode[STR];
    int channel;
    char encryption_key[STR];
    char quality[STR];
    float frequency;
    int signal_level;

    do {

        do {
            printf("What cell do you want to collect? (1 - 21): ");
            fgets(input, STR, stdin);
	    if (atoi(input) < 1 || atoi(input) > 21) {
		printf("Please introduce a valid cell number.");
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
	    fscanf(fp, "Cell %i\n", &networks[position].cell, cell);
	    fscanf(fp, "Address: %s\n", &networks[position].address, address);
	    fscanf(fp, "ESSID:\"%s\"\n", &networks[position].essid, essid);
	    fscanf(fp, "Mode:%s\n", &networks[position].mode, mode);
	    fscanf(fp, "Channel:%i\n", &networks[position].channel, channel);
	    fscanf(fp, "Encryption key:%s\n", &networks[position].encryption_key, encryption_key);
	    fscanf(fp, "Quality=%s\n", &networks[position].quality, quality);
	    fscanf(fp, "Frequency:%f GHz\n", &networks[position].frequency, frequency);
	    fscanf(fp, "Signal level=%i dBm\n", &networks[position].signal_level, signal_level);

            printf("%i %s %s %s %i %s %s %f %i",
                   cell, address, essid, mode, channel, encryption_key, quality, frequency, signal_level);
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
