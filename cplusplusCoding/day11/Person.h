#pragma once
#include "myHead.h"
#include "Phone.h"
class Person
{
public:
	Person();
	Person(int a,int h,Phone p_P);
	Person(const Person &p); 
	~Person();//����������ͨ�����ڽ��������ٵ������ͷš�
	int getAge();
    int getHeight();
	void showP();//չʾ�����������
private:
	int age;
	int* m_height;//��ߣ���ָ������Ϊ��Ҫ�ڶ��������������
	Phone p_Phone;//�ֻ���
};

