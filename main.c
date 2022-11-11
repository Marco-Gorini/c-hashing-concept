//
//  main.c
//  Hashing Algorithm
//
//  Created by Marco Gorini on 11/11/2022.
//  Copyright © 2022 Marco Gorini. All rights reserved.
//


//EXPLANATION

//  In cybersecurity, there are three fundamentals concepts regarding the data, that we can also abbreviate as CIA (Confidentiality, Integrity, Availability). A hash function is used to ensure the integrity: what could happen if a cyber-criminal, for example using a MitM technique (Man in the middle), change the message that a friend want to send to you? And, thinking about something worse, what could happen if the USA President want to send a message to the Italian one, that tells "Hey, how are you?", and a cybercriminal change it into "I want to declare war to Italy"? Obviously this is an exaggerated example, but the thing is that the data needs to be sent and received in their correct way. To make it possible, an important tool is to hash the messages, so to convert them into other strings with an algorithm (easy to implement, difficult to reverse). The converted string has to be possibly unique for every different string ( we will understand why at the end). Let's view an example:
//    - I want to send a "Hello" message to my friend
//    - I convert it into a string, like this: "htrg"
//    - My friend receive the message "Hello", and to be sure that the message is correct,      use the same algorithm I used to convert the string, and the converted string is        "htrg". In this case he is sure that I effectively sent the message "Hello"
//    - In another case, my friend could receive the message "hello, how are you". He           converts the string with my same algorithm, and the converted string is "hagtrer".      It is different from mine! This means that someone changed the content of the           message

//  Here is an example of a easy hash function that converts a random generated string to a hashed one, using a hash table. It is easy to revert, but it is just to make understand you the concept.I will try the algorithm 50 times: all the strings need to be equals!


    
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define MAX_DIM 20
#define NUMBER_OF_TRIALS 50

//STRUCTS

typedef struct nodeHash {
    char charToCompare;
    char convertedChar;
} HashTable;

//FUNCTIONS

void generateRandomString(char *str, int size, char* charSet);
void printString(char* stringToPrint);
void hashMessage(char* stringToConvert, char* hashedMessage, HashTable hashTable[]);
void initializateHashTable(HashTable hashTable[], unsigned long dim, char* charSet);
int hashFunction(char key);


//MAIN

int main(int argc, const char * argv[]) {
    
    char charSet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890|!$%&/()=?^*+:.-_<>, ;";
    char randomMessage[MAX_DIM];
    char hashedMessage[MAX_DIM];
    HashTable hashTable[strlen(charSet)];
    
    generateRandomString(randomMessage,MAX_DIM,charSet);
    printf("Message: ");
    printString(randomMessage);
    initializateHashTable(hashTable,strlen(charSet), charSet);
    for(int i = 0; i < NUMBER_OF_TRIALS; ++i){
        hashMessage(randomMessage, hashedMessage, hashTable);
        printf("Hashed message: ");
        printString(hashedMessage);
    }
    
}

//This function generates a random string. This will generate always the same for a property of the function rand()

void generateRandomString(char* stringToInitializate, int size, char* charSet) {
    
    --size;
    for (size_t n = 0; n < size; n++) {
        int key = rand() % (int) (sizeof charSet - 1);
        stringToInitializate[n] = charSet[key];
    }
    stringToInitializate[size] = '\0';
}

//This function print the string

void printString(char* stringToPrint) {
    for(int i = 0; i < stringToPrint[i] != '\0'; ++i) {
        printf("%c", stringToPrint[i]);
    }
    printf("\n");
}

//Function to convert my string into a total different string

void hashMessage(char* stringToConvert, char* hashedMessage, HashTable hashTable[]){
    int i;
    for(i = 0; stringToConvert[i] != '\0'; ++i){
        hashedMessage[i] = hashTable[hashFunction(stringToConvert[i])].convertedChar;
    }
    hashedMessage[++i] = '\0';
}

//Initializate the hash table

