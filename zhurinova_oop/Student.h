#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>


class Student
{
	std::list <Student*> student;

public:
	void input_student();
	void see_all();
	void save(const std::string& file_name);
	void load(std::string& file_name);
	void delete_all();
	std::string name_student;
	std::string surname_student;
	int age_student = 0;
	std::string group_name;

	friend std::istream& operator >> (std::istream& in, Student& s);
	friend std::ostream& operator << (std::ostream& out, const Student& s);
	friend std::ifstream& operator >> (std::ifstream& in, Student& s);
	friend std::ofstream & operator << (std::ofstream & out, const Student & s);
};


