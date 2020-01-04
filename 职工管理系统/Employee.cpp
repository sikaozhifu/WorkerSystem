#include"Employee.h"

Employee::Employee(int id, string name, int deptId) {
	this->id = id;
	this->name = name;
	this->deptId = deptId;
}
//获取岗位信息
string Employee::getDepet() {
	return string("普通员工");
}
//显示个人信息
void Employee::showInfo() {
	cout << "职工编号：" << this->id
		<< "\t职工姓名：" << this->name
		<< "\t职工岗位：" << this->getDepet()
		<< "\t职工职责：完成经理交给的任务"<<endl;
}