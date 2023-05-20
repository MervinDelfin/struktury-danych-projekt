#pragma once
#include<iostream>

struct Snode {
	int val;
	int count;
	struct Snode* next;
	Snode();
};


class SelfSortList
{
private:
	
	Snode* head;
	Snode* rear;

public:
	class SelfSortList* next;
	SelfSortList();
	void Insert(int);
	bool Search(int);
	void Print();
	void SaveToFile(std::string file);
	void Remove(int);
};

