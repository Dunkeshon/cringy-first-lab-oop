#include "pch.h"
#include "list_node.h"
/*Это "node" класс. Имеется конструктор по умолчанию и конструктор, который задает значение в поле списка*/




 list_node ::list_node()
{
	next = nullptr;
	prev = nullptr;
	info = file();
}


 list_node ::~list_node()
{

}
