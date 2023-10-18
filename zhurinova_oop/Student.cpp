#include "Student.h"
#include "Utils.h"
#include "Group.h"

using namespace std;

int Student::max_id_student = 0;

Student::Student()
{
	id_student = ++max_id_student;
}

int Student::get_id() const
{
	return id_student;
}

istream& operator >> (istream& in, Student& s)
{
	
	cout << "Enter the name of student" << endl;
	getline(in, s.name_student);
	cout << "Enter the surname of student" << endl;
	getline(in, s.surname_student);
	cout << "Enter the student's year of birth" << endl;
	s.age_student = check_the_number(1950, 2023);
	cout << "Enter the name of the student's group" << endl;
	getline(in, s.group_name);
	return in;
}

ostream& operator << (ostream& out, const Student& s)
{
	out << "Student's ID: " << s.id_student 
		<< "\n          Students's surname and name: " << s.surname_student <<" " << s.name_student
		<< "\n          Student's year of birth: " << s.age_student
		<< "\n          Student's group: " << s.group_name << endl;
	return out;
}

ifstream& operator >> (ifstream& in, Student& s)
{
	in >> s.id_student;
	in >> s.name_student;
	in >> s.surname_student;
	in >> s.age_student;
	in >> s.group_name;
	s.max_id_student = s.get_id();
	return in;
}

ofstream& operator << (ofstream& out, const Student& s)
{
	out << s.id_student << endl
		<< s.name_student << endl
		<< s.surname_student << endl
		<< s.age_student << endl
		<< s.group_name << endl;

	return out;
}

