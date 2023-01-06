#include "images.h"



image_PBM init_PBM(unsigned char *pixels, int width, int height) {
    image_PBM image;
    image.width = width;
    image.height = height;
    image.pixel = (unsigned char *)malloc(width * height * sizeof(unsigned char));
    for (int i = 0; i < width * height; i++) {
        image.pixel[i] = pixels[i];
    }
    return image;
}