#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "linkedList.h"

//* Zwraca wartość pod daną pozycją
int searchById(linkedList *list, const int id)
{
  if (id >= list->size || id < 0)
    errorHandler("Bad index\n");
  struct Node *temp = list->head;
  while (temp->id != id)
  {
    if (temp->next == NULL)
      return NULL;
    temp = temp->next;
  }
  return temp->value;
}

//* Zwraca indeks danej pozycji
int searchByValue(linkedList *const list, const int value)
{
  struct Node *temp = list->head;
  while (temp->value != value)
  {
    temp = temp->next;
  }
  if (temp == NULL)
    return -1;
  return temp->id;
}