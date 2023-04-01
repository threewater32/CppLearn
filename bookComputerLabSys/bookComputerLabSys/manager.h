#pragma once

#include<iostream>
#include"Identity.h"
#include"student.h"
#include"teacher.h"
#include"globalFile.h"
#include <fstream>
#include<vector>
#include<algorithm>
#include "computerRoom.h"


class Manager:public Identity
{
public:
	Manager();
	Manager(int id, string name, string pwd);
	virtual void operMenu();
	void addPerson();
	void showPerson();
	void showComputer();
	void cleanFile();
	
	void initVector();
	bool checkRepeat(int id,int type);

	vector<Student> vStu;
	vector<Teacher> vTea;
	vector<ComputerRoom>vCom;
};

