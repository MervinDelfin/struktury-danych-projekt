#pragma once
#include <iostream>
//#include ".\skip-list\skip-list.h"

#include <iostream>
#include <vector>
#include <cstdlib> // for rand() function
#include <ctime> // for seeding the random number generator

class SkipNode {
public:
    int key;
    std::vector<SkipNode*> next;

    SkipNode(int k, int level) {
        key = k;
        next.resize(level, nullptr);
    }
};

class SkipList {
private:
    SkipNode* head;
    int maxLevel;
    int currentLevel;

public:
    SkipList() {
        maxLevel = 1;
        currentLevel = 1;
        head = new SkipNode(0, maxLevel);
        std::srand(std::time(nullptr)); // seed the random number generator
    }

    int randomLevel() {
        int level = 1;
        while (std::rand() % 2 && level < maxLevel + 1) {
            level++;
        }
        return level;
    }

    void insert(int key) {
        int level = randomLevel();
        if (level > currentLevel) {
            for (int i = currentLevel + 1; i <= level; i++) {
                head->next.push_back(nullptr);
            }
            currentLevel = level;
        }

        SkipNode* newNode = new SkipNode(key, level);
        SkipNode* current = head;

        for (int i = currentLevel - 1; i >= 0; i--) {
            while (current->next[i] && current->next[i]->key < key) {
                current = current->next[i];
            }
            if (i < level) {
                newNode->next[i] = current->next[i];
                current->next[i] = newNode;
            }
        }
    }

    bool search(int key) {
        SkipNode* current = head;

        for (int i = currentLevel - 1; i >= 0; i--) {
            while (current->next[i] && current->next[i]->key < key) {
                current = current->next[i];
            }
        }

        current = current->next[0];
        return (current && current->key == key);
    }

    void remove(int key) {
        SkipNode* current = head;
        std::vector<SkipNode*> update(currentLevel, nullptr);

        for (int i = currentLevel - 1; i >= 0; i--) {
            while (current->next[i] && current->next[i]->key < key) {
                current = current->next[i];
            }
            update[i] = current;
        }

        current = current->next[0];

        if (current && current->key == key) {
            for (int i = 0; i < currentLevel; i++) {
                if (update[i]->next[i] != current)
                    break;
                update[i]->next[i] = current->next[i];
            }

            delete current;

            while (currentLevel > 1 && head->next[currentLevel - 1] == nullptr) {
                currentLevel--;
            }
        }
    }

    void display() {
        for (int i = currentLevel - 1; i >= 0; i--) {
            std::cout << "Level " << i << ": ";
            SkipNode* current = head->next[i];
            while (current) {
                std::cout << current->key << " ";
                current = current->next[i];
            }
            std::cout << std::endl;
        }
    }
};


