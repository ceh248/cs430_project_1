
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    unsigned char r, g, b;
}RGB_pixal;

RGB_pixal *buffer;

int width;
int height;

typedef struct {
    int x,y;
    struct PPM_image *data;
}PPM_image;

void skip_ws(FILE* ppm){
    int c = fgetc(ppm);
    while (isspace(c)){
        c = fgetc(ppm);
    }
    ungetc(c,ppm);
}

void ppmrw(const char* ppm){
    FILE* fp= fopen(ppm,"rb");
    char buffer[1024];
    malloc(sizeof(buffer));
    int c = fgetc(fp);
    int i = 0;
    buffer[i] = 0;
    while (c != EOF){
        buffer[i] = c;
        c = fgetc(fp);
        i+=1;
    }
    skip_ws(fp);
    /*while (c != ' '){
        buffer[i] = c;
        c = fgetc(fp);
        i+=1;
    }
    skip_ws(fp);
    while (c != '#'){
        buffer[i] = c;
        c = fgetc(fp);
        i+=1;
    }
    skip_ws(fp);*/

    if (buffer[0] !='P'){
        fprintf(stderr,"Error not correct FILE");
        exit(1);
    }
    if (buffer[1] !='3' || buffer[1] != '6'){
        fprintf(stderr,"Error not correct FILE");
        exit(1);
    }
    return;
}

// ok write to the file now
void write_P3(const char* p3){
    FILE* fp = fopen(p3,"wb");
    //fwrite();
}

void write_P6(){

}

int main (int argc, char *argv[]){
    if (argc != 4){
        fprintf(stderr,"Error not correct amount of argc: \n");
        exit(1);
    }

    // each of the argv to a value
    int format = atoi(argv[1]);
/*    char *input_file = argv[2];
    char *output_file = (argv[3]);*/

    // run ppmrw
    const char *input_file = argv[2];
    ppmrw(input_file);

    if (format == '3'){
        const char *output_file = argv[3];
        write_P3(output_file);
    }
    if (format == '6'){
        write_P6();
    }

    // ok do thing before we get here

}
