#pragma once
#include "definition.h"

void Save_data_student(const vector<GROUP> &);
void Read_data_student(vector<GROUP> &);
void Save_data_project(const vector<PROJECT> &);
void Read_data_project(vector<PROJECT> &);
void Save_data_submission(vector<GROUP> &, vector<PROJECT> &);
void Read_data_submission(vector<PROJECT> &);
void Save_data_overall_statistic(const vector<GROUP> &, const vector<PROJECT> &, string date);

vector<string> split(string &, char);
string UPPERCASE(string);

void Read_data_project(vector<PROJECT> &Pr)
{
    fstream inputFile;
    inputFile.open("data/project.txt", ios::in);
    PROJECT clone_Project;
    string clone;
    while (getline(inputFile, clone))
    {
        vector<string> clone_fields = split(clone, '$');
        clone_Project.Project_Number = stoi(clone_fields[0]);
        clone_Project.Description = clone_fields[1];
        clone_Project.Due_date = clone_fields[2];
        Pr.push_back(clone_Project);
    }
}

void Read_data_student(vector<GROUP> &Gr)
{
    fstream inputFile;
    string clone_1;
    inputFile.open("data/group.txt", ios::in);
    GROUP clone_Gr;
    STUDENT clone_Student;
    int count = 0;

    while (getline(inputFile, clone_1))
    {
        vector<string> clone_fields_1 = split(clone_1, '$');
        clone_Gr.Group_Number = stoi(clone_fields_1[0]);
        for (int count = 1; count < clone_fields_1.size(); count++)
        {
            vector<string> clone_fields_2 = split(clone_fields_1[count], '%');
            clone_Student.Name = clone_fields_2[0];
            clone_Student.ID = clone_fields_2[1];
            clone_Gr.Student.push_back(clone_Student);
        }
        Gr.push_back(clone_Gr);
        clone_Gr = {};
    }
}

vector<string> split(string &str, char delim)
{
    vector<string> result;
    stringstream ss(str);
    string fields;

    while (getline(ss, fields, delim))
    {
        result.push_back(fields);
    }

    return result;
}

string UPPERCASE(string str)
{
    for (int count = 0; count < str.size(); count++)
    {
        str[count] = toupper(str[count]);
    }
    return str;
}

void Save_data_project(const vector<PROJECT> &Project)
{
    fstream outputFile;
    outputFile.open("data/project.txt", ios::out);
    for (int count = 0; count < Project.size(); count++)
    {
        outputFile << Project[count].Project_Number << '$';
        outputFile << Project[count].Description << '$';
        outputFile << Project[count].Due_date << '$';
        outputFile << '\n';
    }
}

void Save_data_student(const vector<GROUP> &Group)
{
    fstream outputFile;
    outputFile.open("data/group.txt", ios::out);
    for (int count_1 = 0; count_1 < Group.size(); count_1++)
    {
        outputFile << Group[count_1].Group_Number << '$';
        for (int count_2 = 0; count_2 < Group[count_1].Student.size(); count_2++)
        {
            outputFile << Group[count_1].Student[count_2].Name << '%';
            outputFile << Group[count_1].Student[count_2].ID << '$';
        }
        outputFile << '\n';
    }
}

void Read_data_submission(vector<PROJECT> &Project)
{
    fstream inputFile;
    inputFile.open("data/submission.txt", ios::in);

    string clone;
    Date clone_Date;

    int project_count = 0;
    while (getline(inputFile, clone))
    {
        vector<string> clone_fields = split(clone, '$');
        for (int count = 0; count < clone_fields.size(); count++)
        {
            clone_Date = Date(clone_fields[count]);
            Project[project_count].Submission_date.push_back(clone_Date);
        }
        project_count++;
    }
}

void Save_data_submission(vector<GROUP> &Group, vector<PROJECT> &Project)
{
    fstream outputFile;
    outputFile.open("data/submission.txt", ios::out);
    for (int count_1 = 0; count_1 < Project.size(); count_1++)
    {
        for (int count_2 = 0; count_2 < Group.size(); count_2++)
        {
            outputFile << Project[count_1].Submission_date[count_2] << '$';
        }
        outputFile << '\n';
    }
    
}

void Save_data_overall_statistic(const vector<GROUP> &Group, const vector<PROJECT> &Project, string date)
{
    fstream outputFile;
    outputFile.open("data/overall_statistic.txt", ios::out);
    outputFile << "DATE: " << date << '\n';
    Date clone_date(date);
    int board = 13 + Group.size() * 18;
    for (int i = 0; i < Project.size(); i++)
    {
        Date clone_due(Project[i].Due_date);
        if (clone_due.soonerOrEqual(&clone_date))
        {
            for (int count = 0; count < board; count++)
                outputFile << "=";
            outputFile << '\n';
            outputFile << setw(13) << ' ';
            for (int i = 0; i < Group.size(); i++)
            {
                outputFile << left << setw(8) << "| GROUP " << setw(10) << i + 1;
            }
            outputFile << '\n';
            for (int count = 0; count < board; count++)
                outputFile << "-";
            for (int i = 0; i < Project.size(); i++)
            {
                Date Due_Date = Project[i].Due_date;
                if (Due_Date.soonerOrEqual(&clone_date))
                {
                    outputFile << left << setw(9) << "\nPROJECT " << setw(2) << i + 1;
                    for (int j = 0; j < Group.size(); j++)
                    {
                        outputFile << left << "   | " << setw(13) << checkState(&Project[i].Due_date, &Project[i].Submission_date[j]);
                    }
                }
            }
            outputFile << '\n';
            for (int count = 0; count < board; count++)
                outputFile << "=";
            outputFile << '\n';
            break;
        }
    }
    outputFile.close();
}
