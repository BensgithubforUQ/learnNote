#pragma once
#include "worker.h"
//class AbstractWorker {//ְ��������
//public:
//	//AbstractWorker();
//	virtual ~AbstractWorker();
//
//	virtual void showPersonalInfo() = 0; //��ʾ������Ϣ�Ĵ��麯��
//	virtual void getDepartmentID();
//
//
//	int w_person_id; //ְ������id
//	string w_name;//ְ����
//	int w_department_id;//ְ������ID
//	string w_job_define;//ְ��ְλ����
//	string w_job_name;//ְ��ְλ����
//};

//��ͨ��Ա��
class Employee : public AbstractWorker {
public:
	Employee(string n,int id,int d_id);
	~Employee();
	void showPersonalInfo();
	string getDepartmentInfo();
	string getJobInfo();
};