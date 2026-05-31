#include "tetris.h"

void menu(char state[5])
{
    char in;
    while(1)
    {
        reset_cursor();
        setcolor(purple);
        for(int k = 0; k <= 4; k++)
        {
            printf("\n");
        }
        printf("\t\t\t\t  #######  ######  #######  ####    #######  ######   \n");
        printf("\t\t\t\t     #     #          #     #   #      #     #        \n");
        printf("\t\t\t\t     #     #####      #     ####       #     ######   \n");
        printf("\t\t\t\t     #     #          #     #   #      #          #   \n");
        printf("\t\t\t\t     #     ######     #     #    #  #######  ######   \n");
        printf("\n\n");
        setcolor(reset);
        printf("\t\t\t\t\t\tPress SPACE to Start\n");
        printf("\t\t\t\t\t\t  Press Q to Quit");
        in = input();
        if(in == ' '){
            strcpy(state, "game");
            clear_screen();
            return;
        }
        if(in == 'q'){
            quit();
        }
        usleep(16666);
    }
}

void game(Cell grid[25][10], char state[5])
{
    Piece piece, ghost_piece, next_piece;
    Color_256 bg = grey_23;
    int bag[7] = {0}, current_piece = 0, full_rows = 0, level = 1;
    double y,velocity, score = 0;
    bool spawn = 1, hard_drop = 0;
    char in;
    ghost_piece.center.value = '#';
    ghost_piece.center.c = grey_50;
    ghost_piece.y = 0;
    fill_bag(bag);
    spawnpiece(&piece, bag, &current_piece);
    current_piece++;
    piece.x = 5;
    piece.y = 0;
    while(1){
        if(strcmp(state, "over") == 0){
            clear_screen();
            return;
        }
        reset_cursor();
        printgrid(grid, piece, ghost_piece, next_piece, floor(score), level, bg, 6);
        fflush(stdout);
        if(spawn){
            spawnpiece(&next_piece, bag, &current_piece);
            current_piece++;
            spawn = 0;
            hard_drop = 0;
            y = piece.y;
            piece.y = 0;
        }
        ghost_piece.type = piece.type;
        ghost_piece.rotation = piece.rotation;
        ghost_piece.x = piece.x;
        ghost_piece.y = piece.y;
        while(!checkcollision(grid, ghost_piece, &velocity, hard_drop, level, state)){
            ghost_piece.y++;
        }
        level = score/1000 + 1;
        in = input_handler();
        if(in == 'q'){
            quit();
        }
        if(in == 'a'){
            switch(piece.type){
                case 'I':
                    switch(piece.rotation)
                    {
                        case 0:
                            if(piece.x > 0 && grid[piece.y][piece.x-1].value != '#' && grid[piece.y-1][piece.x-1].value != '#' && grid[piece.y-2][piece.x-1].value != '#' && grid[piece.y-3][piece.x-1].value != '#')
                                piece.x--;
                            break;
                        case 1:
                            if(piece.x > 3 && grid[piece.y][piece.x-4].value != '#')
                                piece.x--;
                            break;
                        case 2:
                            if(piece.x > 0 && grid[piece.y][piece.x-1].value != '#' && grid[piece.y-1][piece.x-1].value != '#' && grid[piece.y-2][piece.x-1].value != '#' && grid[piece.y-3][piece.x-1].value != '#')
                                piece.x--;
                            break;
                        case 3:
                            if(piece.x > 3 && grid[piece.y][piece.x-4].value != '#')
                                piece.x--;
                            break;
                    }
                    break;
                case 'J':
                    switch(piece.rotation)
                    {
                        case 0:
                            if(piece.x > 1 && grid[piece.y][piece.x-2].value != '#' && grid[piece.y-1][piece.x-1].value != '#')
                                piece.x--;
                            break;
                        case 1:
                            if(piece.x > 0 && grid[piece.y][piece.x-1].value != '#' && grid[piece.y-1][piece.x-1].value != '#' && grid[piece.y-2][piece.x-1].value != '#')
                                piece.x--;
                            break;
                        case 2:
                            if(piece.x > 2 && grid[piece.y][piece.x-1].value != '#' && grid[piece.y-1][piece.x-3].value != '#')
                                piece.x--;
                            break;
                        case 3:
                            if(piece.x > 1  && grid[piece.y][piece.x-2].value != '#' && grid[piece.y-1][piece.x-1].value != '#' && grid[piece.y-2][piece.x-1].value != '#')
                                piece.x--;
                            break;
                    }
                    break;
                case 'L':
                    switch(piece.rotation)
                    {
                        case 0:
                            if(piece.x > 1 && grid[piece.y][piece.x-2].value != '#' && grid[piece.y-1][piece.x].value != '#')
                                piece.x--;
                            break;
                        case 1:
                            if(piece.x > 0 && grid[piece.y][piece.x-1].value != '#' && grid[piece.y-1][piece.x-1].value != '#' && grid[piece.y-2][piece.x-1].value != '#')
                                piece.x--;
                            break;
                        case 2:
                            if(piece.x > 0 && grid[piece.y][piece.x-1].value != '#' && grid[piece.y-1][piece.x-1].value != '#')
                                piece.x--;
                            break;
                        case 3:
                            if(piece.x > 1 && grid[piece.y][piece.x-1].value != '#' && grid[piece.y-1][piece.x-1].value != '#' && grid[piece.y-2][piece.x-2].value != '#')
                                piece.x--;
                            break;
                    }
                    break;
                case 'O':
                    if(piece.x > 0 && grid[piece.y][piece.x-1].value != '#' && grid[piece.y-1][piece.x-1].value != '#')
                        piece.x--;
                    break;
                case 'S':
                    switch(piece.rotation)
                    {
                        case 0:
                            if(piece.x > 1 && grid[piece.y][piece.x-2].value != '#' && grid[piece.y-1][piece.x-1].value != '#')
                                piece.x--;
                            break;
                        case 1:
                            if(piece.x > 1 && grid[piece.y][piece.x-1].value != '#' && grid[piece.y-1][piece.x-2].value != '#' && grid[piece.y-2][piece.x-2].value != '#')
                                piece.x--;
                            break;
                        case 2:
                            if(piece.x > 1 && grid[piece.y][piece.x-2].value != '#' && grid[piece.y-1][piece.x-1].value != '#')
                                piece.x--;
                            break;
                        case 3:
                            if(piece.x > 1 && grid[piece.y][piece.x-1].value != '#' && grid[piece.y-1][piece.x-2].value != '#' && grid[piece.y-2][piece.x-2].value != '#')
                                piece.x--;
                            break;
                    }
                    break;
                case 'T':
                    switch(piece.rotation)
                    {
                        case 0:
                            if(piece.x > 1 && grid[piece.y][piece.x-2].value != '#' && grid[piece.y-1][piece.x-1].value != '#')
                                piece.x--;
                            break;
                        case 1:
                            if(piece.x > 0 && grid[piece.y][piece.x-1].value != '#' && grid[piece.y-1][piece.x-1].value != '#' && grid[piece.y-2][piece.x-1].value != '#')
                                piece.x--;
                            break;
                        case 2:
                            if(piece.x > 1 && grid[piece.y][piece.x-1].value != '#' && grid[piece.y-1][piece.x-2].value != '#')
                                piece.x--;
                            break;
                        case 3:
                            if(piece.x > 1 && grid[piece.y][piece.x-1].value != '#' && grid[piece.y-1][piece.x-2].value != '#' && grid[piece.y-2][piece.x-1].value != '#')
                                piece.x--;
                            break;
                    }
                    break;
                case 'Z':
                    switch(piece.rotation)
                    {
                        case 0:
                            if(piece.x > 1 && grid[piece.y][piece.x-1].value != '#' && grid[piece.y-1][piece.x-2].value != '#')
                                piece.x--;
                            break;
                        case 1:
                            if(piece.x > 0 && grid[piece.y][piece.x-1].value != '#' && grid[piece.y-1][piece.x-1].value != '#' && grid[piece.y-2][piece.x].value != '#')
                                piece.x--;
                            break;
                        case 2:
                            if(piece.x > 1 && grid[piece.y][piece.x-1].value != '#' && grid[piece.y-1][piece.x-2].value != '#')
                                piece.x--;
                            break;
                        case 3:
                            if(piece.x > 0 && grid[piece.y][piece.x-1].value != '#' && grid[piece.y-1][piece.x-1].value != '#' && grid[piece.y-2][piece.x].value != '#')
                                piece.x--;
                            break;
                    }
                    break;
            }
            ghost_piece.y = piece.y;
        }
            
        if(in == 'd'){
            switch(piece.type){
                case 'I':
                    switch(piece.rotation)
                    {
                        case 0:
                            if(piece.x < 9 && grid[piece.y][piece.x+1].value != '#' && grid[piece.y-1][piece.x+1].value != '#' && grid[piece.y-2][piece.x+1].value != '#' && grid[piece.y-3][piece.x+1].value != '#')
                                piece.x++;
                            break;
                        case 1:
                            if(piece.x < 9 && grid[piece.y][piece.x+1].value != '#')
                                piece.x++;
                            break;
                        case 2:
                            if(piece.x < 9 && grid[piece.y][piece.x+1].value != '#' && grid[piece.y-1][piece.x+1].value != '#' && grid[piece.y-2][piece.x+1].value != '#' && grid[piece.y-3][piece.x+1].value != '#')
                                piece.x++;
                            break;
                        case 3:
                            if(piece.x < 9 && grid[piece.y][piece.x+1].value != '#')
                                piece.x++;
                            break;
                    }
                    break;
                case 'J':
                    switch(piece.rotation)
                    {
                        case 0:
                            if(piece.x < 8 && grid[piece.y][piece.x+2].value != '#' && grid[piece.y-1][piece.x].value != '#')
                                piece.x++;
                            break;
                        case 1:
                            if(piece.x < 8 && grid[piece.y][piece.x+1].value != '#' && grid[piece.y-1][piece.x+1].value != '#' && grid[piece.y-2][piece.x+2].value != '#')
                                piece.x++;
                            break;
                        case 2:
                            if(piece.x < 9 && grid[piece.y][piece.x+1].value != '#' && grid[piece.y-1][piece.x+1].value != '#')
                                piece.x++;
                            break;
                        case 3:
                            if(piece.x < 9 && grid[piece.y][piece.x+1].value != '#' && grid[piece.y-1][piece.x+1].value != '#' && grid[piece.y-2][piece.x+1].value != '#')
                                piece.x++;
                            break;
                    }
                    break;
                case 'L':
                    switch(piece.rotation)
                    {
                        case 0:
                            if(piece.x < 8 && grid[piece.y][piece.x+2].value != '#' && grid[piece.y-1][piece.x+2].value != '#')
                                piece.x++;
                            break;
                        case 1:
                            if(piece.x < 8 && grid[piece.y][piece.x+2].value != '#' && grid[piece.y-1][piece.x+1].value != '#' && grid[piece.y-2][piece.x+1].value != '#')
                                piece.x++;
                            break;
                        case 2:
                            if(piece.x < 7 && grid[piece.y][piece.x+1].value != '#' && grid[piece.y-1][piece.x+3].value != '#')
                                piece.x++;
                            break;
                        case 3:
                            if(piece.x < 9 && grid[piece.y][piece.x+1].value != '#' && grid[piece.y-1][piece.x+1].value != '#' && grid[piece.y-2][piece.x+1].value != '#')
                                piece.x++;
                            break;
                    }
                    break;
                case 'O':
                    if(piece.x < 8 && grid[piece.y][piece.x+2].value != '#' && grid[piece.y-1][piece.x+2].value != '#')
                        piece.x++;
                    break;
                case 'S':
                    switch(piece.rotation)
                    {
                        case 0:
                            if(piece.x < 8 && grid[piece.y][piece.x+1].value != '#' && grid[piece.y-1][piece.x+2].value != '#')
                                piece.x++;
                            break;
                        case 1:
                            if(piece.x < 9 && grid[piece.y][piece.x+1].value != '#' && grid[piece.y-1][piece.x+1].value != '#' && grid[piece.y-2][piece.x].value != '#')
                                piece.x++;
                            break;
                        case 2:
                            if(piece.x < 8 && grid[piece.y][piece.x+1].value != '#' && grid[piece.y-1][piece.x+2].value != '#')
                                piece.x++;
                            break;
                        case 3:
                            if(piece.x < 9 && grid[piece.y][piece.x+1].value != '#' && grid[piece.y-1][piece.x+1].value != '#' && grid[piece.y-2][piece.x].value != '#')
                                piece.x++;
                            break;
                    }
                    break;
                case 'T':
                    switch(piece.rotation)
                    {
                        case 0:
                            if(piece.x < 8 && grid[piece.y][piece.x+2].value != '#' && grid[piece.y-1][piece.x+1].value != '#')
                                piece.x++;
                            break;
                        case 1:
                            if(piece.x < 8 && grid[piece.y][piece.x+1].value != '#' && grid[piece.y-1][piece.x+2].value != '#' && grid[piece.y-2][piece.x+1].value != '#')
                                piece.x++;
                            break;
                        case 2:
                            if(piece.x < 8 && grid[piece.y][piece.x+1].value != '#' && grid[piece.y-1][piece.x+2].value != '#')
                                piece.x++;
                            break;
                        case 3:
                            if(piece.x < 9 && grid[piece.y][piece.x+1].value != '#' && grid[piece.y-1][piece.x+1].value != '#' && grid[piece.y-2][piece.x+1].value != '#')
                                piece.x++;
                            break;
                    }
                    break;
                case 'Z':
                    switch(piece.rotation)
                    {
                        case 0:
                            if(piece.x < 8 && grid[piece.y][piece.x+2].value != '#' && grid[piece.y-1][piece.x+1].value != '#')
                                piece.x++;
                            break;
                        case 1:
                            if(piece.x < 8 && grid[piece.y][piece.x+1].value != '#' && grid[piece.y-1][piece.x+2].value != '#' && grid[piece.y-2][piece.x+2].value != '#')
                                piece.x++;
                            break;
                        case 2:
                            if(piece.x < 8 && grid[piece.y][piece.x+2].value != '#' && grid[piece.y-1][piece.x+1].value != '#')
                                piece.x++;
                            break;
                        case 3:
                            if(piece.x < 8 && grid[piece.y][piece.x+1].value != '#' && grid[piece.y-1][piece.x+2].value != '#' && grid[piece.y-2][piece.x+2].value != '#')
                                piece.x++;
                            break;
                    }
                    break;
            }
            ghost_piece.y = piece.y;
        }
            
        if(in == 'w' && valid_rotation(grid, piece)){
            piece.rotation = (piece.rotation + 1) % 4;
            ghost_piece.y = 0;
        }
            
        if (in == ' '){
            hard_drop = 1;
            score += 2*(ghost_piece.y - piece.y);
            piece.y = ghost_piece.y;
        }
        if(in == 's'){
            velocity = fmin(1, 0.2+(level-1)*0.05);
            score += fmin(1, 0.2+(level-1)*0.05);
        }
        else{
            if(piece.y < 5){
                velocity = fmin(0.5, 0.1+(level-1)*0.025);
            }
            else{
               velocity = fmin(0.15, 0.03+(level-1)*0.0075); 
            }
        }
        if( checkcollision(grid, piece, &velocity, hard_drop, level, state)){
            spawn = 1;
            piece = next_piece;
            piece.x = 4;
            piece.y = 0;
            y = piece.y;
        }
        y += velocity;
        if(!hard_drop){
            piece.y = floor(y);
        }
        for(int k = 5; k < 25; k++){
            if(full_row(grid, k)){
                full_rows++;
                score += 100;
                clear_row(grid, k);
                if(full_rows == 4){
                    score += 100;
                }
            }
        }
        full_rows = 0;
        usleep(16666);
    }
}

