//
// Created by alexa on 11-05-2020.
//

#include <stdio.h>

#ifndef UNTITLED_FILEHANDLER_H
#define UNTITLED_FILEHANDLER_H

static int pass = 1;

void setPass (int x){ pass = x;}
int getPass(){return pass;}

void writeLine(const int *singleLine, FILE *fOut){

    if(fOut == NULL){
        printf("Ikke noget Output");
    }
    if(pass == 2) {
        for (int i = 0; i < 16; i++) {
            int out = *(singleLine + i);

            fprintf(fOut, "%d", out);
        }
    }
    fprintf(fOut, "\n");
    //fclose(fOut);
}
#endif //UNTITLED_FILEHANDLER_H