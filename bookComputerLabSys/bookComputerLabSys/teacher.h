#pragma once
#include <iostream>
#include "Identity.h"

using namespace std;

void TeacherMenu(Identity*& teacher);
class Teacher :public Identity
{
public:
	Teacher();
	Teacher(int id, string name, string pws);
	virtual void operMenu();
	void showAllOrder();
	void validOrder();
	
	int m_EmId;
	
	
private:

};
