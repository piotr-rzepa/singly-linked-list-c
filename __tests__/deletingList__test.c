#include "./linkedList__test.h"

void deleteList__test()
{
  for (int i = 0; i < 100; ++i)
  {
    linkedList *testcase = (linkedList *)malloc(sizeof(linkedList));
    for (int j = 0; j < 100; ++j)
    {
      addNode(testcase, j);
    }
    deleteList(testcase);
    if (!testcase)
    {
      printf("deleteList__test failed at iteration: %d, list != NULL\n", i);
      return;
    }
  }
  printf("deleteList__test() -> passed\n");
}

void deleteNodeById__test()
{
  srand(time(NULL));
  for (int i = 0; i < 100; ++i)
  {
    int randomId = rand() % 100;
    linkedList *testcase = (linkedList *)malloc(sizeof(linkedList));
    for (int j = 0; j < 100; ++j)
    {
      addNode(testcase, j);
    }
    deleteNodeById(testcase, randomId);
    struct Node *temp = testcase->head;
    for (int j = 0; j < 99; ++j)
    {
      if (temp->value == randomId)
      {
        printf("deleteNodeById__test failed at iteration: %d, deleted value (%d) exists!\n", i, randomId);
        return;
      }
    }
  }
  printf("deleteNodeById__test() -> passed\n");
}

void deleteNodeByValue__test()
{
  srand(time(NULL));
  for (int i = 0; i < 100; ++i)
  {
    int randomValue = rand() % 100;
    linkedList *testcase = (linkedList *)malloc(sizeof(linkedList));
    for (int j = 0; j < 100; ++j)
    {
      addNode(testcase, j);
    }
    deleteNodeById(testcase, randomValue);
    struct Node *temp = testcase->head;
    for (int j = 0; j < 99; ++j)
    {
      if (temp->value == randomValue)
      {
        printf("deleteNodeById__test failed at iteration: %d, deleted value (%d) exists!\n", i, randomValue);
        return;
      }
    }
  }
  printf("deleteNodeById__test() -> passed\n");
}

void RUN_DELETING_LIST_TESTS()
{
  deleteList__test();
  deleteNodeById__test();
  deleteNodeByValue__test();
}