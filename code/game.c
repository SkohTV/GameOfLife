#include "game.h"





void lifeCycle(image_PBM* generation) {
    image_PBM nextGen = copy_PBM(generation);
    for (int i = 0; i < generation->height * generation->width; i++) {
        /* Adjacents cells will be :
        H-1 & W-1 | H-1 & W | H-1 & W+1
        H & W-1   |         | H & W+1
        H+1 & W-1 | H+1 & W | H+1 & W+1
    
        To get W & H :
        H = i/10 (17/10 = 1)
        W = i%10 (17%10 = 7)
        */
        int H = i/10;
        int W = i%10;


        int friends = {
            isValid(generation, H-1, W-1) +
            isValid(generation, H,  W-1) +
            isValid(generation, H+1, W-1) +

            isValid(generation, H-1, W) +
            isValid(generation, H+1, W) +

            isValid(generation, H-1, W+1) +
            isValid(generation, H, W+1) +
            isValid(generation, H+1, W+1)
        };


        if (get(generation,H,W) == 0) {
            if (friends == 3) {
                set(&nextGen,H,W, 1);
            }
        }
        else { // else : generation,H,W == 1
            if (!(friends == 2 || friends == 3)) {
                set(&nextGen,H,W, 0);
            }
        }
    }

    printf("%d %d, %d", generation->height, generation->width, generation->height * generation->width);

    show_PBM(&nextGen);
    for (int i = 0; i < generation->width * generation->height; i++) {
        generation->pixels[i] = nextGen.pixels[i];
    }
    // for (int i = 0; i < generation->width * generation->height; i++) {
    //     printf("%d", generation->pixels[i]);
    // }
    free(nextGen.pixels);
}


// IF everything is valid, return get(cell), else return 0
int isValid(const image_PBM* image, const int H, const int W) {
    if ((W < 0) || (W > image->width-1) || (H < 0) || (H > image->height-1)) {
        return 0;
    }
    return get(image, H, W);
}



void clearScreen () {
    // printf ("\x1b[2J");
    // printf ("\e[1;1H\e[2J");
    // printf ("\n");
    system("clear");
}

void clearImgs () {
    system("rm images/*.pbm");
}