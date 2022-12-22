#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "in_out.h"
#include <stdbool.h>
/*J'imagine que c'est return 0 pour erreur et 1 pour ok
Tu peux remplacer par un boolean avec return true ou false
1 = true & 0 = false */
bool fread_board(const char *file, Board board){
  FILE *f = NULL; /*Init un pointeur à NULL, ça evite le problème de mémoire lors de la compil et eviter des erreurs de SEGFAULT ^^*/
  int i = 0,j = 0; /*Init les valeurs à 0, pour éviter que la variable prenne une autre valeur*/
  int entry = 0;
  const char *path = "data/";
  char *full_path = NULL;
  full_path = malloc(strlen(file)+5);
  if (full_path == NULL) {
      return false;
      /*Check un malloc, on sait jamais si il y a un probleme de mémoire, comme ça on ne va pas plus loin*/
  }
  strcpy(full_path, path);
  strcat(full_path, file);

  f = fopen(full_path, "r");
  if (f == NULL){
    fprintf(stderr, "Erreur d'ouverture du fichier %s\n", file);
    return false;
  }

  for (i=0 ; i<9 ; i++){
    for (j=0 ; j<9 ; j++){
      fscanf(f, "%d", &entry);
      board[i][j] = entry;
    }
  }

  return true;
}
