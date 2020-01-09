#include"WorkerManager.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

WorkerManager::WorkerManager() {

	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	if (!ifs.is_open())
	{
		//cout << "文件不存在！" << endl;
		this->empNum = 0;
		this->empArray = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在且为空
	char ch; 
	ifs >> ch;
	if (ifs.eof())//文件是否为空
	{
		//cout << "文件为空！" << endl;
		this->empNum = 0;
		this->empArray = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在且不为空

	int num = this->getNumInFile();//获取文件中的数据个数
	this->empNum = num;
	this->empArray = new Worker * [this->empNum];//开辟数组
	this->initEmp();//初始化

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
	this->fileIsEmpty = false;
	cout << "成功添加" << addNum << "名职工" << endl;
	//保存到文件中
	this->save();
	system("pause");
	system("cls");
}
//保存到文件
void WorkerManager::save() {

	ofstream ofs;
	ofs.open(FILENAME,ios::out);
	for (int i = 0; i < this->empNum; i++)
	{
		ofs << this->empArray[i]->id << " "
			<< this->empArray[i]->name << " "
			<< this->empArray[i]->deptId << endl;
	}
	ofs.close();

}


//统计文件中的人数
int WorkerManager::getNumInFile() {
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	int id;
	string name;
	int deptId;
	int num = 0;
	while (ifs>>id&&ifs>>name&&ifs>>deptId)
	{
		num++;
	}
	return num;
}

//初始化员工
void WorkerManager::initEmp() {
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	int id;
	string name;
	int deptId;
	int index = 0;//文件索引
	while (ifs>>id&&ifs>>name&&ifs>>deptId) {//根据空格读取
		Worker* worker = NULL;
		if (deptId==1)
		{
			worker = new Employee(id,name,deptId);
		}
		else if (deptId==2) {
			worker = new Manager(id,name,deptId);

		}
		else
		{
			worker = new Boss(id,name,deptId);
		}
		this->empArray[index] = worker;
		index++;
	}
	ifs.close();
}

//显示职工信息
void WorkerManager::showInfo() {

	this->systemIsEmpty();

	for (int i = 0; i < this->empNum; i++)
	{
		this->empArray[i]->showInfo();
	}
	system("pause");
	system("cls");
}

//删除职工信息
void WorkerManager::deleteEmp() {
	
	this->systemIsEmpty();

	cout << "请输入要删除的职工编号：" << endl;
	int id = 0;
	cin >> id;
	int result = this->getEmpById(id);

	if (result != -1)
	{
		for (int i = result; i < this->empNum-1; i++)
		{
			this->empArray[i] = this->empArray[i+1];
		}
		//delete this->empArray[this->empNum-1];
		
		this->empNum--;
		this->save();//保存到文件
		cout << "删除成功！" << endl;
	}
	else
	{
		cout << "删除失败！该职工不存在！" << endl;
	}
	system("pause");
	system("cls");
}

//根据id查找职工信息

int WorkerManager::getEmpById(int id) {

	this->systemIsEmpty();

	int index = -1;
	for (int i = 0; i < this->empNum; i++)
	{
		if (this->empArray[i]->id == id)
		{
			index = i;//返回职工所在位置
			break;
		}
	}
	return index;
	
}

//根据姓名查找职工信息
void WorkerManager::getEmpByName(string name) {

	this->systemIsEmpty();

	bool flag = false;
	for (int i = 0; i < this->empNum; i++)
	{
		if (this->empArray[i]->name == name)
		{
			this->empArray[i]->showInfo();
			flag = true;
		}
	}
	if (!flag)
	{
		cout << "查无此人！" << endl;
	}

}

//查找职工信息
void WorkerManager::getEmp() {
	
	this->systemIsEmpty();

	cout << "请输入查询条件：" << endl;
	cout << "1.根据职工编号查找：" << endl;
	cout << "2.根据职工姓名查找" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		cout << "请输入职工编号：" << endl;
		int id;
		cin >> id;
		int result = this->getEmpById(id);
		this->empArray[result]->showInfo();
	}
	else if(select == 2)
	{
		cout << "请输入职工姓名：" << endl;
		string name;
		cin >> name;
		this->getEmpByName(name);
	}
	else {
		cout << "您输入的选项有误！" << endl;
	}
	system("pause");
	system("cls");
}


//按照职工编号排序
void WorkerManager::sortEmp() {

	this->systemIsEmpty();
	cout << "请选择要排序的模式：" << endl;
	cout << "1.升序(ASC)" << endl;
	cout << "2.降序(DSC)" << endl;
	int select = 0;
	cin >> select;
	int len = this->empNum;
	for (int i = 0; i < len; i++)//选择排序
	{
		int minOrMax = i;
		if (select==1)
		{
			for (int j = i + 1; j < len; j++)
			{
				if (this->empArray[minOrMax]->id > this->empArray[j]->id)//升序
				{
					minOrMax = j;
				}
			}
		}
		else if (select == 2)
		{
			for (int j = i + 1; j < len; j++)
			{
				if (this->empArray[minOrMax]->id < this->empArray[j]->id)//降序
				{
					minOrMax = j;
				}
			}
		}
		else
		{
			cout << "输入选项有误！默认升序排列：" << endl;

			break;
		}
		
		if (minOrMax != i)
		{
			Worker* temp = this->empArray[minOrMax];
			this->empArray[minOrMax] = this->empArray[i];
			this->empArray[i] = temp;
		}
	}
	//显示信息
	this->showInfo();
}

//判断系统中是否有记录
void WorkerManager::systemIsEmpty() {
	if (this->empArray == NULL)
	{
		cout << "该系统无职工信息！" << endl;
		system("pause");
		system("cls");
		return;
	}
}

