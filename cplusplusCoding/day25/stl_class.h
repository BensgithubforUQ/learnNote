#pragma once
#include <iostream>
#include <string>
using namespace std;

//��������
/*stl��������
���ز��ݵ��ò��������࣬�����Ǹ��࣬������Ϊ��������
����ʹ�õ�ʱ������������Խзº���*/
/*
1.�����в����������з���ֵ��
2.������ͨ�����ĸ������ӵ���Լ���״̬
3.�������������Ϊ�������д���
*/
class myAdd {
public:
	int operator()(int v1, int v2);
};

int myAdd::operator()(int v1, int v2) {
	return v1 + v2;//�����з���ֵ�������в���
}

void test0() {
	myAdd my_add;
	cout << my_add(10, 32) << endl;//��һ������һ�����ã��в�����Ҳ�з���ֵ
}

class myPrint {//�������Լ���״̬
public:
	myPrint() {
		this->count = 0;
	}
	void operator()(string s1);
	//��������һ��ֵ������¼������������˶��ٴ�
	int count;
};

void myPrint::operator()(string s1) {
	this->count++;
	cout << s1 << endl;
}

void test1() {
	myPrint my_Print;
	my_Print("test");//��һ������һ�����ã��в�����Ҳ�з���ֵ
	my_Print("test");
	my_Print("test");
	my_Print("test");
	
}

void doPrint(myPrint &p,string test) {
	p(test);
	cout << "my_Print�����ˣ�" << p.count << "��" << endl;
}


void test2() {//3.�������������Ϊ�������д���
	myPrint my_Print;
	for (int i = 0; i < 5; i++) {
		doPrint(my_Print, "hello world");
	}
	//��ϰһ�£����ô��Σ���ʵ�Σ������βΡ�
}