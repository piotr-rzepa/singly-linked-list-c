
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
linkedList *createListFromArray(const int *const arr, const int size);
linkedList *createListFromList(linkedList *const list);
linkedList *createRandomList();
int *createArrayFromList(linkedList *list);

/*
* Dodawanie elementów do listy
*/
void addNode(linkedList *const list, const int value);
void addNodeAfter(linkedList *const list, const int id, const int value);
void addNodeBefore(linkedList *const list, const int id, const int value);

/*
* Szukanie elementów w liście
*/
int searchById(linkedList *const list, const int id);
int searchByValue(linkedList *const list, const int value);

/*
* Operacje na liście/listach
*/
int listSum(linkedList *const list);
int listSize(linkedList *const list);
linkedList *arithmeticLists(linkedList *const l1, linkedList *const l2, enum Arithmetic ar);
linkedList *mergeLists(linkedList *const l1, linkedList *const l2);

/*
* Usuwanie elementów z listy
*/
void deleteList(linkedList *list);
void deleteNodeById(linkedList *const list, const int id);
void deleteNodeByValue(linkedList *const list, const int value);

/*
* Wyświetlanie elementów listy, utilities
*/
void printList(linkedList *const list);
void errorHandler(const char *error);