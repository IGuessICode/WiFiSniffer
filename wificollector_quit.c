#include <stdio.h>
#include <stdlib.h>
#include "wificollector_quit.h"

void wificollector_quit() {
  // implement input in main.c and here use it as argument??
  do {
    printf("Are you sure you want to exit? [y/N]:\n");
    char input = tolower(getchar());
    
    if (input != 'y' && input != 'n') {
      printf("Please introduce a valid option.");
    }
    
  }while (input != 'y' && input != 'n');
  
  switch (input){
    case 'y': 
      printf("Thanks for using Wifi Collector.\n Wifi collector has been terminated.");
      exit(0);
    default: break;
  
}
