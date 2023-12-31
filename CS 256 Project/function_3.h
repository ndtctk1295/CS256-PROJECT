#pragma once
#include "definition.h"
#include "file_operation.h"

void Input_submission_information(vector<GROUP> &, vector<PROJECT> &);

void Input_submission_information(vector<GROUP> &Group, vector<PROJECT> &Project)
{
    int choice_group;
    int choice_project;

    cout << "=====================================" << '\n';
    cout << "[    FUNCTION 3: Submission         ]" << '\n';
    cout << "=====================================" << '\n';
    cout << "     Group   (1 - " << Group.size() << "): ";
    while (!(cin >> choice_group) || choice_group < 1 || choice_group > Group.size())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "-------------------------------------" << '\n';
        cout << "   ERROR! Please try again.          " << '\n';
        cout << "   Enter (1 - " << Group.size() << "): ";
    }
    choice_group = choice_group - 1;
    char add;
    do
    {
        cout << "-------------------------------------" << '\n';
        cout << "     Project (1 - " << Project.size() << "): ";
        while (!(cin >> choice_project) || choice_project < 1 || choice_project > Project.size())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "-------------------------------------" << '\n';
            cout << "   ERROR! Please try again.          " << '\n';
            cout << "   Enter (1 - " << Project.size() << "): ";
        }
        cout << "-------------------------------------" << '\n';
        choice_project = choice_project - 1;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string clone_str;
        cout << "     Submission date                 " << '\n';
        cout << "     (dd/mm/yyyy): ";
        getline(cin, clone_str);
        clone_str = getValueAfterValidate(clone_str, validateDate);
        Project[choice_project].Submission_date[choice_group] = Date(clone_str);
        cout << "-------------------------------------" << '\n';
        cout << "     Submission date updated.        " << '\n';
        cout << "=====================================" << '\n';
        cout << "   Submit another project (y/n): ";
        cin >> add;
        add = toupper(add);
        cin.clear();

    } while (add == 'Y');
    cout << "=====================================" << '\n';
    Save_data_submission(Group, Project);
}