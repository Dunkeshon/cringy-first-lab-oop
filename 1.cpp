
#include "pch.h"
#include <iostream>
#include "FILE.h"
#include "mylist.h"
#include "list_realisation.h"
using namespace std;

int main()
{
    std::cout << "Hello World!\n"; 
	file<string,int> one;
	one.print_info();
	list_realisation<int> list(one.Get_size());
	list.printFuncList();
	return 0;
}
