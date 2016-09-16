//
// Created by chooker on 9/16/16.
//
#include <stdlib.h>
#include <stdio.h>

typedef struct PPM_Pixel {
    unsigned char red,green,blue;
} PPM_Pixel;

typedef struct PPM_Image{
    int x, y;
    PPM_Pixel *data;
} PPM_Image;

#define RGB_Coloring 255

// reader file
static PPM_Image read_PPM_header(char *input){
    unsigned char buff[16];
    PPM_Image *img;
    int ch, rgb_comp_color;
    FILE *fb;
    fb = fopen(input,"rb");

    if (!fb){
        fprintf(stderr, "Unable to open file '%s'\n",input);
        exit(1);
    }
    if (!fgets(buff, sizeof(buff), fb)) {
        perror(input);
        exit(1);
    }
    // error checking the header file for p3
    if (buff[0] !='P' || buff[1] != '3'){
        fprintf(stderr, "Invlid input image format");
        exit(1);
    }
    // error checking the header file for p6
    if (buff[0] !='P' || buff[1] != '6'){
        fprintf(stderr, "Invlid input image format");
        exit(1);
    }
    img = (PPM_Image *)malloc(sizeof(PPM_Image));
    if (!img) {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }

    //check for comments
    ch = getc(fb);
    while (ch == '#') {
        while (getc(fb) != '\n') ;
        ch = getc(fb);
    }

    ungetc(ch, fb);
    //read image size information
    if (fscanf(fb, "%d %d", &img->x, &img->y) != 2) {
        fprintf(stderr, "Invalid image size (error loading '%s')\n", input);
        exit(1);
    }

    //read rgb component
    if (fscanf(fb, "%d", &rgb_comp_color) != 1) {
        fprintf(stderr, "Invalid rgb component (error loading '%s')\n", input);
        exit(1);
    }

    //check rgb component depth
    if (rgb_comp_color!= RGB_Coloring) {
        fprintf(stderr, "'%s' does not have 8-bits components\n", input);
        exit(1);
    }

    while (fgetc(fb) != '\n') ;
    //memory allocation for pixel data
    img->data = (PPM_Pixel*)malloc(img->x * img->y * sizeof(PPM_Pixel));



    //read pixel data from file
    if (fread(img->data, 3 * img->x, img->y, fb) != img->y) {
        fprintf(stderr, "Error loading image '%s'\n", input);
        exit(1);
    }

    fclose(fb);
    return *img;

}

