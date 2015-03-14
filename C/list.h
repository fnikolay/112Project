
#ifndef __LIST_H__
#define __LIST_H__


typedef struct List* ListRef;

ListRef newList(void);

long isEmpty(ListRef L);

long get(ListRef L);

void insert(ListRef L, long data);

void delete(ListRef L);

#endif
