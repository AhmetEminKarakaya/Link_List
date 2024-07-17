#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef int valueType;

typedef struct Node
{
	valueType data;
	struct Node* pNext;
}Node;

typedef struct
{
	Node* pFirst;
	Node* pLast;
	int counter;
}List,*HndList;

HndList initList();
Node* pushFront(HndList list, valueType val);
Node* pushBack(HndList list, valueType val);
int getSize(const HndList list);
int isEmpty(HndList list);
int popFront(HndList list);
void popBack(HndList list);
Node* insertAfterNode(HndList list, Node* prevNode, valueType val);
Node* insertOndexNode(HndList list, int index, valueType val);
void deleteNode(HndList list, Node* pDelNode);
void deleteIndexNode(HndList list, int index);
void clearList(HndList list);
void destroyList(HndList list);
void displayList(const HndList list);