#pragma once
#include<iostream>
#include"Identity.h"
#include<string>
#include "computerRoom.h"
#include<vector>
#include<fstream>
#include"globalFile.h"

using namespace std;
void studentMenu(Identity*& student);

class Student:public Identity
{
public:
	Student();
	~Student();
	Student(int id, string name, string psw);
	vector<ComputerRoom> vCom;

	//菜单界面
	virtual void operMenu();

	//申请预约
	void applyOrder();

	//查看我的预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

	int m_Id;
};

