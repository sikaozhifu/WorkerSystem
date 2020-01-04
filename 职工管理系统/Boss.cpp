#include "Boss.h"

Boss::Boss(int id, string name, int deptId) {
	this->id = id;
	this->name = name;
	this->deptId = deptId;
}
//获取岗位信息
string Boss::getDepet() {
	return string("公司总裁");
}
//显示个人信息
void Boss::showInfo() {
	cout << "职工编号：" << this->id
		<< "\t职工姓名：" << this->name
		<< "\t职工岗位：" << this->getDepet()
		<< "\t职工职责：管理公司所有事务"<<endl;
}