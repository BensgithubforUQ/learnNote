#include "workerManager.h"
//#include "worker.h"
#include "employee.h"
#include "boss.h"
#include "manager.h"
int main() {
	//����workerManager�����
	WorkerManager wm;
	/*AbstractWorker* w = NULL;
	w = new Employee("����", 1, 1);
	w->showPersonalInfo();*/

	while (1) {
		wm.show_Menu();
		cout << "���������ѡ��" << endl;
		int number;
		cin >> number;
		switch (number) {
		case 0://�˳�
			wm.exit_Menu();
			break;
		case 1://���ְ��
			wm.addEmployee();
			break;
		case 2://��ʾְ��
			wm.show_WorkerInfo();
			break;
		case 3://ɾ��ְ��
			wm.delete_Worker();
			break;
		case 4://�޸�ְ��
			break;
		case 5://����ְ��
			wm.search_Worker();
			break;
		case 6://����ְ��
			break;
		case 7://�������
			break; 
		defualt:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}