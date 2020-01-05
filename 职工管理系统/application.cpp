#include<iostream>
using namespace std;
#include "WorkerManager.h"
#include "Worker.h"
#include "Manager.h"
int main() {

	WorkerManager wk;
	int select = 0;
	while (true)
	{
		wk.showMenu();
		cout << "请输入您的选择：" << endl;
		cin >> select;
		switch (select)
		{
		case 0:
			wk.exitSystem();
			break;
		case 1://增加职工信息
			wk.addEmp();
			break;
		case 2://显示职工信息
			wk.showInfo();
			break;

		case 3://删除离职职工
			wk.deleteEmp();
			break;
		case 4://修改职工信息
			break;
		case 5://查找职工信息
			break;
		case 6://按照编号排序
			break;
		case 7://清空所有文档
			break;
		default:
			system("pause");
			break;
		}
	}
	
	return 0;
}