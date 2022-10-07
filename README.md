# WiFiSniffer
Uni project: WiFi Collector

The program is divided into 4 modules:
* The main in which the execution starts, the menu will be displayed and from where the further on needed functions will be called.
* The module quit to to implement the first task of quitting the program and a function called reset which resets a string back to an empty one.
* The module $collect$ implements the collecting of the networks by counts the number of networks stored in a Cell text file and stores them in a struct of the newly created type network which incorporates all the features of a network and also counts the number of networks stored in a Cell text file.
* And finally, the display module which combines the indivual display as well as the display of all collected networks.

To run it in the shell you need to use the following commands:

- to compile the individual modules
  * gcc -Wall main.c -c
  * gcc -Wall quit.c -c
  * gcc -Wall collect.c -c
  * gcc -Wall display.c -c
- to link the object files into a single binary file
  * gcc *.c -o program
- to execute the program
  * ./program
