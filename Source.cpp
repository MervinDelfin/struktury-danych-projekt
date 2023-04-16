#include<iostream>
#include"SelfSortList.h"




int main()
{
    SelfSortList test;
    test.Insert(3);

    test.Insert(4);
    test.Insert(9);
   
    test.Search(4);
    test.Search(3);
    test.Search(9);

    test.Print();
    test.Remove(3);
    test.Print();
  
    return 0;
}