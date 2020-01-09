#include"WorkerManager.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

WorkerManager::WorkerManager() {

	//�ļ�������
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	if (!ifs.is_open())
	{
		//cout << "�ļ������ڣ�" << endl;
		this->empNum = 0;
		this->empArray = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ�������Ϊ��
	char ch; 
	ifs >> ch;
	if (ifs.eof())//�ļ��Ƿ�Ϊ��
	{
		//cout << "�ļ�Ϊ�գ�" << endl;
		this->empNum = 0;
		this->empArray = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ������Ҳ�Ϊ��

	int num = this->getNumInFile();//��ȡ�ļ��е����ݸ���
	this->empNum = num;
	this->empArray = new Worker * [this->empNum];//��������
	this->initEmp();//��ʼ��

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
//��ʾ�˵�
void WorkerManager::showMenu() {
	cout << "**************************************" << endl;
	cout << "*********��ӭʹ��ְ������ϵͳ*********"<< endl;
	cout << "*********   0.�˳�����ϵͳ   *********" << endl;
	cout << "*********   1.����ְ����Ϣ   *********" << endl;
	cout << "*********   2.��ʾְ����Ϣ   *********" << endl;
	cout << "*********   3.ɾ����ְְ��   *********" << endl;
	cout << "*********   4.�޸�ְ����Ϣ   *********" << endl;
	cout << "*********   5.����ְ����Ϣ   *********" << endl;
	cout << "*********   6.���ձ������   *********" << endl;
	cout << "*********   7.��������ĵ�   *********" << endl;
	cout << "**************************************" << endl;

}
//�˳�ϵͳ
void WorkerManager::exitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//���ְ��
void WorkerManager::addEmp() {
	int addNum = 0;
	cout << "���������ְ��������" << endl;
	
	cin >> addNum;
	if (addNum < 0) {
		cout << "���������������" << endl;
	}
	//�����¿ռ�
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
		cout << "�������" << i + 1 << "���˵�ְ����ţ�" << endl;
		cin >> id;
		
		cout << "�������" << i + 1 << "���˵�ְ��������" << endl;
		cin >> name;

		cout << "��ѡ���ְ����λ��" << endl;
		cout << "1.��ְͨ��" << endl;
		cout << "2.���ž���" << endl;
		cout << "3.��˾�ܲ�" << endl;

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
	cout << "�ɹ����" << addNum << "��ְ��" << endl;
	//���浽�ļ���
	this->save();
	system("pause");
	system("cls");
}
//���浽�ļ�
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


//ͳ���ļ��е�����
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

//��ʼ��Ա��
void WorkerManager::initEmp() {
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	int id;
	string name;
	int deptId;
	int index = 0;//�ļ�����
	while (ifs>>id&&ifs>>name&&ifs>>deptId) {//���ݿո��ȡ
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

//��ʾְ����Ϣ
void WorkerManager::showInfo() {

	this->systemIsEmpty();

	for (int i = 0; i < this->empNum; i++)
	{
		this->empArray[i]->showInfo();
	}
	system("pause");
	system("cls");
}

//ɾ��ְ����Ϣ
void WorkerManager::deleteEmp() {
	
	this->systemIsEmpty();

	cout << "������Ҫɾ����ְ����ţ�" << endl;
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
		this->save();//���浽�ļ�
		cout << "ɾ���ɹ���" << endl;
	}
	else
	{
		cout << "ɾ��ʧ�ܣ���ְ�������ڣ�" << endl;
	}
	system("pause");
	system("cls");
}

//����id����ְ����Ϣ

int WorkerManager::getEmpById(int id) {

	this->systemIsEmpty();

	int index = -1;
	for (int i = 0; i < this->empNum; i++)
	{
		if (this->empArray[i]->id == id)
		{
			index = i;//����ְ������λ��
			break;
		}
	}
	return index;
	
}

//������������ְ����Ϣ
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
		cout << "���޴��ˣ�" << endl;
	}

}

//����ְ����Ϣ
void WorkerManager::getEmp() {
	
	this->systemIsEmpty();

	cout << "�������ѯ������" << endl;
	cout << "1.����ְ����Ų��ң�" << endl;
	cout << "2.����ְ����������" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		cout << "������ְ����ţ�" << endl;
		int id;
		cin >> id;
		int result = this->getEmpById(id);
		this->empArray[result]->showInfo();
	}
	else if(select == 2)
	{
		cout << "������ְ��������" << endl;
		string name;
		cin >> name;
		this->getEmpByName(name);
	}
	else {
		cout << "�������ѡ������" << endl;
	}
	system("pause");
	system("cls");
}


//����ְ���������
void WorkerManager::sortEmp() {

	this->systemIsEmpty();
	cout << "��ѡ��Ҫ�����ģʽ��" << endl;
	cout << "1.����(ASC)" << endl;
	cout << "2.����(DSC)" << endl;
	int select = 0;
	cin >> select;
	int len = this->empNum;
	for (int i = 0; i < len; i++)//ѡ������
	{
		int minOrMax = i;
		if (select==1)
		{
			for (int j = i + 1; j < len; j++)
			{
				if (this->empArray[minOrMax]->id > this->empArray[j]->id)//����
				{
					minOrMax = j;
				}
			}
		}
		else if (select == 2)
		{
			for (int j = i + 1; j < len; j++)
			{
				if (this->empArray[minOrMax]->id < this->empArray[j]->id)//����
				{
					minOrMax = j;
				}
			}
		}
		else
		{
			cout << "����ѡ������Ĭ���������У�" << endl;

			break;
		}
		
		if (minOrMax != i)
		{
			Worker* temp = this->empArray[minOrMax];
			this->empArray[minOrMax] = this->empArray[i];
			this->empArray[i] = temp;
		}
	}
	//��ʾ��Ϣ
	this->showInfo();
}

//�ж�ϵͳ���Ƿ��м�¼
void WorkerManager::systemIsEmpty() {
	if (this->empArray == NULL)
	{
		cout << "��ϵͳ��ְ����Ϣ��" << endl;
		system("pause");
		system("cls");
		return;
	}
}

