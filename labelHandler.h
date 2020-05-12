//
// Created by alexa on 12-05-2020.
//

#ifndef UNTITLED_LABELHANDLER_H
#define UNTITLED_LABELHANDLER_H

void handleLabelfirst(char line[], int len, int count){
    char label[5]; //skal kunne resizes
    char ch;
    int i = 0;
    int pos = 0;
    for( i; i< len; i++ ){
        ch = line[i];
       if(ch != ' '){
           label[pos] = ch;
       } else{
           break;
       }
    }

    for(i+1; i< len; i++){
        ch = line[i];
        if(ch == 'x'){

        }
    }



};



#endif //UNTITLED_LABELHANDLER_H
