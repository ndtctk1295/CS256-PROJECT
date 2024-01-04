#pragma once

#include "definition.h"
#include "file_operation.h"

int Menu_1();
void Display_all_information(const vector<GROUP> &);
void Display_group_information(const vector<GROUP> &);
void Add_group(vector<GROUP> &, vector<PROJECT> &);
void Add_member_group(vector<GROUP> &);
void Delete_member_group(vector<GROUP> &);

int Menu_1()
{
    int choice;
    cout << "==========================================" << '\n';
    cout << "[    FUNCTION 1: Group information       ]" << '\n';
    cout << "==========================================" << '\n';
    cout << "     1. Display class information.        " << '\n';
    cout << "     2. Display a group information.      " << '\n';
    cout << "     3. Add group.                        " << '\n';
    cout << "     4. Add member to a group.            " << '\n';
    cout << "     5. Delete member from a group.       " << '\n';
    cout << "     6. Back.                             " << '\n';
    cout << "------------------------------------------" << '\n';
    cout << "   Enter (1 - 6): ";
    while (!(cin >> choice) || choice < 1 || choice > 6)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "------------------------------------------" << '\n';
        cout << "   ERROR! Please try again.            " << '\n';
        cout << "   Enter (1 - 6): ";
    }
    return choice;
}

void Display_all_information(const vector<GROUP> &Group)
{
    cout << "===========================================" << '\n';
    cout << "[            CLASS INFORMATION            ]" << '\n';
    cout << "===========================================" << '\n';
    if (Group.size() == 0)
    {
        cout << "   There is no group.                " << '\n';
        system("pause");
        return;
    }
    cout << left << setw(4) << "No" << setw(29) << "| NAME" << setw(10) << "| ID" << '\n';
    cout << "-------------------------------------------" << '\n';
    for (int count_1 = 0; count_1 < Group.size(); count_1++)
    {
        cout << left << setw(4) << Group[count_1].Group_Number;
        for (int count_2 = 0; count_2 < Group[count_1].Student.size(); count_2++)
        {
            cout << left << setw(2) << "| " << setw(27) << Group[count_1].Student[count_2].Name
                 << setw(2) << "| " << setw(8) << Group[count_1].Student[count_2].ID << '\n';

            if (count_2 + 1 != Group[count_1].Student.size())
                cout << left << setw(4) << ' ';
        }
        if (count_1 + 1 != Group.size())
        {
            cout << "-------------------------------------------" << '\n';
        }
    }
    cout << "===========================================" << '\n';
    system("pause");
}

void Display_group_information(const vector<GROUP> &Group)
{
    int choice;
    cout << "===========================================" << '\n';
    cout << "[            GROUP INFORMATION            ]" << '\n';
    cout << "===========================================" << '\n';
    if (Group.size() == 0)
    {
        cout << "   There is no group.                " << '\n';
        system("pause");
        return;
    }
    cout << "   Enter group number (1 - " << Group.size() << "): ";
    while (!(cin >> choice) || choice < 1 || choice > Group.size())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "-------------------------------------------" << '\n';
        cout << "   ERROR! Please try again.           " << '\n';
        cout << "   Enter (1 - " << Group.size() << "):";
    }

    choice = choice - 1;

    cout << "-------------------------------------------" << '\n';
    cout << left << setw(4) << "No" << setw(29) << "| MEMBER" << setw(10) << "| ID" << '\n';
    cout << "-------------------------------------------" << '\n';

    for (int count = 0; count < Group[choice].Student.size(); count++)
    {
        cout << left << setw(4) << count + 1;
        cout << setw(2) << "| " << setw(27) << Group[choice].Student[count].Name
             << setw(2) << "| " << setw(10) << Group[choice].Student[count].ID
             << '\n';
    }
    cout << "===========================================" << '\n';
    system("pause");
}

