#include "workerManager.h"

WorkerManager::WorkerManager() {//���캯��

}

WorkerManager::~WorkerManager() {//��������

}

void WorkerManager::show_Menu() {//��ʾ�˵�
	cout << "��ӭʹ��ְ������ϵͳ" << endl;
	cout << "0.�˳�ְ������ϵͳ" << endl;
	cout << "**1.����ְ����Ϣ**" << endl;
	cout << "**2.��ʾְ����Ϣ**" << endl;
	cout << "**3.ɾ����ְְ��**" << endl;
	cout << "**4.�޸�ְ����Ϣ**" << endl;
	cout << "**5.����ְ����Ϣ**" << endl;
	cout << "6.�����ӡְ����Ϣ" << endl;
	cout << "**7.�����������**" << endl;
	cout << endl;
}

void WorkerManager::exit_Menu() {
	cout << "�ڴ��´�ʹ�ã��ټ�" << endl;
	system("pause");
	exit(0);
}