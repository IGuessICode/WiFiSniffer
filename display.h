#ifndef DISPLAY_H
#define DISPLAY_H

#define MAX 200 //arrays
#define STR 80 //strings

#ifdef DEBUG
#define debug(msg) fprintf(stderr, msg)
#else
#define debug(msg)
#endif

int print(int n, struct network *networks);
void wificollector_display(struct network *networks);
void wificollector_display_all(struct network *networks);

#endif //DISPLAY_H
