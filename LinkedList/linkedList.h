#ifndef LINKED_LIST_H
#define LINKED_LIST_H
struct Node
{
  int id;
  int value;
  struct Node *next;
};

typedef struct
{
  int size;
  struct Node *head;
} linkedList;

enum Arithmetic
{
  ADD,
  MINUS,
  MUL,
  DIV
};

/*
* Konstruktory
*/
linkedList *createList();
linkedList *createListFromArray(const int *const, const int);
linkedList *createListFromList(linkedList *const);
linkedList *createRandomList();
int *createArrayFromList(linkedList *);

/*
* Dodawanie elementów do listy
*/
void addNode(linkedList *const, const int);
void addNodeAfter(linkedList *const, const int, const int);
void addNodeBefore(linkedList *const, const int, const int);

/*
* Szukanie elementów w liście
*/
int searchById(linkedList *const, const int);
int searchByValue(linkedList *const, const int);

/*
* Operacje na liście/listach
*/
int listSum(linkedList *const);
int listSize(linkedList *const);
linkedList *arithmeticLists(linkedList *const, linkedList *const, enum Arithmetic);
linkedList *mergeLists(linkedList *const, linkedList *const);

/*
* Usuwanie elementów z listy
*/
void deleteList(linkedList *);
void deleteNodeById(linkedList *const, const int);
void deleteNodeByValue(linkedList *const, const int);

/*
* Wyświetlanie elementów listy, utilities
*/
void printList(linkedList *const);
void errorHandler(const char *);

#endif