#pragma once
#include<iostream>
#include<string>
using namespace std;
#include "Worker.h"

class WorkerManager {
public:
	WorkerManager();
	
	~WorkerManager();
	//��ʾ�˵�
	void showMenu();
	//�˳�ϵͳ
	void exitSystem();
	//���ְ��
	void addEmp();
	int empNum;
	Worker ** empArray;
};