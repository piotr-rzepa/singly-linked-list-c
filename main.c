#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "LinkedList/linkedList.h"

void foo()
{
  printf("Hello World!\n");
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  linkedList *l1 = createList();
  linkedList *l2 = createRandomList();
  linkedList *l3 = createListFromArray(arr, sizeof arr / sizeof arr[0]);
  linkedList *l4 = createListFromList(l3);
  printList(l1);
  printList(l2);
  printList(l3);
  printList(l4);
  return 0;
}