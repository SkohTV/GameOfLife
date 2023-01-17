#include "code/game.h"
#include "code/images.h"


int main(int argc, char *argv[]) {
    // printf("\n\n\n");

    printf("Generating images...\n");

    // Base data, will be made changeable later on
    int width = 0;
    int height = 0;

    // unsigned char * pixe = (unsigned char *)malloc(width * height * sizeof(unsigned char));
    // for (int i = 0; i < width * height; i++) {
    //     pixe[i] = 0;
    //     // pixe[i] = (unsigned char)'0';
    // }




// unsigned char glider[100] = {
//  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//  0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
//  0, 1, 0, 1, 0, 0, 0, 0, 0, 0,
//  0, 0, 1, 1, 0, 0, 0, 0, 0, 0,
//  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//  0, 0, 0, 0, 0, 0, 0, 0, 0, 0
// };

// for (int i = 0; i < width * height; i++) {
//     printf("%c", (char)glider[i]);


    // printf("%d\n", get(&image, 5, 5));

    image_PBM image = init_PBM(NULL, &width, &height);
    // image_PBM newImage = copy_PBM(&image);
    // set(&newImage, 5, 5, 1);


    // clearScreen();

    int turn = 100000;
    char filename[30] = "";


    for (int i = 0; i < MAX_TURNS; i++) {
        snprintf(filename, 30, "images/img-%d.pbm", turn); 
        turn++;

        // printf("%s\n", filename);
        write_pbm(filename , &image);
        // show_PBM(&image);

        // printf("\n");
        // printf("Image %d generated\n", i+1);
        lifeCycle(&image);

    }

    // Free and clear
    free(image.pixels);

    printf("Done !\n");
    return EXIT_SUCCESS;
}