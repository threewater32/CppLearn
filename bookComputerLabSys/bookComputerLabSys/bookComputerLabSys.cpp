// 机房预约.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "bookComputerLabSys.h"

using namespace std;

int main()
{
    
    int select = 0;

    while (true)
    {
        show_Menu();
        get_Select(select);

        system("pause");
        system("cls");
    }
}

void show_Menu() {

    cout << "======================  欢迎来到传智播客机房预约系统  =====================" << endl;
    cout << endl << "请输入您的身份" << endl;
    cout << "\t\t -------------------------------\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          " << STUDENT << "." << "学生代表           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          " << TEACHER << "." << "老    师           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          " << ADMIN << "." << "管 理 员           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          " << EXIT << "." << "退    出           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t -------------------------------\n";
    cout << "输入您的选择: ";
}

void get_Select(int& select)
{
    cin >> select; //接受用户选择

    switch (select)
    {
    case STUDENT: //学生身份
        cout << "选择学生身份" << endl;
        LoginIn(STUDENT_FILE, STUDENT);
        break;
    case TEACHER: //老师身份
        cout << "选择老师身份" << endl;
        LoginIn(TEACHER_FILE, TEACHER);
        break;
    case ADMIN: //管理员身份
        cout << "选择管理员身份" << endl;
        LoginIn(ADMIN_FILE, ADMIN);
        break;
    case EXIT: //退出系统
        cout << "选择退出系统" << endl;
        exit(0);
    default:
        cout << "输入有误，请重新选择！" << endl;
    }
}

void LoginIn(string fileName, int type)
{
    Identity* person = NULL;
    ifstream ifs;
    ifs.open(fileName, ios::out);

    if (!ifs.is_open()) {
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }

    int id = 0;
    string name;
    string pwd;

    if (type == STUDENT)
    {
        cout << "请输入你的学号" << endl;
        cin >> id;

    }
    else if (type == TEACHER)
    {
        cout << "请输入你的职工号" << endl;
        cin >> id;

    }
    else if (type == ADMIN)
    {
        cout << "请输入你的管理员账号" << endl;
        
    }
    else
    {
        cout << "验证登录失败!" << endl;

        system("pause");
        system("cls");
        return;
    }
    cout << "输入用户名" << endl;
    cin >> name;
    cout << "输入密码" << endl;
    cin >> pwd;
    if (type == STUDENT)
    {
        //学生登录验证
        int fId;
        string fName;
        string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            if (id == fId && name == fName && pwd == fPwd) {
                cout << "学生验证成功" << endl;
                system("pause");
                system("cls");
                person = new Student(id, name, pwd);
                studentMenu(person);
                return;
            }
        }

    }
    else if (type == TEACHER)
    {
        //教师登录验证
        int fId;
        string fName;
        string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            if (id == fId && name == fName && pwd == fPwd) {
                cout << "教师验证成功" << endl;
                system("pause");
                system("cls");
                person = new Teacher(id, name, pwd);
                TeacherMenu(person);
                return;
            }
        }
    }
    else if (type == ADMIN)
    {
        //管理员登录验证
        
        string fName;
        string fPwd;
        while (  ifs >> fName && ifs >> fPwd)
        {
            if (name == fName && pwd == fPwd) {
                cout << "管理员验证成功" << endl;
                system("pause");
                system("cls");
                person = new Manager(id, name, pwd);
                managerMenu(person);
                return;
            }
        }
    }

    cout << "验证登录失败!" << endl;

    system("pause");
    system("cls");
    return;
}

void managerMenu(Identity*& manager)
{
    while (true)
    {
        manager->operMenu();
        Manager* man = (Manager*)manager;
        int select = 0;

        cin >> select;

        if (select == 1)  //添加账号
        {
            cout << "添加账号" << endl;
            man->addPerson();
        }
        else if (select == 2) //查看账号
        {
            cout << "查看账号" << endl;
            man->showPerson();
        }
        else if (select == 3) //查看机房
        {
            cout << "查看机房" << endl;
            man->showComputer();
        }
        else if (select == 4) //清空预约
        {
            cout << "清空预约" << endl;
            man->cleanFile();
        }
        else
        {
            delete manager;
            cout << "注销成功" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}
   



