#ifndef __SUDOKU__
#define __SUDOKU__

typedef int Board[9][9];

void print_board(Board grid);
int permutations (Board grid, int ligne, int colonne);

#endif
