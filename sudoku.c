#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sudoku.h"

/* void initialize_empty_board(Board grid) */

/* void clearScreen(){
    const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
     write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
 } */

/*affiche le sudoku*/
void print_board(Board grid){
    int i, e;

    for(i=0; i<9; i++){
        printf("-------------------------------------\n");
        for(e=0; e<9; e++){
            if(e == 0){
                printf("| %d |",grid[i][e]);
            }
            else{
                printf(" %d |",grid[i][e]);
            }
        }
        printf("\n");
    }
    printf("-------------------------------------\n");
}

/*renvoie 1 si la grille est valide, 0 sinon*/
int grid_valid(Board grid){
    int x, y;

    for(x=0; x<9; x++){
        for(y=0; y<9; y++){
            if(grid[x][y]==0){
                return 0;
            }
        }
    }

    return 1;
}

/*renvoie 1 si la valeur se trouve dans la même ligne, 0 sinon*/
int line_valid(Board grid, int x, int value){
    int y;

    for(y=0; y<9; y++){
        if(grid[x][y]==value){
            return 1;
        }
    }

    return 0;
}

/*renvoie 1 si la valeur se trouve dans la même colonne, 0 sinon*/
int column_valid(Board grid, int y, int value){
    int x;

    for(x=0; x<9; x++){
        if(grid[x][y]==value){
            return 1;
        }
    }

    return 0;
}

/*renvoie 1 si la valeur se trouve dans la même case, 0 sinon*/
int box_valid(Board grid, int x, int y, int value){
    int line, column;

    for(line=0;line<=2;line++){
        for(column=0;column<=2;column++){
            if(grid[line+3*(x/3)][column+3*(y/3)]==value){
                return 1;
            }
        }
    }

    return 0;
}

int permutations (Board grid, int ligne, int colonne)
{
    int k;

    /*si on sort du sudoku (il n'y a que 9 lignes)*/
    if (ligne > 8)
        return 1;

    /*la cellule contient une valeur: on passe à la suivante*/
    if (grid[ligne][colonne] != 0) {
        if (colonne == 8)
            return permutations(grid, ligne+1, 0);
        else
            return permutations(grid, ligne, colonne+1);  
    }

    /*la cellule contient un zéro, on doit donc la remplir*/
    for (k=1; k <= 9; k++)
    {
        if (box_valid(grid,ligne,colonne,k)==0 && line_valid(grid,ligne,k)==0 && column_valid(grid,colonne,k)==0)
        {
            grid[ligne][colonne] = k;

            if (colonne==8) {
                if (permutations(grid, ligne+1, 0))
                    return 1;
                    }
            else{
                if (permutations(grid, ligne, colonne+1))
                    return 1;
                    }        
        }
    }
    /*backtracking : on remet la zone à zéro*/
    grid[ligne][colonne] = 0;
    print_board(grid);
    usleep(100000);

    return 0;
}