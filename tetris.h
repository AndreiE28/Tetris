#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <signal.h>
#include "dyeterm.h"
#include "livein.h"
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"

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

ma_engine audio_engine;
ma_sound bg_music;

char input_handler() 
{
    char in = input();
    if (in == '\033') {
        char nxt1,nxt2;
        nxt1 = input();
        if (nxt1 == '[') {
            nxt2 = input();
            switch(nxt2){
                case 'A':
                    return 'w';
                    break;
                case 'B':
                    return 's';
                    break;
                case 'C':
                    return 'd';
                    break;
                case 'D':
                    return 'a';
                    break;
            }
             
        }
    }
    return in;
}

void fill_bag(int bag[7])
{
    for(int i = 0; i < 7; i++){
        bag[i] = rand()%7;
        for(int j = 0; j < i; j++){
            while(bag[j] == bag[i]){
                bag[i] = rand()%7;
                j = 0;
            }
        }
    }
}

void spawnpiece(Piece *piece, int bag[7], int *current_piece)
{
    if(*current_piece == 7){
        *current_piece = 0;
        fill_bag(bag);
    }
    int type = bag[*current_piece];
    piece->center.value = '#';
    piece->rotation = 0;
    piece->x = 1;
    piece->y = 2;
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

bool findpiece(Cell grid[25][10], int i, int j, Piece piece, Piece ghost_piece, Color_256 bg)
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
                    if(((ghost_piece.x == j && ghost_piece.y == i) || (ghost_piece.x == j && ghost_piece.y == i + 1) || (ghost_piece.x == j && ghost_piece.y == i + 2) || (ghost_piece.x == j && ghost_piece.y == i + 3)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c ", ghost_piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c", ghost_piece.center.value);
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
                    if(((ghost_piece.x == j && ghost_piece.y == i) || (ghost_piece.x == j + 1 && ghost_piece.y == i) || (ghost_piece.x == j + 2 && ghost_piece.y == i) || (ghost_piece.x == j + 3 && ghost_piece.y == i)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c ", ghost_piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c", ghost_piece.center.value);
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
                    if(((ghost_piece.x == j && ghost_piece.y == i) || (ghost_piece.x == j && ghost_piece.y == i + 1) || (ghost_piece.x == j && ghost_piece.y == i + 2) || (ghost_piece.x == j && ghost_piece.y == i + 3)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c ", ghost_piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c", ghost_piece.center.value);
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
                    if(((ghost_piece.x == j && ghost_piece.y == i) || (ghost_piece.x == j + 1 && ghost_piece.y == i) || (ghost_piece.x == j + 2 && ghost_piece.y == i) || (ghost_piece.x == j + 3 && ghost_piece.y == i)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c ", ghost_piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c", ghost_piece.center.value);
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
                    if(((ghost_piece.x == j && ghost_piece.y == i) || (ghost_piece.x == j + 1 && ghost_piece.y == i) || (ghost_piece.x == j - 1 && ghost_piece.y == i) || (ghost_piece.x == j + 1 && ghost_piece.y == i + 1)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c ", ghost_piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c", ghost_piece.center.value);
                        }
                        return 1;
                    }
                    break;
                case 1:
                    if(((piece.x == j && piece.y == i) || (piece.x == j && piece.y == i + 1) || (piece.x == j && piece.y == i + 2) || (piece.x == j - 1 && piece.y == i + 2)))
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
                    if(((ghost_piece.x == j && ghost_piece.y == i) || (ghost_piece.x == j && ghost_piece.y == i + 1) || (ghost_piece.x == j && ghost_piece.y == i + 2) || (ghost_piece.x == j - 1 && ghost_piece.y == i + 2)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c ", ghost_piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c", ghost_piece.center.value);
                        }
                        return 1;
                    }
                    break;
                case 2:
                    if(((piece.x == j && piece.y == i) || (piece.x == j && piece.y == i + 1) || (piece.x == j + 1 && piece.y == i + 1) || (piece.x == j + 2 && piece.y == i + 1)))
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
                    if(((ghost_piece.x == j && ghost_piece.y == i) || (ghost_piece.x == j && ghost_piece.y == i + 1) || (ghost_piece.x == j + 1 && ghost_piece.y == i + 1) || (ghost_piece.x == j + 2 && ghost_piece.y == i + 1)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c ", ghost_piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c", ghost_piece.center.value);
                        }
                        return 1;
                    }
                    break;
                case 3:
                    if(((piece.x == j && piece.y == i) || (piece.x == j + 1 && piece.y == i) || (piece.x == j && piece.y == i + 1) || (piece.x == j && piece.y == i + 2)))
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
                    if(((ghost_piece.x == j && ghost_piece.y == i) || (ghost_piece.x == j + 1 && ghost_piece.y == i) || (ghost_piece.x == j && ghost_piece.y == i + 1) || (ghost_piece.x == j && ghost_piece.y == i + 2)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c ", ghost_piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c", ghost_piece.center.value);
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
                    if(((ghost_piece.x == j && ghost_piece.y == i) || (ghost_piece.x == j + 1 && ghost_piece.y == i) || (ghost_piece.x == j - 1 && ghost_piece.y == i) || (ghost_piece.x == j - 1 && ghost_piece.y == i + 1)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c ", ghost_piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c", ghost_piece.center.value);
                        }
                        return 1;
                    }
                    break;
                case 1:
                    if(((piece.x == j && piece.y == i) || (piece.x == j - 1 && piece.y == i) || (piece.x == j && piece.y == i + 1) || (piece.x == j && piece.y == i + 2)))
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
                    if(((ghost_piece.x == j && ghost_piece.y == i) || (ghost_piece.x == j - 1 && ghost_piece.y == i) || (ghost_piece.x == j && ghost_piece.y == i + 1) || (ghost_piece.x == j && ghost_piece.y == i + 2)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c ", ghost_piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c", ghost_piece.center.value);
                        }
                        return 1;
                    }
                    break;
                case 2:
                    if(((piece.x == j && piece.y == i) || (piece.x == j && piece.y == i + 1) || (piece.x == j - 1 && piece.y == i + 1) || (piece.x == j - 2 && piece.y == i + 1)))
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
                    if(((ghost_piece.x == j && ghost_piece.y == i) || (ghost_piece.x == j && ghost_piece.y == i + 1) || (ghost_piece.x == j - 1 && ghost_piece.y == i + 1) || (ghost_piece.x == j - 2 && ghost_piece.y == i + 1)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c ", ghost_piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c", ghost_piece.center.value);
                        }
                        return 1;
                    }
                    break;
                case 3:
                    if(((piece.x == j && piece.y == i) || (piece.x == j && piece.y == i - 1) || (piece.x == j && piece.y == i - 2) || (piece.x == j + 1 && piece.y == i)))
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
                    if(((ghost_piece.x == j && ghost_piece.y == i) || (ghost_piece.x == j && ghost_piece.y == i + 1) || (ghost_piece.x == j && ghost_piece.y == i + 2) || (ghost_piece.x == j + 1 && ghost_piece.y == i + 2)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c ", ghost_piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c", ghost_piece.center.value);
                        }
                        return 1;
                    }
                    break;
            }
            break;
        case 'O':
            if((piece.x == j && piece.y == i) || (piece.x == j - 1 && piece.y == i) || ((piece.x == j - 1 && piece.y == i + 1) || (piece.x == j && piece.y == i + 1)))
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
            if(((ghost_piece.x == j && ghost_piece.y == i) || (ghost_piece.x == j - 1 && ghost_piece.y == i) || (ghost_piece.x == j - 1 && ghost_piece.y == i + 1) || (ghost_piece.x == j && ghost_piece.y == i + 1))){
                if(j != 9)
                {
                    color_on_bg_256(ghost_piece.center.c, bg);
                    printf("%c ", ghost_piece.center.value);
                }
                else
                {
                    color_on_bg_256(ghost_piece.center.c, bg);
                    printf("%c", ghost_piece.center.value);
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
                    if(((ghost_piece.x == j && ghost_piece.y == i) || (ghost_piece.x == j + 1 && ghost_piece.y == i) || (ghost_piece.x == j - 1 && ghost_piece.y == i + 1) || (ghost_piece.x == j && ghost_piece.y == i + 1)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c ", ghost_piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c", ghost_piece.center.value);
                        }
                        return 1;
                    }
                    break;
                case 1:
                    if(((piece.x == j && piece.y == i) || (piece.x == j && piece.y == i + 1) || (piece.x == j + 1 && piece.y == i + 1) || (piece.x == j + 1 && piece.y == i + 2)))
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
                    if(((ghost_piece.x == j && ghost_piece.y == i) || (ghost_piece.x == j && ghost_piece.y == i + 1) || (ghost_piece.x == j + 1 && ghost_piece.y == i + 1) || (ghost_piece.x == j + 1 && ghost_piece.y == i + 2)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c ", ghost_piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c", ghost_piece.center.value);
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
                    if(((ghost_piece.x == j && ghost_piece.y == i) || (ghost_piece.x == j + 1 && ghost_piece.y == i) || (ghost_piece.x == j - 1 && ghost_piece.y == i + 1) || (ghost_piece.x == j && ghost_piece.y == i + 1)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c ", ghost_piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c", ghost_piece.center.value);
                        }
                        return 1;
                    }
                    break;
                case 3:
                    if(((piece.x == j && piece.y == i) || (piece.x == j && piece.y == i + 1) || (piece.x == j + 1 && piece.y == i + 1) || (piece.x == j + 1 && piece.y == i + 2)))
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
                    if(((ghost_piece.x == j && ghost_piece.y == i) || (ghost_piece.x == j && ghost_piece.y == i + 1) || (ghost_piece.x == j + 1 && ghost_piece.y == i + 1) || (ghost_piece.x == j + 1 && ghost_piece.y == i + 2)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c ", ghost_piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c", ghost_piece.center.value);
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
                    if(((ghost_piece.x == j && ghost_piece.y == i) || (ghost_piece.x == j + 1 && ghost_piece.y == i) || (ghost_piece.x == j - 1 && ghost_piece.y == i) || (ghost_piece.x == j && ghost_piece.y == i + 1)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c ", ghost_piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c", ghost_piece.center.value);
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
                    if(((ghost_piece.x == j && ghost_piece.y == i) || (ghost_piece.x == j && ghost_piece.y == i + 1) || (ghost_piece.x == j - 1 && ghost_piece.y == i + 1) || (ghost_piece.x == j && ghost_piece.y == i + 2)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c ", ghost_piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c", ghost_piece.center.value);
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
                    if(((ghost_piece.x == j && ghost_piece.y == i) || (ghost_piece.x == j + 1 && ghost_piece.y == i + 1) || (ghost_piece.x == j - 1 && ghost_piece.y == i + 1) || (ghost_piece.x == j && ghost_piece.y == i + 1)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c ", ghost_piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c", ghost_piece.center.value);
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
                    if(((ghost_piece.x == j && ghost_piece.y == i) || (ghost_piece.x == j && ghost_piece.y == i + 1) || (ghost_piece.x == j + 1 && ghost_piece.y == i + 1) || (ghost_piece.x == j && ghost_piece.y == i + 2)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c ", ghost_piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c", ghost_piece.center.value);
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
                    if(((ghost_piece.x == j && ghost_piece.y == i) || (ghost_piece.x == j + 1 && ghost_piece.y == i + 1) || (ghost_piece.x == j - 1 && ghost_piece.y == i) || (ghost_piece.x == j && ghost_piece.y == i + 1)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c ", ghost_piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c", ghost_piece.center.value);
                        }
                        return 1;
                    }
                    break;
                case 1:
                    if(((piece.x == j && piece.y == i) || (piece.x == j && piece.y == i + 1) || (piece.x == j - 1 && piece.y == i + 1) || (piece.x == j - 1 && piece.y == i + 2)))
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
                    if(((ghost_piece.x == j && ghost_piece.y == i) || (ghost_piece.x == j && ghost_piece.y == i + 1) || (ghost_piece.x == j - 1 && ghost_piece.y == i + 1) || (ghost_piece.x == j - 1 && ghost_piece.y == i + 2)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c ", ghost_piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c", ghost_piece.center.value);
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
                    if(((ghost_piece.x == j && ghost_piece.y == i) || (ghost_piece.x == j + 1 && ghost_piece.y == i + 1) || (ghost_piece.x == j - 1 && ghost_piece.y == i) || (ghost_piece.x == j && ghost_piece.y == i + 1)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c ", ghost_piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c", ghost_piece.center.value);
                        }
                        return 1;
                    }
                    break;
                case 3:
                    if(((piece.x == j && piece.y == i) || (piece.x == j && piece.y == i + 1) || (piece.x == j - 1 && piece.y == i + 1) || (piece.x == j - 1 && piece.y == i + 2)))
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
                    if(((ghost_piece.x == j && ghost_piece.y == i) || (ghost_piece.x == j && ghost_piece.y == i + 1) || (ghost_piece.x == j - 1 && ghost_piece.y == i + 1) || (ghost_piece.x == j - 1 && ghost_piece.y == i + 2)))
                    {
                        if(j != 9)
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c ", ghost_piece.center.value);
                        }
                        else
                        {
                            color_on_bg_256(ghost_piece.center.c, bg);
                            printf("%c", ghost_piece.center.value);
                        }
                        return 1;
                    }
                    break;
            }
            break;
    }
    return 0;
}

bool findnxtpiece(Cell grid[4][3], int i, int j, Piece piece, Color_256 bg)
{
    switch(piece.type)
    {
        case 'I':
                if(piece.x == j && (piece.y == i || piece.y == i + 1 || piece.y == i + 2 || piece.y == i - 1))
                {
                    color_on_bg_256(piece.center.c, bg);
                    printf("%c ", piece.center.value);
                    return 1;
                }
               break;
        case 'J':
                if(((piece.x == j && piece.y == i) || (piece.x == j + 1 && piece.y == i) || (piece.x == j - 1 && piece.y == i) || (piece.x == j + 1 && piece.y == i + 1))){
                    color_on_bg_256(piece.center.c, bg);
                    printf("%c ", piece.center.value);
                    return 1;
                }
                break;
        case 'L':
                if(((piece.x == j && piece.y == i) || (piece.x == j + 1 && piece.y == i) || (piece.x == j - 1 && piece.y == i) || (piece.x == j - 1 && piece.y == i + 1))){
                    color_on_bg_256(piece.center.c, bg);
                    printf("%c ", piece.center.value);
                    return 1;
                }
                break;
        case 'O':
            if((piece.x == j && piece.y == i) || (piece.x == j - 1 && piece.y == i) || ((piece.x == j - 1 && piece.y == i + 1) || (piece.x == j && piece.y == i + 1))){
                color_on_bg_256(piece.center.c, bg);
                printf("%c ", piece.center.value);
                return 1;
            }
            break;
        case 'S':
                if(((piece.x == j && piece.y == i) || (piece.x == j + 1 && piece.y == i) || (piece.x == j - 1 && piece.y == i + 1) || (piece.x == j && piece.y == i + 1))){
                    color_on_bg_256(piece.center.c, bg);
                    printf("%c ", piece.center.value);
                    return 1;
                }
                break;
        case 'T':
                if(((piece.x == j && piece.y == i) || (piece.x == j + 1 && piece.y == i) || (piece.x == j - 1 && piece.y == i) || (piece.x == j && piece.y == i + 1))){
                    color_on_bg_256(piece.center.c, bg);
                    printf("%c ", piece.center.value);
                    return 1;
                }
                break;
        case 'Z':
                if(((piece.x == j && piece.y == i) || (piece.x == j + 1 && piece.y == i + 1) || (piece.x == j - 1 && piece.y == i) || (piece.x == j && piece.y == i + 1)) ){
                    color_on_bg_256(piece.center.c, bg);
                    printf("%c ", piece.center.value);
                    return 1;
                }
                break;
    }
    return 0;
}

void printgrid(Cell grid[25][10], Piece piece, Piece ghost_piece, Piece next_piece, Piece held_piece, int score, int level, Color_256 bg, int offset)
{
    bool ok = 1, nxt = 1;
    Cell nxt_box[4][3];
    Cell hld_box[4][3];
    for(int k = 0; k <= 4; k++)
    {
        printf("\n");
    }
    printf("\t\t\t\t\t\tSCORE: %d   LEVEL: %d\n", score, level);
    for(int i = 5; i < 25; i++)
    {
        for(int k = 0; k < offset; k++){
                printf("\t");
            }
        for(int j = 0; j < 10; j++)
        {
            ok = !findpiece(grid, i, j, piece, ghost_piece, bg);
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
        if(i == 7){
            setcolor(reset);
            printf("\t\t\tNEXT PIECE:");
        }
        if(i >= 8 && i < 12){
            setcolor(reset);
            printf("\t\t\t  ");
            for(int l = 0; l < 3; l++){
                nxt = !findnxtpiece(nxt_box, i-8, l, next_piece, bg);
                if(nxt){
                    color_on_bg_256(white_256, bg);
                    printf("0 ");
                }
            }
        }
        if(i == 15){
            setcolor(reset);
            printf("\t\t\tHELD PIECE:");
        }
        if(i >= 16 && i < 20){
            setcolor(reset);
            printf("\t\t\t  ");
            for(int l = 0; l < 3; l++){
                if(held_piece.type != '\0'){
                    nxt = !findnxtpiece(hld_box, i-16, l, held_piece, bg);
                }
                else{
                    nxt = 1;
                }
                if(nxt){
                    color_on_bg_256(white_256, bg);
                    printf("0 ");
                }
            }
        }
        setcolor(reset);
        printf("\n");
    }
}

void emptygrid(Cell grid[25][10])
{
    for(int i = 0; i < 25; i++)
        for(int j = 0; j < 10; j++)
        {
            grid[i][j].value = '0';
            grid[i][j].c = white_256;
        }
}

bool checkcollision(Cell grid[25][10], Piece piece, double *velocity, bool hard_drop, int level, char state[5])
{
    static int cooldown = 200, counter = 0;
    switch(piece.type){
        case 'I':
            switch(piece.rotation){
                case 0:
                    if(piece.y == 24 || (piece.y < 24 && grid[piece.y+1][piece.x].value == '#')){
                        if(piece.center.c != grey_50){
                            counter++;
                            *velocity = 0;
                            if(counter == fmin(cooldown - 10*(level-1), 60)  || hard_drop == 1){
                                if(piece.y <= 7){
                                strcpy(state, "over");
                                return 1;
                                }
                                grid[piece.y][piece.x] = piece.center;
                                grid[piece.y-1][piece.x] = piece.center;
                                grid[piece.y-2][piece.x] = piece.center;
                                grid[piece.y-3][piece.x] = piece.center;
                                counter = 0;
                                return 1;
                            }
                        }
                        else{
                            if(piece.center.c == grey_50){
                                return 1;
                            }
                            else{
                                *velocity = 0;
                                return 0;
                            }
                        }
                    }
                    break;
                case 1:
                    if(piece.y == 24 || (piece.y < 24 && (grid[piece.y+1][piece.x].value == '#' || grid[piece.y+1][piece.x-1].value == '#' || grid[piece.y+1][piece.x-2].value == '#' || grid[piece.y+1][piece.x-3].value == '#'))){
                        if(piece.center.c != grey_50){
                            counter++;
                            *velocity = 0;
                            if(counter == fmin(cooldown - 10*(level-1), 60)  || hard_drop == 1){
                                if(piece.y <= 4){
                                strcpy(state, "over");
                                return 1;
                                }
                                grid[piece.y][piece.x] = piece.center;
                                grid[piece.y][piece.x-1] = piece.center;
                                grid[piece.y][piece.x-2] = piece.center;
                                grid[piece.y][piece.x-3] = piece.center;
                                counter = 0;
                                return 1;
                            }
                            
                        }
                        else{
                            if(piece.center.c == grey_50){
                                return 1;
                            }
                            else{
                                *velocity = 0;
                                return 0;
                            }
                        }
                    }
                    break;
                case 2:
                    if(piece.y == 24 || (piece.y < 24 && grid[piece.y+1][piece.x].value == '#')){
                        if(piece.center.c != grey_50){
                            counter++;
                            *velocity = 0;
                            if(counter == fmin(cooldown - 10*(level-1), 60)  || hard_drop == 1){
                                if(piece.y <= 7){
                                strcpy(state, "over");
                                return 1;
                                }
                                grid[piece.y][piece.x] = piece.center;
                                grid[piece.y-1][piece.x] = piece.center;
                                grid[piece.y-2][piece.x] = piece.center;
                                grid[piece.y-3][piece.x] = piece.center;
                                counter = 0;
                                return 1;
                            }
                        }
                        else{
                            if(piece.center.c == grey_50){
                                return 1;
                            }
                            else{
                                *velocity = 0;
                                return 0;
                            }
                        }
                    }
                    break;
                case 3:
                    if(piece.y == 24 || (piece.y < 24 && (grid[piece.y+1][piece.x].value == '#' || grid[piece.y+1][piece.x-1].value == '#' || grid[piece.y+1][piece.x-2].value == '#' || grid[piece.y+1][piece.x-3].value == '#'))){
                        if(piece.center.c != grey_50){
                            counter++;
                            *velocity = 0;
                            if(counter == fmin(cooldown - 10*(level-1), 60)  || hard_drop == 1){
                                if(piece.y <= 4){
                                strcpy(state, "over");
                                return 1;
                                }
                                grid[piece.y][piece.x] = piece.center;
                                grid[piece.y][piece.x-1] = piece.center;
                                grid[piece.y][piece.x-2] = piece.center;
                                grid[piece.y][piece.x-3] = piece.center;
                                counter = 0;
                                return 1;
                            }
                        }
                        else{
                            if(piece.center.c == grey_50){
                                return 1;
                            }
                            else{
                                *velocity = 0;
                                return 0;
                            }
                        }
                    }
                    break;
            }
            break;
        case 'J':
            switch(piece.rotation){
                case 0:
                    if(piece.y == 24 || (piece.y < 24 && (grid[piece.y+1][piece.x].value == '#' || grid[piece.y+1][piece.x-1].value == '#' || grid[piece.y+1][piece.x+1].value == '#'))){
                        if(piece.center.c != grey_50){
                            counter++;
                            *velocity = 0;
                            if(counter == fmin(cooldown - 10*(level-1), 60)  || hard_drop == 1){
                                if(piece.y <= 5){
                                strcpy(state, "over");
                                return 1;
                                }
                                grid[piece.y][piece.x] = piece.center;
                                grid[piece.y][piece.x-1] = piece.center;
                                grid[piece.y][piece.x+1] = piece.center;
                                grid[piece.y-1][piece.x-1] = piece.center;
                                counter = 0;
                                return 1;
                            }
                        }
                        else{
                            if(piece.center.c == grey_50){
                                return 1;
                            }
                            else{
                                *velocity = 0;
                                return 0;
                            }
                        }
                    }
                    break;
                case 1:
                    if(piece.y == 24 || (piece.y < 24 && (grid[piece.y+1][piece.x].value == '#' || grid[piece.y-1][piece.x+1].value == '#'))){
                        if(piece.center.c != grey_50){
                            counter++;
                            *velocity = 0;
                            if(counter == fmin(cooldown - 10*(level-1), 60)  || hard_drop == 1){
                                if(piece.y <= 6){
                                strcpy(state, "over");
                                return 1;
                                }
                                grid[piece.y][piece.x] = piece.center;
                                grid[piece.y-1][piece.x] = piece.center;
                                grid[piece.y-2][piece.x] = piece.center;
                                grid[piece.y-2][piece.x+1] = piece.center;
                                counter = 0;
                                return 1;
                            }
                        }
                        else{
                            if(piece.center.c == grey_50){
                                return 1;
                            }
                            else{
                                *velocity = 0;
                                return 0;
                            }
                        }
                    }
                    break;
                case 2:
                    if(piece.y == 24 || (piece.y < 24 && (grid[piece.y+1][piece.x].value == '#' || grid[piece.y][piece.x-1].value == '#' || grid[piece.y][piece.x-2].value == '#'))){
                        if(piece.center.c != grey_50){
                            counter++;
                            *velocity = 0;
                            if(counter == fmin(cooldown - 10*(level-1), 60)  || hard_drop == 1){
                                if(piece.y <= 5){
                                strcpy(state, "over");
                                return 1;
                                }
                                grid[piece.y][piece.x] = piece.center;
                                grid[piece.y-1][piece.x] = piece.center;
                                grid[piece.y-1][piece.x-1] = piece.center;
                                grid[piece.y-1][piece.x-2] = piece.center;
                                counter = 0;
                                return 1;
                            }
                        }
                        else{
                            if(piece.center.c == grey_50){
                                return 1;
                            }
                            else{
                                *velocity = 0;
                                return 0;
                            }
                        }
                    }
                    break;
                case 3:
                    if(piece.y == 24 || (piece.y < 24 && (grid[piece.y+1][piece.x].value == '#' || grid[piece.y+1][piece.x-1].value == '#'))){
                        if(piece.center.c != grey_50){
                            counter++;
                            *velocity = 0;
                            if(counter == fmin(cooldown - 10*(level-1), 60)  || hard_drop == 1){
                                if(piece.y <= 6){
                                strcpy(state, "over");
                                return 1;
                                }
                                grid[piece.y][piece.x] = piece.center;
                                grid[piece.y][piece.x-1] = piece.center;
                                grid[piece.y-1][piece.x] = piece.center;
                                grid[piece.y-2][piece.x] = piece.center;
                                counter = 0;
                                return 1;
                            }
                        }
                            
                        else{
                            if(piece.center.c == grey_50){
                                return 1;
                            }
                            else{
                                *velocity = 0;
                                return 0;
                            }
                        }
                    }
                    break;
            }
            break;
        case 'L':
            switch(piece.rotation){
                case 0:
                    if(piece.y == 24 || (piece.y < 24 && (grid[piece.y+1][piece.x].value == '#' || grid[piece.y+1][piece.x-1].value == '#' || grid[piece.y+1][piece.x+1].value == '#'))){
                        if(piece.center.c != grey_50){
                            counter++;
                            *velocity = 0;
                            if(counter == fmin(cooldown - 10*(level-1), 60)  || hard_drop == 1){
                                if(piece.y <= 5){
                                strcpy(state, "over");
                                return 1;
                                }
                                grid[piece.y][piece.x] = piece.center;
                                grid[piece.y][piece.x-1] = piece.center;
                                grid[piece.y][piece.x+1] = piece.center;
                                grid[piece.y-1][piece.x+1] = piece.center;
                                counter = 0;
                                return 1;
                            }  
                        }
                        else{
                            if(piece.center.c == grey_50){
                                return 1;
                            }
                            else{
                                *velocity = 0;
                                return 0;
                            }
                        }
                    }
                    break;
                case 1:
                    if(piece.y == 24 || (piece.y < 24 && (grid[piece.y+1][piece.x].value == '#' || grid[piece.y+1][piece.x+1].value == '#'))){
                        if(piece.center.c != grey_50){
                            counter++;
                            *velocity = 0;
                            if(counter == fmin(cooldown - 10*(level-1), 60)  || hard_drop == 1){
                                if(piece.y <= 6){
                                strcpy(state, "over");
                                return 1;
                                }
                                grid[piece.y][piece.x] = piece.center;
                                grid[piece.y][piece.x+1] = piece.center;
                                grid[piece.y-1][piece.x] = piece.center;
                                grid[piece.y-2][piece.x] = piece.center;
                                counter = 0;
                                return 1;
                            }
                        }
                        else{
                            if(piece.center.c == grey_50){
                                return 1;
                            }
                            else{
                                *velocity = 0;
                                return 0;
                            }
                        }
                    }
                    break;
                case 2:
                    if(piece.y == 24 || (piece.y < 24 && (grid[piece.y+1][piece.x].value == '#' || grid[piece.y][piece.x+1].value == '#' || grid[piece.y][piece.x+2].value == '#'))){
                        if(piece.center.c != grey_50){
                            counter++;
                            *velocity = 0;
                            if(counter == fmin(cooldown - 10*(level-1), 60)  || hard_drop == 1){
                                if(piece.y <= 5){
                                strcpy(state, "over");
                                return 1;
                            }
                            grid[piece.y][piece.x] = piece.center;
                            grid[piece.y-1][piece.x] = piece.center;
                            grid[piece.y-1][piece.x+1] = piece.center;
                            grid[piece.y-1][piece.x+2] = piece.center;
                            counter = 0;
                            return 1;
                            }
                        }
                        else{
                            if(piece.center.c == grey_50){
                                return 1;
                            }
                            else{
                                *velocity = 0;
                                return 0;
                            }
                        }
                    }
                    break;
                case 3:
                    if(piece.y == 24 || (piece.y < 24 && (grid[piece.y+1][piece.x].value == '#' || grid[piece.y-1][piece.x-1].value == '#'))){
                        if(piece.center.c != grey_50){
                            counter++;
                            *velocity = 0;
                            if(counter == fmin(cooldown - 10*(level-1), 60)  || hard_drop == 1){
                                if(piece.y <= 6){
                                strcpy(state, "over");
                                return 1;
                                }
                                grid[piece.y][piece.x] = piece.center;
                                grid[piece.y-2][piece.x-1] = piece.center;
                                grid[piece.y-1][piece.x] = piece.center;
                                grid[piece.y-2][piece.x] = piece.center;
                                counter = 0;
                                return 1;
                            }
                        }
                        else{
                            if(piece.center.c == grey_50){
                                return 1;
                            }
                            else{
                                *velocity = 0;
                                return 0;
                            }
                        }
                    }
                    break;
            }
            break;
        case 'O':
            if(piece.y == 24 || (piece.y < 24 && (grid[piece.y+1][piece.x].value == '#' || grid[piece.y+1][piece.x+1].value == '#'))){
                if(piece.center.c != grey_50){
                    counter++;
                    *velocity = 0;
                    if(counter == fmin(cooldown - 10*(level-1), 60)  || hard_drop == 1){
                        if(piece.y <= 5){
                        strcpy(state, "over");
                        return 1;
                    }
                    grid[piece.y][piece.x] = piece.center;
                    grid[piece.y][piece.x+1] = piece.center;
                    grid[piece.y-1][piece.x+1] = piece.center;
                    grid[piece.y-1][piece.x] = piece.center;
                    counter = 0;
                    return 1;
                    }
                }
                else{
                    if(piece.center.c == grey_50){
                        return 1;
                    }
                    else{
                        *velocity = 0;
                        return 0;
                    }
                }
                
            }
            break;
        case 'S':
            switch(piece.rotation){
                case 0:
                    if(piece.y == 24 || (piece.y < 24 && (grid[piece.y+1][piece.x].value == '#' || grid[piece.y+1][piece.x-1].value == '#' || grid[piece.y][piece.x+1].value == '#'))){
                        if(piece.center.c != grey_50){
                            counter++;
                            *velocity = 0;
                            if(counter == fmin(cooldown - 10*(level-1), 60)  || hard_drop == 1){
                                if(piece.y <= 5){
                                strcpy(state, "over");
                                return 1;
                                }
                                grid[piece.y][piece.x] = piece.center;
                                grid[piece.y][piece.x-1] = piece.center;
                                grid[piece.y-1][piece.x+1] = piece.center;
                                grid[piece.y-1][piece.x] = piece.center;
                                counter = 0;
                                return 1;
                            }
                        }
                        else{
                            if(piece.center.c == grey_50){
                                return 1;
                            }
                            else{
                                *velocity = 0;
                                return 0;
                            }
                        }
                    }
                    break;
                case 1:
                    if(piece.y == 24 || (piece.y < 24 && (grid[piece.y+1][piece.x].value == '#' || grid[piece.y][piece.x-1].value == '#'))){
                        if(piece.center.c != grey_50){
                            counter++;
                            *velocity = 0;
                            if(counter == fmin(cooldown - 10*(level-1), 60)  || hard_drop == 1){
                                if(piece.y <= 6){
                                strcpy(state, "over");
                                return 1;
                                }
                                grid[piece.y][piece.x] = piece.center;
                                grid[piece.y-1][piece.x] = piece.center;
                                grid[piece.y-1][piece.x-1] = piece.center;
                                grid[piece.y-2][piece.x-1] = piece.center;
                                counter = 0;
                                return 1;
                            }
                        }
                        else{
                            if(piece.center.c == grey_50){
                                return 1;
                            }
                            else{
                                *velocity = 0;
                                return 0;
                            }
                        }
                    }
                    break;
                case 2:
                    if(piece.y == 24 || (piece.y < 24 && (grid[piece.y+1][piece.x].value == '#' || grid[piece.y+1][piece.x-1].value == '#' || grid[piece.y][piece.x+1].value == '#'))){
                        if(piece.center.c != grey_50){
                            counter++;
                            *velocity = 0;
                            if(counter == fmin(cooldown - 10*(level-1), 60)  || hard_drop == 1){
                                if(piece.y <= 5){
                                strcpy(state, "over");
                                return 1;
                                }
                                grid[piece.y][piece.x] = piece.center;
                                grid[piece.y][piece.x-1] = piece.center;
                                grid[piece.y-1][piece.x+1] = piece.center;
                                grid[piece.y-1][piece.x] = piece.center;
                                counter = 0;
                                return 1;
                            }
                        }
                        else{
                            if(piece.center.c == grey_50){
                                return 1;
                            }
                            else{
                                *velocity = 0;
                                return 0;
                            }
                        }
                    }
                    break;
                case 3:
                    if(piece.y == 24 || (piece.y < 24 && (grid[piece.y+1][piece.x].value == '#' || grid[piece.y][piece.x-1].value == '#'))){
                        if(piece.center.c != grey_50){
                            counter++;
                            *velocity = 0;
                            if(counter == fmin(cooldown - 10*(level-1), 60)  || hard_drop == 1){
                                if(piece.y <= 6){
                                strcpy(state, "over");
                                return 1;
                                }
                                grid[piece.y][piece.x] = piece.center;
                                grid[piece.y-1][piece.x] = piece.center;
                                grid[piece.y-1][piece.x-1] = piece.center;
                                grid[piece.y-2][piece.x-1] = piece.center;
                                counter = 0;
                                return 1;
                            }
                        }
                        else{
                            if(piece.center.c == grey_50){
                                return 1;
                            }
                            else{
                                *velocity = 0;
                                return 0;
                            }
                        }
                    }
                    break;
            }
            break;
        case 'T':
            switch(piece.rotation)
            {
                case 0:
                    if(piece.y == 24 || (piece.y < 24 && (grid[piece.y+1][piece.x].value == '#' || grid[piece.y+1][piece.x-1].value == '#' || grid[piece.y+1][piece.x+1].value == '#'))){
                        if(piece.center.c != grey_50){
                            counter++;
                            *velocity = 0;
                            if(counter == fmin(cooldown - 10*(level-1), 60)  || hard_drop == 1){
                                if(piece.y <= 5){
                                strcpy(state, "over");
                                return 1;
                                }
                                grid[piece.y][piece.x] = piece.center;
                                grid[piece.y][piece.x-1] = piece.center;
                                grid[piece.y][piece.x+1] = piece.center;
                                grid[piece.y-1][piece.x] = piece.center;
                                counter = 0;
                                return 1;
                            }
                        }
                        else{
                            if(piece.center.c == grey_50){
                                return 1;
                            }
                            else{
                                *velocity = 0;
                                return 0;
                            }
                        }
                    }
                    break;
                case 1:
                    if(piece.y == 24 || (piece.y < 24 && (grid[piece.y+1][piece.x].value == '#' || grid[piece.y][piece.x+1].value == '#'))){
                        if(piece.center.c != grey_50){
                            counter++;
                            *velocity = 0;
                            if(counter == fmin(cooldown - 10*(level-1), 60)  || hard_drop == 1){
                                if(piece.y <= 6){
                                strcpy(state, "over");
                                return 1;
                                }
                                grid[piece.y][piece.x] = piece.center;
                                grid[piece.y-1][piece.x] = piece.center;
                                grid[piece.y-1][piece.x+1] = piece.center;
                                grid[piece.y-2][piece.x] = piece.center;
                                counter = 0;
                                return 1;
                            }
                        }
                        else{
                            if(piece.center.c == grey_50){
                                return 1;
                            }
                            else{
                                *velocity = 0;
                                return 0;
                            }
                        }
                    }
                    break;
                case 2:
                    if(piece.y == 24 || (piece.y < 24 && (grid[piece.y+1][piece.x].value == '#' || grid[piece.y][piece.x-1].value == '#' || grid[piece.y][piece.x+1].value == '#'))){
                        if(piece.center.c != grey_50){
                            counter++;
                            *velocity = 0;
                            if(counter == fmin(cooldown - 10*(level-1), 60)  || hard_drop == 1){
                                if(piece.y <= 5){
                                strcpy(state, "over");
                                return 1;
                                }
                                grid[piece.y][piece.x] = piece.center;
                                grid[piece.y-1][piece.x-1] = piece.center;
                                grid[piece.y-1][piece.x+1] = piece.center;
                                grid[piece.y-1][piece.x] = piece.center;
                                counter = 0;
                                return 1;
                            }
                        }
                        else{
                            if(piece.center.c == grey_50){
                                return 1;
                            }
                            else{
                                *velocity = 0;
                                return 0;
                            }
                        }
                    }
                    break;
                case 3:
                    if(piece.y == 24 || (piece.y < 24 && (grid[piece.y+1][piece.x].value == '#' || grid[piece.y-1][piece.x-1].value == '#'))){
                        if(piece.center.c != grey_50){
                            counter++;
                            *velocity = 0;
                            if(counter == fmin(cooldown - 10*(level-1), 60)  || hard_drop == 1){
                                if(piece.y <= 6){
                                strcpy(state, "over");
                                return 1;
                                }
                                grid[piece.y][piece.x] = piece.center;
                                grid[piece.y-1][piece.x] = piece.center;
                                grid[piece.y-1][piece.x-1] = piece.center;
                                grid[piece.y-2][piece.x] = piece.center;
                                counter = 0;
                                return 1;
                            }
                        }
                        else{
                            if(piece.center.c == grey_50){
                                return 1;
                            }
                            else{
                                *velocity = 0;
                                return 0;
                            }
                        }
                    }
                    break;
            }
            break;
        case 'Z':
            switch(piece.rotation){
                case 0:
                    if(piece.y == 24 || (piece.y < 24 && (grid[piece.y+1][piece.x].value == '#' || grid[piece.y+1][piece.x+1].value == '#' || grid[piece.y][piece.x-1].value == '#'))){
                        if(piece.center.c != grey_50){
                            counter++;
                            *velocity = 0;
                            if(counter == fmin(cooldown - 10*(level-1), 60)  || hard_drop == 1){
                                if(piece.y <= 5){
                                strcpy(state, "over");
                                return 1;
                                }
                                grid[piece.y][piece.x] = piece.center;
                                grid[piece.y-1][piece.x-1] = piece.center;
                                grid[piece.y][piece.x+1] = piece.center;
                                grid[piece.y-1][piece.x] = piece.center;
                                counter = 0;
                                return 1;
                            }
                        }
                        else{
                            if(piece.center.c == grey_50){
                                return 1;
                            }
                            else{
                                *velocity = 0;
                                return 0;
                            }
                        }
                    }
                    break;
                case 1:
                    if(piece.y == 24 || (piece.y < 24 && (grid[piece.y+1][piece.x].value == '#' || grid[piece.y][piece.x+1].value == '#'))){
                        if(piece.center.c != grey_50){
                            counter++;
                            *velocity = 0;
                            if(counter == fmin(cooldown - 10*(level-1), 60)  || hard_drop == 1){
                                if(piece.y <= 6){
                                strcpy(state, "over");
                                return 1;
                                }
                                grid[piece.y][piece.x] = piece.center;
                                grid[piece.y-1][piece.x] = piece.center;
                                grid[piece.y-1][piece.x+1] = piece.center;
                                grid[piece.y-2][piece.x+1] = piece.center;
                                counter = 0;
                                return 1;
                            }
                        }
                        else{
                            if(piece.center.c == grey_50){
                                return 1;
                            }
                            else{
                                *velocity = 0;
                                return 0;
                            }
                        }
                    }
                    break;
                case 2:
                    if(piece.y == 24 || (piece.y < 24 && (grid[piece.y+1][piece.x].value == '#' || grid[piece.y+1][piece.x+1].value == '#' || grid[piece.y][piece.x-1].value == '#'))){
                        if(piece.center.c != grey_50){
                            counter++;
                            *velocity = 0;
                            if(counter == fmin(cooldown - 10*(level-1), 60)  || hard_drop == 1){
                                if(piece.y <= 5){
                                strcpy(state, "over");
                                return 1;
                                }
                                grid[piece.y][piece.x] = piece.center;
                                grid[piece.y-1][piece.x-1] = piece.center;
                                grid[piece.y][piece.x+1] = piece.center;
                                grid[piece.y-1][piece.x] = piece.center;
                                counter = 0;
                                return 1;
                            }
                            
                        }
                        else{
                            if(piece.center.c == grey_50){
                                return 1;
                            }
                            else{
                                *velocity = 0;
                                return 0;
                            }
                        }
                    }
                    break;
                case 3:
                    if(piece.y == 24 || (piece.y < 24 && (grid[piece.y+1][piece.x].value == '#' || grid[piece.y][piece.x+1].value == '#'))){
                        if(piece.center.c != grey_50){
                            counter++;
                            *velocity = 0;
                            if(counter == fmin(cooldown - 10*(level-1), 60)  || hard_drop == 1){
                                if(piece.y <= 6){
                                strcpy(state, "over");
                                return 1;
                                }
                                grid[piece.y][piece.x] = piece.center;
                                grid[piece.y-1][piece.x] = piece.center;
                                grid[piece.y-1][piece.x+1] = piece.center;
                                grid[piece.y-2][piece.x+1] = piece.center;
                                counter = 0;
                                return 1;
                            }
                            
                        }
                        else{
                            if(piece.center.c == grey_50){
                                return 1;
                            }
                            else{
                                *velocity = 0;
                                return 0;
                            }
                        }
                    }
                    break;
            }
            break;
    }
    return 0;
}

bool valid_rotation(Cell grid[25][10], Piece piece)
{
    switch(piece.type){
        case 'I':
            switch(piece.rotation){
                case 0:
                    if(grid[piece.y][piece.x-1].value == '#' || grid[piece.y][piece.x-2].value == '#' || grid[piece.y][piece.x-3].value == '#' || piece.x < 3){
                        return 0;
                    }
                    return 1;
                    break;
                case 1:
                    if(grid[piece.y-1][piece.x].value == '#' || grid[piece.y-2][piece.x].value == '#' || grid[piece.y-3][piece.x].value == '#'){
                        return 0;
                    }
                    return 1;
                    break;
                case 2:
                    if(grid[piece.y][piece.x-1].value == '#' || grid[piece.y][piece.x-2].value == '#' || grid[piece.y][piece.x-3].value == '#' || piece.x < 3){
                        return 0;
                    }
                    return 1;
                    break;
                case 3:
                if(grid[piece.y-1][piece.x].value == '#' || grid[piece.y-2][piece.x].value == '#' || grid[piece.y-3][piece.x].value == '#'){
                        return 0;
                    }
                    return 1;
                    break;
            }
            break;
        case 'J':
            switch(piece.rotation){
                case 0:
                    if(grid[piece.y-1][piece.x].value == '#' || grid[piece.y-2][piece.x].value == '#' || grid[piece.y-2][piece.x+1].value == '#'){
                        return 0;
                    }
                    return 1;
                    break;
                case 1:
                    if(grid[piece.y-1][piece.x-1].value == '#' || grid[piece.y-1][piece.x-2].value == '#' || piece.x < 2){
                        return 0;
                    }
                    return 1;
                    break;
                case 2:
                    if(grid[piece.y][piece.x-1].value == '#' || grid[piece.y-2][piece.x].value == '#'){
                        return 0;
                    }
                    return 1;
                    break;
                case 3:
                if(grid[piece.y][piece.x+1].value == '#' || grid[piece.y-1][piece.x-1].value == '#' || grid[piece.y][piece.x-1].value == '#' || piece.x > 8){
                        return 0;
                    }
                    return 1;
                    break;
            }
            break;
        case 'L':
            switch(piece.rotation){
                case 0:
                    if(grid[piece.y-1][piece.x].value == '#' || grid[piece.y-2][piece.x].value == '#'){
                        return 0;
                    }
                    return 1;
                    break;
                case 1:
                    if(grid[piece.y-1][piece.x+1].value == '#' || grid[piece.y-1][piece.x+2].value == '#' || piece.x > 7){
                        return 0;
                    }
                    return 1;
                    break;
                case 2:
                    if(grid[piece.y-2][piece.x].value == '#' || grid[piece.y-2][piece.x-1].value == '#' || piece.x < 1){
                        return 0;
                    }
                    return 1;
                    break;
                case 3:
                    if(grid[piece.y-1][piece.x+1].value == '#' || grid[piece.y][piece.x-1].value == '#' ||  grid[piece.y][piece.x+1].value == '#'){
                        return 0;
                    }
                    return 1;
                    break;
            }
            break;
        case 'O':
            return 1;
            break;
        case 'S':
            switch(piece.rotation){
                case 0:
                    if(grid[piece.y-1][piece.x-1].value == '#' || grid[piece.y-2][piece.x-1].value == '#'){
                        return 0;
                    }
                    return 1;
                    break;
                case 1:
                    if(grid[piece.y][piece.x-1].value == '#' || grid[piece.y-1][piece.x+1].value == '#' || piece.x > 8){
                        return 0;
                    }
                    return 1;
                    break;
                case 2:
                    if(grid[piece.y-1][piece.x-1].value == '#' || grid[piece.y-2][piece.x-1].value == '#'){
                        return 0;
                    }
                    return 1;
                    break;
                case 3:
                    if(grid[piece.y][piece.x-1].value == '#' || grid[piece.y-1][piece.x+1].value == '#' || piece.x > 8){
                        return 0;
                    }
                    return 1;
                    break;
            }
            break;
        case 'T':
            switch(piece.rotation){
                case 0:
                    if(grid[piece.y-1][piece.x+1].value == '#' || grid[piece.y-2][piece.x].value == '#'){
                        return 0;
                    }
                    return 1;
                    break;
                case 1:
                    if(grid[piece.y-1][piece.x-1].value == '#' || piece.x < 1){
                        return 0;
                    }
                    return 1;
                    break;
                case 2:
                    if(grid[piece.y-2][piece.x].value == '#'){
                        return 0;
                    }
                    return 1;
                    break;
                case 3:
                    if(grid[piece.y][piece.x-1].value == '#' || grid[piece.y][piece.x+1].value == '#' || piece.x > 8){
                        return 0;
                    }
                    return 1;
                    break;
            }
            break;
        case 'Z':
            switch(piece.rotation){
                case 0:
                    if(grid[piece.y-1][piece.x+1].value == '#' || grid[piece.y-2][piece.x+1].value == '#'){
                        return 0;
                    }
                    return 1;
                    break;
                case 1:
                    if(grid[piece.y][piece.x+1].value == '#' || grid[piece.y-1][piece.x-1].value == '#' || piece.x < 1){
                        return 0;
                    }
                    return 1;
                    break;
                case 2:
                    if(grid[piece.y-1][piece.x+1].value == '#' || grid[piece.y-2][piece.x+1].value == '#'){
                            return 0;
                        }
                    return 1;
                    break;
                case 3:
                    if(grid[piece.y][piece.x+1].value == '#' || grid[piece.y-1][piece.x-1].value == '#' || piece.x < 1){
                        return 0;
                    }
                    return 1;
                    break;
            }
            break;
    }
}

bool full_row(Cell grid[25][10], int i)
{
    for(int j = 0; j < 10; j++){
        if(grid[i][j].value != '#'){
            return 0;
        }
    }
    return 1;  
}

void clear_row(Cell grid[25][10], int k)
{
    if(k == 0)
    {
        for(int j = 0; j < 10; j++){
            grid[k][j].value = '0';
            grid[k][j].c = white_256;
        }
    }
    else
        for(int i = k; i > 0; i--)
            for(int j = 0; j < 10; j++)
                grid[i][j] = grid[i-1][j];
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

void init(Cell grid[25][10])
{
    enableRawMode();
    srand(time(0));
    emptygrid(grid);
    hide_cursor();
    clear_screen();
}

void start_bg_music()
{
    if (ma_engine_init(NULL, &audio_engine) != MA_SUCCESS) {
        fprintf(stderr, "Warning: Could not initialize audio engine.\n");
    } else {
        ma_sound_init_from_file(&audio_engine, "tetris_theme.wav", MA_SOUND_FLAG_STREAM, NULL, NULL, &bg_music);
        ma_sound_set_looping(&bg_music, MA_TRUE);
        ma_sound_set_volume(&bg_music, 0.4f); 
        ma_sound_start(&bg_music);
    }
}

void stop_music(){
    ma_sound_stop(&bg_music);
}

void quit(int signal_nr)
{
    stop_music();
    disableRawMode();
    clear_screen();
    reset_cursor();
    show_cursor();
    setcolor(reset);
    exit(signal_nr);
}

void clean_exit()
{
    quit(1);
}