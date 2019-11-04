/**
*file
*brief Header file containing class catalog
*This file contains definition and implementation of catalog
*/
#pragma once
#include <iostream>
#include <string>
#include "Taime.h"
using namespace std;
/**
*brief An implementation of list_realisation.
*details Realization of list, this class is a super class for "file". It has common info and methods for both of them
*/
class Catalog
{
protected:
	Catalog *parent;
	string _name;
	int _size;
	Taime _time;
	Taime _changed_time;
public:
	/**
	*brief returns true, if this catalog wasn't created, false if it exists and has a proper name and size 
	@return true, if this catalog has empty name and size ==0 , false if it has name and size that are bigger than 0
	*/
	bool is_empty(); 
	/**
	*brief set all private fields of file class, by user's input
	@param parent A pointer to Catalog which set the parent of current catalog
	*/
	virtual void set_info(Catalog *parent);
	/**
	*brief print in console all private fields of catalog class
	*/
	virtual void print_info();
	/**
	*returns protected variable string _name of class catalog
	@return string _name of class catalog
	*/
	string Get_name() const;
	/**
	*returns protected variable int _size of class catalog
	@return int _size of class catalog
	*/
	int Get_size() const;
	/**
	*returns protected variable Taime _time (time of creation) of class catalog
	@return Taime _time of class catalog
	*/
	Taime Get_time() const;
	/**
	*returns protected variable Taime _changed_time (time of last change) of class catalog
	@return Taime _changed_time of class catalog
	*/
	Taime Get_changed_time() const;
	/**
	*returns pointer to parent of class catalog
	@return pointer to parent of class catalog
	*/
	Catalog* Get_parent() const;
	/**
	*brief initialize all protected fields with 0
	*/
	Catalog();
	~Catalog();
	/**
	*brief overloaded assignment operator
	@param other Other Catalog class that we assign to current Catalog
	*details assign all fields of other Catalog to this
	@return *this
	*/
	Catalog operator =(Catalog other);
};

#include "Catalog.hxx"