#include <stdio.h>
#include "convert.h"
#include "fileHandler.h"

char word[20];

int main() {
    int re = remove("outputFile.txt");

    FILE *f = fopen("inputFile.txt", "r");
    //https://stackoverflow.com/questions/21074084/check-text-file-length-in-c
    if(f == NULL){
        printf("Ikke noget input");
    }
    int toPrint[] = {0,0,1,0,1};
    //writeLine(toPrint);
    int ch;
    char singleLine[20];
    int linePoint = 0;
    while (ch != EOF) {
        ch = fgetc(f);

        if (ch != ';') {
            singleLine[linePoint] = ch;
            linePoint++;
        } else {
            linePoint = 0;
            writeLine(getOpration(singleLine));
        }
//https://www.tutorialspoint.com/cprogramming/c_return_arrays_from_function.htm

    }
    fclose(f);

}
