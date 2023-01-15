GameOfLife: game.o images.o main.c
	gcc $^ -o $@ -lm

game.o: code/game.c code/game.h
	gcc -Wall -c $< -o $@ -lm

images.o: code/images.c code/images.h
	gcc -Wall -c $< -o $@ -lm

clean:
	rm -f *.o GameOfLife | rm images/*.pbm

soft:
	rm -f *.o | rm images/*.pbm

create:
	./script.sh