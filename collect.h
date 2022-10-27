#ifndef COLLECT_H
#define COLLECT_H

#define SIZE 5 //dynamic arrays
#define STR 80 //strings

struct network {
    int cell;
    char address[STR];
    char essid[STR];
    char mode[STR];
    int channel;
    char encryption_key[STR];
    char quality[STR];
    float frequency;
    int signal_level;
};

void wificollector_collect(struct network *networks);

#endif //COLLECT_H
