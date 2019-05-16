#include "bluetooth.h"
#include "mbed.h"

extern Serial HC06;
extern char data;
extern Serial PC;

int main() {
char S = 0x1;
char D = 0x2;
char I = 0x7;
char DA = 0xF;
read();
        while(1){
            
            wait_ms(500);
            HC06.printf("AT\r\n");
            wait_ms(500);
            send(S,D,I,DA);
            //wait_ms(500);
       }
    }