void initializateHashTable(HashTable hashTable[], unsigned long dim, char* charSet) {
    
    for(int i = 0; i < dim; i++){
        hashTable[i].charToCompare = charSet[i];
    }
    
    hashTable[0].convertedChar = 's';
    hashTable[1].convertedChar = 'y';
    hashTable[2].convertedChar = 'r';
    hashTable[3].convertedChar = 'i';
    hashTable[4].convertedChar = 'q';
    hashTable[5].convertedChar = 'z';
    hashTable[6].convertedChar = 'p';
    hashTable[7].convertedChar = 'a';
    hashTable[8].convertedChar = 'c';
    hashTable[9].convertedChar = 'A';
    hashTable[10].convertedChar = 'C';
    hashTable[11].convertedChar = 'S';
    hashTable[12].convertedChar = 'Y';
    hashTable[13].convertedChar = 'R';
    hashTable[14].convertedChar = 'I';
    hashTable[15].convertedChar = 'Q';
    hashTable[16].convertedChar = 'Z';
    hashTable[17].convertedChar = 'P';
    hashTable[18].convertedChar = 'b';
    hashTable[19].convertedChar = 'w';
    hashTable[20].convertedChar = 'e';
    hashTable[21].convertedChar = 'B';
    hashTable[22].convertedChar = 'W';
    hashTable[23].convertedChar = 'E';
    hashTable[24].convertedChar = 't';
    hashTable[25].convertedChar = 'u';
    hashTable[26].convertedChar = 'o';
    hashTable[27].convertedChar = 'd';
    hashTable[28].convertedChar = 'D';
    hashTable[29].convertedChar = 'O';
    hashTable[30].convertedChar = 'T';
    hashTable[31].convertedChar = 'U';
    hashTable[32].convertedChar = 'f';
    hashTable[33].convertedChar = 'F';
    hashTable[34].convertedChar = 'g';
    hashTable[35].convertedChar = 'h';
    hashTable[36].convertedChar = 'j';
    hashTable[37].convertedChar = 'G';
    hashTable[38].convertedChar = 'H';
    hashTable[39].convertedChar = 'J';
    hashTable[40].convertedChar = 'k';
    hashTable[41].convertedChar = 'K';
    hashTable[42].convertedChar = 'l';
    hashTable[43].convertedChar = 'x';
    hashTable[44].convertedChar = 'v';
    hashTable[45].convertedChar = 'n';
    hashTable[46].convertedChar = 'm';
    hashTable[47].convertedChar = 'L';
    hashTable[48].convertedChar = 'X';
    hashTable[49].convertedChar = 'V';
    hashTable[50].convertedChar = 'N';
    hashTable[51].convertedChar = 'M';
    hashTable[52].convertedChar = '7';
    hashTable[53].convertedChar = '3';
    hashTable[54].convertedChar = '0';
    hashTable[55].convertedChar = '1';
    hashTable[56].convertedChar = '9';
    hashTable[57].convertedChar = '8';
    hashTable[58].convertedChar = '2';
    hashTable[59].convertedChar = '4';
    hashTable[60].convertedChar = '6';
    hashTable[61].convertedChar = '!';
    hashTable[62].convertedChar = '(';
    hashTable[63].convertedChar = '?';
    hashTable[64].convertedChar = '=';
    hashTable[65].convertedChar = ' ';
    hashTable[66].convertedChar = '/';
    hashTable[67].convertedChar = '&';
    hashTable[68].convertedChar = '%';
    hashTable[69].convertedChar = '$';
    hashTable[70].convertedChar = '|';
    hashTable[71].convertedChar = ')';
    hashTable[72].convertedChar = '*';
    hashTable[73].convertedChar = '+';
    hashTable[74].convertedChar = '-';
    hashTable[75].convertedChar = '_';
    hashTable[76].convertedChar = ':';
    hashTable[77].convertedChar = '.';
    hashTable[78].convertedChar = ',';
    hashTable[79].convertedChar = ';';
    hashTable[80].convertedChar = '<';
    hashTable[81].convertedChar = '>';
    hashTable[82].convertedChar = '^';
    hashTable[83].convertedChar = '5';
}

