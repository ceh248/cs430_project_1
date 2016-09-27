
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


void ppmrw(const char* ppmin,const char* ppmout, int format){
    FILE* fp= fopen(ppmin,"rb");

    fseek(fp,0L,SEEK_END);
    rewind(fp);

    char *std = malloc(sizeof(fp));
    //char buffer[] = malloc(sizeof(fp));
    int c = fgetc(fp);
    int i = 0;
    std[i] = 0;
    while (c != EOF){
        if(c == '\n'){
            c = fgetc(fp);
        }else if(isspace(c)){
            c = fgetc(fp);
        } else if(c == '#'){
            // need to skip a line
            c = fgetc(fp);
        } else{
            std[i] = c;
            c = fgetc(fp);
            i+=1;
        }
    }

    if (format == 3){
        //char* take_along = std;
        write_P3(ppmout,std);
    }
    if (format == 6){
        write_P6(ppmout,std);
    }
    return;
}

// ok write to the file in p6 format right now.
void write_P3(const char* p3, char* take_along){
    FILE* fp = fopen(p3,"wb");
    //char *std = malloc(sizeof(take_along));
    //fwrite(take_along,sizeof(take_along),sizeof(take_along),fp);

    //fclose(fp);
    return;
}
// write to the file in p6 format
void write_P6(const char* p6, char*take_along){
    FILE* fp = fopen(p6,"wb");
    //char *std = malloc(sizeof(take_along));
    fwrite(take_along,sizeof(take_along),sizeof(take_along),fp);
    return;
}

int main (int argc, char *argv[]){
    if (argc != 4){
        fprintf(stderr,"Error not correct amount of argc: \n");
        exit(1);
    }

    // each of the argv to a value
    int format = atoi(argv[1]);

    // run ppmrw
    const char *input_file = argv[2];
    const char *output_file = argv[3];
    ppmrw(input_file,output_file,format);

}
