#include <stdio.h>
#include "LinkList.h"

int main()
{
    HndList list = initList();

    pushFront(list, 20);
    pushFront(list, 40);
    pushFront(list, 50);
    pushBack(list, 10);
    pushBack(list, 90);
    displayList(list);

}


