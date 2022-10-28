#ifndef COLLECT_H
#define COLLECT_H

#define SIZE 5 //dynamic arrays
#define STR 80 //strings

typedef struct network {
    int cell;
    char address[STR];
    char essid[STR];
    char mode[STR];
    int channel;
    char encryption_key[STR];
    char quality[STR];
    float frequency;
    int signal_level;
} network;

void wificollector_collect(void);

#endif //COLLECT_H
