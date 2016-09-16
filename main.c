//
// Created by Colter Hooker on 9/13/16.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "ppmrw.h"

int main(int argc, char *argv[]){
    // Take in four aruments from the user
    printf("Enter programming name, number, input and output file");
    if (argv < 4){
        perror("Too few arguments");
        exit(1);
    }
    if ( argv > 4){
        perror("Too many arguments");
        exit(0);
    }
    int format = atoi(avgv[1]);
    const char *input_file = argv[2];
    const char *output_file = argv[3];

    //Image *img;

    printf("Program done running");
}

