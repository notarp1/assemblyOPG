#include <stdio.h>
#include "convert.h"


char word[20];

int main() {
    int re = remove("outputFile.txt");

    FILE* f = fopen("inputFile.txt", "r");
   //https://stackoverflow.com/questions/21074084/check-text-file-length-in-c
    FILE *fOut = fopen("outputFile.txt", "w");


    int ch;
    char singleLine[20];
    int linePoint= 0;
    while(ch != EOF){
        ch = fgetc(f);
        if(ch != ';'){
            singleLine[linePoint] = ch;
            linePoint++;
        } else{
            linePoint = 0;
            int *p = getOpration(singleLine);
            
            for(int i = 0; i < 16; i++){
                int out = *(p+i);
                printf("%d",out);
                fprintf(fOut, "%d", out);
            }
            fprintf(fOut, "\n");
        }

    }
    fclose(f);
    fclose(fOut);






//https://www.tutorialspoint.com/cprogramming/c_return_arrays_from_function.htm


}

