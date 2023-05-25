#pragma once

#include <iostream>
#include <chrono>
#include<cstdlib>
#include<fstream>
#include<vector>


#include "./skip-list/skip-list.h"
#include "./self-organizing-list/SelfSortList.h"

using std::vector;
void SaveData(SkipList skp, SelfSortList sfl)
{
	skp.saveList("skiplist");
	sfl.SaveToFile("selfsortinglist");
}
void Measure(vector<int> randomArray, SkipList skp, SelfSortList sfl)
{

	//measure time of adding elements to implemented structures
	auto startskp = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < randomArray.size(); i++)
	{
		skp.insertElement(randomArray[i]);
	}
	auto stopskp = std::chrono::high_resolution_clock::now();
	auto createSkpDuration = std::chrono::duration_cast<std::chrono::microseconds>(stopskp - startskp);
	
	auto startsfl = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < randomArray.size(); i++)
	{
		sfl.Insert(randomArray[i]);
	}
	auto stopsfl = std::chrono::high_resolution_clock::now();
	auto createSflDuration = std::chrono::duration_cast<std::chrono::microseconds>(stopsfl - startsfl);
	SaveData(skp, sfl);

	vector<std::chrono::microseconds> searchSkipArray;
	vector<std::chrono::microseconds> searchSflArray;

	//measure time of searching for given elements in implemented structures (50 elements in total)

	for (int i = 0; i < randomArray.size(); i+=randomArray.size()/50)
	{

		auto start = std::chrono::high_resolution_clock::now();
		skp.searchElement(randomArray[i]);
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		searchSkipArray.push_back(duration);

		start = std::chrono::high_resolution_clock::now();
		sfl.Search(randomArray[i]);
		stop = std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		searchSflArray.push_back(duration);

	}
	vector<std::chrono::microseconds> skpDeleteTime;
	vector<std::chrono::microseconds> sflDeleteTime;

	//measure time of deleting given elements from the structure

	
	for (int i = randomArray.size() - 1; i >= randomArray.size() / 50; i -= randomArray.size() / 50)
	{
		auto start = std::chrono::high_resolution_clock::now();
		skp.deleteElement(randomArray[i]);
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		skpDeleteTime.push_back(duration);

		start = std::chrono::high_resolution_clock::now();
		sfl.Remove(randomArray[i]);
		stop = std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		sflDeleteTime.push_back(duration);
		

	}

	std::ofstream Results;

	Results.open("measurement_results.txt", std::ios_base::app);
	Results << "\n\n\n##############################" << randomArray.size() << " ELEMENTOW" << "\n================== czasy dodawania elementow\nskiplista:\t"
		<< createSkpDuration.count() << "\nself sorting list:\t" << createSflDuration.count();
	
	Results.close();

	Results.open("measurement_results_wyszukiwanie.txt", std::ios_base::app);

	Results << "Wartosc elementu\tCzas skip lista\tCzas self sorting lista\n";

	for (int i = 0; i < searchSkipArray.size(); i++)
	{
		Results << randomArray[i * randomArray.size() / 50] <<"\t" << searchSkipArray[i].count()<< "\t" << searchSflArray[i].count() << "\n";

	}

	Results.close();

	Results.open("measurement_results_usuwanie.txt", std::ios_base::app);
	
	Results << "Wartosc elementu\tCzas skip lista\tCzas self sorting lista\n";

	for (int i = 0; i < skpDeleteTime.size(); i++)
	{
		Results << randomArray[i * randomArray.size() / 50] << "\t" << skpDeleteTime[i].count() << "\t" << sflDeleteTime[i].count() << "\n";

	}

	Results.close();

}
