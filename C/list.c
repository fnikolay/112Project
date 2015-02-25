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
    long length;
    NodeType* first;
    NodeType* last;
    NodeType* current;
} ListType;


//TRUE = 1; FALSE = 0;

/*** Constructors-Destructors ***/
ListRef newList(void){
    ListRef new = malloc(sizeof(struct List));
    new->length = 0;
    new->first = NULL;
    new->current = NULL;
    new->last = NULL;
    return new;
}

void freeList(ListRef* pL){
    ListRef L = *pL;
    makeEmpty(L);
    free(L);
    return;
}

/*** Access functions ***/
long isEmpty(ListRef L){
    if (L->first == NULL) {
        return 1;
    }else{
        return 0;
    }
}

long offEnd(ListRef L){
    if (L->current == NULL) {
        return 1;
    }else{
        return 0;
    }
}

long atFirst(ListRef L){
    if (L->current == L->first && !offEnd(L)) {
        return 1;
    }else{
        return 0;
    }
}

long atLast(ListRef L){
    if (L->current == L->last && !offEnd(L)) {
        return 1;
    }else{
        return 0;
    }
}

long getFirst(ListRef L){
    assert(!isEmpty(L));
    return L->first->data;
}

long getLast(ListRef L){
    assert(!isEmpty(L));
    return L->last->data;
}

long getCurrent(ListRef L){
    assert(!isEmpty(L));
    return L->current->data;
}

long getLength(ListRef L){
    return L->length;
}

long equals (ListRef A, ListRef B){
    nodeRef tmpA = A->current;
    nodeRef tmpB = B->current;

    moveFirst(A);
    moveFirst(B);
    if (A->length != B->length) {
        A->current = tmpA;
        B->current = tmpB;
        return 0;
    }
    while (!offEnd(A) || !offEnd(B)) {
        if (A->current->data != B->current->data){
            A->current = tmpA;
            B->current = tmpB;
            return 0;
        }
        moveNext(A);
        moveNext(B);
    }
    A->current = tmpA;
    B->current = tmpB;
    return 1;
} // return true if the two lists have the same keys
// in the same order

/*** Manipulation procedures ***/
void makeEmpty(ListRef L){
    while (!isEmpty(L)) {
        deleteFirst(L);
    }
    return;
}

void moveFirst(ListRef L){
    assert(!isEmpty(L));
    L->current = L->first;
    assert(!offEnd(L));
    return;
}

void moveLast(ListRef L){
    assert(!isEmpty(L));
    L->current = L->last;
    assert(!offEnd(L));
    return;
}

void movePrev(ListRef L){
    assert(!isEmpty(L));
    L->current = L->current->prev;
    assert(!offEnd(L));
    return;
}

void moveNext(ListRef L){
    assert(!isEmpty(L));
    if(atLast(L)){
        L->current = L->current->next;
        assert(offEnd(L));
        return;
    }
    L->current = L->current->next;
    return;
}

void insertBeforeFirst(ListRef L, long data){
    nodeRef tmp = malloc(sizeof(struct Node));
    tmp->prev = NULL;
    tmp->data = data;
    tmp->next = NULL;
    if(isEmpty(L)) L->first = L->current = L->last = tmp;
    else{
        tmp->next = L->first;
        L->first->prev = tmp;
        L->first = tmp;
    }
    L->length++;
    assert(!isEmpty(L));
    return;
}

void insertAfterLast(ListRef L, long data){
    nodeRef tmp = malloc(sizeof(struct Node));
    tmp->prev = NULL;
    tmp->data = data;
    tmp->next = NULL;
    if(isEmpty(L))L->current = L->first = L->last = tmp;
    else{
        tmp->prev = L->last;
        L->last->next = tmp;
        L->last = tmp;
    }
    L->length++;
    assert(isEmpty(L) != 1);

    return;
}

void insertBeforeCurrent(ListRef L, long data){
    assert(!offEnd(L));
    nodeRef tmp = malloc(sizeof(struct Node));
    tmp->prev = NULL;
    tmp->data = data;
    tmp->next = NULL;

    if(isEmpty(L)){
        L->current = L->first = L->last = tmp;
    }else{
        if (atFirst(L)) {
            insertBeforeFirst(L, data);
            return;
        }else{
            L->current->prev->next = tmp;
            tmp->prev = L->current->prev;
            L->current->prev = tmp;
            tmp->next = L->current;
        }
    }
    L->length++;
    assert(!isEmpty(L));
    assert(!offEnd(L));
    return;
}

void insertAfterCurrent(ListRef L, long data){
    assert(!offEnd(L));
    nodeRef tmp = malloc(sizeof(struct Node));
    tmp->prev = NULL;
    tmp->data = data;
    tmp->next = NULL;

    if(isEmpty(L)){
        L->current = L->first = L->last = tmp;
    }else{
        if (atLast(L)) {
            insertAfterLast(L, data);
            return;
        }else{
            tmp->next = L->current->next;
            tmp->prev = L->current;
            L->current->next = tmp;
        }
    }
    L->length++;
    assert(!isEmpty(L));
    assert(!offEnd(L));
    return;
}

void deleteFirst(ListRef L){
    assert(!isEmpty(L));
    nodeRef tmp = L->first;
    L->first = L->first->next;
    free(tmp);
    L->length--;
    return;
}

void deleteLast(ListRef L){
    assert(!isEmpty(L));
    nodeRef tmp = L->last;
    L->last = L->last->prev;
    free(tmp);
    L->last->next = NULL;
    L->length--;
    return;
}

void deleteCurrent(ListRef L){
    assert(!isEmpty(L));
    assert(!offEnd(L));
    nodeRef tmp = L->current;
    L->current->prev->next = L->current->next;
    L->current->next->prev = L->current->prev;
    free(tmp);
    L->current = NULL;
    assert(offEnd(L));
}

/*** Other operations ***/
void prlongList(FILE* out, ListRef L){
    nodeRef tmp = L->first;
    while(tmp != NULL){
        fprintf(out, "%ld ", tmp->data);
        tmp = tmp->next;
    }

    return;
}

ListRef copyList(ListRef L){
    ListRef new = newList();
    nodeRef tmp = L->current;
    moveFirst(L);
    while (!offEnd(L)) {
        insertAfterLast(new, L->current->data);
        moveNext(L);
    }
    L->current = tmp;
    return new;
}
