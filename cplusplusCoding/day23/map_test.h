#pragma once
#include <map>
#include <iostream>
using namespace std;

/*map�ǹ��������������е�Ԫ�ض���pair����һ��ֵΪkey��ֵ���ڶ���Ԫ��Ϊvalueʵֵ
����Ԫ�ض������key��ֵ�Զ�����
�ײ�ṹ�Ƕ�����

�ŵ㣺���Ը���keyֵ�����ҵ�valueֵ������set���߱��ģ�setֻ�ܸ���ֵ�ҵ�����λ��
*/
template<typename T>
void printContainer(const map<int,T> &m) {
	for (typename map<int, T>::const_iterator it = m.begin(); it != m.end(); it++) {
		cout << "key��" << (*it).first << " value:" << it->second << " ";
	}
	cout << endl;
}
void test_map0() {
	map<int, int>m0;
	m0.insert(pair<int, int>(1, 10));//pair<int, int>(1, 10)��һ��������pair����
	m0.insert(pair<int, int>(3, 30));
	m0.insert(pair<int, int>(2, 20));
	m0.insert(pair<int, int>(4, 40));
	m0.insert(pair<int, int>(6, 60));
	m0.insert(pair<int, int>(5, 50));
	m0.insert(pair<int, int>(7, 70));//����keyֵ���򣬲��ǰ���value
	printContainer(m0);
	//��������
	map<int, int>m1(m0);
	m1.insert(pair<int, int>(8, 80));
	printContainer(m1);
	//��ֵ
	map<int, int>m3;
	m3 = m1;
	printContainer(m3);
	//map�����Ĵ�С�ͽ���
	//size����������Ԫ�ظ�����empty
	//swap
	if (!m1.empty()) {
		cout << "m1���ǿյ����������СΪ��" << m1.size() << endl;
	}
	m1.swap(m0);//����
	printContainer(m0);
}