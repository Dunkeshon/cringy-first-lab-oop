
#include "pch.h"
#include <iostream>
#include "FILE.h"
#include "mylist.h"
#include "list_realisation.h"
#include <vector>
using namespace std;

int main()
{
    std::cout << "Hello World!\n"; 
	file<string,int> one;
	one.print_info();
	list_realisation <Taime> list(one.Get_time());
	list.printFuncList();
	return 0;
}
