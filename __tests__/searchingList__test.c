#include "./linkedList__test.h"

void searchById__test()
{
  srand(time(NULL));
  for (int i = 0; i < 100; ++i)
  {
    int Id = rand() % 100;
    linkedList *testcase = (linkedList *)malloc(sizeof(linkedList));
    if (testcase)
    {
      testcase->head = NULL;
      testcase->size = 0;
    }
    for (int j = 0; j < 100; ++j)
    {
      addNode(testcase, j);
    }
    int found_id = searchById(testcase, Id);
    if (found_id != Id)
    {
      printf("searchById__test failed at iteration: %d, searched id: %d, found id: %d\n", i, Id, found_id);
      return;
    }
  }
  printf("searchById__test() -> passed\n");
}
void searchByValue__test()
{
  srand(time(NULL));
  for (int i = 0; i < 100; ++i)
  {
    int value = rand() % 100;
    linkedList *testcase = (linkedList *)malloc(sizeof(linkedList));
    if (testcase)
    {
      testcase->head = NULL;
      testcase->size = 0;
    }
    for (int j = 0; j < 100; ++j)
    {
      addNode(testcase, j);
    }
    int found_id = searchByValue(testcase, value);
    if (found_id != value)
    {
      printf("searchByValue__test failed at iteration: %d, searched value: %d, found id: %d\n", i, value, found_id);
      return;
    }
  }
  printf("searchByValue__test() -> passed\n");
}

void RUN_SEARCHING_LIST_TESTS()
{
  searchById__test();
  searchByValue__test();
}