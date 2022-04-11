#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "person.h"
using namespace std;

void myPrint(int a) {
	cout << a << endl;
}
/*����vector����*/
void test_vector() {
	vector<int> arr_vec;//����
	arr_vec.push_back(10);//������ֵ��vector��β�巨
	arr_vec.push_back(30);
	arr_vec.push_back(20);

	//ͨ�����������������е�����
	vector<int>::iterator itBegin = arr_vec.begin();//��ʼ��������ָ���һԪ��arr_vec[0]������ָ��
	vector<int>::iterator itEnd = arr_vec.end();//������������ָ�����һ��Ԫ�غ����һ��λ��arr_vec[size]
	//��һ�ֱ�������whileѭ��
	while (itBegin != itEnd) {
		cout << *itBegin << endl;//����Ҫ�ý���������ȡ���ݣ���Ϊ�˴��ĵ����������Ե���һ��ָ��
		itBegin++; //ָ��++��ʵ�����ڴ���λ���ƶ���
	}
	//�ڶ��ֱ�������forѭ��
	for (vector<int>::iterator it = arr_vec.begin(); it != itEnd; it++) {
		cout << *it << endl;//����Ҫ�ý���������ȡ���ݣ���Ϊ�˴��ĵ����������Ե���һ��ָ��
	}
	//�����ַ�����forѭ��auto i:arr_vec
	for (auto i : arr_vec) {
		cout << i << endl;
	}
	//�����ַ�������STL��algorithm�е��ṩ���㷨
	for_each(arr_vec.begin(), arr_vec.end(), myPrint);
	//ע�⣬���������˻ص��ļ���
	//��һ�������͵ڶ��������涨�˱������䣬����������һ��������
	//�ײ�Դ���Ǹ����������һ��forѭ��������Ȼ�󷵻���ֵ�������������ĺ�����ȥ
}


//vector �����д���Զ������������
void test_vector1() {
	vector<person>p_v;
	person p1("����", 10, "�������");
	person p2("����", 11, "�ж�����");
	person p3("����", 12, "С������");

	//���������������
	p_v.push_back(p1);
	p_v.push_back(p2);
	p_v.push_back(p3);

	//���������е�����
	for (vector<person>::iterator it = p_v.begin(); it != p_v.end(); it++) {
		(* it).showInfo();
	}
}
//vector �����д���Զ�����������ͣ���η�������ָ�룬�������ĵ�ַ�Ž�ȥ
void test_vector2() {
	vector<person*>p_v;//<person*>��ָ��
	person p1("����", 10, "�������");
	person p2("����", 11, "�ж�����");
	person p3("����", 12, "С������");

	//���������������
	p_v.push_back(&p1);//T *p = &p1 �ѵ�ַ�浽������
	p_v.push_back(&p2);
	p_v.push_back(&p3);

	//���������е�����
	for (vector<person*>::iterator it = p_v.begin(); it != p_v.end(); it++) {
		//(*(*it)).showInfo();//(*it)��it��ָ�룬�����person�����ĵ�ַ�����*itȡ��������person�����ĵ�ַ
		//*(*it)��*it��person�����ĵ�ַ���ټӸ�*��ȡ�����������
		(* it)->showInfo();//����д��Ҳ���ԡ�����this��>,thisҲ�Ǹ�ָ�롣
	}
}

//vector����Ƕ������
void v_V_push_back(int i, vector<vector<int>>&v_V, vector<int> &v1) {//����Ϊ����
	int max = i + 4;
	for (; i < max; i++) {
		v1.push_back(i);
	}
	v_V.push_back(v1);
}
void test_vector3() {//vector������Ƕ��vector������ʵ��һ�����ƶ�ά���������
	vector<vector<int>>v_V;
	vector<int> v1,v2,v3,v4;
	v_V_push_back(1, v_V, v1);
	v_V_push_back(2, v_V, v2);
	v_V_push_back(3, v_V, v3);
	v_V_push_back(4, v_V, v4);
	for (vector<vector<int>>::iterator it_v = v_V.begin(); it_v != v_V.end(); it_v++) {
		for (vector<int>::iterator it_int = (*it_v).begin(); it_int != (*it_v).end(); it_int++) {
			cout << *it_int <<" ";//*it_int���õ�����ȡ����Сvector�е�ֵ
		}
		cout << endl;
	}
}