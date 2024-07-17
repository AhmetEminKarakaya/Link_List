# Linked List Data Structure

This repository contains the implementation of a linked list data structure in C. Linked lists are fundamental data structures used in computer science for dynamic data storage and manipulation.

## Features

- **Dynamic Size:** Automatically adjusts its size as elements are added or removed.
- **Efficient Insertions/Deletions:** Provides efficient insertions and deletions at any position.
- **Simplicity:** Simple and easy-to-understand API for common linked list operations.

# API Reference

- **HndList initList();**
- **Node*pushFront(HndList list, valueType val);**
- **Node*pushBack(HndList list, valueType val);**
- **int getSize(const HndList list);**
- **int isEmpty(HndList list);**
- **int popFront(HndList list);**
- **void popBack(HndList list);**
- **Node*insertAfterNode(HndList list, Node*prevNode, valueType val);**
- **Node*insertIndexNode(HndList list, int index, valueType val);**
- **void deleteNode(HndList list, Node*pDelNode);**
- **void deleteIndexNode(HndList list, int index);**
- **void clearList(HndList list);**
- **void destroyList(HndList list);**
- **void displayList(const HndList list);**
