#include "mbed.h"

Serial HC06(PF_7,PF_6, 115200);
char data;
Serial PC(USBTX, USBRX,115200);


void send(char SRC, char DST, char ID, char  DATA){
    char trame[4] = {0};
    trame[0] = 0xAA;
    trame[1] = (SRC<<4) | DST;
    trame[2] = (ID<<4) | DATA;
    trame[3] = 0xAB; 
    HC06.printf("%x%x%x%x\r\n", trame[0],trame[1],trame[2],trame[3]);    
}

void callback(){
    while(HC06.readable()){
        data = HC06.getc();
        PC.printf("%c",data);
        }
}

void read(){
    HC06.attach(&callback);
    
    }