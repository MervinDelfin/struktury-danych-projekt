#include <iostream>
#include "skip-list.h"
#include <vector>
#include<fstream>


using namespace std;


Node::Node(int key, int level) {
    this->key = key;
    forward = new Node * [level + 1];
    memset(forward, 0, sizeof(Node*) * (level + 1));
};

ostream& operator<<(ostream& os, const Node& node) {
    os << node.key;
    return os;
};


SkipList::SkipList(int MAXLVL, float P) {
    if (MAXLVL < 1 || P < 0 || P > 1) {
        throw invalid_argument("Invalid arguments");
    }

    this->MAXLVL = MAXLVL;
    this->P = P;
    level = 0;

    header = new Node(-1, MAXLVL);
};

int SkipList::randomLevel() {
    float r = (float)rand() / RAND_MAX;
    int lvl = 0;
    while (r < P && lvl < MAXLVL) {
        lvl++;
        r = (float)rand() / RAND_MAX;
    }
    return lvl;
};


bool SkipList::insertElement(int key) {
    Node* current = header;
    vector<Node*> update(MAXLVL + 1);
    //Node* update[MAXLVL + 1];
    //memset(update, 0, sizeof(Node*) * (MAXLVL + 1));

    for (int i = level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];

    if (current == NULL || current->key != key) {
        int rlevel = randomLevel();

        if (rlevel > level)
        {
            for (int i = level + 1; i < rlevel + 1; i++)
                update[i] = header;

            level = rlevel;
        }

        Node* n = new Node(key, level);

        for (int i = 0; i <= rlevel; i++)
        {
            n->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = n;
        }
        return true;
    }
    return false;
};


bool SkipList::deleteElement(int key) {
    Node* current = header;

    vector<Node*> update(MAXLVL + 1);
    //memset(update, 0, sizeof(Node*) * (MAXLVL + 1));

    for (int i = level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->key < key)
            current = current->forward[i];
        update[i] = current;
    }

    current = current->forward[0];

    if (current != NULL and current->key == key) {
        for (int i = 0; i <= level; i++) {
            if (update[i]->forward[i] != current)
                break;

            update[i]->forward[i] = current->forward[i];
        }

        delete (current);

        while (level > 0 && header->forward[level] == 0)
            level--;

        return true;
    }
    return false;
};

Node* SkipList::searchElement(int key) {
    Node* current = header;

    for (int i = level; i >= 0; i--) {
        while (current->forward[i] &&
            current->forward[i]->key < key)
            current = current->forward[i];
    }

    current = current->forward[0];

    if (current and current->key == key) {
        return current;
    }
    return NULL;
};

Node* SkipList::nextNode(int key) {
    Node* current = searchElement(key);
    if (current)
        return current->forward[0];
    return NULL;
};

Node* SkipList::prevNode(int key) {
    Node* current = header;

    for (int i = level; i >= 0; i--) {
        while (current->forward[i] &&
            current->forward[i]->key < key)
            current = current->forward[i];
    }

    if (current->forward[0] and current->forward[0]->key == key)
        return current;
    return NULL;
};

void SkipList::displayList() {
    cout << "\n*****Skip List*****"
        << "\n";
    for (int i = 0; i <= level; i++)
    {
        Node* node = header->forward[i];
        cout << "Level " << i << ": ";
        while (node != NULL)
        {
            cout << node->key << " ";
            node = node->forward[i];
        }
        cout << "\n";
    }
};

void SkipList::saveList(std::string file)
{
    std::ofstream Save(file + ".txt");
    Save << "\n*****Skip List*****"
        << "\n";
    for (int i = 0; i <= level; i++)
    {
        Node* node = header->forward[i];
        Save << "Level " << i << ": ";
        while (node != NULL)
        {
            Save << node->key << " ";
            node = node->forward[i];
        }
        Save << "\n";
    }
    Save.close();
};

//int main() {
//    srand((unsigned)time(0));
//
//    SkipList skiplist(3, 0.5);
//
//    skiplist.insertElement(3);
//    skiplist.insertElement(6);
//    skiplist.insertElement(7);
//    skiplist.insertElement(9);
//    skiplist.insertElement(12);
//    skiplist.insertElement(19);
//    skiplist.insertElement(17);
//    skiplist.insertElement(26);
//    skiplist.insertElement(21);
//    skiplist.insertElement(25);
//    skiplist.displayList();
//
//
//    cout << *skiplist.searchElement(19) << endl;
//
//    skiplist.deleteElement(19);
//
//    cout << skiplist.searchElement(19) << endl;
//
//    skiplist.displayList();
//
//    cout << skiplist.nextNode(26) << endl;
//    cout << *skiplist.prevNode(3) << endl;
//}