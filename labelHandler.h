//
// Created by alexa on 12-05-2020.
//
#include "hashMap.h"
#ifndef UNTITLED_LABELHANDLER_H
#define UNTITLED_LABELHANDLER_H

void handleLabelPassOne(char label[5],char line[], int pos, int len, int LC){
    char ch;
    int i = pos;

    //check if label exist, if i do not, insert key and data
    if(doKeyExist(label) != 1){
        insertKey(label);
        insertLock(label, LC+1);
    }


}



#endif //UNTITLED_LABELHANDLER_H
