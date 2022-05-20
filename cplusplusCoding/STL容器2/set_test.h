#pragma once
#include <iostream>
#include <set>
#include <list>
#include <time.h>
#include "Person.h"
using namespace std;

template<typename T>
class  MyCompare;



/*set���ڹ���ʽ�������ײ�ṹ�Ƕ�����������Ԫ���ڲ����ʱ����Զ�����*/
/*set��multiset������
set�������ظ�Ԫ�أ�multiset�����ظ�Ԫ��*/
template <typename T>
void printContainer(set<T> &s1) {//����ģ�壬��ӡset����������
	if (!s1.empty()) {
		cout << "size: " << s1.size() << " set :";
		for (typename set<T>::const_iterator it = s1.begin(); it != s1.end(); it++) {
			cout << *it << " ";
		}
	}
	else {
		cout << "it is NULL";
	}
	cout << endl;
}



template <typename T>
void printContainer(multiset<T>& s1) {//����ģ�壬��ӡmultiset����������
	if (!s1.empty()) {
		cout << "size: " << s1.size() << " set :";
		for (typename multiset<T>::const_iterator it = s1.begin(); it != s1.end(); it++) {
			cout << *it << " ";
		}
	}
	else {
		cout << "it is NULL";
	}
	cout << endl;
}

template <typename T>
void printContainer(list<T>& l1) {//����ģ�壬��ӡ��������������
	if (!l1.empty()) {
		for (typename list<T>::const_iterator it = l1.begin(); it != l1.end(); it++) {
			cout << *it << " ";
		}
	}
	else {
		cout << "it is NULL";
	}
	cout << endl;
}

template <typename T>
void printContainer(set<T,MyCompare<T>>& s1) {//����ģ�壬��ӡ����������set����������
	//֪ʶ�㣬��ģ�����ǰ��������ģ���ʹ�ã��º���+��ģ��+STL����+����ģ��ͬʱʹ��
	//���أ���װ
	if (!s1.empty()) {
		cout << "size: " << s1.size() << " set :";
		for (typename set<T>::const_iterator it = s1.begin(); it != s1.end(); it++) {
			cout << *it << " ";
		}
	}
	else {
		cout << "it is NULL";
	}
	cout << endl;
}


void set_test0() {
	srand((unsigned int)time(NULL)); //�������������
	//����
	set<double> s1,s3;
	list<double> l1;
	for (int i = 10; i > 0; i--) {
		double temp = i + (rand() % 99 + 0) + (rand() / double(RAND_MAX));
		s1.insert(temp);//��������
		l1.push_back(temp);
		if (i == 10) {
			//���£�������ͬ������
			s1.insert(temp);
			l1.push_back(temp);
		}
	}
	printContainer(s1);  //���Ǵ�ӡ��ʱ�򣬳�����������ģ���������set���������ԡ�
	printContainer(l1); //��ӡһ�������������Ƚ��½��
	cout << "����ĳ��ȣ�" << l1.size() << " set�����ĳ��� " << s1.size() << endl;
	//����2
	set<double > s2(s1);
	// = ��ֵ
	s3 = s2;
	//printContainer(s3);
}

void set_test1() {
	srand((unsigned int)time(NULL)); //�������������
	set<double> s1, s2;
	for (int i = 10; i > 0; i--) {
		s1.insert((rand()%99 + 1) + (rand()/double(RAND_MAX)));//��������
		s2.insert((rand() % 99 + 1) + (rand() / double(RAND_MAX)));//�������룬�������
		//����
		if (i == 10) {
			s2.insert((rand() % 99 + 1) + (rand() / double(RAND_MAX)));
		}
	}
	printContainer(s1);
	printContainer(s2);
	s1.swap(s2);//��Բ�ͬ���ȵ�set����Ҳ������
	printContainer(s1);
	printContainer(s2);
}

void set_test2() {
	set<int> s1;
	s1.insert(11);
	s1.insert(12);
	s1.insert(10);
	s1.insert(8);
	printContainer(s1);
	s1.erase(s1.begin()); //�õ�����ɾ
	printContainer(s1);
	s1.erase(10);
	printContainer(s1); //��ֵɾ
	set<int>s2(s1);
	s1.clear();//���
	printContainer(s1);
	s2.erase(s2.begin(), s2.end());
	printContainer(s2);
}

