#include "headers/headers.h"
#include "headers/prototypes.h"
#include <stdio.h>
#include <unistd.h>
int cd(char **args){

  size_t dir_size = Directory_SIZE;
  char *dir = (char* )malloc(dir_size * sizeof(char));

  if(!dir){
    fprintf(stderr, "shell: memory allocation failed");
    return 1;
  }

  if(args[1] == NULL){
    perror("shell: expected command \"cd\"\n");
  }
  else{
    if(chdir(args[1]) != 0){
      perror("lsh");
    }
    else{
      if(getcwd(dir, dir_size) != NULL){
        printf("Directory changed to %s\n", dir);
      }
    }
  }

  return 1;
}
