#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "linkedList.h"

void addNode(linkedList *list, const int value)
{
  //* Alokujemy dynamicznie pamięć na stercie dla nowego elementu
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  //* Jeżeli pomyślnie zaalokowaliśmy pamięć, wypełniamy węzeł
  if (newNode)
  {
    newNode->value = value;
    newNode->id = list->size;
    newNode->next = NULL;
    list->size++;
    //* Jeżeli lista była pusta, nowy element staje się głową
    if (list->head == NULL)
      list->head = newNode;
    else
    {
      //* Iterujemy do końca listy aby dodać nowy element
      struct Node *temp = list->head;
      while (temp->next != NULL)
      {
        temp = temp->next;
      }
      temp->next = newNode;
    }
  }
}

void addNodeAfter(linkedList *list, const int id, const int value)
{
  if (id >= list->size || id < 0)
    errorHandler("Bad index\n");
  struct Node *newNode = (struct Node *)malloc((sizeof(struct Node)));
  //* Jeżeli pomyślnie zaalokowaliśmy pamięć, możemy zacząć szukać po ID
  if (newNode)
  {
    struct Node *temp = list->head;
    while (temp != NULL && temp->id != id)
    {
      temp = temp->next;
    }
    //* Jeżeli nie znaleźliśmy węzła o danym ID
    if (temp == NULL)
      return;

    //* Wypełniamy nowy węzeł dopiero w momencie znalezienia dla niego miejsca
    newNode->value = value;
    newNode->id = temp->id + 1;
    newNode->next = temp->next;
    temp->next = newNode;

    //* Poprawianie indeksów po dodaniu elementu
    struct Node *temp2 = newNode->next;
    while (temp2 != NULL)
    {
      temp2->id = temp2->id + 1;
      temp2 = temp2->next;
    }
    list->size++;
  }
}

void addNodeBefore(linkedList *list, const int id, const int value)
{
  if (id >= list->size || id < 0)
    errorHandler("Bad index\n");
  struct Node *newNode = (struct Node *)malloc((sizeof(struct Node)));
  //* Jeżeli pomyślnie zaalokowaliśmy pamięć, możemy zacząć szukać po ID
  if (newNode)
  {

    struct Node *temp = list->head;
    //* Sytuacja gdy chcemy dodać węzeł jako nową głowę
    if (temp != NULL && temp->id == id)
    {
      newNode->value = value;
      newNode->id = 0;
      newNode->next = temp;
      list->head = newNode;
    }
    else
    {
      while (temp != NULL && temp->next->id != id)
        temp = temp->next;

      //* Jeżeli nie znaleźliśmy węzła o danym ID
      if (temp == NULL)
        return;

      //* Wypełniamy nowy węzeł dopiero w momencie znalezienia dla niego miejsca
      newNode->value = value;
      newNode->id = temp->id + 1;
      newNode->next = temp->next;
      temp->next = newNode;
    }

    //* Poprawianie indeksów po dodaniu elementu
    struct Node *temp2 = newNode->next;
    while (temp2 != NULL)
    {
      temp2->id = temp2->id + 1;
      temp2 = temp2->next;
    }
    list->size++;
  }
}