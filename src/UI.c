

#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  char* take;
  List* hist=init_history();
 live:
    take=malloc(501);
    fputs("q at start exits do a space first\n$ ", stdout);
    fflush(stdout);
    fgets(take, 501, stdin);
    //tokenize(take);
    //Histadd(take);
    if (take[0] == 'q')
      goto deez;
    if (take[0] == '?')
      goto hist;
    printf("green:  %s\n", take);
    add_history(hist, take);
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
     hist:
     if(take[1]=='a'){
     print_history(hist);
     }else if(take[1]=='h'){
       free_history(hist);
       hist=init_history();
     }else{
       printf(get_history(hist, *(take+1)-'0'));
     }
     free(take);
     goto live;
 deez:
  return 0;
}
