#include <iostream>
#include <chrono>
#include<cstdlib>


#include ".\skip-list\skip-list.h"
#include ".\self-organizing-list\SelfSortList.h"


int main()
{

	srand((unsigned)time(NULL));
	int randomArray[10];
	for (int i = 0; i < 10; i++)
	{
		randomArray[i] = rand();
	}


	//measuring creation time of skip list
	auto createskipliststart = std::chrono::high_resolution_clock::now();
	SkipList skp(4,0.5);
	auto createskipliststop = std::chrono::high_resolution_clock::now();
	auto createskiplistduration = std::chrono::duration_cast<std::chrono::microseconds>(createskipliststop - createskipliststart);
	
	//measuring creation time of self sorting list
	auto createselfsortstart = std::chrono::high_resolution_clock::now();
	SelfSortList sfl;
	auto createselfsortstop = std::chrono::high_resolution_clock::now();
	auto createselfsortduration = std::chrono::duration_cast<std::chrono::microseconds>(createskipliststop - createskipliststart);
	
	//arrays keeping time needed to add each element to respective structures
	std::chrono::microseconds insertSkipArray[10];
	std::chrono::microseconds insertSflArray[10];

	//measure time of adding elements to implemented structures
	for (int i = 0; i < 10; i++)
	{
		auto start = std::chrono::high_resolution_clock::now();
		skp.insertElement(randomArray[i]);
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration  = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		insertSkipArray[i] = duration;


		start = std::chrono::high_resolution_clock::now();
		sfl.Insert(randomArray[i]);
		stop = std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		insertSflArray[i] = duration;

	}


	std::chrono::microseconds searchSkipArray[10];
	std::chrono::microseconds searchSflArray[10];

	//measure time of searching for given elements in implemented structures
	for (int i = 0; i < 10; i++)
	{

		auto start = std::chrono::high_resolution_clock::now();
		skp.searchElement(randomArray[i]);
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		searchSkipArray[i] = duration;

		start = std::chrono::high_resolution_clock::now();
		sfl.Search(randomArray[i]);
		stop = std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		searchSkipArray[i] = duration;

	}

	std::chrono::microseconds deleteSkipArray[10];
	std::chrono::microseconds deleteSflArray[10];

	//measure time of deleting given elements from the structure
	for (int i = 9; i >= 0; i--)
	{
		auto start = std::chrono::high_resolution_clock::now();
		skp.deleteElement(randomArray[i]);
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		searchSkipArray[i] = duration;

	}





}