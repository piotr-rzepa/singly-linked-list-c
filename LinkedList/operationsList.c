#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include "linkedList.h"

/* 
  * Tworzy nową listę na podstawie operacji miedzy dwoma listami podanymi jako argumenty
  * W przypadku różnych długości list, zwracana lista będzie miała długość = min(l1->size, l2->size);
  * Wykorzystuje typ enum do sterowania rodzajem operacji
*/
linkedList *arithmeticLists(linkedList *const l1, linkedList *const l2, enum Arithmetic ar)
{
  //* 1. Listy są tego samego rozmiaru
  linkedList *l = createList();
  struct Node *temp1 = l1->head;
  struct Node *temp2 = l2->head;
  while (temp1 != NULL && temp2 != NULL)
  {
    switch (ar)
    {
    case ADD:
      addNode(l, (temp1->value + temp2->value));
      break;
    case MINUS:
      addNode(l, (temp1->value - temp2->value));
      break;
    case MUL:
      addNode(l, (temp1->value * temp2->value));
      break;
    case DIV:
      assert(temp2->value != 0);
      addNode(l, (temp1->value / temp2->value));
      break;
    default:
      return NULL;
    }
    temp1 = temp1->next;
    temp2 = temp2->next;
  }
  return l;
}

//* Łączy dwie listę w jedną o długości = sum(l1->size, l2->size)
//* Kolejność łączenia list zalezy od kolejności przesłania ich jako parametr
linkedList *mergeLists(linkedList *const l1, linkedList *const l2)
{
  linkedList *l = createList();
  struct Node *temp_l1 = l1->head;
  struct Node *temp_l2 = l2->head;
  for (; temp_l1 != NULL; temp_l1 = temp_l1->next)
  {
    addNode(l, temp_l1->value);
  }
  for (; temp_l2 != NULL; temp_l2 = temp_l2->next)
  {
    addNode(l, temp_l2->value);
  }
  return l;
}

//* Suma elementów listy
int listSum(linkedList *const list)
{
  int sum = 0;
  struct Node *temp = list->head;
  while (temp != NULL)
  {
    sum += temp->value;
    temp = temp->next;
  }
  return sum;
}

//* Rozmiar tablicy
int listSize(linkedList *const list)
{
  return list->size;
}

void printList(linkedList *list)
{
  struct Node *temp = list->head;
  printf("Size of the list: %d\n", list->size);
  while (temp != NULL)
  {
    printf("Id: %d, Value: %d\n", temp->id, temp->value);
    temp = temp->next;
  }
}