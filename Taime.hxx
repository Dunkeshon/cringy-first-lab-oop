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
	hour = other.hour;
	min = other.min;
	return *this;
}
std::ostream& operator<< (std::ostream &out, const Taime &time)
{
	out << time.hour<< ":" << time.min;
	return out;
}