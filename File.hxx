#include "pch.h"
#include "FILE.h"




file::file()//создаем новый файл, вводим данные с клавиатуры 
{
	_file_type = string();
	_name = string();
	_size = 0;
	_time = Taime();
	_changed_time = Taime();
}


file::~file()
{
	
}

 void file::set_info()
{
	 string temp_name, temp_file_type;
	 int temp_size;
	 cout << "enter name : ";
	 cin >> temp_name;
	 cout << "enter size : ";
	 cin >> temp_size;
	 cout << "enter the time of creation : " << endl;
	 _time.SetTime();
	 cout << "enter the time of the last change : " << endl;
	 _changed_time.SetTime();
	 cout << "enter the file type : ";
	 cin >> temp_file_type;
	 _name = temp_name;
	 _size = temp_size;
	 _file_type = temp_file_type;
}

void file::print_info()//вывод информации о файле 
{
	//cout << '\t' << "File info: " << '\n';
	cout << "File _name: " << _name << '\n';
	cout << "File _size: " << _size << '\n';
	cout << "Time of creation: ";
	_time.PrintTime();
	cout << "Time of the last change: ";
	_changed_time.PrintTime();
	cout << "File type: " << _file_type << '\n';

}
/**
геттеры для получиния информации из private полей
*/

inline string file::Get_name() const
{
	return _name;
}
inline int file::Get_size() const
{
	return _size;
}

inline Taime file::Get_time() const
{
	return _time;
}

inline Taime file ::Get_changed_time() const
{
	return _changed_time;
}

inline string file::Get_type() const
{
	return _file_type;
}
