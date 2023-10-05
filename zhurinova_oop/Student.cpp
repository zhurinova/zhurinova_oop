#include "Student.h"
#include "Utils.h"

using namespace std;

void Student::input_student()
{
	Student s;
	cin >> s;
	student.push_back(new Student(s));
}

void Student::see_all()
{
	if (student.size() != 0)
	{
		for (const auto* st : student)
		{
			cout << *st << endl;
		}
	}
	else
		cout << "Student's list is empty" << endl;
}

void Student::save(const string& file_name)
{
	ofstream fout;
	fout.open(file_name);
	if (!fout.is_open())
	{
		cerr << "File open error" << endl;
	}
	else
	{
		fout << student.size() << endl;
		for (const auto* st : student)
			fout << *st;
		fout.close();
	}
}

void Student::load(string& file_name)
{
	student.clear();

	int amount_of_students = 0;
	ifstream fin;
	fin.open(file_name, ofstream::in);
	if (!fin.is_open())
	{
		cerr << "File open error" << endl;
	}
	else
	{
		Student s;
		fin >> amount_of_students;
		for (int i = 0; i < amount_of_students; i++)
		{
			fin >> s;
			student.push_back(new Student(s));
		}
		fin.close();
	}
}

void Student::delete_all()
{
	for (const auto* st : student)
	{
		delete st;
	}
	student.clear();
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
	out << "Students's surname and name: " << s.surname_student <<" " << s.name_student
		<< "\n          Student's year of birth: " << s.age_student
		<< "\n          Student's group: " << s.group_name << endl;
	return out;
}

ifstream& operator >> (ifstream& in, Student& s)
{
	in >> s.name_student;
	in >> s.surname_student;
	in >> s.age_student;
	in >> s.group_name;
	return in;
}

ofstream& operator << (ofstream& out, const Student& s)
{
	out << s.name_student << endl
		<< s.surname_student << endl
		<< s.age_student << endl
		<< s.group_name << endl;
	return out;
}