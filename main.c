#include <stdio.h>
#include "sudoku.h"
#include "in_out.h"

int main(int argc, char* argv[]){
  Board B;

  /* Vérifier qu'il y a bien 2 arguments dans*/
  if (argc >= 2) {
      if (!fread_board(argv[1], B)) /*Si y'a une erreur alors */
          return 404; /*return erreur*/
      permutations(B,0,0);

      print_board(B);
  } else {
      printf("essayer : /sudoku <grille>\n");
      return 404;
  }
  return 0;
}
