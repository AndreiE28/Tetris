#include "livein.h"
#include "tetris.h"

void menu()
{
    char in;
    while(1)
    {
        reset_cursor();
        for(int k = 0; k <= 4; k++)
        {
            printf("\n");
        }
        printf("\t\t\t\t  #######  #####  #######  #####   #####  #####   \n");
        printf("\t\t\t\t     #     #         #     #   #     #    #       \n");
        printf("\t\t\t\t     #     ####      #     ####      #    #####   \n");
        printf("\t\t\t\t     #     #         #     #   #     #        #   \n");
        printf("\t\t\t\t     #     #####     #     #    #  #####  #####   \n");
        printf("\n\n");
        printf("\t\t\t\t\t\tPress SPACE to Start");
        in = input();
        if(in == ' ')
            break;
        if(in == 'q')
            quit();
        usleep(100000);
    }
    clear_screen();
}

void game(Cell grid[20][10])
{
    Piece piece;
    Color_256 bg = navy_blue;
    int counter = 0;
    bool spawn = 1;
    char in;
    while(1)
    {
        reset_cursor();
        printgrid(grid, piece,  bg, 6);
        fflush(stdout);
        if(spawn)
        {
            spawnpiece(&piece);
            spawn = 0;
        }
        in = input();
        if(in == 'q')
            quit();
        if(in == 'a')
            switch(piece.type)
            {
                case 'I':
                    switch(piece.rotation)
                    {
                        case 0:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x--;
                            break;
                        case 1:
                            if(piece.x > 3 && piece.x < 10)
                                piece.x--;
                            break;
                        case 2:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x--;
                            break;
                        case 3:
                            if(piece.x > 3 && piece.x < 10)
                                piece.x--;
                            break;
                    }
                    break;
                case 'J':
                    switch(piece.rotation)
                    {
                        case 0:
                            if(piece.x > 1 && piece.x < 10)
                                piece.x--;
                            break;
                        case 1:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x--;
                            break;
                        case 2:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x--;
                            break;
                        case 3:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x--;
                            break;
                    }
                    break;
                case 'L':
                    switch(piece.rotation)
                    {
                        case 0:
                            if(piece.x > 1 && piece.x < 10)
                                piece.x--;
                            break;
                        case 1:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x--;
                            break;
                        case 2:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x--;
                            break;
                        case 3:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x--;
                            break;
                    }
                    break;
                case 'O':
                    if(piece.x > 0 && piece.x < 10)
                        piece.x--;
                    break;
                case 'S':
                    switch(piece.rotation)
                    {
                        case 0:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x--;
                            break;
                        case 1:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x--;
                            break;
                        case 2:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x--;
                            break;
                        case 3:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x--;
                            break;
                    }
                    break;
                case 'T':
                    switch(piece.rotation)
                    {
                        case 0:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x--;
                            break;
                        case 1:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x--;
                            break;
                        case 2:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x--;
                            break;
                        case 3:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x--;
                            break;
                    }
                    break;
                case 'Z':
                    switch(piece.rotation)
                    {
                        case 0:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x--;
                            break;
                        case 1:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x--;
                            break;
                        case 2:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x--;
                            break;
                        case 3:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x--;
                            break;
                    }
                    break;
            }
        if(in == 'd' && piece.x >= 0 && piece.x < 9)
            switch(piece.type)
            {
                case 'I':
                    switch(piece.rotation)
                    {
                        case 0:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x++;
                            break;
                        case 1:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x++;
                            break;
                        case 2:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x++;
                            break;
                        case 3:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x++;
                            break;
                    }
                    break;
                case 'J':
                    switch(piece.rotation)
                    {
                        case 0:
                            if(piece.x > 0 && piece.x < 8)
                                piece.x++;
                            break;
                        case 1:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x++;
                            break;
                        case 2:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x++;
                            break;
                        case 3:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x++;
                            break;
                    }
                    break;
                case 'L':
                    switch(piece.rotation)
                    {
                        case 0:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x++;
                            break;
                        case 1:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x++;
                            break;
                        case 2:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x++;
                            break;
                        case 3:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x++;
                            break;
                    }
                    break;
                case 'O':
                    if(piece.x > 0 && piece.x < 10)
                        piece.x++;
                    break;
                case 'S':
                    switch(piece.rotation)
                    {
                        case 0:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x++;
                            break;
                        case 1:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x++;
                            break;
                        case 2:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x++;
                            break;
                        case 3:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x++;
                            break;
                    }
                    break;
                case 'T':
                    switch(piece.rotation)
                    {
                        case 0:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x++;
                            break;
                        case 1:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x++;
                            break;
                        case 2:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x++;
                            break;
                        case 3:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x++;
                            break;
                    }
                    break;
                case 'Z':
                    switch(piece.rotation)
                    {
                        case 0:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x++;
                            break;
                        case 1:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x++;
                            break;
                        case 2:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x++;
                            break;
                        case 3:
                            if(piece.x > 0 && piece.x < 10)
                                piece.x++;
                            break;
                    }
                    break;
            }
        if(in == 'w')
            piece.rotation = (piece.rotation + 1) % 4;
        if(in == 's')
        {
            if(piece.y < 19 && counter % 5 == 0)
            {
                piece.y++;
            }
        }
        else
        {
            if(piece.y < 19 && counter % 50 == 0)
            {
                piece.y++;
            }
        }
        if(checkcollision(grid, piece, counter))
            spawn = 1;
        counter++;
        usleep(16666);
    }
}

int main()
{
    Cell grid[20][10];
    enableRawMode();
    srand(time(0));
    emptygrid(grid);
    hide_cursor();
    clear_screen();
    menu();
    game(grid);
    color_on_bg(0, 0);
    return 0;
}