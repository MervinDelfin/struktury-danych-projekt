#pragma once
using namespace std;
#include <iostream>

#ifndef SKIP_LIST_H
#define SKIP_LIST_H

class Node {
public:
    int key;

    Node **forward;
    Node(int, int); // key, level

    friend ostream& operator<<(ostream& os, const Node& node);
};


class SkipList {
    int MAXLVL;
    int level;
    float P; // fraction of nodes compered to the previous level
    Node *header;

public:
    SkipList(int, float); // MAXLVL, P
    int randomLevel();
    bool insertElement(int); // key
    bool deleteElement(int); // key
    void displayList();
    Node* searchElement(int); // key
    Node* nextNode(int); // key
    Node* prevNode(int); // key
};

#endif
