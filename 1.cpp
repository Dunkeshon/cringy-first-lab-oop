
#include "pch.h"
#include <iostream>
#include "FILE.h"
#include "mylist.h"
#include "list_realisation.h"
using namespace std;

int main()
{
    std::cout << "Hello World!\n"; 
	file<string,int> one;// error
	one.print_info();
	cout << one.Get(Size);
	//list_realisation<int> list(one.);
	return 0;
}
