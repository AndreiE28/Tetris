#include <stdlib.h>
#include <time.h>
#include "dyeterm.h"

typedef struct cell{
    Color_256 c;
    char value;
}Cell;

typedef struct piece{
    Cell center;
    int x,y;
    char type;
    int rotation;
}Piece;

void spawnpiece(Piece *piece)
{
    int type = rand()%7;
    piece->center.value = '#';
    piece->y = 0;
    piece->x = 5;
    piece->rotation = 0;
    switch(type)
    {
        case 0:
            piece->type = 'I';
            piece->center.c = cyan_1;
            break;
        case 1:
            piece->type = 'J';
            piece->center.c = blue_1;
            break;
        case 2:
            piece->type = 'L';
            piece->center.c = dark_orange_1;
            break;
        case 3:
            piece->type = 'O';
            piece->center.c = yellow_1;
            break;
        case 4:
            piece->type = 'S';
            piece->center.c = green_1;
            break;
        case 5:
            piece->type = 'T';
            piece->center.c = dark_violet_b;
            break;
        case 6:
            piece->type = 'Z';
            piece->center.c = red_1;
            break;
    }
}

bool findpiece(int i, int j, Piece piece, Color_256 bg)
{
    switch(piece.type)
    {
        case 'I':
            switch(piece.rotation)
            {
                case 0:
                    if(((piece.x == j && piece.y == i) || (piece.x == j && piece.y == i + 1) || (piece.x == j && piece.y == i + 2) || (piece.x == j && piece.y == i + 3)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c ", piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c", piece.center.value);
                        }
                        return 1;
                    }
                    break;
                case 1:
                    if(((piece.x == j && piece.y == i) || (piece.x == j + 1 && piece.y == i) || (piece.x == j + 2 && piece.y == i) || (piece.x == j + 3 && piece.y == i)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c ", piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c", piece.center.value);
                        }
                        return 1;
                    }
                    break;
                case 2:
                    if(((piece.x == j && piece.y == i) || (piece.x == j && piece.y == i + 1) || (piece.x == j && piece.y == i + 2) || (piece.x == j && piece.y == i + 3)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c ", piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c", piece.center.value);
                        }
                        return 1;
                    }
                    break;
                case 3:
                    if(((piece.x == j && piece.y == i) || (piece.x == j + 1 && piece.y == i) || (piece.x == j + 2 && piece.y == i) || (piece.x == j + 3 && piece.y == i)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c ", piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c", piece.center.value);
                        }
                        return 1;
                    }
                    break;
            }
            break;
        case 'J':
            switch(piece.rotation)
            {
                case 0:
                    if(((piece.x == j && piece.y == i) || (piece.x == j + 1 && piece.y == i) || (piece.x == j - 1 && piece.y == i) || (piece.x == j + 1 && piece.y == i + 1)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c ", piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c", piece.center.value);
                        }
                        return 1;
                    }
                    break;
                case 1:
                    if(((piece.x == j && piece.y == i) || (piece.x == j + 1 && piece.y == i) || (piece.x == j - 1 && piece.y == i) || (piece.x == j + 1 && piece.y == i + 1)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c ", piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c", piece.center.value);
                        }
                        return 1;
                    }
                    break;
                case 2:
                    if(((piece.x == j && piece.y == i) || (piece.x == j + 1 && piece.y == i) || (piece.x == j - 1 && piece.y == i) || (piece.x == j + 1 && piece.y == i + 1)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c ", piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c", piece.center.value);
                        }
                        return 1;
                    }
                    break;
                case 3:
                    if(((piece.x == j && piece.y == i) || (piece.x == j + 1 && piece.y == i) || (piece.x == j - 1 && piece.y == i) || (piece.x == j + 1 && piece.y == i + 1)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c ", piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c", piece.center.value);
                        }
                        return 1;
                    }
                    break;
            }
            break;
        case 'L':
            switch(piece.rotation)
            {
                case 0:
                    if(((piece.x == j && piece.y == i) || (piece.x == j + 1 && piece.y == i) || (piece.x == j - 1 && piece.y == i) || (piece.x == j - 1 && piece.y == i + 1)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c ", piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c", piece.center.value);
                        }
                        return 1;
                    }
                    break;
                case 1:
                    if(((piece.x == j && piece.y == i) || (piece.x == j + 1 && piece.y == i) || (piece.x == j - 1 && piece.y == i) || (piece.x == j - 1 && piece.y == i + 1)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c ", piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c", piece.center.value);
                        }
                        return 1;
                    }
                    break;
                case 2:
                    if(((piece.x == j && piece.y == i) || (piece.x == j + 1 && piece.y == i) || (piece.x == j - 1 && piece.y == i) || (piece.x == j - 1 && piece.y == i + 1)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c ", piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c", piece.center.value);
                        }
                        return 1;
                    }
                    break;
                case 3:
                    if(((piece.x == j && piece.y == i) || (piece.x == j + 1 && piece.y == i) || (piece.x == j - 1 && piece.y == i) || (piece.x == j - 1 && piece.y == i + 1)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c ", piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c", piece.center.value);
                        }
                        return 1;
                    }
                    break;
            }
            break;
        case 'O':
            if(((piece.x == j && piece.y == i) || (piece.x == j - 1 && piece.y == i) || (piece.x == j - 1 && piece.y == i + 1) || (piece.x == j && piece.y == i + 1)))
            {
                if(j != 9)
                {
                    color_on_bg_256(piece.center.c, bg);
                    printf("%c ", piece.center.value);
                }
                else
                {
                    color_on_bg_256(piece.center.c, bg);
                    printf("%c", piece.center.value);
                }
                
                return 1;
            }
            break;
        case 'S':
            switch(piece.rotation)
            {
                case 0:
                    if(((piece.x == j && piece.y == i) || (piece.x == j + 1 && piece.y == i) || (piece.x == j - 1 && piece.y == i + 1) || (piece.x == j && piece.y == i + 1)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c ", piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c", piece.center.value);
                        }
                        return 1;
                    }
                    break;
                case 1:
                    if(((piece.x == j && piece.y == i) || (piece.x == j + 1 && piece.y == i) || (piece.x == j - 1 && piece.y == i + 1) || (piece.x == j && piece.y == i + 1)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c ", piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c", piece.center.value);
                        }
                        return 1;
                    }
                    break;
                case 2:
                    if(((piece.x == j && piece.y == i) || (piece.x == j + 1 && piece.y == i) || (piece.x == j - 1 && piece.y == i + 1) || (piece.x == j && piece.y == i + 1)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c ", piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c", piece.center.value);
                        }
                        return 1;
                    }
                    break;
                case 3:
                    if(((piece.x == j && piece.y == i) || (piece.x == j + 1 && piece.y == i) || (piece.x == j - 1 && piece.y == i + 1) || (piece.x == j && piece.y == i + 1)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c ", piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c", piece.center.value);
                        }
                        return 1;
                    }
                    break;
            }
            break;
        case 'T':
            switch(piece.rotation)
            {
                case 0:
                    if(((piece.x == j && piece.y == i) || (piece.x == j + 1 && piece.y == i) || (piece.x == j - 1 && piece.y == i) || (piece.x == j && piece.y == i + 1)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c ", piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c", piece.center.value);
                        }
                        return 1;
                    }
                    break;
                case 1:
                    if(((piece.x == j && piece.y == i) || (piece.x == j && piece.y == i + 1) || (piece.x == j - 1 && piece.y == i + 1) || (piece.x == j && piece.y == i + 2)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c ", piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c", piece.center.value);
                        }
                        return 1;
                    }
                    break;
                case 2:
                    if(((piece.x == j && piece.y == i) || (piece.x == j + 1 && piece.y == i + 1) || (piece.x == j - 1 && piece.y == i + 1) || (piece.x == j && piece.y == i + 1)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c ", piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c", piece.center.value);
                        }
                        return 1;
                    }
                    break;
                case 3:
                    if(((piece.x == j && piece.y == i) || (piece.x == j && piece.y == i + 1) || (piece.x == j + 1 && piece.y == i + 1) || (piece.x == j && piece.y == i + 2)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c ", piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c", piece.center.value);
                        }
                        return 1;
                    }
                    break;
            }
            break;
        case 'Z':
            switch(piece.rotation)
            {
                case 0:
                    if(((piece.x == j && piece.y == i) || (piece.x == j + 1 && piece.y == i + 1) || (piece.x == j - 1 && piece.y == i) || (piece.x == j && piece.y == i + 1)) )
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c ", piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c", piece.center.value);
                        }
                        return 1;
                    }
                    break;
                case 1:
                    if(((piece.x == j && piece.y == i) || (piece.x == j + 1 && piece.y == i + 1) || (piece.x == j - 1 && piece.y == i) || (piece.x == j && piece.y == i + 1)) )
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c ", piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c", piece.center.value);
                        }
                        return 1;
                    }
                    break;
                case 2:
                    if(((piece.x == j && piece.y == i) || (piece.x == j + 1 && piece.y == i + 1) || (piece.x == j - 1 && piece.y == i) || (piece.x == j && piece.y == i + 1)) )
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c ", piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c", piece.center.value);
                        }
                        return 1;
                    }
                    break;
                case 3:
                    if(((piece.x == j && piece.y == i) || (piece.x == j + 1 && piece.y == i + 1) || (piece.x == j - 1 && piece.y == i) || (piece.x == j && piece.y == i + 1)) )
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c ", piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(piece.center.c, bg);
                            printf("%c", piece.center.value);
                        }
                        return 1;
                    }
                    break;
            }
            break;
    }
    return 0;
}

