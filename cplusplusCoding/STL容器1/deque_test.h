#pragma once
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

//deque��������Ϊ˫������
//�����vector������ͷ�����в���Ļ���vector������ҪŲ���ڴ洢���λ�ã���ǳ�������
//����vector���������ڷ����ٶȿ죬��Ϊvector�Ǵ���һ�����������Կռ����
//��deque����������һ�����������Կռ�

/*deque��vector�Ľṹ�����ƣ������Ƕ�������ռ䣬
���vector�ռ䲻����ʱ��Ҫ���·���ռ䣬�������е����ݸ��Ƶ��µĿռ���ȥ��
deque������ô��������ȥ���⿪��һ�������ռ�ȥ������ݣ�
���Դ洢Ч�ʷ���deque����vector,
��deque�ֲ�ͬ������������˵��˳��洢�ṹ����ʽ�洢�ṹ��һ�����з���*/

/*deque����һ���п�����ά��ÿ�λ�����֮�е����ݣ��������д����ʵ����
�п�����ά�����ǻ������ĵ�ַ��ʹʹ��deque��ʱ�������ڷ���һƬ�������ڴ�ռ�
��ˣ�����Ԫ�أ�deque��Ҫ�����п�����ά���ĵ�ַ��Ȼ��ͨ����ַ���ʶ�Ӧ�Ļ�������Ȼ���ҵ���Ӧ������*/

/*deque�ĵ�����ҲҲ��֧��������ʵģ�����߼���*/
template<typename T>
void printDeque(const deque<T>&deq) {//�ٴ����Ժ���ģ��
	for (typename deque<T>::const_iterator it = deq.begin(); it != deq.end(); it++) {//ֻ��������
		cout << *it << " ";
		//����const֮�󣬾Ͳ��������������������޸ĵ�����ˣ��Ƚϰ�ȫ��
		//ע����const_iterator������const iterator
	}
	cout << endl;
}
void test_deque0() {
	//���캯��
	//��vectorһ����dequeҲ��Ĭ�ϣ������Ǽ���
	deque<int> deq;
	for (int i = 0; i < 10; i++) {
		deq.push_back(i);
	}
	printDeque(deq);
	//������һdeque�������ʼ��
	deque<int>d2(deq.begin(), deq.end());
	printDeque(d2);
	//������n��ʼ��
	deque<int>d3(10, 9);
	printDeque(d3);
	//����һ��deque����֮���ʼ����������ʼ��
	deque<int>d4(d3);
	printDeque(d4);
}

void test_deque1() {
	//��ֵ����
	//Ҳ��vector������һ��
	deque<int>d1, d2, d3, d4;
	d1.assign(10, 9);//n��mֵ�ĸ�ֵ��ʽ
	printDeque(d1);
	d2 = d1;//�����ķ�ʽ
	printDeque(d2);
	for (int i = 0; i < 10; i++) {
		d3.push_back(i);
	}
	d4.assign(d3.begin() + 1, d3.end());
	printDeque(d3);
	printDeque(d4);//assign����ĸ�ֵ��ʽ
}

void test_deque2() {
	//deque�����Ĵ�С����,����ָ����С����,��vector���������ڣ�dequeû�������ĸ��
	deque<int>d1;
	d1.assign(10, 9);
	printDeque(d1);
	cout << "d1�Ĵ�СΪ��" << d1.size() << endl;
	//resize
	d1.resize(20);
	printDeque(d1);//����Ŀռ���0����
	cout << "d1�Ĵ�СΪ��" << d1.size() << endl;
	//resize��С�ĳ���
	d1.resize(5);
	printDeque(d1);
	cout << "d1�Ĵ�СΪ��" << d1.size() << endl;
	cout << "resize������" << endl;
	if (!d1.empty()) {
		cout << "d1.empty()��ֵΪ��" << d1.empty() << endl;//Ϊ0����Ϊ��
		cout << "d1��Ϊ��" << endl;
		cout << "d1�Ĵ�СΪ��" << d1.size() << endl;
		d1.resize(0);
	}
	if (d1.empty()) {
		cout << "d1Ϊ��" << endl;
		cout << "d1�Ĵ�СΪ��" << d1.size() << endl;
	}
}

void test_deque3(){
	//push_back,pop_back,pop_front,push_front
	//insert,erase,clear
	//���˵Ĳ����ɾ��
	deque<int>d1;
	d1.push_back(20);
	d1.push_back(21);
	d1.push_front(19);
	d1.push_front(18);
	printDeque(d1);
	d1.pop_front();
	d1.pop_back();
	printDeque(d1);
	//insert
	d1.insert(d1.begin() + 1, 111);//�����������ʾλ�ã���һ����Ҫ�����ֵ
	printDeque(d1);
	d1.insert(d1.begin() + 1, 3, 20);//�����������ʾλ�ã���n����Ҫ�����ֵ
	printDeque(d1);
	deque<int>d2(9, 9);
	printDeque(d2);
	d1.insert(d1.begin(), d2.end() - 3, d2.end());//����������룬����һ��������������
	printDeque(d1);
	//eraseɾ��
	deque<int>::iterator it = d1.begin() + 3;
	d1.erase(it);
	printDeque(d1);//ɾ��ָ��λ�õ�ֵ��
	d1.erase(d1.begin()+1, it);
	printDeque(d1);
	//clear
	d1.clear();
	printDeque(d1);//ֱ�������
}

void test_deque4() {
	//[] at,front,back
	deque<int>d1;
	d1.push_back(20);
	d1.push_back(21);
	d1.push_front(19);
	d1.push_front(18);
	//[]
	cout << "��[]����" << endl;
	for (int i = 0; i != d1.size(); i++) {
		cout << d1[i] << " ";
	}
	cout <<endl << "�õ���������" << endl;
	//*������
	for (deque<int>::const_iterator it = d1.begin(); it != d1.end(); it++) {
		cout << *it << " ";
	}
	
	cout << endl << "��at����" << endl;
	//at
	for (int i = 0; i != d1.size(); i++) {
		cout << d1.at(i) << " ";
	}
	//front & end
	cout << endl << "front & end" << endl;
	cout << d1.front() << " " << d1.back() << endl;
}

void test_deque5() {
	//������algorithm�����sort
	deque<int>d1;
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
		d1.push_front(i);
	}
	printDeque(d1);//��ӡһ��
	sort(d1.begin(),d1.end());
	cout << "sort���˳��,Ĭ�������㷨" << endl;
	printDeque(d1);
	//����֧��������ʵĵ���������������������sort������vector��
}