//
// Created by alexa on 11-05-2020.
//
#include <stdio.h>
#ifndef UNTITLED_HASHMAP_H
#define UNTITLED_HASHMAP_H

static char keys[100][10];
static int locks[100];
static int len = 100;
static int top = -1;
static int labelLen = 5;

void insertKey(char key[]){  // Indsætter en key uden lock værdi
   top = top +1;

   for(int i = 0; i < labelLen; i++){
       keys[top][i] = key[i];
   }
}


void insertLock(char key[], int lock ){ // Indsætter lock til key ( pls ikke brug key der ikke er der... crasher måske)
    int valid = 1;

    for(int i = 0; i < len -1; i++){
        valid = 1;
        for(int x = 0; x < labelLen; x++){
            if(keys[i][x] != key[x]){
                valid = 0;
            }
        }
        if(valid == 1){
            locks[i] = lock;
            break;
        }

    }


}


int doKeyExist(char key[]){ // checker om en key er der, retuner 1 elle 0 (boolean)
    int valid = 1;
    for(int i = 0; i < len -1; i++){
        valid = 1;
        for(int x = 0; x < labelLen; x++){
            if(keys[i][x] != key[x]){
                valid = 0;
            }
        }
        if(valid == 1){
            return 1;
        }

    }
    return 0;

}



int getLock(char key[]){ // returne data fra en key
    int valid = 1;
    for(int i = 0; i < len -1; i++){
        valid = 1;
        for(int x = 0; x < labelLen; x++){
            if(keys[i][x] != key[x]){
                valid = 0;
            }
        }
        if(valid == 1){
            return locks[i];
        }

    }
    return -1;

}

void dummyData(){ // opretter dummydata
    char key[] = {'l','a','b','e','l'};
    insertKey(key);
    insertLock(key, 1);
}

void printHash(){ // Printer hashmapped til consolen
    for(int i = 0; i <= top; i++){
        printf("key: ");
        for(int x = 0; x<labelLen; x++){
            char ch = keys[i][x];

            // if(ch >= 'a' && ch <= 'z' ||ch >= 'A' && ch <= 'Z' ){
            printf("%c",ch);
            //}else{
              //  break;
            //}
        }
        printf(" locket: ");
        printf("%d",locks[i]);

        printf("%c", '\n');
    }


}




#endif //UNTITLED_HASHMAP_H
