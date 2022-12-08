#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodelib.h"
#include "quit.h"
#include "collect.h"
#include "display.h"
#include "select.h"

float numerator, denominator, quality;

void print_by_quality(float n, Node *head) {

    while (head != NULL) {
		numerator = (float) head->data.quality[0];
		denominator = (float) head->data.quality[1];
        	quality = numerator / denominator;

        	if (quality == n) {
            		print(head->data);
        	}

		head = head->next;

    }

}


float wificollector_select_best(Node *head) {
    float best = 0;

    if (head == NULL) {
    	printf("ERROR: List is empty.\n");
    }
    else {
	do {
		numerator = (float) head->data.quality[0];
		denominator = (float) head->data.quality[1];
        	quality = numerator / denominator;

        	if (quality > best) {
            		best = quality;
        	}

		head = head->next;

    	} while (head != NULL);
    }

    printf("The best quality is %f, which corresponds to the following network(s): \n", best);
    return best;
}


float wificollector_select_worst(Node *head) {
    float worst = 1;

    if (head == NULL) {
    	printf("ERROR: List is empty.\n");
    }
    else {
	do {
		numerator = (float) head->data.quality[0];
		denominator = (float) head->data.quality[1];
        	quality = numerator / denominator;

        	if (quality < worst) {
            		worst = quality;
        	}

		head = head->next;

    	} while (head != NULL);
    }

    printf("The worst quality is %f, which corresponds to the following network(s): \n", worst);
    return worst;
}
