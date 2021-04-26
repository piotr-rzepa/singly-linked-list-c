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
//gcc -Wall -Wshadow main.c ./__tests__/linkedList__test_main.c ./__tests__/deletingList__test.c ./__tests__/operationsList__test.c ./__tests__/searchingList__test.c ./__tests__/addingNode__test.c ./__tests__/creatingList__test.c ./LinkedList/addingNode.c ./LinkedList/creatingList.c ./LinkedList/deletingList.c ./LinkedList/linkedList.c ./LinkedList/operationsList.c ./LinkedList/searchingList.c -o test && test