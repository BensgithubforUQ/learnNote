#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class AbstractWorker {//ְ��������
public:
	//AbstractWorker();
	//virtual ~AbstractWorker();

	virtual void showPersonalInfo() = 0; //��ʾ������Ϣ�Ĵ��麯��
	//virtual int getDepartmentID();

public:
	int w_person_id; //ְ������id
	string w_name;//ְ����
	int w_department_id;//ְ������ID
	string w_job_define;//ְ��ְλ����
	string w_job_name;//ְ��ְλ����
};