int hashFunction(char key) {
    
    if(key == 'a') {
        return 0;
    }
    else if(key == 'b') {
        return 1;
    }
    else if(key == 'c') {
        return 2;
    }
    else if(key == 'd') {
        return 3;
    }
    else if(key == 'e') {
        return 4;
    }
    else if(key == 'f') {
        return 5;
    }
    else if(key == 'g') {
        return 6;
    }
    else if(key == 'h') {
        return 7;
    }
    else if(key == 'i') {
        return 8;
    }
    else if(key == 'j') {
        return 9;
    }
    else if(key == 'k') {
        return 10;
    }
    else if(key == 'l') {
        return 11;
    }
    else if(key == 'm') {
        return 12;
    }
    else if(key == 'n') {
        return 13;
    }
    else if(key == 'o') {
        return 14;
    }
    else if(key == 'p') {
        return 15;
    }
    else if(key == 'q') {
        return 16;
    }
    else if(key == 'r') {
        return 17;
    }
    else if(key == 's') {
        return 18;
    }
    else if(key == 't') {
        return 19;
    }
    else if(key == 'u') {
        return 20;
    }
    else if(key == 'v') {
        return 21;
    }
    else if(key == 'w') {
        return 22;
    }
    else if(key == 'x') {
        return 23;
    }
    else if(key == 'y') {
        return 24;
    }
    else if(key == 'z') {
        return 25;
    }
    else if(key == 'A') {
        return 26;
    }
    else if(key == 'B') {
        return 27;
    }
    else if(key == 'C') {
        return 28;
    }
    else if(key == 'D') {
        return 29;
    }
    else if(key == 'E') {
        return 30;
    }
    else if(key == 'F') {
        return 31;
    }
    else if(key == 'G') {
        return 32;
    }
    else if(key == 'H') {
        return 33;
    }
    else if(key == 'I') {
        return 34;
    }
    else if(key == 'J') {
        return 35;
    }
    else if(key == 'K') {
        return 36;
    }
    else if(key == 'L') {
        return 37;
    }
    else if(key == 'M') {
        return 38;
    }
    else if(key == 'N') {
        return 39;
    }
    else if(key == 'O') {
        return 40;
    }
    else if(key == 'P') {
        return 41;
    }
    else if(key == 'Q') {
        return 42;
    }
    else if(key == 'R') {
        return 43;
    }
    else if(key == 'S') {
        return 44;
    }
    else if(key == 'T') {
        return 45;
    }
    else if(key == 'U') {
        return 46;
    }
    else if(key == 'V') {
        return 47;
    }
    else if(key == 'W') {
        return 48;
    }
    else if(key == 'X') {
        return 49;
    }
    else if(key == 'Y') {
        return 50;
    }
    else if(key == 'Z') {
        return 51;
    }
    else if(key == '1') {
        return 52;
    }
    else if(key == '2') {
        return 53;
    }
    else if(key == '3') {
        return 54;
    }
    else if(key == '4') {
        return 55;
    }
    else if(key == '5') {
        return 56;
    }
    else if(key == '6') {
        return 57;
    }
    else if(key == '7') {
        return 58;
    }
    else if(key == '8') {
        return 59;
    }
    else if(key == '9') {
        return 60;
    }
    else if(key == '0') {
        return 61;
    }
    else if(key == '|') {
        return 62;
    }
    else if(key == '!') {
        return 63;
    }
    else if(key == '$') {
        return 64;
    }
    else if(key == '%') {
        return 65;
    }
    else if(key == '&') {
        return 66;
    }
    else if(key == '/') {
        return 67;
    }
    else if(key == '(') {
        return 68;
    }
    else if(key == ')') {
        return 69;
    }
    else if(key == '=') {
        return 70;
    }
    else if(key == '?') {
        return 71;
    }
    else if(key == '^') {
        return 72;
    }
    else if(key == '*') {
        return 73;
    }
    else if(key == '+') {
        return 74;
    }
    else if(key == ':') {
        return 75;
    }
    else if(key == '.') {
        return 76;
    }
    else if(key == '-') {
        return 77;
    }
    else if(key == '_') {
        return 78;
    }
    else if(key == '>') {
        return 79;
    }
    else if(key == '<') {
        return 80;
    }
    else if(key == ',') {
        return 81;
    }
    else if(key == ' ') {
        return 82;
    }
    else if(key == ';') {
        return 83;
    }
    else{
        return 84;
    }
}


