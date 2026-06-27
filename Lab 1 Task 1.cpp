#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string id;
    string name;
    string course;
    int age;
};

int main()
{
    Student student[5];

    // Input 5 students
    cout << "Enter information for 5 students" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << endl;
        cout << "Student " << i + 1 << endl;

        cout << "ID: ";
        cin >> student[i].id;

        cin.ignore();

        cout << "Name: ";
        getline(cin, student[i].name);

        cout << "Course: ";
        getline(cin, student[i].course);

        cout << "Age: ";
        cin >> student[i].age;
    }

    // Display all students
    cout << endl;
    cout << "===== STUDENT LIST =====" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << endl;
        cout << "ID: " << student[i].id << endl;
        cout << "Name: " << student[i].name << endl;
        cout << "Course: " << student[i].course << endl;
        cout << "Age: " << student[i].age << endl;
    }

    // Search student by ID
    string searchID;
    bool found = false;

    cout << endl;
    cout << "Enter ID to search: ";
    cin >> searchID;

    for (int i = 0; i < 5; i++)
    {
        if (student[i].id == searchID)
        {
            cout << "Student Name: " << student[i].name << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Student not found" << endl;
    }

    // Update section
    string updateID;

    cout << endl;
    cout << "Enter ID to update (or Q to quit): ";
    cin >> updateID;

    if (updateID == "Q" || updateID == "q")
    {
        cout << "Program ended." << endl;
        return 0;
    }

    found = false;

    for (int i = 0; i < 5; i++)
    {
        if (student[i].id == updateID)
        {
            found = true;

            string choice;

            cout << "What do you want to change (id/name/course/age): ";
            cin >> choice;

            if (choice == "id")
            {
                cout << "Enter new ID: ";
                cin >> student[i].id;
            }
            else if (choice == "name")
            {
                cin.ignore();

                cout << "Enter new Name: ";
                getline(cin, student[i].name);
            }
            else if (choice == "course")
            {
                cin.ignore();

                cout << "Enter new Course: ";
                getline(cin, student[i].course);
            }
            else if (choice == "age")
            {
                cout << "Enter new Age: ";
                cin >> student[i].age;
            }

            cout << endl;
            cout << "Updated Student Information" << endl;
            cout << "ID: " << student[i].id << endl;
            cout << "Name: " << student[i].name << endl;
            cout << "Course: " << student[i].course << endl;
            cout << "Age: " << student[i].age << endl;

            break;
        }
    }

    if (!found)
    {
        cout << "Student not found" << endl;
    }

    return 0;
}
