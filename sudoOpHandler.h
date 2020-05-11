//
// Created by alexa on 11-05-2020.
//
#include <stdio.h>
#include "fileHandler.h"
#include "convert.h"


void handleSudoOp(char *input[]){
    void FILL( char var[]);
    if(*(input + 1) == 'F'){
       char value[4];
       int i = 2;
       while(1){
           if(*(input+i) == 'x'){
               value = {*(input+i+1),*(input+i+2),*(input+i+3),*(input+i+4) };
               break;
           }

       }
       FILL(value);
    }
}

void FILL( char value[]){
    //Loade R6 ned i en værdi
    // loade værdien ned i R7 og gemme det i LC ( måske LC ) idk man

    int reg = LC + 1;
    char ld[] = {'L','D',' ','R','6',',','0','x',*(value),*(value + 1),*(value +1),*(value+ 1)};
    //Første linje hentet.
    writeLine(getOpration(ld));

    char st[] = {'S','T',' ','R','6',',',' ', '0'};
    //Anden linje til print;
    writeLine(getOpration(st));
}