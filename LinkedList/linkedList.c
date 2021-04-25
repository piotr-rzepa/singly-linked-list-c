#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "linkedList.h"

void errorHandler(const char *error)
{
  fprintf(stderr, error);
  exit(EXIT_FAILURE);
}

//gcc -Wall -Wshadow main.c ./LinkedList/addingNode.c ./LinkedList/creatingList.c ./LinkedList/deletingList.c ./LinkedList/linkedList.c ./LinkedList/operationsList.c ./LinkedList/searchingList.c -o test && test