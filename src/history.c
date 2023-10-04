#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"

 
/* Initialize the linked list to keep the history. */
List* init_history(){
  return calloc(1, sizeof(List));
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
  char *nstr = strdup(str);
  Item *new = calloc(1, sizeof(Item));
  new->str=nstr;
  Item *end = list->root;
  if (end == NULL){
    new->id = 1;
    list->root = new;
  }else{
    int i = 2;
    while(end->next!=NULL){
      end = end->next;
      i++;
    }
    new->id = i;
    end->next = new;
  }

}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
  Item *tem= list->root;
  while(tem!=NULL){
    if (tem->id==id){
    return tem->str;
    }
    tem = tem->next;
  }
  return "not found\n";
}

/*Print the entire contents of the list. */
void print_history(List *list){
Item *tem= list->root;
  while(tem!=NULL){
    printf("%d: %s",tem->id, tem->str);
    tem = tem->next;
  }
}

void free_items(Item *it){
if(it == NULL){
return;
}
free_items(it->next);
free(it->str);
free(it);
}

/*Free the history list and the strings it references. */
void free_history(List *list){
free_items(list->root);
free(list);
}


