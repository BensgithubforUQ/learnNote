#pragma once
#include <iostream>
#include <string>
#include "virtual_father.hpp"
using namespace std;

template<class T1, class T2, class T3 >//����һ��buff�ĵ�
class abstractFather {
public:
	virtual void showInfo() = 0;
	T1 name;
	T2 age;
	T3 id;
	//��������:��Ϊ�����п����˶������ݣ��ͷŸ���ָ���ʱ���޷�����������������
	//�����Ҫ���������ߴ�������
	//����������Ҫ���ж��壬����ʵ��
	abstractFather() {
		cout << "���๹�캯������" << endl;
	}
	virtual~abstractFather() = 0;
};

template<class T1, class T2, class T3 >
abstractFather<T1, T2, T3 >::~abstractFather() {//��ģ��Ĵ�����������������ʵ��
	cout << "������������" << endl;
}