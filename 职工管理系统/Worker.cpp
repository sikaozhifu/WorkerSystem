#include"Worker.h"
Worker::Worker(int id, string name, int deptId) {
	this->id = id;
	this->name = name;
	this->deptId = deptId;
}

string Worker::getDepet(int deptId) {
	if (deptId == 1)
	{
		return string("普通职工");
	}
	else if(deptId == 2)
	{
		return string("部门经理");
	}
	else
	{
		return string("公司总裁");
	}
}