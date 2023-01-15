// Define for safety
#ifndef GAME_H
#define GAME_H

// Includes & Defines
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "images.h"


// Functionns
/**
 * @brief 
 * 
 * @param generation
 */
void lifeCycle(image_PBM* generation);

/**
 * @brief 
 * 
 * @param image 
 * @param V 
 * @param H 
 */
int isValid(const image_PBM* image, const int W, const int H);

/**
 * @brief 
 * 
 */
void clearScreen ();

/**
 * @brief 
 * 
 */
void clearImgs ();


// Close safety define
#endif