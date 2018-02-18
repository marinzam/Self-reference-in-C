//
//  main.c
//
//  C Linked List
//
//  Created by Geraldine Marin-Zamora
//
//
#include <stdio.h>
#define TRUE 1
#define FALSE 0
typedef int BOOLEAN;

struct Node {
    int value;
    struct Node *next;
};

void insert(int x, struct Node **pL);
void printList(struct Node * L);
BOOLEAN lookup(int x, struct Node * L);
void delete(int x, struct Node **pL);

int main(int argc, char const *argv[]) {
    struct Node *L;
    
    int i;
    for (i = 1; i < 20; i+=2)
        insert(i, &L);
    printList(L);
    for (i = 0; i < 20; i++)
        printf("%d %s FOUND\n", i, ((lookup(i,L) == TRUE) ? "": "NOT"));
    for (i = 0; i < 20; i+=3)
        delete(i,&L);
    printList(L);
    return 0;
}

void insert(int x, struct Node **pL) {
    if((*pL) == NULL)
    {
        (*pL) = malloc(sizeof(*pL));
        (*pL)->value = x;
        (*pL)->next = NULL;
    }
    else
    {
        insert(x,&((*pL)->next));
    }
}

void printList(struct Node * L) {
    if(L != NULL)
        printf("%d\n", L->value);
    else
        return;
    printList(L->next);
}

BOOLEAN lookup(int x, struct Node * L) {
    if(L != NULL)
    {
        if(L->value == x)
            return TRUE;
        else
            return lookup(x, L->next);
    }
    return FALSE;
}

void delete(int x, struct Node **pL) {
    if((*pL) != NULL)
    {
        if((*pL)->value == x)
            (*pL) = (*pL)->next;
        else
            delete(x, &((*pL)->next));
    }
    return;
}
