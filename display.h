#ifndef DISPLAY_H
#define DISPLAY_H

#define MAX 200 //arrays
#define STR 80 //strings

#ifdef DEBUG
#define debug(msg) fprintf(stderr, msg)
#else
#define debug(msg)
#endif

int print(int n);
void wificollector_display(void);
void wificollector_display_all(void);

#endif //DISPLAY_H
