#pragma once

#include <iostream>
#include <chrono>
#include<cstdlib>
#include<fstream>
#include<vector>


#include "./skip-list/skip-list.h"
#include "./self-organizing-list/SelfSortList.h"

using std::vector;
void SaveData(SkipList skp, SelfSortList sfl);
void Measure(vector<int> randomArray, SkipList skp, SelfSortList sfl);
