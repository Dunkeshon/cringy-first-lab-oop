#include "pch.h"
#include "list_node.h"
/*Это "node" класс. Имеется конструктор по умолчанию и конструктор, который задает значение в поле списка*/




 template <class T> list_node <T> ::list_node()
{
	next = nullptr;
	prev = nullptr;
	info = T();
}


 template <class T> list_node <T> ::~list_node()
{

}
