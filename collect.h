#ifndef COLLECT_H
#define COLLECT_H

#define MAX 200 //arrays
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

//void create_file_pointers(void);

void wificollector_collect(void);

#endif //COLLECT_H
