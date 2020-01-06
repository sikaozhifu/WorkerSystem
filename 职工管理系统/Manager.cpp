#include"Manager.h"

Manager::Manager(int id, string name, int deptId) {

	this->id = id;
	this->name = name;
	this->deptId = deptId;
}
//获取岗位信息
string Manager::getDepet() {
	return string("部门经理");
}
//显示个人信息
void Manager::showInfo() {
	cout << "职工编号：" << this->id
		<< "\t职工姓名：" << this->name
		<< "\t职工岗位：" << this->getDepet()
		<< "\t职工职责：完成老板交给的任务"<<endl;
}