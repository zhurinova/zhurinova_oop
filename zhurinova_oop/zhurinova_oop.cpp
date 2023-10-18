#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "Utils.h"
#include "Student.h"
#include "Group.h"


using namespace std;

void menu() {
    cout << "0. Exit" << endl;
    cout << "1. Create student" << endl;
    cout << "2. See all students" << endl;
    cout << "3. Save" << endl;
    cout << "4. Download" << endl;
    cout << "5. Delete student" << endl;
    cout << "Choose action" << endl;
}

int main()
{
    Group student_list;
    while (true)
    {
        menu();
        switch (check_the_number(0, 6))
        {
        case 0:
        {
            cout << "Goodbye!\n" << endl;
            exit(0);        }
        case 1:
        {
            student_list.input_student();
            break;
        }
        case 2:
        {
            student_list.see_all();
            break;
        }
        case 3:
        {
            cout << "Enter the file name: " << endl;
            string file_name;
            cin >> ws;
            getline(cin, file_name);
            file_name += ".txt";
            student_list.save(file_name);
            break;
        }
        case 4:
        {
            cout << "Enter the file name: " << endl;
            string file_name;
            cin >> ws;
            getline(cin, file_name);
            file_name += ".txt";
            student_list.delete_all();
            student_list.load(file_name);
            break;
        }
        case 5:
        {
            student_list.delete_all();
            break;
        }
        default:
        {
            cout << "Program error";
        }
        }
    }
    return 0;
}
