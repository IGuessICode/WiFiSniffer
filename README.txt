# WiFiSniffer
Uni project: WiFi Collector

The program is divided into 4 modules:
* The _main_ in which the execution starts, the menu will be displayed and from where the further on needed functions will be called.
* The module _quit_ to implement the first task of quitting the program and a function called _reset()_ which resets a string back to an empty one.
* The module _collect_ implements the collecting of the networks by counting the number of networks stored in a Cell text file and then saving them in an array of the newly created type network which incorporates all the features of a network in a struct.
* And finally, the _display_ module which combines the individual display, as well as the display of all collected networks and the function _print()_ which is used by both of the display functions to not repeat code.

To run it in the shell you need to use the following commands:

- to compile the individual modules
    gcc -Wall main.c -c
    gcc -Wall quit.c -c
    gcc -Wall collect.c -c
    gcc -Wall display.c -c

- to link the object files into a single binary file
    gcc *.c -o program
  if you want to display the debugging message:
    gcc *.c -DDEBUG -o program

- to execute the program
    ./program
