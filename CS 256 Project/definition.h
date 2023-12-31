#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <limits>
#include "validdate.h"
#include "date.h"
using namespace std;

const int ID_SIZE = 8;

struct STUDENT
{
    string Name;
    string ID;
};

struct PROJECT
{
    int Project_Number;
    string Description;
    Date Due_date;
    vector<Date> Submission_date;
};

struct GROUP
{
    int Group_Number;
    vector<STUDENT> Student;
};
