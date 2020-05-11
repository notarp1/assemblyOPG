//
// Created by alexa on 11-05-2020.
//
#include <stdio.h>
#include "fileHandler.h"
#include "convert.h"

#ifndef UNTITLED_SUDOOPHANDLER_H
#define UNTITLED_SUDOOPHANDLER_H

void handleSudoOp(char input[], FILE *fOut){
    void FILL( char value[], FILE *fOut);
    if(*(input + 1) == 'F'){
        char value[4];
        int i = 2;
        while(1){

            if(*(input+i) == 'x'){


                value[0] = *(input+i+1);
                value[1] = *(input+i+2);
                value[2] = *(input+i+3);
                value[3] = *(input+i+4);

                break;
            }
            i++;
        }
        FILL(value, fOut);
    }
}

void FILL( char value[], FILE *fOut){
    //Loade R6 ned i en værdi
    // loade værdien ned i R7 og gemme det i LC ( måske LC ) idk man


    char ld[] = {'L','D',' ','R','6',',',' ','x',*(value),*(value + 1),*(value +1),*(value+ 1)};
    //Første linje hentet.
    writeLine(getOpration(ld), fOut);

    char st[] = {'S','T',' ','R','6',',',' ', '0'};
    //Anden linje til print;
    writeLine(getOpration(st), fOut);
}
#endif