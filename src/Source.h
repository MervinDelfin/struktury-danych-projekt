#pragma once

#include <iostream>
#include <chrono>
#include<cstdlib>
#include<fstream>
#include<vector>


#include "./skip-list/skip-list.h"
#include "./self-organizing-list/SelfSortList.h"
#include "./skiplist-lib.hpp"
#include "./self-sort-lib.hpp"

using std::vector;
void SaveData(SkipList skp, SelfSortList sfl);
void Measure(vector<int> randomArray, SkipList skp, SelfSortList sfl);
void MeasureSkipList(vector<int> randomArray, SkipList skp, skiplist<int> skplib);
void MeasureSelfOrg(vector<int> randomArray, SelfSortList selfsort, node *selfsortlib);
