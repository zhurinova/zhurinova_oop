#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "Student.h"
#include "Utils.h"

class Group
{
	std::list <class Student*> student;

public:
	void input_student();
	void see_all();
	void save(const std::string& file_name);
	void load(std::string& file_name);
	void delete_all();
};

