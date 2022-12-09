#ifndef NETWORK_H
#define NETWORK_H

#define SIZE 5 //dynamic arrays
#define STR 80 //strings

typedef struct network {
    int cell;
    char address[STR];
    char essid[STR];
    char mode[STR];
    int channel;
    char encryption_key[STR];
    int quality[2];
    float frequency;
    int signal_level;
} network;

#endif //NETWORK_H
