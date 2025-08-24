#include "headers/headers.h"
#include "headers/prototypes.h"
#include <stdio.h>

int lsf(char **args){
  DIR *d = opendir(".");
  if(d == NULL){
    perror("opendir");
    return 1;
  }

  struct dirent *dir;

  while((dir = readdir(d)) != NULL){
    printf("%s ", dir->d_name);
  }
  printf("\n");
  return 1;
}
