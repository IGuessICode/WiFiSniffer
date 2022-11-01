#include <stdio.h>
#include <stdlib.h>
#include "quit.h"
#include "collect.h"
#include "display.h"
#include "select.h"

//extern struct network *networks;

void wificollector_select_best(struct network *networks) {
    int best = 0;

    printf("The best quality is 1.000000, which corresponds to the following network(s):");
}


void wificollector_select_worst(struct network *networks) {
    int worst = 1;
    printf("The worst quality is 0.528571, which corresponds to the following network(s):");

}
