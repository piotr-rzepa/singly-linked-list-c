#include "./linkedList__test.h"

void createList__test()
{
  for (int i = 0; i < 100; ++i)
  {
    linkedList *l = (linkedList *)malloc(sizeof(linkedList));
    if (l)
    {
      l->head = NULL;
      l->size = 0;
    }
    else
    {
      printf("createList__test failed at iteration: %d, memory not allocated\n", i);
      return;
    }
    free(l);
    l = NULL;
  }
  printf("createList__test() -> passed\n");
}

void createListFromArray__test()
{
  for (int i = 0; i < 10; ++i)
  {
    int *arr = testcase_array(100);
    linkedList *testcase = createListFromArray(arr, 100);
    struct Node *temp = testcase->head;
    for (int j = 0; j < 100; ++j)
    {
      if (temp->value != *(arr + j))
      {
        printf("createListFromArray__test failed at iteration: %d, (list[%d] = %d) != (array[%d] = %d)\n", j, j, temp->value, j, *(arr + j));
        return;
      }
      else
      {
        temp = temp->next;
      }
    }
  }
  printf("createListFromArray__test() -> passed\n");
}

void createListFromList__test()
{
  for (int i = 0; i < 10; ++i)
  {
    int *arr = testcase_array(100);
    linkedList *listFrom = createListFromArray(arr, 100);
    linkedList *testcase = createListFromList(listFrom);
    struct Node *temp = testcase->head;
    for (int j = 0; j < 100; ++j)
    {
      if (temp->value != *(arr + j) && temp->value != listFrom->head->value)
      {
        printf("createListFromArray__test failed at iteration: %d, (list[%d] = %d) != (array[%d] = %d) && (list[%d] = %d) != (listFrom[%d] = %d)\n", j, j, temp->value, j, *(arr + j), j, temp->value, j, listFrom->head->value);
        return;
      }
      else
      {
        temp = temp->next;
        listFrom->head = listFrom->head->next;
      }
    }
  }
  printf("createListFromList__test() -> passed\n");
}

void createArrayFromList__test()
{
  for (int i = 0; i < 10; ++i)
  {
    linkedList *testcase = (linkedList *)malloc(sizeof(linkedList));
    if (testcase)
    {
      testcase->head = NULL;
      testcase->size = 0;
    }
    srand(time(NULL));
    for (int j = 0; j < 100; ++j)
    {
      addNode(testcase, rand() % 100);
    }
    int *array = createArrayFromList(testcase);
    struct Node *temp = testcase->head;
    for (int j = 0; j < 100; ++j)
    {
      if (temp->value != *(array + j))
      {
        printf("createArrayFromList__test failed at iteration: %d, (list[%d] = %d) != (array[%d] = %d)", j, j, temp->value, j, *(array + j));
        return;
      }
      else
      {
        temp = temp->next;
      }
    }
  }
  printf("createArrayFromList__test() -> passed\n");
}

void RUN_CREATE_LIST_TESTS()
{
  createList__test();
  createListFromArray__test();
  createListFromList__test();
  createArrayFromList__test();
}