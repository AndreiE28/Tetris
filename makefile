tetris: tetris.h dyeterm.h livein.h tetris.c
	gcc -o tetris tetris.c -lm

debug:
	gcc -g -O0 -o tetris tetris.c -lm

clean:
	rm tetris

run:
	make
	./tetris