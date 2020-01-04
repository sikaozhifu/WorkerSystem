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
	cout << "�ɹ����" << addNum << "��ְ��" << endl;
	system("pause");
	system("cls");
}