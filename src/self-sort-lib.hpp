#pragma once
#include<iostream>
using namespace std;
struct node {
   int d;
   node *next;
};
node* CreateNode(int d) ;
node* InsertIntoList(node *head, int d) ;
void Display(node *head);
node* SearchItem(node *head, int item);