#include"WorkerManager.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

WorkerManager::WorkerManager() {
	this->empNum = 0;
	this->empArray = NULL;

}
WorkerManager::~WorkerManager() {
	if (this->empArray != NULL) {
		for (int i = 0; i < this->empNum; i++)
		{
			delete this->empArray[i];
			this->empArray[i] = NULL;
		}
		delete[] this->empArray;
		this->empArray = NULL;
	}
	
}
//显示菜单
void WorkerManager::showMenu() {
	cout << "**************************************" << endl;
	cout << "*********欢迎使用职工管理系统*********"<< endl;
	cout << "*********   0.退出管理系统   *********" << endl;
	cout << "*********   1.增加职工信息   *********" << endl;
	cout << "*********   2.显示职工信息   *********" << endl;
	cout << "*********   3.删除离职职工   *********" << endl;
	cout << "*********   4.修改职工信息   *********" << endl;
	cout << "*********   5.查找职工信息   *********" << endl;
	cout << "*********   6.按照编号排序   *********" << endl;
	cout << "*********   7.清空所有文档   *********" << endl;
	cout << "**************************************" << endl;

}
//退出系统
void WorkerManager::exitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//添加职工
void WorkerManager::addEmp() {
	int addNum = 0;
	cout << "请输入添加职工的人数" << endl;
	
	cin >> addNum;
	if (addNum < 0) {
		cout << "您输入的数据有误！" << endl;
	}
	//开辟新空间
	int newNum = this->empNum + addNum;
	Worker ** newSpace = new Worker * [newNum];
	if (this->empArray != NULL) {
		for (int i = 0; i < this->empNum; i++)
		{
			newSpace[i] = this->empArray[i];
		}
	}
	for (int i = 0; i < addNum;i++) {
		int id = 0;
		string name;
		int deptId;
		cout << "请输入第" << i + 1 << "个人的职工编号：" << endl;
		cin >> id;
		
		cout << "请输入第" << i + 1 << "个人的职工姓名：" << endl;
		cin >> name;

		cout << "请选择该职工岗位：" << endl;
		cout << "1.普通职工" << endl;
		cout << "2.部门经理" << endl;
		cout << "3.公司总裁" << endl;

		cin >> deptId;

		Worker * worker = NULL;
		switch (deptId)
		{
		case 1:
			worker = new Employee(id,name,1);
			break;
		case 2:
			worker = new Manager(id,name,2);
		case 3:
			worker = new Boss(id,name,3);
		default:
			break;
		}
		newSpace[this->empNum + i] = worker;
	}
	delete[] this->empArray;
	this->empArray = newSpace;
	this->empNum = newNum;
	cout << "成功添加" << addNum << "名职工" << endl;
	system("pause");
	system("cls");
}