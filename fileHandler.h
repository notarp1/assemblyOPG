//
// Created by alexa on 11-05-2020.
//

#include <stdio.h>

#ifndef UNTITLED_FILEHANDLER_H
#define UNTITLED_FILEHANDLER_H




void writeLine(const int *singleLine, FILE *fOut){

    if(fOut == NULL){
        printf("Ikke noget Output");
    }

    for(int i = 0; i < 16; i++){
        int out = *(singleLine+i);

        fprintf(fOut, "%d", out);
    }
    fprintf(fOut, "\n");
    //fclose(fOut);
}
#endif //UNTITLED_FILEHANDLER_H