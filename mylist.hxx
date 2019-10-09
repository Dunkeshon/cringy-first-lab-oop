#include "pch.h"
#include "mylist.h"
/*Это "node" класс. Имеется конструктор по умолчанию и конструктор, который задает значение в поле списка*/




 mylist ::mylist()
{
	next = nullptr;
	prev = nullptr;
	info = file();
}


 mylist ::~mylist()
{

}
