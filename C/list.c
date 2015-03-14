#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#include "list.h"

typedef struct Node* nodeRef;

typedef struct Node {
    long data;
    struct Node* next;
    struct Node* prev;
} NodeType;

typedef struct List {
    NodeType* first;
    NodeType* last;
} ListType;


//TRUE = 1; FALSE = 0;

/*** Constructors-Destructors ***/
ListRef newList(void){
    ListRef new = malloc(sizeof(struct List));
    new->first = NULL;
    new->last = NULL;
    return new;
}

long isEmpty(ListRef L){
    if (L->first == NULL) {
        return 1;
    }else{
        return 0;
    }
}

long get(ListRef L){
    assert(!isEmpty(L));
    return L->first->data;
}

void insert(ListRef L, long data){
    nodeRef tmp = malloc(sizeof(struct Node));
    tmp->prev = NULL;
    tmp->data = data;
    tmp->next = NULL;
    if(isEmpty(L))L->first = L->last = tmp;
    else{
        tmp->prev = L->last;
        L->last->next = tmp;
        L->last = tmp;
    }
    assert(isEmpty(L) != 1);

    return;
}

void delete(ListRef L){
    assert(!isEmpty(L));
    nodeRef tmp = L->first;
    L->first = L->first->next;
    free(tmp);
    return;
}
