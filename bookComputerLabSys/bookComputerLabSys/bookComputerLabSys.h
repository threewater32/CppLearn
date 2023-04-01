#pragma once
#include"Identity.h"
#include<string>
#include"student.h"
#include"teacher.h"
#include"manager.h"
#include <iostream>
#include"globalFile.h"
#include<fstream>

void show_Menu();
void get_Select(int& select);
void LoginIn(string fileName, int type);
void managerMenu(Identity*& manager);


// 定义常量
const int STUDENT = 1;
const int TEACHER = 2;
const int ADMIN = 3;
const int EXIT = 0;





