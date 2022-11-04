#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quit.h"
#include "collect.h"
#include "display.h"
#include "select.h"

float numerator, denominator, quality;

void print2(float n, struct network *networks) {

    for (int i = 0; i < size_of_networks(); i++) {

        numerator = (float) networks[i].quality[0];
        denominator = (float) networks[i].quality[1];
        quality = numerator / denominator;

        if (quality == n) {
            printf("%i %s %s %s %i %s %i/%i %f %i \n",
                   networks[i].cell, networks[i].address, networks[i].essid,
                   networks[i].mode, networks[i].channel, networks[i].encryption_key,
                   networks[i].quality[0], networks[i].quality[1], networks[i].frequency, networks[i].signal_level);
        }
    }
}


void wificollector_select_best(struct network *networks) {
    float best = 0;

    for (int i = 0; i < size_of_networks(); i++) {

        numerator = (float) networks[i].quality[0];
        denominator = (float) networks[i].quality[1];
        quality = numerator / denominator;

        //printf("%i/%i=%f\n", networks[i].quality[0], networks[i].quality[1], quality);

        if (quality > best) {
            best = quality;
        }
    }

    printf("The best quality is %f, which corresponds to the following network(s): \n", best);
    print2(best, networks);
}


void wificollector_select_worst(struct network *networks) {
    float worst = 1;

    for (int i = 0; i < size_of_networks(); i++) {

        numerator = (float) networks[i].quality[0];
        denominator = (float) networks[i].quality[1];
        quality = numerator / denominator;

        //printf("%i/%i=%f\n", networks[i].quality[0], networks[i].quality[1], quality);

        if (quality < worst) {
            worst = quality;
        }
    }

    printf("The worst quality is %f, which corresponds to the following network(s): \n", worst);
    print2(worst, networks);
}