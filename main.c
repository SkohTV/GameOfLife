#include "code/game.h"
#include "code/images.h"


int main(int argc, char *argv[]) {
    printf("\n\n\n");

    printf("Hello World!\n");

    // Base data, will be made changeable later on
    int width = 0;
    int height = 0;
    FILE * myfile = fopen("start/test.pbm", "r");
    
    // Check if file exists
    if (myfile == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    char * line = NULL; // Buffer
    size_t len = 0; // Buffer size
    getline(&line, &len, myfile); // We don't care about first line (magic number)
    getline(&line, &len, myfile); // We care about second line (width and height)
    sscanf(line,"%d %d", &width, &height);

    free(line);

    // Third to the end will be the image data
    char tmp;
    unsigned char * pixels = (unsigned char *)malloc(width * height * sizeof(unsigned char));
    int count = 0;
        while (tmp != EOF){
            tmp = fgetc(myfile);
            if (tmp == '1' || tmp == '0')
                pixels[count] = (unsigned char)tmp;
                count++;
        }

    for (int i = 0; i < width * height; i++) {
        printf("%c", (char)pixels[i]);
    }

    free(pixels);


    // Close file
    fclose(myfile);

    return EXIT_SUCCESS;
}