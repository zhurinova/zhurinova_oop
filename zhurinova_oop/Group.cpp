#include "Group.h"

using namespace std;

void Group::input_student()
{
	Student s;
	cin >> s;
	student.push_back(new Student(s));
}

void Group::see_all()
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

void Group::save(const string& file_name)
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

void Group::load(string& file_name)
{
	ifstream fin;
	fin.open(file_name, ofstream::in);
	if (!fin.is_open())
	{
		cerr << "File open error" << endl;
	}
	else
	{
		int amount_of_students = 0;
		fin >> amount_of_students;
		for (int i = 0; i < amount_of_students; i++)
		{
			Student* s = new Student();
			fin >> *s;
			student.push_back(s);
		}

		cout << "\nInformation is uploaded!" << endl;
		fin.close();
	}
}

void Group::delete_all()
{
	for (auto* st : student)
	{
		delete st;
	}
	Student::max_id_student = 0;
	student.clear();
}
