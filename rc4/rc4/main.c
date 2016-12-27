//
//  main.c
//  rc4
//
//  Created by Grace Akpan on 9/8/16.
//  Copyright © 2016 Grace Akpan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SIZE 256

typedef unsigned char uns8;
typedef unsigned short uns16;

static uns8 state[SIZE];
int i;
uns8 j;

// function declaration
uns8* encryptMessage(uns8 key[], uns8 msg[]);
void rc4_init(uns8 key[]);
uns8* charCopy(uns8* szString, uns8 c);
uns8 rc4_setup();

int main (void){
    uns8 key[] = "zxcvb";
    uns8 msg[] = "This class is easier than I thought.";
    uns8* temp = (uns8*)malloc(100*sizeof(uns8));
    uns8* encr = (uns8*)malloc(100*sizeof(uns8));
    uns8* decr = (uns8*)malloc(100*sizeof(uns8));
    
    
   temp =  encryptMessage(key, msg);
    
    strcat((char*)encr, (const char*)temp);
    printf("Encrypted value: %s \n\n", encr);
    // reset temp
    temp = (uns8*)malloc(100*sizeof(uns8));
    
    temp = encryptMessage(key, encr);
    strcat((char*)decr, (const char*)temp);
    printf("Decrypted value: %s \n\n", decr);
    
    
    return 0;
}

/**
 * used to encrypt/decrypt a plaintext message
 */
uns8* encryptMessage(uns8 key[], uns8 msg[]){
    int in = 0;
    uns8* res = (uns8*)malloc(100*sizeof(uns8));
    uns8* final = (uns8*)malloc(100*sizeof(uns8));
    
    rc4_init(key);
    while(in < strlen((const char*)msg)){
        char m = msg[in];
        // XOR each 8 bits of plaintext with the 8 bits generate in order
        // to create a cyphertext
        uns8 str = (uns8)m^rc4_setup();
        res = charCopy(res, str);
        // concatenate encrypted character an array of strings
        strcat((char*)final,(const char*)res);
        in++;
    }
    return final;
}

/**
 * perform initial permutation of the state array
 */
 
void rc4_init(uns8 key[]){
    uns8 t;
    uns8 keyArray[SIZE];
    
    // initialize the state array
    for(i = 0; i < SIZE; i++)
        state[i] = i;
    
    // initialize key array to match the length of state array
    for(i = 0; i < SIZE; i++)
        keyArray[i] = key[i%sizeof(key, SIZE)];
    
    // perform permutation
    for(i = 0, j = 0; i < SIZE; i++){
        j = (j + state[i] + keyArray[i]) % SIZE;
        // perform swap indexes of state array to increase randomness
        t = state[i];
        state[i] = state[j];
        state[j] = t;
    }
}

/**
 * generate an 8 bit cyphertext for each 8 bit of plaintext
 */
uns8 rc4_setup(){
    uns8 t;
    // generate 8 bits that are XOR'd with each 8 bits of plaintext to
    // produce a cyphertext
    i = (i+1) % SIZE;
    j = (j+state[i]) % SIZE;
    // swap state array index to increase randomness
    t = state[i];
    state[i] = state[j];
    state[j] = t;
    
    return state[(state[i]+state[j])%SIZE];
}

/**
 * copy encrypted character to a temporary array
 */
uns8* charCopy(uns8* szString, uns8 c){
    asprintf((char**)&szString, "%c", c);
    return szString;
}



