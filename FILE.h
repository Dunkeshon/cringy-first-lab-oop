/**
	*file
	*brief Header file containing class file
	*This file contains definition and implementation of file
*/
#pragma once
#include "Catalog.h"
/**
	*brief An implementation of file.
	*details Realization of file, this class is child class of Catalog. It has info and methods, provided specially for file
*/
class file :public Catalog
{
private:
	string _file_type;
public:
/**
	*brief initialize all private fields with 0
*/
	file();
	~file();
/**
	#override virtual void set_info(Catalog *parent)

	*brief set all private fields of file class, by user's input
	@param parent A pointer to Catalog which set the parent of current file
*/
	void set_info(Catalog *parent)override;// i will call this method for a file , created by method of catalog "Create_file_child"
/**
	#override virtual void Catalog :: print_info()
	*brief print in console all private fields of file class
*/
	void print_info()override;
/**
	*returns protected variable string _file_type of class file
	@return string _file_type of class file
*/
	string Get_type() const;
/**
	*brief overloaded assignment operator
	@param other Other file class that we assign to current file
	*details assign all fields of other file to this
	@return *this
*/
	file operator =(file other);


};
#include"FILE.hxx"