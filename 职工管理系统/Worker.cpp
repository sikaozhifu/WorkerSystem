#include"Worker.h"
Worker::Worker(int id, string name, int deptId) {
	this->id = id;
	this->name = name;
	this->deptId = deptId;
}

string Worker::getDepet(int deptId) {
	if (deptId == 1)
	{
		return string("��ְͨ��");
	}
	else if(deptId == 2)
	{
		return string("���ž���");
	}
	else
	{
		return string("��˾�ܲ�");
	}
}