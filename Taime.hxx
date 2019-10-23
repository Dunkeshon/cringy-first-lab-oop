#include "Taime.h"
#pragma once


Taime::Taime()
{
	hour = 0;
	min = 0;
}


Taime::~Taime()
{
}

inline void Taime::SetTime()
{
	cout << "enter hour : ";
	cin >> hour;
	cout << "enter minutes:";
	cin >> min;
}

inline void Taime::PrintTime()
{
	cout<<hour << ":" << min << '\n';
}
Taime Taime::operator=(Taime other)
{
	Taime one;
	one.hour = other.hour;
	one.min = other.min;
	return one;
}
std::ostream& operator<< (std::ostream &out, const Taime &time)
{
	// Поскольку operator<< является другом класса Point, то мы имеем прямой доступ к членам Point
	out << time.hour<< ":" << time.min;

	return out;
}