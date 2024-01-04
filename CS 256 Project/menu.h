#pragma once

#include "function_1.h"
#include "function_2.h"
#include "function_32.h"
#include "function_4.h"
#include "function_5.h"
#include "function_6.h"

int Menu();
void Run_code(int Function);

int Menu()
{
    int choice;
    cout << "=====================================" << '\n';
    cout << "[   PROJECT SUBMISSION MANAGEMENT   ]" << '\n';
    cout << "=====================================" << '\n';
    cout << "     1. Group information.           " << '\n';
    cout << "     2. Project.                     " << '\n';
    cout << "     3. Submit project.              " << '\n';
    cout << "     4. Statistic.                   " << '\n';
    cout << "     5. Overall Statistic.           " << '\n';
    cout << "     6. Incomplete/Late submitted.   " << '\n';
    cout << "     7. Quit.                        " << '\n';
    cout << "-------------------------------------" << '\n';
    cout << "   Enter (1 - 7): ";
    while (!(cin >> choice) || choice < 1 || choice > 7)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "-------------------------------------" << '\n';
        cout << "   ERROR! Please try again.           " << '\n';
        cout << "   Enter (1 - 7): ";
    }

    return choice;
}

void Run_code(vector<GROUP> Group, vector<PROJECT> Project, int Function)
{
    system("cls");
    Read_data_student(Group);
    Read_data_project(Project);
    Read_data_submission(Project);

    do
    {
        system("cls");
        Function = Menu();
        switch (Function)
        {
        case 1:
            do
            {
                system("cls");
                Function = Menu_1();
                switch (Function)
                {
                case 1:

                    system("cls");
                    Display_all_information(Group);
                    break;
                case 2:
                    system("cls");
                    Display_group_information(Group);
                    break;
                case 3:
                    system("cls");
                    Add_group(Group, Project);
                    break;
                case 4:
                    system("cls");
                    Add_member_group(Group);
                    break;
                case 5:
                    system("cls");
                    Delete_member_group(Group);
                    break;
                default:
                    break;
                }
            } while (Function >= 1 && Function <= 5);
            break;
        case 2:
            do
            {
                system("cls");
                Function = Menu_2();
                switch (Function)
                {
                case 1:
                    system("cls");
                    Display_project_information(Project);
                    break;
                case 2:
                    system("cls");
                    Add_project(Group, Project);
                    break;
                default:
                    break;
                }
            } while (Function >= 1 && Function <= 2);
            break;

        case 3:
            system("cls");
            Input_submission_information(Group, Project);
            break;

        case 4:
            do
            {
                system("cls");
                Function = Menu_4();
                switch (Function)
                {
                case 1:
                    system("cls");
                    Display_statistic_project(Group, Project);
                    break;

                case 2:
                    system("cls");
                    Display_statistic_group(Group, Project);
                    break;

                default:
                    break;
                }
            } while (Function >= 1 && Function <= 2);
            break;

        case 5:
            do
            {
                system("cls");
                Function = Menu_5();
                switch (Function)
                {
                case 1:
                    system("cls");
                    Display_overall_statistic_specific(Group, Project);
                    break;
                case 2:
                    system("cls");
                    Display_overall_statistic_current(Group, Project);
                    break;
                default:
                    break;
                }
            } while (Function >= 1 && Function <= 2);
            break;

        case 6:
            system("cls");
            Display_incomplete_late_group(Group, Project);
            break;

        default:
            cout << "-------------------------------------" << '\n';
            system("pause");
            return;
        }
    } while (true);
}