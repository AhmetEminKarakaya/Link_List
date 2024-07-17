#include "LinkList.h"

HndList initList()
{
	HndList pList = (HndList)malloc(sizeof(List));

	if (pList == NULL)
	{
		printf("initList error");
		return NULL;
	}

	pList->counter = 0;
	pList->pFirst = NULL;
	pList->pLast = NULL;

	return pList;
}

Node* pushFront(HndList list, valueType val)
{
	Node* pNewNode = (Node*)malloc(sizeof(Node));

	if (pNewNode == NULL)
	{
		printf("error pushFront...");
		return pNewNode;
	}

	if (list->pFirst == NULL)
		list->pLast = pNewNode;

	pNewNode->data = val;
	pNewNode->pNext = list->pFirst;
	list->pFirst = pNewNode;

	list->counter++;

	return pNewNode;
}

Node* pushBack(HndList list, valueType val)
{
	Node* pNewNode = (Node*)malloc(sizeof(Node));

	if (pNewNode == NULL)
	{
		printf("error pushBack...");
		return NULL;
	}

	if (list->pFirst == NULL)
	{
		list->pFirst = pNewNode;
	}
	else
	{
		list->pLast->pNext = pNewNode;
	}
	pNewNode->pNext = NULL;
	list->pLast = pNewNode;

	list->counter++;
	pNewNode->data = val;

	return pNewNode;
}

int getSize(const HndList list)
{
	return list->counter;
}

int isEmpty(HndList list)
{
	return list->counter == 0;
}

int popFront(HndList list)
{
	if (isEmpty == 1)
	{
		printf("error popFront...");
		return -1;
	}

	Node* ptemp = list->pFirst;
	list->pFirst = list->pFirst->pNext;
	free(ptemp);

	list->counter--;

	return 0;
}

void popBack(HndList list)
{
	Node* pTemp, * previous;
	pTemp = list->pFirst;
	previous == NULL;

	Node* pTempLast = list->pLast;

	while (pTemp != list->pLast)
	{
		previous = pTemp;
		pTemp = pTemp->pNext;
	}

	if (previous == NULL)
		list->pFirst = NULL;
	else
		previous->pNext = NULL;
	list->pLast = previous;

	free(pTempLast);
}

Node* insertAfterNode(HndList list, Node* prevNode, valueType val)
{
	Node* pNewNode = (Node*)malloc(sizeof(Node));

	if (pNewNode == NULL)
	{
		printf("error pushFront...");
		return pNewNode;
	}
	pNewNode->data = val;

	pNewNode->pNext = prevNode->pNext;
	prevNode->pNext = pNewNode;

	list->counter++;

	return pNewNode;
}

Node* insertOndexNode(HndList list, int index, valueType val)
{
	if (index > list->counter)
		return NULL;

	if (index == 0)
	{
		Node* pFirst = pushFront(list, val);
		return pFirst;
	}

	Node* pPrevNode = list->pFirst;

	for (int i = 1; i < index; i++)
		pPrevNode = pPrevNode->pNext;

	return insertAfterNode(list, pPrevNode, val);
}

void deleteNode(HndList list, Node* pDelNode)
{
	Node* pTemp, * previous;
	pTemp = list->pFirst;
	previous == NULL;

	while (pTemp != pDelNode)
	{
		previous = pTemp;
		pTemp = pTemp->pNext;
	}
	previous->pNext = pDelNode->pNext;
	list->counter--;
	free(pDelNode);
}

void deleteIndexNode(HndList list, int index)
{
	if (index > list->counter)
		exit(EXIT_FAILURE);

	if (index == 0)
	{
		Node* pFirst = popFront(list);
		return;
	}

	Node* pDeleteNode = list->pFirst;

	for (int i = 0; i < index; i++)
		pDeleteNode = pDeleteNode->pNext;

	deleteNode(list, pDeleteNode);

}

void clearList(HndList list)
{
	while (!isEmpty(list))
		popFront(list);
}
void destroyList(HndList list)
{
	clearList(list);
	free(list);
}

void displayList(const HndList list)
{
	for (Node* p = list->pFirst; p != NULL; p = p->pNext)
		printf("%d ", p->data);
}