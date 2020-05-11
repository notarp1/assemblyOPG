#include "math.h"
#include "fileHandler.h"

char s[2];
char test[4];

static int operation[16];


int * getOpration(char word[20]){
    char action[3];
    int regLock = 0;
    int srcLock = 0;
    int parseInt();
    int intFromHexa(char *A, int len );
    int binaryConvert(int n, int l, int b);
    int intFromArray(int *A, int len);
    //for ADD
    int add = 0;
    //for LD/STR
    int ldst = 0;
    //for LDR
    int ldr = 0;
    //for BR
    int br = 0;
    int temp = 1;


    for (int i = 0; word[i] != 0; i++) {

        if (word[i] == '\x20' || word[i] == '\x2C') {
            continue;
        }

        //.Orig
        if(word[i] == '\x2E' && word[i+1] == '\x4F'){
            i = 7;
            int intPrep[] = {word[i], word[i+1], word[i+2], word[i+3]};
            binaryConvert(intFromArray(intPrep,4),0,15);


            break;
        }


        if( temp == 1){

            //ADD & AND
            if (word[i] == '\x41') {
                add = 1;

                if (word[i + 1] == '\x44') {   //ADD
                    operation[0] = 0;
                    operation[1] = 0;
                    operation[2] = 0;
                    operation[3] = 1;
                    i += 3;
                    continue;
                } else {                //AND
                    operation[0] = 0;
                    operation[1] = 1;
                    operation[2] = 0;
                    operation[3] = 1;
                    i += 3;
                    continue;
                }

            }

            //LD & LDR
            if (word[i] == '\x4C') {

                if (word[i + 2] == '\x52') { //LDR
                    operation[0] = 0;
                    operation[1] = 1;
                    operation[2] = 1;
                    operation[3] = 0;
                    i += 3;
                    ldr = 1;
                    continue;
                } else {                    //LD
                    operation[0] = 0;
                    operation[1] = 0;
                    operation[2] = 1;
                    operation[3] = 0;
                    i += 2;
                    ldst = 1;
                    continue;
                }
            }

            //ST
            if (word[i] == '\x53') {
                operation[0] = 0;
                operation[1] = 0;
                operation[2] = 1;
                operation[3] = 1;
                i += 2;
                ldst = 1;
                continue;
            }

            //BR
            if (word[i] == '\x42') {
                operation[0] = 0;
                operation[1] = 0;
                operation[2] = 0;
                operation[3] = 0;
                i += 1;
                br = 1;
                ldst = 1;
                continue;
            }

            //NOT
            if (word[i] == '\x4E') {
                operation[0] = 1;
                operation[1] = 0;
                operation[2] = 0;
                operation[3] = 1;
                operation[10] = 1;
                operation[11] = 1;
                operation[12] = 1;
                operation[13] = 1;
                operation[14] = 1;
                operation[15] = 1;
                i += 3;

                continue;

            }

            if (br == 1) {
                br = 0;
                if (word[i] == '\x6E') { //n
                    operation[4] = 1;
                    if (word[i + 1] == '\x70') {
                        operation[6] = 1;
                        continue;
                    } else operation[6] = 0;
                    if (word[i + 1] == '\x7A') { //z
                        operation[5] = 1;
                    } else operation[5] = 0;
                    if (word[i + 2] == '\x70') { //p
                        operation[6] = 1;
                    } else operation[6] = 0;

                    i = i + 2;
                    continue;
                } else operation[4] = 0;

                if (word[i] == '\x7A') { //z
                    operation[5] = 1;

                    if (word[i + 1] == '\x70') { //p
                        operation[6] = 1;
                    } else operation[6] = 0;
                    i = i + 1;
                    continue;
                } else operation[5] = 0;

                if (word[i] == '\x70') {
                    operation[6] = 1;
                } else operation[6] = 0;
                continue;

            }

            //REGISTERS
            if (word[i] == '\x52' && regLock == 0) {

                regLock = 1;
                switch (word[i + 1]) {

                    case '\x30': //R0
                        operation[4] = 0;
                        operation[5] = 0;
                        operation[6] = 0;
                        i += 2;
                        break;

                    case '\x31': //R1
                        operation[4] = 0;
                        operation[5] = 0;
                        operation[6] = 1;
                        i += 2;
                        break;
                    case '\x32': //R2
                        operation[4] = 0;
                        operation[5] = 1;
                        operation[6] = 0;
                        i += 2;
                        break;

                    case '\x33': //R3
                        operation[4] = 0;
                        operation[5] = 1;
                        operation[6] = 1;
                        i += 2;
                        break;

                    case '\x34': //R4
                        operation[4] = 1;
                        operation[5] = 0;
                        operation[6] = 0;
                        i += 2;
                        break;

                    case '\x35': //R5
                        operation[4] = 1;
                        operation[5] = 0;
                        operation[6] = 1;
                        i += 2;
                        break;

                    case '\x36': //R6
                        operation[4] = 1;
                        operation[5] = 1;
                        operation[6] = 0;
                        i += 2;
                        break;

                    case '\x37': //R7
                        operation[4] = 1;
                        operation[5] = 1;
                        operation[6] = 1;
                        i += 2;
                        break;


                }
                continue;

            }

            //SRC1
            if (regLock == 1 && srcLock == 0 && ldst == 0) {
                srcLock = 1;


                if (add == 1) {
                    operation[10] = 0;
                    operation[11] = 0;
                    operation[12] = 0;
                }

                if (word[i] == '\x52') {

                    switch (word[i + 1]) {

                        case '\x30': //R0
                            operation[7] = 0;
                            operation[8] = 0;
                            operation[9] = 0;
                            i += 2;
                            break;

                        case '\x31': //R1
                            operation[7] = 0;
                            operation[8] = 0;
                            operation[9] = 1;
                            i += 2;
                            break;
                        case '\x32': //R2
                            operation[7] = 0;
                            operation[8] = 1;
                            operation[9] = 0;
                            i += 2;
                            break;

                        case '\x33': //R3
                            operation[7] = 0;
                            operation[8] = 1;
                            operation[9] = 1;
                            i += 2;
                            break;

                        case '\x34': //R4
                            operation[7] = 1;
                            operation[8] = 0;
                            operation[9] = 0;
                            i += 2;
                            break;

                        case '\x35': //R5
                            operation[7] = 1;
                            operation[8] = 0;
                            operation[9] = 1;
                            i += 2;
                            break;

                        case '\x36': //R6
                            operation[7] = 1;
                            operation[8] = 1;
                            operation[9] = 0;
                            i += 2;
                            break;

                        case '\x37': //R7
                            operation[7] = 1;
                            operation[8] = 1;
                            operation[9] = 1;
                            i += 2;
                            break;


                    }
                    continue;

                }


            }

            //SRC2
            if (regLock == 1 && srcLock == 1) {

                if (word[i] == '\x52') {

                    switch (word[i + 1]) {

                        case '\x30': //R0
                            operation[13] = 0;
                            operation[14] = 0;
                            operation[15] = 0;
                            i += 2;
                            break;

                        case '\x31': //R1
                            operation[13] = 0;
                            operation[14] = 0;
                            operation[15] = 1;
                            i += 2;
                            break;
                        case '\x32': //R2
                            operation[13] = 0;
                            operation[14] = 1;
                            operation[15] = 0;
                            i += 2;
                            break;

                        case '\x33': //R3
                            operation[13] = 0;
                            operation[14] = 1;
                            operation[15] = 1;
                            i += 2;
                            break;

                        case '\x34': //R4
                            operation[13] = 1;
                            operation[14] = 0;
                            operation[15] = 0;
                            i += 2;
                            break;

                        case '\x35': //R5
                            operation[13] = 1;
                            operation[14] = 0;
                            operation[15] = 1;
                            i += 2;
                            break;

                        case '\x36': //R6
                            operation[13] = 1;
                            operation[14] = 1;
                            operation[15] = 0;
                            i += 2;
                            break;

                        case '\x37': //R7
                            operation[13] = 1;
                            operation[14] = 1;
                            operation[15] = 1;
                            i += 2;
                            break;


                    }

                    continue;
                }


            }

            // ADD imm5
            if (add == 1) {
                if (word[i] == '\x23') {

                    operation[10] = 1;

                    if (word[i + 1] == '\x2D') {   //Negative Number
                        s[0] = word[i + 2];
                        s[1] = word[i + 3];

                        int number = parseInt();
                        number = number * (-1);

                        binaryConvert(number, 11, 4);
                        break;

                    } else {                       // Positive Number
                        s[0] = word[i + 1];
                        s[1] = word[i + 2];

                        int number = parseInt();

                        binaryConvert(number, 11, 4);
                        break;

                    }


                }

            }

            //LD/STR + LDR PCoffset
            if (ldst == 1 || ldr == 1) {

                if (word[i + 1] == '\x2D') {   //Negative Number
                    s[0] = word[i + 2];
                    s[1] = word[i + 3];

                    int number = parseInt();
                    number = number * (-1);

                    if (ldst == 1) {
                        binaryConvert(number, 7, 8);
                    } else
                        binaryConvert(number, 10, 5);
                    break;

                } else {                       // Positive Number
                    s[0] = word[i + 1];
                    s[1] = word[i + 2];

                    int number = parseInt();

                    if (ldst == 1) {
                        binaryConvert(number, 7, 8);
                    } else
                        binaryConvert(number, 10, 5);
                    break;

                }

            }
        }


    }


    return operation;



}

