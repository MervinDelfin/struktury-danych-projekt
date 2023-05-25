#include <iostream>

#include "Source.h"

int main(int argc, char *argv[])
{
    
	int n1 = 1000000;
	int n2 = 100000;
	int n3 = 10000;

	//srand((unsigned)time(NULL));
	vector<int> randomArray1, randomArray2, randomArray3;
	for (int i = 0; i < n1; i++)
	{
		randomArray1.push_back( rand());
		if (i < n2)
		{
			randomArray2.push_back(randomArray1[i]);

			if (i < n3)
				randomArray3.push_back(randomArray1[i]);
		}
	}
	std::ofstream Data("data.txt");
	for (int i = 0; i < randomArray1.size(); i++)
	{
		Data << i << ") " << randomArray1[i] << "\n";

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
	


	std::ofstream Results("measurement_results.txt");

	Results << "================CZAS TWORZENIA STRUKTURY=================\nskiplista:\t" << createskiplistduration.count() <<
		"\nself sorting list:\t" << createselfsortduration.count();


	Results.close();

	Measure(randomArray1, skp, sfl);



	

}

