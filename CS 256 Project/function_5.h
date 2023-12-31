#pragma once
#include "definition.h"
#include "file_operation.h"

int Menu_5();
void Display_overall_statistic_specific(const vector<GROUP> &, const vector<PROJECT> &);
void Display_overall_statistic_current(const vector<GROUP> &, const vector<PROJECT> &);

int Menu_5()
{
    int choice;
    cout << "=======================================" << '\n';
    cout << "[   FUNCTION 5: Overall Statistics    ]" << '\n';
    cout << "=======================================" << '\n';
    cout << "    1. Statistic for specific date.    " << '\n';
    cout << "    2. Statistic for current date.     " << '\n';
    cout << "    3. Back.                           " << '\n';
    cout << "---------------------------------------" << '\n';
    cout << "   Enter (1 - 3): ";
    while (!(cin >> choice) || choice < 1 || choice > 3)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "---------------------------------------" << '\n';
        cout << "   ERROR! Please try again.          " << '\n';
        cout << "   Enter (1 - 3): ";
    }
    return choice;
}
void Display_overall_statistic_specific(const vector<GROUP> &Group, const vector<PROJECT> &Project)
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string clone;
    cout << "==============================================" << '\n';
    cout << "[               SPECIFIC DATE                ]" << '\n';
    cout << "==============================================" << '\n';
    cout << "     Enter date (dd/mm/yyyy): ";
    getline(cin, clone);
    clone = getValueAfterValidate(clone, validateDate);
    Date clone_Date(clone);
    bool check = false;
    for (int i = 0; i < Project.size(); i++)
    {
        Date Due_Date = Project[i].Due_date;
        if (Due_Date.soonerOrEqual(&clone_Date))
        {
            check = true;
            break;
        }
    }
    if (check == true)
    {
        system("cls"); 
        int board = 13 + Group.size() * 18;
        cout << "=============================" << '\n';
        cout << "[ SPECIFIC DATE: " << clone_Date << " ]" << '\n';
        for (int count = 0; count < board; count++)
            cout << "=";
        cout << '\n';
        cout << setw(13) << ' ';
        for (int i = 0; i < Group.size(); i++)
        {
            cout << left << setw(8) << "| GROUP " << setw(10) << i + 1;
        }
        cout << '\n';
        for (int count = 0; count < board; count++)
            cout << "-";
        for (int i = 0; i < Project.size(); i++)
        {
            Date Due_Date = Project[i].Due_date;
            if (Due_Date.soonerOrEqual(&clone_Date))
            {
                cout << left << setw(9) << "\nPROJECT " << setw(2) << i + 1;
                for (int j = 0; j < Group.size(); j++)
                {
                    cout << left << "   | " << setw(13) << checkState(&Project[i].Due_date, &Project[i].Submission_date[j]);
                }
            }
        }
        cout << '\n';
        for (int count = 0; count < board; count++)
            cout << "=";
        cout << '\n';
    }
    else
    {
        cout << "----------------------------------------------" << '\n';
        cout << "     No project is due.                       " << '\n';
        cout << "==============================================" << '\n';
    }
    Save_data_overall_statistic(Group, Project, clone);
    system("pause");
    return;
}

void Display_overall_statistic_current(const vector<GROUP> &Group, const vector<PROJECT> &Project)
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "=============================================" << '\n';
    cout << "[               CURRENT DATE                ]" << '\n';
    cout << "=============================================" << '\n';
    cout << "     Current date: " << getCurrentDate() << '\n';
    Date clone_Date(getCurrentDate());
    cout << "---------------------------------------------" << '\n';
    bool check = false;
    for (int i = 0; i < Project.size(); i++)
    {
        Date Due_Date = Project[i].Due_date;
        if (Due_Date.soonerOrEqual(&clone_Date))
        {
            check = true;
            break;
        }
    }
    if (check == true)
    {
        system("cls");
        int board = 13 + Group.size() * 18;
        cout << "============================" << '\n';
        cout << "[ CURRENT DATE: " << clone_Date << " ]" << '\n';
        for (int count = 0; count < board; count++)
            cout << "=";
        cout << '\n';
        cout << setw(13) << ' ';
        for (int i = 0; i < Group.size(); i++)
        {
            cout << left << setw(8) << "| GROUP " << setw(10) << i + 1;
        }
        cout << '\n';
        for (int count = 0; count < board; count++)
            cout << "-";
        for (int i = 0; i < Project.size(); i++)
        {
            Date Due_Date = Project[i].Due_date;
            if (Due_Date.soonerOrEqual(&clone_Date))
            {
                cout << left << setw(9) << "\nPROJECT " << setw(2) << i + 1;
                for (int j = 0; j < Group.size(); j++)
                {
                    cout << left << "   | " << setw(13) << checkState(&Project[i].Due_date, &Project[i].Submission_date[j]);
                }
            }
        }
        cout << '\n';
        for (int count = 0; count < board; count++)
            cout << "=";
        cout << '\n';
    }
    else
    {
        cout << "     No project is due.                      " << '\n';
        cout << "=============================================" << '\n';
    }
    string date = getCurrentDate();
    Save_data_overall_statistic(Group, Project, date);
    system("pause");
}