void printgrid(Cell grid[20][10], Piece piece, Color_256 bg, int offset)
{
    bool ok = 1;
    for(int k = 0; k <= 4; k++)
    {
        printf("\n");
    }
    for(int i = 0; i < 20; i++)
    {
        for(int k = 0; k < offset; k++)
            printf("\t");
        for(int j = 0; j < 10; j++)
        {
            ok = !findpiece(i, j, piece, bg);
            if(ok)
            {
                if(j != 9)
                {
                    color_on_bg_256(grid[i][j].c, bg);
                    printf("%c ", grid[i][j].value);
                }
                else
                {
                    color_on_bg_256(grid[i][j].c, bg);
                    printf("%c", grid[i][j].value);
                }
            }
        }
        setcolor(reset);
        printf("\n");
    }
}

void emptygrid(Cell grid[20][10])
{
    for(int i = 0; i < 20; i++)
        for(int j = 0; j < 10; j++)
        {
            grid[i][j].value = '0';
            grid[i][j].c = white_256;
        }
}

bool checkcollision(Cell grid[20][10], Piece piece, int counter)
{
    switch(piece.type)
    {
        case 'I':
            switch(piece.rotation)
            {
                case 0:
                    if(piece.y == 19 || grid[piece.y+1][piece.x].value == '#')
                    {
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y-1][piece.x] = piece.center;
                        grid[piece.y-2][piece.x] = piece.center;
                        grid[piece.y-3][piece.x] = piece.center;
                        return 1;
                    }
                    break;
                case 1:
                    if(piece.y == 19 || grid[piece.y+1][piece.x].value == '#')
                    {
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        return 1;
                    }
                    break;
                case 2:
                    if(piece.y == 19 || grid[piece.y+1][piece.x].value == '#')
                    {
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        return 1;
                    }
                    break;
                case 3:
                    if(piece.y == 19 || grid[piece.y+1][piece.x].value == '#')
                    {
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        return 1;
                    }
                    break;
            }
            break;
        case 'J':
            switch(piece.rotation)
            {
                case 0:
                    if(piece.y == 19 || grid[piece.y+1][piece.x].value == '#' || grid[piece.y+1][piece.x-1].value == '#' || grid[piece.y+1][piece.x+1].value == '#')
                    {
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x-1] = piece.center;
                        grid[piece.y][piece.x+1] = piece.center;
                        grid[piece.y-1][piece.x-1] = piece.center;
                        return 1;
                    }
                    break;
                case 1:
                    if(piece.y == 19 || grid[piece.y+1][piece.x].value == '#')
                    {
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        return 1;
                    }
                    break;
                case 2:
                    if(piece.y == 19 || grid[piece.y+1][piece.x].value == '#')
                    {
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        return 1;
                    }
                    break;
                case 3:
                    if(piece.y == 19 || grid[piece.y+1][piece.x].value == '#')
                    {
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        return 1;
                    }
                    break;
            }
            break;
        case 'L':
            switch(piece.rotation)
            {
                case 0:
                    if(piece.y == 19 || grid[piece.y+1][piece.x].value == '#' || grid[piece.y+1][piece.x-1].value == '#' || grid[piece.y+1][piece.x+1].value == '#')
                    {
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x-1] = piece.center;
                        grid[piece.y][piece.x+1] = piece.center;
                        grid[piece.y-1][piece.x+1] = piece.center;
                        return 1;
                    }
                    break;
                case 1:
                    if(piece.y == 19 || grid[piece.y+1][piece.x].value == '#')
                    {
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        return 1;
                    }
                    break;
                case 2:
                    if(piece.y == 19 || grid[piece.y+1][piece.x].value == '#')
                    {
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        return 1;
                    }
                    break;
                case 3:
                    if(piece.y == 19 || grid[piece.y+1][piece.x].value == '#')
                    {
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        return 1;
                    }
                    break;
            }
            break;
        case 'O':
            if(piece.y == 19 || grid[piece.y+1][piece.x].value == '#' || grid[piece.y+1][piece.x+1].value == '#')
            {
                grid[piece.y][piece.x] = piece.center;
                grid[piece.y][piece.x+1] = piece.center;
                grid[piece.y-1][piece.x+1] = piece.center;
                grid[piece.y-1][piece.x] = piece.center;
                return 1;
            }
            break;
        case 'S':
            switch(piece.rotation)
            {
                case 0:
                    if(piece.y == 19 || grid[piece.y+1][piece.x].value == '#' || grid[piece.y+1][piece.x-1].value == '#' || grid[piece.y][piece.x+1].value == '#')
                    {
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x-1] = piece.center;
                        grid[piece.y-1][piece.x+1] = piece.center;
                        grid[piece.y-1][piece.x] = piece.center;
                        return 1;
                    }
                    break;
                case 1:
                    if(piece.y == 19 || grid[piece.y+1][piece.x].value == '#')
                    {
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        return 1;
                    }
                    break;
                case 2:
                    if(piece.y == 19 || grid[piece.y+1][piece.x].value == '#')
                    {
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        return 1;
                    }
                    break;
                case 3:
                    if(piece.y == 19 || grid[piece.y+1][piece.x].value == '#')
                    {
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        return 1;
                    }
                    break;
            }
            break;
        case 'T':
            switch(piece.rotation)
            {
                case 0:
                    if(piece.y == 19 || grid[piece.y+1][piece.x].value == '#' || grid[piece.y+1][piece.x-1].value == '#' || grid[piece.y+1][piece.x+1].value == '#')
                        if(counter % 300 == 0)
                        {
                            grid[piece.y][piece.x] = piece.center;
                            grid[piece.y][piece.x-1] = piece.center;
                            grid[piece.y][piece.x+1] = piece.center;
                            grid[piece.y-1][piece.x] = piece.center;
                            return 1;
                        }
                    break;
                case 1:
                    if(piece.y == 19 || grid[piece.y+1][piece.x].value == '#' || grid[piece.y-1][piece.x+1].value == '#')
                        if(counter % 500 == 0)
                        {
                            grid[piece.y][piece.x] = piece.center;
                            grid[piece.y-1][piece.x] = piece.center;
                            grid[piece.y-1][piece.x+1] = piece.center;
                            grid[piece.y-2][piece.x] = piece.center;
                            return 1;
                        }
                    break;
                case 2:
                    if(piece.y == 19 || grid[piece.y+1][piece.x].value == '#' || grid[piece.y][piece.x-1].value == '#' || grid[piece.y][piece.x+1].value == '#')
                        if(counter % 500 == 0)
                        {
                            grid[piece.y][piece.x] = piece.center;
                            grid[piece.y-1][piece.x-1] = piece.center;
                            grid[piece.y-1][piece.x+1] = piece.center;
                            grid[piece.y-1][piece.x] = piece.center;
                            return 1;
                        }
                    break;
                case 3:
                    if(piece.y == 19 || grid[piece.y+1][piece.x].value == '#' || grid[piece.y-1][piece.x-1].value == '#')
                        if(counter % 500 == 0)
                        {
                            grid[piece.y][piece.x] = piece.center;
                            grid[piece.y-1][piece.x] = piece.center;
                            grid[piece.y-1][piece.x-1] = piece.center;
                            grid[piece.y-2][piece.x] = piece.center;
                            return 1;
                        }
                    break;
            }
            break;
        case 'Z':
            switch(piece.rotation)
            {
                case 0:
                    if(piece.y == 19 || grid[piece.y+1][piece.x].value == '#' || grid[piece.y+1][piece.x+1].value == '#' || grid[piece.y][piece.x-1].value == '#')
                    {
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y-1][piece.x-1] = piece.center;
                        grid[piece.y][piece.x+1] = piece.center;
                        grid[piece.y-1][piece.x] = piece.center;
                        return 1;
                    }
                    break;
                case 1:
                    if(piece.y == 19 || grid[piece.y+1][piece.x].value == '#')
                    {
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        return 1;
                    }
                    break;
                case 2:
                    if(piece.y == 19 || grid[piece.y+1][piece.x].value == '#')
                    {
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        return 1;
                    }
                    break;
                case 3:
                    if(piece.y == 19 || grid[piece.y+1][piece.x].value == '#')
                    {
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        grid[piece.y][piece.x] = piece.center;
                        return 1;
                    }
                    break;
            }
            break;
    }
    return 0;
}

void clear_screen()
{
    printf("\033[H\033[2J");
}

void reset_cursor()
{
    printf("\033[H");
}

void show_cursor()
{
    printf("\033[?25h");
}

void hide_cursor()
{
    printf("\033[?25l");
}

void quit()
{
    disableRawMode();
    clear_screen();
    reset_cursor();
    show_cursor();
    setcolor(reset);
    exit(1);
}