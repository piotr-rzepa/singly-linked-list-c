#include "./linkedList__test.h"

int *testcase_array(const int size)
{
  int *arr = calloc(size, sizeof(int));
  srand(time(NULL));
  for (int i = 0; i < size; ++i)
  {
    *(arr + i) = rand() % 100;
  }
  return arr;
}

void addNode__test()
{
  for (int i = 0; i < 10; ++i)
  {
    int *arr = testcase_array(100);
    linkedList *testcase = (linkedList *)malloc(sizeof(linkedList));
    testcase->head = NULL;
    testcase->size = 0;
    for (int j = 0; j < 100; ++j)
    {
      addNode(testcase, *(arr + j));
    }
    struct Node *temp = testcase->head;
    for (int k = 0; k < 100; ++k)
    {
      if (temp->value != *(arr + k))
      {
        printf("addNode__test failed at iteration: %d, (list[%d] = %d) != (array[%d] = %d)\n", k, k, temp->value, k, *(arr + k));
        return;
      }
      temp = temp->next;
    }
    free(testcase);
    testcase = NULL;
  }
  printf("addNode__test() -> passed\n");
}

void addNodeAfter__test()
{
  for (int i = 0; i < 10; ++i)
  {
    int *arr = testcase_array(101);
    linkedList *testcase = (linkedList *)malloc(sizeof(linkedList));
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    first->id = 0;
    first->next = NULL;
    first->value = *(arr);
    testcase->head = first;
    testcase->size = 1;

    for (int j = 0; j < 100; ++j)
    {
      addNodeAfter(testcase, j, *(arr + j + 1));
    }
    struct Node *temp = testcase->head;
    for (int k = 0; k < 101; ++k)
    {
      if (temp->value != *(arr + k))
      {
        printf("addNodeAfter__test failed at iteration: %d, (list[%d] = %d) != (array[%d] = %d)\n", k, k, temp->value, k, *(arr + k));
        return;
      }
      temp = temp->next;
    }
  }
  printf("addNodeAfter__test() -> passed\n");
}

void addNodeBefore__test()
{
  for (int i = 0; i < 10; ++i)
  {
    int *arr = testcase_array(101);
    linkedList *testcase = (linkedList *)malloc(sizeof(linkedList));
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    first->id = 0;
    first->next = NULL;
    first->value = *(arr);
    testcase->head = first;
    testcase->size = 1;

    for (int j = 0; j < 100; ++j)
    {
      addNodeAfter(testcase, j, *(arr + j + 1));
    }
    struct Node *temp = testcase->head;
    reverseArray(arr, 101);
    for (int k = 0; k < 101; ++k)
    {
      if (temp->value != *(arr + k))
      {
        printf("addNodeAfter__test failed at iteration: %d, (list[%d] = %d) != (array[%d] = %d)\n", k, k, temp->value, k, *(arr + k));
        return;
      }
      temp = temp->next;
    }
  }
  printf("addNodeBefore__test() -> passed\n");
}

//* Utility do sprawdzania listy po dodaniu węzła przed dany indeks
void reverseArray(int *const array, const int size)
{
  for (int i = i; i < size / 2; ++i)
  {
    int temp = *(array + i);
    *(array + i) = *(array + (size - i - 1));
    *(array + (size - i - 1)) = temp;
  }
}

void RUN_ADDING_NODE_TESTS()
{
  addNode__test();
  addNodeAfter__test();
  addNodeBefore__test();
}