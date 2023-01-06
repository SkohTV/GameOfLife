// Define for safety
#ifndef IMAGES_H
#define IMAGES_H

// Includes & Defines
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structs & Enums
typedef struct _image_PBM {
    int width;
    int height;
    unsigned char * pixel;
} image_PBM;


// Functions
/**
 * @brief 
 * 
 * @param pixels 
 * @param width 
 * @param height 
 * @return image_PBM 
 */
image_PBM init_PBM(unsigned char *pixels, int width, int height);




// Close safety define
#endif