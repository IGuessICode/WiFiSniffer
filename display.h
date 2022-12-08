#ifndef DISPLAY_H
#define DISPLAY_H

#define STR 80 //strings

#ifdef DEBUG
#define debug(msg) fprintf(stderr, msg)
#else
#define debug(msg)
#endif

void print(struct network networks);
void wificollector_display(Node *head);
void wificollector_display_all(Node *head);

#endif //DISPLAY_H