void game_over(char state[5], Cell grid[25][10])
{
    char in;
    emptygrid(grid);
    clear_screen();
    while(1)
    {
        reset_cursor();
        setcolor(red);
        for(int k = 0; k <= 4; k++)
        {
            printf("\n");
        }
        printf("\t\t\t  ######  ######  ##   ##  ######      ######  #     #  ######  ####    #  \n");
        printf("\t\t\t  #       #    #  # # # #  #           #    #  #     #  #       #   #   #  \n");
        printf("\t\t\t  #  ###  ######  #  #  #  #####       #    #   #   #   #####   ####    #  \n");
        printf("\t\t\t  #    #  #    #  #     #  #           #    #    # #    #       #   #      \n");
        printf("\t\t\t  ######  #    #  #     #  ######      ######     #     ######  #    #  #  \n");
        printf("\n\n");
        setcolor(reset);
        printf("\t\t\t\t\t\tPress SPACE to Restart\n");
        printf("\t\t\t\t\t\t  Press Q to Quit");
        in = input();
        if(in == ' '){
            strcpy(state, "game");
            clear_screen();
            return;
        }
        if(in == 'q'){
            quit();
        }
        usleep(16666);
    }
}

int main()
{
    Cell grid[25][10];
    init(grid);
    char state[5] = "menu";
    while(1){
        if(strcmp(state, "menu") == 0){
            menu(state);
        }
        if(strcmp(state, "game") == 0){
            game(grid, state);
        }
        if(strcmp(state, "over") == 0){
            game_over(state, grid);
        }
    }
    atexit(quit);
    return 0;
}