#pragma once
#include <iostream>
#include <string>
#include <array>
#include <stack>
#include<thread>
#include <ctime>
#include <vector>
#include "Building.h"
using namespace std;
void getParameter(int& e_num, int& f_num, int& p_num); //获取参数
void PrintPeople(vector<vector<People>> the_floors, int& max_floor);
void run(bool& f);
