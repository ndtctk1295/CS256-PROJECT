#pragma once
#include "definition.h"

int Menu_4();
void Display_statistic_project(const vector<GROUP> &, const vector<PROJECT> &);
void Display_statistic_group(const vector<GROUP> &, const vector<PROJECT> &);

int Menu_4()
{
    int choice;
    cout << "=====================================" << '\n';
    cout << "[   FUNCTION 4: Statistics          ]" << '\n';
    cout << "=====================================" << '\n';
    cout << "     1. Statistics for project.      " << '\n';
    cout << "     2. Statistics for group.        " << '\n';
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

void Display_statistic_project(const vector<GROUP> &Group, const vector<PROJECT> &Project)
{
    int choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "======================================" << '\n';
    cout << "[         PROJECT STATISTICS         ]" << '\n';
    cout << "======================================" << '\n';
    cout << "   Enter project number (1 - " << Project.size() << "): ";

    while (!(cin >> choice) || choice < 1 || choice > Project.size())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "--------------------------------------" << '\n';
        cout << "   ERROR! Please try again.           " << '\n';
        cout << "   Enter (1 - " << Project.size() << "):";
    }
    choice = choice - 1;
    cout << "--------------------------------------" << '\n';
    cout << left << setw(18) << "  GROUP"
         << "| STATE" << '\n';
    cout << "--------------------------------------" << '\n';

    for (int count = 0; count < Group.size(); count++)
    {
        cout << right << setw(5) << count + 1;
        cout << left << setw(13) << ' ' << "| " << checkState(&Project[choice].Due_date, &Project[choice].Submission_date[count]) << '\n';
    }
    cout << "======================================" << '\n';
    system("pause");
}

void Display_statistic_group(const vector<GROUP> &Group, const vector<PROJECT> &Project)
{
    int choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "======================================" << '\n';
    cout << "[          GROUP STATISTICS          ]" << '\n';
    cout << "======================================" << '\n';
    cout << "   Enter group number (1 - " << Group.size() << "): ";

    while (!(cin >> choice) || choice < 1 || choice > Group.size())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "--------------------------------------" << '\n';

        cout << "   ERROR! Please try again.           " << '\n';
        cout << "   Enter (1 - " << Group.size() << "):";
    }
    choice = choice - 1;
    cout << "======================================" << '\n';
    cout << left << setw(18) << "  PROJECT"
         << "| STATE" << '\n';
    cout << "--------------------------------------" << '\n';
    for (int count = 0; count < Project.size(); count++)
    {
        cout << right << setw(5) << count + 1;
        cout << left << setw(13) << ' ' << "| " << checkState(&Project[count].Due_date, &Project[count].Submission_date[choice]) << '\n';
    }
    cout << "======================================" << '\n';
    system("pause");
}