//https://stackoverflow.com/questions/5488377/converting-an-integer-to-binary-in-c
//https://www.programmingsimplified.com/c/source-code/c-program-convert-decimal-to-binary
int parseInt () {
    char c;
    int f;
    int digit;
    int number=0;

    for(f = 0; f < 2; f++)
    {
        c = s[f];
        if(c>='0' && c<='9')
        {
            digit = c - '0';
            number = number*10 + digit;

        }
    }
    return number;
}


int intFromArray( int *A, int len){
    int res = 0;
    int numb = 0;
    int offset = '0';
    for(int i = 0; i < len; i++){
        numb = *(A+i) - offset;
        if(i == len-1){
            res = res + (numb );
        }else {
            res = res + (int)( numb * pow(10,(len - 1 - i)));
        }
    }
   return res;
}


int binaryConvert(int n, int l, int b) {
    int k;
    int c;

    for (c = b; c >= 0; c--) {

        k = n >> c;

        if (k & 1) {
            operation[l] = 1;
        } else {
            operation[l] = 0;

        }
        l++;
    }
}
int intFromHexa(char *A, int len){
    int intFromHexaDecimal(char in);
    double res = 0;
    int numb = 0;


    for(int i = 0; i < len; i++){
        numb = intFromHexaDecimal(*(A+i));
        if(i == len-1){
            res = res + (numb );
        }else {
            res = res + (int)( numb * pow(16,(len - 1 - i)));
        }
    }
    return (int)res;
}

int intFromHexaDecimal(char in){

    switch (in) {
        case 'A': return 10;
        case 'B': return 11;
        case 'C': return 12;
        case 'D': return 13;
        case 'E': return 14;
        case 'F': return 15;

        default: return in - '0';
    }
}