void set_test3() {
	//find��count
	multiset<int> s1; //multiset���ǿ����ظ�Ԫ�ص�set
	s1.insert(11);
	s1.insert(11);
	s1.insert(11);
	s1.insert(11);
	s1.insert(12);
	s1.insert(10);
	s1.insert(8);
	multiset<int>::iterator it_11 = s1.begin();
	//multiset<int>::iterator it_11 = s1.find(11); //�������11�����ص���11��Ӧ�ĵ���������������ڷ���end����
	/*if (it_11 != s1.end()) {
		cout << "11���� " <<s1.count(11) <<" ��" << endl;

	}*/
	int i = 0;
	do
	{
		++i;
		it_11 = s1.find(11);
		printContainer(s1);
		cout << "11���� " << s1.count(11) << " ��" << endl;
		//cout << "ɾ��һ��11" << endl;
		//s1.erase(it_11);//���ﲻ��ɾ����Ϊ�����и����������ã�set��list��ͬ������������������һ�����������
		//*it_11,���Ǹ�const��!!!!!
		if (i > s1.size()) {
			break;//���ѭ��ע����ѭ��hh
			//��Ϊû����set�������������
		}

	} while (it_11 != s1.end());
}
//��װ���ж��Ƿ����ɹ��ĺ���
//template <typename T>
//void insertFeedback(pair<typename set<T>::iterator, bool> ret) {
void insertFeedback(bool target){
	if(target) {
		cout << "����ɹ�" << endl;
	}
	else{
		cout << "����ʧ��" << endl;
	}
}
void set_test4() {
	//set��multiset������
	set<int> s1;
	multiset<int> s2;
	cout << "insert multiple same element into a set" << endl;
	for (int i = 0; i < 10; i++) {
		pair<set<int>::iterator, bool> ret = s1.insert(10);
		// insertFeedback�����Լ���װ�������ж��Ƿ����ɹ��ĺ���
		insertFeedback(ret.second);
		//pairΪ���飬��һ���������ͣ���s1.insert�����᷵������ֵ��һ���ǲ����λ�ã�һ�����Ƿ����ɹ�
	}
	cout << "insert multiple same element into a multiset" << endl;
	for (int i = 0; i < 10; i++) {
		multiset<int>::iterator pos = s2.insert(10);
		//multiset��insertû�з��ض����������ͣ�ֱ�ӷ��ص���һ����������
		// insertFeedback�����Լ���װ�������ж��Ƿ����ɹ��ĺ���
		insertFeedback(pos != s2.end());
		//pairΪ���飬��һ���������ͣ���s1.insert�����᷵������ֵ��һ���ǲ����λ�ã�һ�����Ƿ����ɹ�
	}
	
}

template<typename T>
class  MyCompare {//�º���
public:
	bool operator()(T first,T second) const;//���أ�����ע������ط��������const�ᱨ��
	
	/*Error C3848 : expression having type ��const myCompare�� 
		would lose some const - volatile qualifiers in order to call 
		��bool myCompare::operator ()(int, int)��*/
		//volatile���
		// 
//�������ݴ����˼Ϊ:����Ĳ������ʽӦ���С�const myCompare�����ͣ�
//������õġ�bool myCompare::operator ()(T, T)�����߱�const���ԣ�
//�ᶪʧconst�޶��������޷�ͨ�����롣
//
//��ֻҪ��operator()����const���Ա�ɣ�����

};

template<typename T>
bool MyCompare<typename T>::operator() (T first, T second) const {
	
	return first > second;
}



//set�����������߼�
void set_test5() {
	//�º����ٴ����á�
	//set����������õ��������͵������߼�
	set<int> s1;
	for (int i = 10; i > 0; i--) {
		s1.insert(i);//��������,������Զ���������
	}
	printContainer(s1);
	//ָ���������Ϊ����
	//��Ϊset��������Ĭ������ģ����Ҫ�ڴ���set������ʱ�򣬾��趨���������
	set<int, MyCompare<int>> s2;
	
	for (int i = 10; i > 0; i--) {
		s2.insert(i);
	}
	printContainer(s2);//�����о�������+��װ������������汾��set�����Ĵ�ӡ��ʽ��
	//for (set<int>::iterator it = s2.begin(); it != s2.end(); it++) {
	//	cout << *it << " ";
	//}
}



//set�����������߼�-�Զ����������͵�����
//��person����Ϊʵ�����----------------------------------------------------------------------
class myCompare_Person {//�º���
public:
	bool operator()(const Person& p1, const Person& p2) const;//���أ���,�Զ����������͵���������趨
};
bool myCompare_Person::operator()(const Person& p1, const Person& p2) const {
		if (p1.getAge() == p2.getAge()) return p1.getheight() < p2.getheight();
		return p1.getAge() > p2.getAge();//����ط����˺þ���ô��person���л���private����������
		//����ʧ���ˣ����ջ��ǰ�person�ĳ���public���������ͣ���Ȼ����ط�ʼ�ձ�����ʱ��֪����ô���
}
void printContainer(set<Person, myCompare_Person>& s1) {
	//˵������Ŀӣ����������set���������Ҫ���ϣ���Ȼ�Ҳ����������
	//��Σ��������������ģ�岢����������ϵ��ֱ�ӵ�������д
	//�ٴΣ�����ѷº����Ķ���д�����ǰ�档
	if (!s1.empty()) {
		cout << "size: " << s1.size() << " set :";
		for (typename set<Person>::iterator it = s1.begin(); it != s1.end(); it++) {
			it->showInfo();
		}
	}
	else {
		cout << "it is NULL";
	}
	cout << endl;
}


//set�����������߼�-�Զ����������͵�����
//��person����Ϊʵ�����
void set_test6() {
	int size = 10;
	set<Person, myCompare_Person> s_p;
	for (int i = 0; i < size; i++) {
		char name_temp = (i + 65);
		string name{ name_temp };
		int age = rand() % 25 + 20;
		float height = (rand() % 30 + 160) + (rand() / double(RAND_MAX));
		Person p_temp(name, age, height);
		s_p.insert(p_temp);//�������ֱ������Ļ����ͻᱨ����Ϊ���������
		//�Ͼ�����������֪����ô�Ƚ��Զ����������͵Ĵ�С���͸���������
		/*error C2676 : �����ơ� < �� : ��const _Ty����������������Ԥ����������ɽ��յ����͵�ת��*/
		//����Զ�����������Ͷ���ָ���������
		//������ﻹ��Ҫ�õ��º������º��������Ǹ��ࡣ
	}
	printContainer(s_p);
}