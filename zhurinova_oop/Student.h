#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Student
{
	int id_student;
	static int max_id_student;

public:
	std::string name_student;
	std::string surname_student;
	int age_student = 0;
	std::string group_name;

	Student();
	int get_id() const;

	friend std::istream& operator >> (std::istream& in, Student& s);
	friend std::ostream& operator << (std::ostream& out, const Student& s);
	friend std::ifstream& operator >> (std::ifstream& in, Student& s);
	friend std::ofstream & operator << (std::ofstream & out, const Student & s);
	friend class Group;
};


