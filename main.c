

#include <stdio.h>
#include "convert.h"
#include "fileHandler.h"
#include "sudoOpHandler.h"
#include "hashMap.h"

char word[20];


int LC = 0;
int main() {
    int re = remove("outputFile.txt");


    FILE *f = fopen("inputFile.txt", "r");
    FILE *fOut = fopen("outputFile.txt", "w");
    //https://stackoverflow.com/questions/21074084/check-text-file-length-in-c
    if(f == NULL){
        printf("Ikke noget input");
    }

    int ch;
    char singleLine[20];
    int linePoint = 0;
    while (ch != EOF) {
        ch = fgetc(f);

        if(ch == '\n') {
            char singleLine[20];



        } else if (ch != ';') {
            singleLine[linePoint] = ch;
            linePoint++;
        }else if(singleLine[0] == '.' && singleLine[1]== 'E' && singleLine[2] == 'N' && singleLine[3] == 'D'){
            if(getPass() == 1){
                setPass(2);
                LC = 0;
                rewind(f);
            }

        } else if (singleLine[0] == '.') {

            linePoint = 0;
            handleSudoOp(singleLine, fOut);
            char singleLine[20];


        } else {
            linePoint = 0;
            writeLine(getOpration(singleLine), fOut);
            char singleLine[20];
        }
        LC++;
//https://www.tutorialspoint.com/cprogramming/c_return_arrays_from_function.htm

    }
    fclose(f);

}



