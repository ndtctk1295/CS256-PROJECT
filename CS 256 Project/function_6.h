#pragma once
#include "definition.h"

void Display_incomplete_late_group(const vector<GROUP> &, const vector<PROJECT> &);

void Display_incomplete_late_group(const vector<GROUP> &Group, const vector<PROJECT> &Project)
{
    int incomplete_group;
    vector<int> incomplete_project;
    string clone_state;
    vector<string> state;

    cout << "=====================================" << '\n';
    cout << "[    INCOMPLETE/LATE SUBMISSION     ]" << '\n';
    cout << "=====================================" << '\n';
    for (int count_1_1 = 0, count_1_2 = Group.size(); count_1_1 < count_1_2; count_1_1++)
    {
        incomplete_group = -1;
        incomplete_project.clear();
        state.clear();
        for (int count_2_1 = 0, count_2_2 = Project.size(); count_2_1 < count_2_2; count_2_1++)
        {
            clone_state = checkState(&Project[count_2_1].Due_date, &Project[count_2_1].Submission_date[count_1_1]);
            if (clone_state == "Late." || clone_state == "Not Submit.")
            {
                incomplete_group = count_1_1 + 1;
                incomplete_project.push_back(count_2_1 + 1);
                state.push_back(clone_state);
            }
        }
        if (incomplete_group != -1)
        {
            cout << "-----------" << '\n';
            cout << "[ GROUP " << incomplete_group << " ]" << '\n';
            cout << "-------------------------------------" << '\n';
            cout << left << setw(18) << "  PROJECT  "
                 << "| STATE" << '\n';
            cout << "-------------------------------------" << '\n';
            for (int count = 0, max = incomplete_project.size(); count < max; count++)
            {
                cout << right << setw(5) << incomplete_project[count]
                     << right << setw(15) << "| " << state[count] << '\n';
            }
            cout << "=====================================" << '\n';
            cout << '\n';
        }
    }
    system("pause");
}