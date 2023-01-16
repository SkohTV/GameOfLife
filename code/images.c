#include "images.h"



image_PBM init_PBM(unsigned char *pixels, int *width, int *height) {
    image_PBM image;

    if (pixels == NULL) {
        FILE * myfile = fopen(DEMOFILE, "r"); // REMOVE LATER

        // Check if file exists
        if (myfile == NULL) {
            printf("Error opening file!\n");
            exit(1);
        }

        char * line = NULL; // Buffer
        size_t len = 0; // Buffer size
        getline(&line, &len, myfile); // We don't care about first line (magic number)
        getline(&line, &len, myfile); // We care about second line (width and height)
        sscanf(line,"%d %d", width, height);
        image.width = *width;
        image.height = *height;
        image.pixels = (unsigned char *)malloc((*width) * (*height) * sizeof(unsigned char));

        // Third to the end will be the image data
        char tmp = ' ';
        int count = 0;
        while (tmp != EOF){
            tmp = fgetc(myfile);
            if (tmp == '1') {
                image.pixels[count] = 1;
                count++;
            }
            else if (tmp == '0') {
                image.pixels[count] = 0;
                count++;
            }
        }
        printf("\n");
        free(line);
        fclose(myfile); // Close file

    }
    else {
        image.width = *width;
        image.height = *height;
        image.pixels = (unsigned char *)malloc((*width) * (*height) * sizeof(unsigned char));
        for (int i = 0; i < (*width) * (*height); i++) {
            image.pixels[i] = pixels[i];
        }
    }

    return image;
}

void show_PBM(const image_PBM* image) {
    for (int i = 0; i < image->width * image->height; i++) {
        printf("%c", (image->pixels[i] == 0 ? ':' : 'X'));
        if ((i + 1) % image->width == 0) {
            printf("\n");
        }
    }
}


unsigned char get(const image_PBM* image, int i, int j) {
    return image->pixels[i * image->width + j];
}


void set (image_PBM* image, int i, int j, unsigned char valeur) {
    image->pixels[i * image->width + j] = valeur;
}


image_PBM copy_PBM(const image_PBM* image) {
    image_PBM newImage;
    newImage.width = image->width;
    newImage.height = image->height;
    newImage.pixels = (unsigned char *)malloc(image->width * image->height * sizeof(unsigned char));

    for (int i = 0; i < image->width * image->height; i++) {
        newImage.pixels[i] = image->pixels[i];
    }

    return newImage;
}


int write_pbm(const char* filename, const image_PBM* image) {
    FILE * myfile = fopen(filename, "w");

    // Check if file exists
    if (myfile == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("We arrive here %s\n", filename);
    fprintf(myfile, "P1\n%d %d\n", image->width, image->height); // ! PROBLEME HERE
    printf("We arrive here %s\n", filename);

    // Loop to write each pixel
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            fprintf(myfile, "%d ", image->pixels[i*image->width + j]);
        }
        fprintf(myfile, "\n");
    }
    
    fclose(myfile);
    return EXIT_SUCCESS;
}