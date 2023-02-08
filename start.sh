# Clean all remains of previous executions (+ old executable && gif)
make clean;

# Compile the .c and .h files
make;

# Create the images directory
mkdir images;
chmod 777 images;

# Execute the program to generate images
./GameOfLife $1 $2;

# Clear all remains
rm -f *.o;
rm GameOfLife;

# Convert images to gif
convert -delay $3 images/img-*.pbm Game.gif

# Clear images
rm images/*.pbm;
rmdir images;

# Done
echo "Done !"
echo "- filename : $1"
echo "- period : $2"
echo "- delay : $3 ms"