#pragma once
#include<iostream>
#include"Identity.h"
#include<string>
using namespace std;

class Student:public Identity
{
public:
	Student();
	~Student();
	Student(int id, string name, string psw);


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

