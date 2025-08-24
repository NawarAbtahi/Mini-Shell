#include "headers/headers.h"
#include "headers/prototypes.h"

int getdir(char **args){
  size_t dir_size = Directory_SIZE; 
  char *dir = (char* )malloc(dir_size * sizeof(char));

  if (!dir){
    perror("Failed to allocate memory\n");
    return 1;
  }

  if(getcwd(dir, dir_size) != NULL){
    printf("Current working directory: %s\n", dir);
  }
  else{
    perror("Failed to get current directory\n");
  }

  free(dir);
  return 1;
}
