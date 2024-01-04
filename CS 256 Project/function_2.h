#pragma once
#include "definition.h"
#include "file_operation.h"

int Menu_2();
void Display_project_information(const vector<PROJECT> &);
void Add_project(vector<GROUP> &, vector<PROJECT> &);

int Menu_2()
{
    int choice;
    cout << "=====================================" << '\n';
    cout << "[    FUNCTION 2: Project            ]" << '\n';
    cout << "=====================================" << '\n';
    cout << "     1. View project(s).             " << '\n';
    cout << "     2. Add project.                 " << '\n';
    cout << "     3. Back.                        " << '\n';
    cout << "-------------------------------------" << '\n';
    cout << "   Enter (1 - 3): ";
    while (!(cin >> choice) || choice < 1 || choice > 3)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "-------------------------------------" << '\n';
        cout << "   ERROR! Please try again.          " << '\n';
        cout << "   Enter (1 - 3): ";
    }
    return choice;
}

void Display_project_information(const vector<PROJECT> &Project)
{
    cout << "=============================================" << '\n';
    cout << "[            PROJECT INFORMATION            ]" << '\n';
    cout << "=============================================" << '\n';
    if (Project.size() == 0)
    {
        cout << "   There is no project.                " << '\n';
        system("pause");
        return;
    }
    cout << left << setw(3) << "No"
         << setw(30) << "| DESCRIPTION"
         << setw(11) << "| DUE DATE" << '\n';
    cout << "---------------------------------------------" << '\n';
    for (int count = 0; count < Project.size(); count++)
    {
        cout << left << setw(3) << Project[count].Project_Number
             << setw(2) << "| " << setw(28) << Project[count].Description
             << setw(2) << "| " << Project[count].Due_date << '\n';
    }

    cout << "=============================================" << '\n';
    system("pause");
}

void Add_project(vector<GROUP> &Group, vector<PROJECT> &Project)
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    PROJECT clone_Project;
    string clone;
    clone_Project.Project_Number = Project.size() + 1;

    cout << "=============================================" << '\n';
    cout << "[                ADD PROJECT                ]" << '\n';
    cout << "=============================================" << '\n';
    cout << "     Project number: "
         << clone_Project.Project_Number << '\n';
    cout << "---------------------------------------------" << '\n';
    cout << "     Enter project information:              " << '\n';
    cout << "---------------------------------------------" << '\n';
    cout << "     Description: ";
    getline(cin, clone);
    clone_Project.Description = UPPERCASE(clone);
    cout << "     Due date (dd/mm/yyyy): ";
    getline(cin, clone);
    clone = getValueAfterValidate(clone, validateDate);
    clone_Project.Due_date = Date(clone);
    Project.push_back(clone_Project);

    Date clone_Date;
    for (int count_1 = 0, count_2 = Group.size(); count_1 < count_2; count_1++)
    {
        Project[Project.size() - 1].Submission_date.push_back(clone_Date);
    }
    if (Group.size() == 0)
    {
        return;
    }
    else
        Save_data_submission(Group, Project);
    Save_data_project(Project);
    cout << "---------------------------------------------" << '\n';
    cout << "     Project is added to list.               " << '\n';
    cout << "=============================================" << '\n';
    system("pause");
}
