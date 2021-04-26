#ifndef LINKED_LIST_TEST_H
#define LINKED_LIST_TEST_H
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include "../LinkedList/linkedList.h"

void createList__test();
void createListFromArray__test();
void createListFromList__test();
void createArrayFromList__test();
void RUN_CREATE_LIST_TESTS();

/*
* Dodawanie elementów do listy
*/
void addNode__test();
void addNodeAfter__test();
void addNodeBefore__test();
void RUN_ADDING_NODE_TESTS();
/*
* Szukanie elementów w liście
*/
void searchById__test();
void searchByValue__test();
void RUN_SEARCHING_LIST_TESTS();

/*
* Operacje na liście/listach
*/
void listSum__test();
void listSize__test();
void arithmeticLists__test();
void mergeLists__test();
void RUN_OPERATIONS_LIST_TESTS();

/*
* Usuwanie elementów z listy
*/
void deleteList__test();
void deleteNodeById__test();
void deleteNodeByValue__test();
void RUN_DELETING_LIST_TESTS();

/*
* Utilities
*/
void reverseArray(int *const, const int);
int *testcase_array(const int);
/*
* Przeprowadzenie testów 
*/
void RUN_ALL_TESTS();

#endif