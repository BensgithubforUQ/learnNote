#pragma once
#include "myHead.h"

class Fruit {
public:
	//���캯��
	Fruit();
	Fruit(string color);
	Fruit(const Fruit &f);//������const����Ϊ�ǳ�ʼ�������ܸı䴫������ֵ
	//Ȼ�󻹱���������
	//��������
	~Fruit();
	void getColor();
private:
	string color;
};