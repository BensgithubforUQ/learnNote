#pragma once
#include <iostream>
using namespace std;

//����Ĵ�����ʹ��
//����Ҫ����ͷ�ļ����Ƿǳ����õ�stl�ļ�
//ע��set������insert�᷵��һ�����飨������������ֵ������multiset��insertֻ�᷵��һ��������

void pair_test0() {
	//��һ�ֹ�����ʽ
	pair<string, int>p("Tom", 18);
	cout << "output first element��" << p.first << endl;
	cout << "output second element��" << p.second << endl;
	//�ڶ��ַ�ʽ����
	pair<string, int>p2 = make_pair("Jerry", 30);
	cout << "output first element��" << p2.first << endl;
	cout << "output second element��" << p2.second << endl;
}
