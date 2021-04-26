#include "./linkedList__test.h"

void listSum__test()
{
  srand(time(NULL));
  for (int i = 0; i < 100; ++i)
  {
    int sum = 0;
    linkedList *testcase1 = (linkedList *)malloc(sizeof(linkedList));
    if (testcase1)
    {
      testcase1->head = NULL;
      testcase1->size = 0;
    }
    for (int j = 0; j < 100; ++j)
    {
      int random = rand() % 100;
      sum += random;
      addNode(testcase1, random);
    }
    if (sum != listSum(testcase1))
    {
      printf("listSum__test failed at iteration: %d, sum of list: %d, correct sum: %d", i, listSum(testcase1), sum);
      return;
    }
  }
  printf("listSum__test() -> passed\n");
}
void listSize__test()
{
  srand(time(NULL));
  for (int i = 0; i < 100; ++i)
  {
    linkedList *testcase1 = (linkedList *)malloc(sizeof(linkedList));
    if (testcase1)
    {
      testcase1->head = NULL;
      testcase1->size = 0;
    }
    int randomSize = rand() % 100;
    for (int j = 0; j < randomSize; ++j)
    {
      addNode(testcase1, j);
    }
    if (listSize(testcase1) != randomSize)
    {
      printf("listSize__test failed at iteration: %d, size of list: %d, correct size: %d", i, listSize(testcase1), randomSize);
      return;
    }
  }
  printf("listSize__test() -> passed\n");
}

void arithmeticLists__test()
{
  srand(time(NULL));
  for (int operation = 0; operation < 4; ++operation)
  {
    for (int i = 0; i < 10; ++i)
    {
      const int someValue = rand() % 100;
      linkedList *testcase1 = (linkedList *)malloc(sizeof(linkedList));
      linkedList *testcase2 = (linkedList *)malloc(sizeof(linkedList));
      if (testcase1 && testcase2)
      {
        testcase1->head = NULL;
        testcase2->head = NULL;
        testcase1->size = 0;
        testcase2->size = 0;
      }
      for (int j = 0; j < 100; ++j)
      {
        addNode(testcase1, someValue);
        addNode(testcase2, someValue);
      }
      linkedList *result = arithmeticLists(testcase1, testcase2, operation);
      struct Node *temp = result->head;
      while (temp != NULL)
      {
        switch (operation)
        {
        case 0:
        {
          const int sum = someValue + someValue;
          if (temp->value != sum)
          {
            printf("arithmeticLists__test failed at iteration: %d, operation: %d, value: %d, correct value: %d", i, operation, temp->value, sum);
            return;
          }
          temp = temp->next;
          break;
        }
        case 1:
        {
          if (temp->value != someValue - someValue)
          {
            printf("arithmeticLists__test failed at iteration: %d, operation: %d, value: %d, correct value: %d", i, operation, temp->value, someValue - someValue);
            return;
          }
          temp = temp->next;
          break;
        }
        case 2:
        {
          if (temp->value != someValue * someValue)
          {
            printf("arithmeticLists__test failed at iteration: %d, operation: %d, value: %d, correct value: %d", i, operation, temp->value, someValue * someValue);
            return;
          }
          temp = temp->next;
          break;
        }
        case 3:
        {
          if (temp->value != someValue / someValue)
          {
            printf("arithmeticLists__test failed at iteration: %d, operation: %d, value: %d, correct value: %d", i, operation, temp->value, 1);
            return;
          }
          temp = temp->next;
          break;
        }
        default:
          break;
        }
      }
    }
  }
  printf("arithmeticLists__test() -> passed\n");
}
void mergeLists__test()
{
  srand(time(NULL));
  for (int i = 0; i < 10; ++i)
  {
    linkedList *testcase1_longer = (linkedList *)malloc(sizeof(linkedList));
    linkedList *testcase1 = (linkedList *)malloc(sizeof(linkedList));
    if (testcase1_longer && testcase1)
    {
      testcase1_longer->head = NULL;
      testcase1->head = NULL;
      testcase1_longer->size = 0;
      testcase1->size = 0;
    }
    int size1 = rand() % 100;
    for (int j = 0; j < size1; ++j)
    {
      addNode(testcase1_longer, j);
    }
    int size2 = rand() % 100;
    for (int j = 0; j < size2; ++j)
    {
      addNode(testcase1, j);
    }
    linkedList *result = mergeLists(testcase1_longer, testcase1);
    if (result->size != size1 + size2)
    {
      printf("mergeLists__test failed at iteration: %d, sum of lists: %d, correct sum: %d", i, result->size, size1 + size2);
      return;
    }
  }
  printf("mergeLists__test() -> passed\n");
}

void RUN_OPERATIONS_LIST_TESTS()
{
  listSize__test();
  listSum__test();
  arithmeticLists__test();
  mergeLists__test();
}