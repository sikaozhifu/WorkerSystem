#pragma once
#include<iostream>
#include<string>
using namespace std;
#include "Worker.h"
#include<fstream>
#define FILENAME "empFile.txt"

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
	//���浽empFile.txt�ļ���
	void save();
	//������ְ������
	int empNum;
	//ְ������
	Worker ** empArray;

	//�ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;

	//ͳ���ļ��е�����
	int getNumInFile();

	//��ʼ��Ա��
	void initEmp();

	//��ʾְ����Ϣ
	void showInfo();
};