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

	//�˵�����
	virtual void operMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴�ҵ�ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	int m_Id;
};

