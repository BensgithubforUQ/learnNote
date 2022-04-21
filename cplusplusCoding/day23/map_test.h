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

template<typename T>
void printContainer(const multimap<int, T>& m) {
	for (typename multimap<int, T>::const_iterator it = m.begin(); it != m.end(); it++) {
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

void test_map1() {
	//insert������
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(3,30));
	m.insert(map<int,int>::value_type(2,21));
	m[4] = 40;//������Ƽ��ã������Ǵ���keyֵΪ4��valueΪ40��pair�����׳���
	cout << m[5] << endl;//���m[5]ʵ�����Ǵ���һ��keyֵΪ5,valueΪ0��ֵ��
	printContainer(m);
	//ɾ��erase
	m.erase(m.begin());
	printContainer(m);
	m.erase(2);//����keyֵɾ��
	printContainer(m);
	m.erase(m.begin(), --m.end());//���������ģʽɾ��
	printContainer(m);
	//clear
	m.clear();
	if (!m.empty()) {
		printContainer(m);
	}
	else {
		cout << "blank container" << endl;
	}
	
}

void test_map2() {
	//find,����key��ѯ
	//count������keyͳ��
	multimap<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(3, 30));
	m.insert(multimap<int, int>::value_type(2, 21));
	//m[4] = 40;//������Ƽ��ã������Ǵ���keyֵΪ4��valueΪ40��pair�����׳���

	map<int, int>::iterator target = m.find(1);
	if (target != m.end()) {
		cout << "�ҵ���: " << target->first << " " << target->second << endl;
		cout << "һ���У� " << m.count(1) << endl;
	}
	else {
		cout << "û�ҵ�" << endl;
	}

}
class myCompare {
public:
	bool operator()(int p1,int p2) const{
		return p1 > p2;
	}
};

template<typename T>
void printContainer( map<int, T, myCompare>& m) {
	for (typename map<int, T, myCompare>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key��" << (*it).first << " value:" << it->second << " ";
	}
	cout << endl;
}

void test_map3() {
	map<int, int, myCompare>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(3, 30));
	m.insert(map<int, int>::value_type(2, 21));
	m[4] = 40;//������Ƽ��ã������Ǵ���keyֵΪ4��valueΪ40��pair�����׳���
	cout << m[5] << endl;//���m[5]ʵ�����Ǵ���һ��keyֵΪ5,valueΪ0��ֵ��
	printContainer(m);
}