void Add_group(vector<GROUP> &Group, vector<PROJECT> &Project)
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    GROUP clone_Group;
    STUDENT clone_Student;
    clone_Group.Group_Number = Group.size() + 1;
    cout << "=====================================" << '\n';
    cout << "[            ADD GROUP              ]" << '\n';
    cout << "=====================================" << '\n';
    cout << "   Group number " << Group.size() + 1 << '\n';
    cout << "-------------------------------------" << '\n';
    cout << "   Enter students information:       " << '\n';
    bool check_1 = false;
    bool check_2 = false;
    bool check_3 = true;
    int student_count = 0;
    char add;
    string clone_str;
    do
    {
        cout << "-------------------------------------" << '\n';
        cout << "   Name: ";
        getline(cin, clone_str);
        clone_Student.Name = UPPERCASE(clone_str);
        cout << "   ID (8 digits) : ";
        getline(cin, clone_Student.ID);
        while (true)
        {
            // check if 8 digits
            if (clone_Student.ID.size() == ID_SIZE)
            {
                check_1 = true;
            }
            else
            {
                check_1 = false;
            }

            // check if digit
            for (int count = 0; count < ID_SIZE; count++)
            {
                if (isdigit(clone_Student.ID[count]))
                {
                    check_2 = true;
                }
                else
                {
                    check_2 = false;
                    break;
                }
            }

            int count_1 = 0;
            int count_2 = 0;

            for (count_1 = 0; count_1 < Group.size(); count_1++)
            {
                for (count_2 = 0; count_2 < Group[count_1].Student.size(); count_2++)
                {
                    if (clone_Student.ID == Group[count_1].Student[count_2].ID)
                    {
                        check_3 = false;
                        break;
                    }
                    else
                    {
                        check_3 = true;
                    }
                }
            }

            if (check_1 == true && check_2 == true && check_3 == true)
            {
                break;
            }
            else
            {
                cin.clear();
                cout << "-------------------------------------" << '\n';
                cout << "   ERROR! Please try again.          " << '\n';
                if (check_1 == false)
                {
                    cout << "   ID must have 8 digits.            " << '\n';
                }
                else if (check_2 == false)
                {
                    cout << "   ID only contains digits.          " << '\n';
                }
                if (check_3 == false)
                {
                    cout << "   Student's ID already existed.     " << '\n';
                }
                cout << "-------------------------------------" << '\n';
                cout << "   Name: ";
                getline(cin, clone_str);
                clone_Student.Name = UPPERCASE(clone_str);
                cout << "   ID (8 digits) : ";
                getline(cin, clone_Student.ID);
            }
        }

        clone_Group.Student.push_back(clone_Student);
        student_count++;

        if (student_count >= 1)
        {
            cout << "=====================================" << '\n';
            cout << "   Add more student (y/n): ";
            cin >> add;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            add = toupper(add);
        }
        else
        {
            add = 'Y';
        }
        cin.clear();
    } while (add == 'Y');
    Date clone_Date;
    for (int count_1 = 0, count_2 = Project.size(); count_1 < count_2; count_1++)
    {
        Project[count_1].Submission_date.push_back(clone_Date);
    }
    cout << "=====================================" << '\n';
    Group.push_back(clone_Group);
    Save_data_student(Group);
    Save_data_submission(Group, Project);
}

