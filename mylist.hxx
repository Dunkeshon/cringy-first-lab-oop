#include "pch.h"
#include "mylist.h"
/*Это "node" класс. Имеется конструктор по умолчанию и конструктор, который задает значение в поле списка*/


 mylist ::mylist(file* val)// нужно передать класс по указателю
{
	next = nullptr;
	prev = nullptr;
	info = val;
}

 mylist ::mylist()
{
	next = nullptr;
	prev = nullptr;
	info = file();// не знаю нужен ли
}


 mylist ::~mylist()
{

}
