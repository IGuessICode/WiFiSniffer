# WiFiSniffer
Uni project: WiFi Collector

The program is divided into 7 modules:
* The _main_ in which the execution starts, the menu will be displayed and from where the further on needed functions will be called.
* The _network_ contains the general structure of the networks, plus the constants needed for previous submissions and the maximum length of the strings.
* The module _nodelib_ is a self-made library with the structure of a Node and all the operations related to nodes.
* The module _quit_ to implement the first task of quitting the program and a function called _reset()_ which resets a string back to an empty one.
* The module _collect_ implements the collecting of the networks by counting the number of networks stored in a Cell text file and then saving them in nodes that are appended to the list.
* The module _select_ implements the functions for finding the best and worst network quality, as well as a printing function to display networks by their quality. In this case, it is only used to print those networks with top/bottom values.
* And finally, the _display_ module which combines the individual display, as well as the function _print()_ which is used by almost all printing functions to not repeat code.

To run it in the shell you need to use the following commands:

- to compile the individual modules (except for network.h)
    gcc -Wall main.c -c
    gcc -Wall nodelib.c -c
    gcc -Wall quit.c -c
    gcc -Wall collect.c -c
    gcc -Wall display.c -c
    gcc -Wall select.c -c

- to link the object files into a single binary file
    gcc *.c -o program
  if you want to display the debugging message:
    gcc *.c -DDEBUG -o program

- to execute the program
    ./program
