
#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main(){
  char* take;
 live:
    take=malloc(501);
    fputs("q at start exits do a space first\n$ ", stdout);
    fflush(stdout);
    fgets(take, 501, stdin);
    //tokenize(take);
    //Histadd(take);
    if (take[0] == 'q')
      goto deez;
    printf("green:  %s\n", take);
    /*printf("%d\n", space_char(*(take+2)));
    printf(non_space_char(*(take+2))?"not":"space");
    printf("\n");
    printf("%c",token_start(take)==NULL?'0':*token_start(take));
    printf("\n");
    */ printf("%d\n",count_tokens(take));
    char** tokens = tokenize(take);
    print_tokens(tokens);
    free_tokens(tokens);
    free(take);
 
     goto live;
 deez:
  return 0;
}
