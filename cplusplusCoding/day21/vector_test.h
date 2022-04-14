#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "person.h"
using namespace std;

//vector Ҳ����Ϊ��������
//�����Ǿ�̬�ռ�ģ������Զ�̬��չ
//��̬��չ��������ԭ�еĿռ��������¿ռ䣬���Ǹ�������ռ��С����ԭ�������ݿ�����ȥ��
//vector���׶��Ƿ�յģ������Բ�����
//vector����β���βɾ��������insert��erase��ɾ����
//vector�ĵ������ǿ���������ʵģ�����ǿ���һ�ֵ�����
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

//��װһ��vector�Ĵ�ӡ
template<typename T>//СС�ĸ�ϰһ�º���ģ��
void printVector(vector<T> &v) {
	for(typename vector<T>::iterator it = v.begin();it!=v.end();it++){//typename���뱻���ϣ��Է�������
		//��Ϊ���������﷨���õ�::,<>���������������T�Ǹ����͵�ʱ��ǰ����ü�typename
		cout << *it <<" ";
	}
	cout << endl;
}

void test_vector4() {
	vector<int> v1;//�޲ι��죬Ĭ�Ϲ���
	for (int i = 0;i<10;i++){
		v1.push_back(i);
	}
	printVector(v1);
	//��������ķ�ʽ����
	vector<int>v2(v1.begin(), v1.end()-1);//��������һ��vector����������������,���ﻹ��������λ�ü��㡣
	printVector(v2);
	//n��elements�Ĺ���취
	vector<char>v3(10, 'a');
	printVector(v3);
	//��������
	vector<char>v4(v3);
	printVector(v4);
}

void test_vector5() {
	//��ֵ��Ҫ�����ص�=�ͷ�װ��assign����������
	//=
	vector<int> v1;
	vector<int> v2(10, 9);
	v1 = v2;
	printVector(v1);
	//assign
	v2.push_back(8);
	v1.assign(v2.begin()+10, v2.end());//ע��������һ�����ε��ǵ�ַ������ֵ��
	printVector(v1);

	//��n����
	v1.assign(10, 7);
	printVector(v1);
}

void test_vector6() {
	//�����ʹ�С
	//empty��capacity��size
	vector<char>v_char;
	for (int i = 65; i < 91; i++) {
		v_char.push_back((char)i);
	}
	printVector(v_char);

	cout << "�Ƿ�Ϊ�գ�0Ϊ����" << v_char.empty() << endl;
	cout << "������С��" << v_char.capacity() << endl;
	cout << "�������ȣ�" << v_char.size() << endl;
	cout << "���������ĳ��Ⱥ�������С�Ĳ�һ����������vector�Ķ�̬��չ������" << endl;
	//�������ó��ȣ�����̫���Ļ���Ĭ����0����
	v_char.resize(11);
	printVector(v_char);
	cout << "�Ƿ�Ϊ�գ�0Ϊ���� " << v_char.empty() << endl;
	cout << "������С��" << v_char.capacity() << endl;
	cout << "�������ȣ�" << v_char.size() << endl;
}

void test_vector7() {
	//�����ɾ����������Ҫ�õ���������������ֵ��Ҳ����˵Ҫ�õ�ַ��ͬ��������Ǹ�end��begin
	vector<int>v1(10, 9);
	//β�巨
	v1.push_back(11);
	printVector(v1);
	//βɾ��
	v1.pop_back();
	printVector(v1);
	//insert
	v1.insert(v1.begin(), 8);
	printVector(v1);
	v1.insert(v1.begin()+5,3 ,10);//�����Բ�n��һ��������
	printVector(v1);
	//erase ɾ��������ɾ�����䣬Ҳ����ɾ���������ǵ������������
	v1.erase(v1.begin() + 5,v1.begin()+8);
	printVector(v1);
	//clear ���
	v1.clear();
	printVector(v1);
	if (v1.empty()) {
		cout << "blank" << endl;
	}
}

void test_vector8() {
	//at��[]���ʣ�front��back
	vector<char>v_char;
	for (int i = 65; i < 91; i++) {
		v_char.push_back((char)i);
	}
	printVector(v_char);
	//front
	cout << "front: " << v_char.front() << endl;
	//back
	cout << "back: " << v_char.back() << endl;
	//at
	cout << "at.������һ��: " << v_char.at(v_char.size() - 1) << endl;
	//[]
	cout << "[]�� " << v_char[0] << endl;
}

void test_vector9() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	vector<int> v2(5, 10);
	//vector�������û�
	cout << "����ǰ��" << endl;
	printVector(v1);
	printVector(v2);
	cout << "������" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
	//����swap���������ڴ�ռ�
	vector<int>v3(10000001, 5);
	cout << "v3������С��" << v3.capacity() << endl;
	cout << "v3�������ȣ�" << v3.size() << endl;
	//�������һ��������10000001�ĳ���ɾ�ˣ���resize����һ��
	v3.resize(3);
	cout << "resize��v3������С��" << v3.capacity() << endl;
	cout << "v3�������ȣ�" << v3.size() << endl;
	//��������Ϳ�����swap����һ��
	//vector<int>(v3),���������¶���������������v3����������
	//.swap���ǰ�������������v3����
	//ע�⣬����������������ֻ������ֵ����������Ҳֻ��������
	cout << "��������������С��" << vector<int>(v3).capacity() << endl;
	cout << "���������������ȣ�" << vector<int>(v3).size() << endl;
	vector<int>(v3).swap(v3);
	//��ӡһ�½������v3����������������
	cout << "swap+resize��v3������С��" << v3.capacity() << endl;
	cout << "v3�������ȣ�" << v3.size() << endl;
}

void test_vector10() {
	//Ԥ���ռ�reserve
	vector<int> v1;
	v1.reserve(10);
	cout << "v1��ʼ����reserve��10��������С��" << v1.capacity() << endl;
	cout << "v1��ʼ����reserve��10���������ȣ�" << v1.size() << endl;
	//Ԥ���ռ������
	//����Ҫ��һ���޴������
	int* p = NULL;
	vector<int> v2;
	//v2.reserve(10000000);
	// �������reserve�Ĺ�Ч�������֪��Ҫ���پ޴�Ŀռ�Ļ���������ǰ��reserveԤ����
	//vector<int>::iterator p = v2.begin();
	int i = 0,num = 0;
	while (i < 10000000) {
		v2.push_back(i);
		if (p != &v2[0]) {
		//if (p != v2.begin()) {//ע������ʵ����һ��vector�ı��ʱ��ʹ�õ������Ĳ���
			//ע�⣬������������һһ��Ӧ��һ�������仯���������Ͳ������ˡ�
			p = &v2[0];
			//p = v2.begin();
			num++;
		}
		i++;
	}
	cout << "��̬��չ�ˣ�" << num << " ��" << endl;
	//���﷢�֣��������reserve���ﶯ̬��չ����ʮ��Σ����Ƿǳ����ص�����

}