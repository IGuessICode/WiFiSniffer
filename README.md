# WiFiSniffer
Uni project: WiFi Collector

To run it in the shell you need to use the following commands:

- to compile the individual modules
  * gcc -Wall main.c -c
  * gcc -Wall functions.c -c
  * gcc -Wall quit.c -c
  * gcc -Wall collect.c -c
  * gcc -Wall display.c -c
- to link the object files into a single binary file
  gcc *.c -o program
- to execute the program
  ./program
