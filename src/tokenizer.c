#include <stdio.h>
#include <stdlib.h>

int space_char(char c){
  return (c == ' ' || c == '\t'|| c=='\n');
}

int non_space_char(char c){
  return (c == '\0')?0:!(space_char(c));
}

char* token_start(char* str){
  
  return non_space_char(*str)?str:space_char(*str)?token_start(str+1):NULL;
}

char* token_terminator(char* token){
  return non_space_char(*token)?token_terminator(token+1):token;
}

int count_tokens(char* str){
  return token_start(str)==NULL?0:1+count_tokens(token_terminator(token_start(str)));
}

char* copy_str(char* inStr, short len){
  char* outStr = malloc(len+1);
  for(int i=0; i < len; i++){
    outStr[i]=inStr[i];
  }
  outStr[len]='\0';
  return outStr;
}

char** tokenize(char* str){
  int count=count_tokens(str);
  int len;
  char** out = malloc(1+(sizeof(char*)*count));
  char* temp;
  temp=str;
  for(int i=0; i<count; i++){
    temp=token_start(temp);
    len = token_terminator(temp)-temp;
    out[i]= copy_str(temp, len);
    temp = temp+len;
  }
  out[count] = NULL;
  return out;
}

void print_tokens(char **tokens){
  int i = 0;
  while (tokens[i] != NULL){
    printf(tokens[i]);
    printf("\n");
    i++;
    }
}

void free_tokens(char **tokens){
int i = 0;
  while (tokens[i] != NULL){
    free(tokens[i]);
    i++;
    }
  free(tokens);
}
