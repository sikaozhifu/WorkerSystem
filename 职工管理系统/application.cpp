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
		cout << "ÇëÊäÈëÄúµÄÑ¡Ôñ£º" << endl;
		cin >> select;
		switch (select)
		{
		case 0:
			wk.exitSystem();
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			system("pause");
			break;
		}
	}
	
	return 0;
}