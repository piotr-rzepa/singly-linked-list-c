#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include "linkedList.h"

linkedList *createList()
{
  linkedList *l = (linkedList *)malloc(sizeof(linkedList));
  if (l)
  {
    l->head = NULL;
    l->size = 0;
  }
  return l;
}

linkedList *createListFromArray(const int *arr, const int size)
{
  linkedList *l = createList();
  for (int i = 0; i < size; ++i)
  {
    addNode(l, *(arr + i));
  }
  return l;
}

linkedList *createListFromList(linkedList *const list)
{
  linkedList *l = createList();
  struct Node *temp = list->head;
  while (temp != NULL)
  {
    addNode(l, temp->value);
    temp = temp->next;
  }
  return l;
}

int *createArrayFromList(linkedList *list)
{
  struct Node *temp = list->head;
  int *arr = (int *)malloc(list->size * sizeof(int));
  for (int i = 0; i < list->size; ++i)
  {
    *(arr + i) = temp->value;
    temp = temp->next;
  }
  return arr;
}

//* Tworzenie listy o losowym rozmiarze i losowych wartościach; głównie do debugowania
linkedList *createRandomList()
{
  srand(time(NULL));
  linkedList *l = createList();
  const unsigned int cnt = rand() % 100;
  for (int i = 0; i < cnt; ++i)
  {
    addNode(l, (rand() % 2000) - 1000); //* Zakres  < -1000;999 >
  }
  return l;
}
