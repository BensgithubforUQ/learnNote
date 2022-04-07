#pragma once//��ֹͷ�ļ��ظ�����
#include <iostream>
#include <string>
#include <fstream>
#include "worker.h"
using namespace std;

class WorkerManager {
public:
	//���캯��
	WorkerManager();
	//��������
	~WorkerManager();
	//�����Ժ���
		//��ʾ�˵�
	void show_Menu();
	void exit_Menu();
	void save_file();
	void addEmployee();
	int get_worker_number();
	void initial_Worker();
	void show_WorkerInfo();
	void search_Worker();
	int isExist(string name);
	int isExist(int id);
	void delete_Worker();
	void confirm_delete(int id);
private:
	int worker_size;
	AbstractWorker** worker_array;
	bool fileIsEmpty;
};