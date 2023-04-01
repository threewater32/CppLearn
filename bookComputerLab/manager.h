#pragma once
#include<iostream>
#include"Identity.h"

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

};
