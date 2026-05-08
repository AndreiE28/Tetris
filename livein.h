#include <stdio.h>
#include <termios.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

struct termios og_term;

void disableRawMode()
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &og_term);
}

void enableRawMode()
{
    tcgetattr(STDIN_FILENO, &og_term);
    struct termios raw = og_term;
    raw.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
}

char input()
{
    char in;
    if(read(STDIN_FILENO, &in, 1) == 1)
    {
        fflush(stdout);
        return in;
    }
    return 0;
}