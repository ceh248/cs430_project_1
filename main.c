//
// Created by chooker on 9/13/16.
//
#include <stdlib.h>
#include <stdio.h>
//#include <cstdio>

// reader file
static void readPPMheader(FILE *input){
    unsigned char buff[2];
    if (!input){
        fprintf(stderr, "Unable to open file %c\n",input);
        exit(1);
    }
    // error checking the header file for p3
    if (buff[0] !='P' || buff[1] != '3'){
        //fprinf(stderr, "Invlid input image format");
        exit(1);
    }
    // error checking the header file for p6
    if (buff[0] !='P' || buff[1] != '6'){
        //fprinf(stderr, "Invlid input image format");
        exit(1);
    }
    // call read p3 file to read in binary text
    if (buff[1] == '3'){
        //readP3file;
    }
    // call read p6 file to read in binary text
    if (buff[1] == '6'){
        //readP6file;
    }
}

// if the file is a P3
static void readP3file(){
    //
}

// if the file is P6
static void readP6file(){

    // read individual byts from the file
    int num;
    //num = fgetc();
}

void writeP3_file(){
    // ppmrw 3 input.ppm output.ppm
    int ch;
    //fprintf(ch, output);
}

int main (int argc, char *argv[2]){
    // first what to check my inputs
    // we want to see " ppmrw 3 or 6 input_file and output_file
    //check_args(argc, argv);
    printf("Enter the format for the file to converted into");

    int ppmrw3;
    FILE *input = fopen(argv[0],"rb");
    FILE *output = fopen(argv[1],"wb");
    // call ppm 3

    // or call ppm 6

    // close the file
    fclose(input);
    fclose(output);
}
