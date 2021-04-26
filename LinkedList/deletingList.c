#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "linkedList.h"

void deleteList(linkedList *list)
{
  struct Node *temp = list->head;
  struct Node *next;
  while (temp != NULL)
  {
    next = temp->next;
    free(temp);
    temp = next;
  }
  list->head = NULL;
  list->size = 0;
  free(list);
  list = NULL;
}

void deleteNodeById(linkedList *list, const int id)
{
  if (id >= list->size || id < 0)
    errorHandler("Bad index\n");
  struct Node *temp = list->head;
  struct Node *prev = list->head;

  //* Element o danym id jest pierwszy na liście
  if (temp != NULL && temp->id == id)
  {
    list->head = temp->next;
    free(temp);
    list->size--;
  }
  //* Element o danym id nie był pierwszym na liście
  else
  {
    while (temp != NULL && temp->id != id)
    {
      prev = temp;
      temp = temp->next;
    }
    if (temp == NULL)
      return;
    prev->next = temp->next;
    free(temp);
    list->size--;
  }
  //* Poprawianie indeksów po usunięciu elementu
  struct Node *temp2 = temp->next;
  while (temp2 != NULL)
  {
    temp2->id = temp2->id - 1;
    temp2 = temp2->next;
  }
}

void deleteNodeByValue(linkedList *list, const int value)
{
  struct Node *temp = list->head;
  struct Node *prev = list->head;

  //* Element o danym value jest pierwszy na liście
  if (temp != NULL && temp->value == value)
  {
    list->head = temp->next;
    free(temp);
    list->size--;
  }
  //* Element o danym value nie był pierwszym na liście
  else
  {
    while (temp != NULL && temp->value != value)
    {
      prev = temp;
      temp = temp->next;
    }
    if (temp == NULL)
      return;
    prev->next = temp->next;
    free(temp);
    list->size--;
  }
  //* Poprawianie indeksów po usunięciu elementu
  struct Node *temp2 = temp->next;
  while (temp2 != NULL)
  {
    temp2->id = temp2->id - 1;
    temp2 = temp2->next;
  }
}