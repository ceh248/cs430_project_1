
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    unsigned char r, g, b;
}RGB_pixal;

static void write_P3(char* p6, char*take_along);
static void write_P6(char* p6, char*take_along);

static void ppmrw(int format, char* input, char* ouput){
    // ok are taking in a  format to tranform data in to
    // input = ppm file
    // output = tranform ppm file

    // read individual bytes
    FILE* fp = fopen(input,"rb");

    // seek to the end of the file to get its size
    fseek(fp,0L,SEEK_END);
    rewind(fp);
    int ch;
    ch = fgetc(fp);

    // malloc the size of the file
    char *pixmap;
    pixmap = (char *)malloc(sizeof(fp));

    // check the header
    // checking each bye
    int i = 0;
    pixmap[i] = 0;
    while(ch != EOF){
        if(ch == '\n'){
            ch = fgetc(fp);
        }else if(isspace(ch)){
            ch = fgetc(fp);
        } else if(ch == '#'){
            // need to skip a line
            while(ch != '\n'){
                ch = fgetc(fp);
            }
            ch = fgetc(fp);
        } else{
            pixmap[i] = ch;
            ch = fgetc(fp);
            i+=1;
        }
    }
    if (pixmap[0]!='P'){
        fprintf(stderr,"Error not PPM file header:\n");
        exit(1);
    }
    if (!(pixmap[1] == '6' || '3' == pixmap[1])){
        fprintf(stderr,"Error not PPM file header type:\n");
        exit(1);
    }

    if (format == 3){
        write_P3(ouput,pixmap);
    }
    if (format == 6){
        write_P6(ouput,pixmap);
    }
}

static void write_P3(char* p3, char*take_along){
    FILE* fp = fopen(p3,"wb");
    fwrite(take_along,sizeof(take_along),sizeof(take_along),fp);
    fclose(fp);
    return;
}

static void write_P6(char* p6, char*take_along){
    FILE* fp = fopen(p6,"wb");
    fwrite(take_along,sizeof(take_along),sizeof(take_along),fp);
    fclose(fp);
    return;
}


int main (int argc, char *argv[]){
    if (argc != 4){
        fprintf(stderr,"Error not correct amount of argc: \n");
        exit(1);
    }
/*
    // each of the argv to a value
    const char *input_file = argv[2];
    const char *output_file = argv[3];
    // break everything up right now
    ppmrw(input_file,output_file,format);
    // testing*/
    int format = atoi(argv[1]);
    ppmrw(format,argv[2],argv[3]);

    return 0;
}