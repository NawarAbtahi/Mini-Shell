#include "headers/headers.h"
#include "headers/prototypes.h"

char *shell_read_line();
char **shell_split_line(char *line);
int help(char **args);
int shell_execute(char **args);

int num_of_builtin_func();

char *builtin_str[] = {
  "cd",
  "getdir",
  "lsf",
  "clscr",
  "--help",
  "quit"
};

int (*builtin_func[])(char**) = {
  &cd,
  &getdir,
  &lsf,
  &clearscr,
  &help,
  &quit
};

int main(int argc, char **argv){
  char *line;
  char **args;
  int status;

  do{
    printf("> ");
    line = shell_read_line();
    args = shell_split_line(line);
    status = shell_execute(args);
  }while(status);

  return 0;
}

char *shell_read_line(){
  int line_size = LINE_SIZE;
  int position = 0;
  char *line = (char* )malloc(line_size * sizeof(char));

  if(!line){
    fprintf(stderr, "shell: allocation error\n");
    exit(EXIT_FAILURE);
  }
  
  int get_inp;

  while(1){
    get_inp = getchar();

    if(get_inp == EOF || get_inp == '\n'){
      line[position] = '\0';
      return line;
    }
    else{
      line[position] = get_inp;
    }
    position++;

    if(position >= TOKEN_SIZE){
      line_size += TOKEN_SIZE;
      line = realloc(line, line_size* sizeof(char));

      if(!line){
        fprintf(stderr, "shell: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}

char **shell_split_line(char *line){
  int token_size = TOKEN_SIZE;
  int position = 0;
  char **tokens = (char** )malloc(token_size * sizeof(char*));

  if(!tokens){
    fprintf(stderr, "shell: allocation error\n");
    exit(EXIT_FAILURE);
  }

  char *token = strtok(line, TOKEN_DELIM);

  while(token !=NULL){
    tokens[position] = token;
    position++;

    if(position >= TOKEN_SIZE){
      token_size += TOKEN_SIZE;

      tokens = realloc(tokens, token_size * sizeof(char*));
      if(!tokens){
        fprintf(stderr, "shell: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, TOKEN_DELIM);
  }

  tokens[position] = NULL;

  return tokens;
}

int num_of_builtin_func(){
  return (sizeof(builtin_str)) / sizeof(char*);
}

int help(char **args){
  printf("~-Abtahi's Shell-~\n\n");
  printf("Here are the following built-in commands:\n\n");

  for(int i = 0; i < num_of_builtin_func(); i++){
    printf("  %s\n", builtin_str[i]);
  }

  return 1;
}

int shell_execute(char **args){
  if(args[0] == NULL){
    return 1;
  }
 
  int wrong_command = 0;

  for(int i = 0; i < num_of_builtin_func(); i++){
    if((strcmp(args[0], builtin_str[i])) == 0){
      return builtin_func[i](args);
    }
    else{
      wrong_command = 1;
    }
  }

  if(wrong_command){
    printf("No commands found with '%s'\n",args[0]);
    printf("Type '--help' to see shell's commands.\n");
  }
  return 1;  
}
