/*
    Creation d'un chenillard
    echo 0 > /sys/class/leds/d0/brightness

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/param.h>

FILE* file = NULL;
char text[50];

void turnOn(int ledNumber);
void turnOff(int ledNumber);
void blinkLed(int ledNumber);

int main (int argc, char *argv[]) {

    int n = 0;
    while(n < 2)
    {
        for(int i=0; i<=7; i++)
        {
            sprintf(text, "/sys/class/leds/d%d/brightness",i);
            file = fopen(text, "w");

            fprintf(file, "255");

            fclose(file);  
            usleep(250000);
        }
        for(int j=7; j>=0; j--)
        {
            sprintf(text, "/sys/class/leds/d%d/brightness",j);
            file = fopen(text, "w");

            fprintf(file, "0");

            fclose(file);  
            usleep(250000);
        }
        n++;
    }
    turnOn(4);
    turnOn(5);
    usleep(300000);
    turnOff(4);
    turnOff(5);
    blinkLed(1);
    return 0;
}

void turnOn(int ledNumber) {
    sprintf(text, "/sys/class/leds/d%d/brightness",ledNumber);
    file = fopen(text, "w");
    fprintf(file, "255");
    fclose(file); 
}

void turnOff(int ledNumber) {
    sprintf(text, "/sys/class/leds/d%d/brightness",ledNumber);
    file = fopen(text, "w");
    fprintf(file, "0");
    fclose(file); 
}

void blinkLed(int ledNumber){
    int x = 0;
    do {    
    sprintf(text, "/sys/class/leds/d%d/brightness",ledNumber);
    file = fopen(text, "w");
    fprintf(file, "255");
    fclose(file);
    usleep(200000);
    file = fopen(text, "w");
    fprintf(file, "0");
    fclose(file);
    x++;
    } while (x < 25);
}
