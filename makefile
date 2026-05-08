tetris: tetris.h dyeterm.h livein.h tetris.c
	gcc -o tetris tetris.c

gay:
	gcc -Wall -Wextra -pedantic -o tetris tetris.c

debug:
	gcc -g -O0 -o tetris tetris.c

clean:
	rm tetris