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
    unsigned char * pixels;
} image_PBM;


// Functions
/**
 * @brief Create grid item from NULL or pixels array
 * 
 * @param pixels 
 * @param width 
 * @param height 
 * @return image_PBM 
 */
image_PBM init_PBM(unsigned char *pixels, int width, int height);

/**
 * @brief Show grid
 * 
 * @param image 
 */
void show_PBM(const image_PBM* image);

/**
 * @brief Get value of cell
 * 
 * @param image 
 * @param i 
 * @param j 
 * @return unsigned char 
 */
unsigned char get(const image_PBM* image, int i, int j);

/**
 * @brief Set value of cell
 * 
 * @param image 
 * @param i 
 * @param j 
 * @param valeur
 */
void set (image_PBM* image, int i, int j, unsigned char valeur);

/**
 * @brief Copy grid to a new one
 * 
 * @param image 
 * @return image_PBM 
 */
image_PBM copy_PBM(const image_PBM* image);

/**
 * @brief 
 * 
 * @param generation
 */
void lifeCycle(image_PBM* generation);



// Close safety define
#endif