void Add_member_group(vector<GROUP> &Group)
{
    GROUP clone_Group;
    STUDENT clone_Student;

    int choice;
    cout << "=====================================" << '\n';
    cout << "[            ADD MEMBER             ]" << '\n';
    cout << "=====================================" << '\n';
    if (Group.size() == 0)
    {
        cout << "   There is no group.                " << '\n';
        system("pause");
        return;
    }
    cout << "   Add member to group (1 - " << Group.size() << "): ";
    while (!(cin >> choice) || choice < 1 || choice > Group.size())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "-------------------------------------" << '\n';
        cout << "   ERROR! Please try again.           " << '\n';
        cout << "   Enter (1 - " << Group.size() << "):";
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    choice = choice - 1;

    cout << "-------------------------------------" << '\n';
    cout << "   Enter students information:       " << '\n';
    bool check_1 = false;
    bool check_2 = false;
    bool check_3 = true;
    char add;
    string clone_str;
    do
    {

        cout << "-------------------------------------" << '\n';
        cout << "   Name: ";
        getline(cin, clone_str);
        clone_Student.Name = UPPERCASE(clone_str);
        cout << "   ID (8 digits) : ";
        getline(cin, clone_Student.ID);
        while (true)
        {
            // check if 8 digits
            if (clone_Student.ID.size() == ID_SIZE)
            {
                check_1 = true;
            }
            else
            {
                check_1 = false;
            }

            // check if digit
            for (int count = 0; count < ID_SIZE; count++)
            {
                if (isdigit(clone_Student.ID[count]))
                {
                    check_2 = true;
                }
                else
                {
                    check_2 = false;
                    break;
                }
            }

            int count_1 = 0;
            int count_2 = 0;
            // check if exist
            for (count_1 = 0; count_1 < Group.size(); count_1++)
            {
                for (count_2 = 0; count_2 < Group[count_1].Student.size(); count_2++)
                {
                    if (clone_Student.ID == Group[count_1].Student[count_2].ID)
                    {
                        check_3 = false;
                        break;
                    }
                    else
                    {
                        check_3 = true;
                    }
                }
            }

            if (check_1 == true && check_2 == true && check_3 == true)
            {
                break;
            }
            else
            {
                cin.clear();
                cout << "-------------------------------------" << '\n';
                cout << "   ERROR! Please try again.          " << '\n';
                if (check_1 == false)
                {
                    cout << "   ID must have 8 digits.            " << '\n';
                }
                else if (check_2 == false)
                {
                    cout << "   ID only contains digits.          " << '\n';
                }
                if (check_3 == false)
                {
                    cout << "   Student's already existed.     " << '\n';
                }
                cout << "-------------------------------------" << '\n';
                cout << "   Name: ";
                getline(cin, clone_str);
                clone_Student.Name = UPPERCASE(clone_str);
                cout << "   ID (8 digits) : ";
                getline(cin, clone_Student.ID);
            }
        }

        Group[choice].Student.push_back(clone_Student);

        cout << "=====================================" << '\n';
        cout << "   Add more student (y/n): ";
        cin >> add;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        add = toupper(add);

        cin.clear();
    } while (add == 'Y');

    cout << "=====================================" << '\n';
    Save_data_student(Group);
    system("pause");
}

void Delete_member_group(vector<GROUP> &Group)
{
    int choice_gr;
    int choice_st;
    cout << "=====================================" << '\n';
    cout << "[           DELETE MEMBER           ]" << '\n';
    cout << "=====================================" << '\n';
    if (Group.size() == 0)
    {
        cout << "   There is no group.                " << '\n';
        system("pause");
        return;
    }

    cout << "   Enter group number (1 - " << Group.size() << "): ";

    while (!(cin >> choice_gr) || choice_gr < 1 || choice_gr > Group.size())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "-------------------------------------" << '\n';
        cout << "   ERROR! Please try again.          " << '\n';
        cout << "   Enter (1 - " << Group.size() << "):";
    }

    choice_gr = choice_gr - 1;

    if (Group[choice_gr].Student.size() <= 1)
    {
        cout << "-------------------------------------" << '\n';
        cout << "   ERROR! Please try again.          " << '\n';
        cout << "[Group must have at least  members.]" << '\n';
        cout << "-------------------------------------" << '\n';
    }
    else
    {
        cout << "-------------------------------------" << '\n';
        cout << left << setw(4) << "No" << setw(25) << "MEMBER" << setw(10) << "ID" << '\n';
        cout << "-------------------------------------" << '\n';

        for (int count = 0; count < Group[choice_gr].Student.size(); count++)
        {
            cout << left << setw(4) << count + 1;
            cout << left << setw(25) << Group[choice_gr].Student[count].Name
                 << setw(10) << Group[choice_gr].Student[count].ID << '\n';
        }

        cout << "-------------------------------------" << '\n';
        cout << "   Delete member (1 - " << Group[choice_gr].Student.size() << "): ";
        while (!(cin >> choice_st) || choice_st < 1 || choice_st > Group[choice_gr].Student.size())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "--------------------------------------" << '\n';
            cout << "   ERROR! Please try again.           " << '\n';
            cout << "   Enter (1 - " << Group[choice_gr].Student.size() << "):";
        }

        choice_st = choice_st - 1;
        Group[choice_gr].Student.erase(Group[choice_gr].Student.begin() + choice_st);
        cout << "-------------------------------------" << '\n';
        cout << "   Student is removed.               " << '\n';
        cout << "=====================================" << '\n';
    }
    Save_data_student(Group);
    system("pause");
}