#pragma once
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

//������������鲻ͬ�����������������Կռ䣬���������ǣ���������ÿ���ڵ�����¼���ڵĽڵ��λ��
//�ڵ����������ָ���򹹳ɣ���������ʾ��������ݣ�����ָ����ά�������ڵĽ��ĵ�ַ�����һ��ָ��NULL
/*������ŵ㣺
���Զ������λ�ã�ͨ������ָ����ķ�ʽ�����п��ٵ���ӣ����룬ɾ��
������ɴ����Ŀռ��˷ѣ���Ϊ�����һ��������ģ���������������һ���Է���������ڴ�ռ�*/
/*�����ȱ�㣺
���ȶ��������ı����ٶȣ�û������졣��Ϊ������ڴ�ռ��������ġ�
ռ�õĿռ䣬�������Ҫ����Ϊ�������ָ����ָ��Ҫռ�ĸ��ռ䣨x32��*/
//������������ȱ���ǻ����ģ���Ҫ����������Ŷ���

/*STL�з�װ��list��������һ��˫��ѭ���ġ�
list����������ָ�룬һ��ָ��ǰһ����㣬һ��ָ����һ����㡣��������ͷ������β����
����stl����������ͷβ֮�֣���begin��end��push_front,push_back,pop_front,��
��Ϊ�����������ڴ�ռ䣬��˵�������Ҳ��������ʵģ���˫���������ֻ֧��ǰ�ƺ���
*/

//��Ҫ���ʣ�vector�У�������һ��ɾ������������һ����һ��������ȥ�������ݣ�����list�п��ԡ�
//list��vector����õ�����������������֮�ء�
//�ص�����myCompare������ʵ�ֽ�������
bool myCompare(int v1, int v2) {
	//���� ���õ�һ���� > �ڶ�����
	return v1 > v2;
	//����v1>v2�ͻ᷵��һ������ֵ��������ھͻ᷵����
}

template<typename T>
void printList(const list<T> &l) {
	if (!l.empty()) {
		for (typename list<T>::const_iterator it = l.begin(); it != l.end(); it++) {
			cout << *it << " ";
		}
	}
	else {
		cout << "��������" << endl;
	}
	cout << endl;
}

void list_test0() {//һϵ�л���list�����Ĳ���
	//���캯��
	list<int>l1,l4,l5;
	list<int>l2(10, 9);
	list<int>l3(l2);

	//��ֵһ��
	for (int i = 0; i < 10; i++) {
		l1.push_back(i+10);
	}
	//��ֵassign
	l4.assign(l1.begin(), l1.end());//������Ϊ���������ڴ��ַ����˲���+-��ַ�Ĳ���
	printList(l1);
	printList(l2);
	printList(l3);
	printList(l4);
	cout << "l5��size: " << l5.size() << endl<<"��l1 & l5����swap����"<<endl;
	l5.swap(l1);
	if (!l5.empty()) {//l5��=0
		cout << "l5.empty() :" << l5.empty() << endl;
		printList(l5);
		//resize
		cout << "l5.resize(5);" << endl;
		l5.resize(5);
		printList(l5);
		//resize
		cout << "l5.resize(10);" << endl;
		l5.resize(10,1024);//�ڶ����������������������
		printList(l5);
	}
	//list�����Ĳ����ɾ��
	cout << "list�����Ĳ����ɾ��" << endl;
	for (int i = 0; i < 10; i++) {
		l1.push_back(i + 10);
		l1.push_front(i + 100);
	}
	//β���ͷ��Ľ��
	cout << "β���ͷ��Ľ���� ";
	printList(l1);
	//ͷɾ1��Ԫ�أ�βɾ2��Ԫ��
	l1.pop_back();
	l1.pop_back();
	l1.pop_front();
	cout << "ͷɾ1��Ԫ�أ�βɾ2��Ԫ�أ� ";
	printList(l1);
	//insert����
	list<int>::iterator it = l1.begin();
	++it;//����+value�����ǿ���++��������˫����������ص㣬ֻ��һ�����ӣ�����һ����������֧��������ʵ����֡�
	l1.insert(it, 1024);
	cout << "//insert����,��ͷ������һ�������룬1024�� ";
	printList(l1);
	//ɾ�� erase
	//l1.erase(++it);
	//l1.erase(it);
	//���������һ������Ȥ������������itά������Ȼ����һ��insert֮ǰ�Ľ�㡣
	//��Ҫ���ʣ�vector�У�������һ��ɾ������������һ����һ��������ȥ�������ݣ�����list�п��ԡ�
	//����������++it��ɾ������ʵ�������еĵ��ĸ�����
	//�������ɾ��it��ɾ����ʵ����û��insert֮ǰ��it��¼������
	//������¶���һ�������������ң������������,�������¸�ֵΪһ������ȷ��λ�õ�ê�㡣
	list<int>::iterator it_2 = l1.begin();
	++(++it_2);
	l1.erase(it_2);
	cout << "//ɾ�� erase,������㣺 ";
	printList(l1);
	//remove
	cout << "�Ȳ���һЩһ��������" << endl;
	for (int i = 0; i < 10; i++) {
		l1.push_back(100);
		l1.push_front(100);
	}
	printList(l1);
	cout << "//ɾ��remove���е�100�� ";
	l1.remove(100);
	printList(l1);
	//���clear
	l1.clear();
	cout << "//clear ";
	printList(l1);
	//����front��back
	cout << "l5��Ԫ��Ϊ ";
	printList(l5);
	cout << "����front�� " << l5.front() << " ����back ��" << l5.back() << endl;
	//list�ķ�ת������
	cout << "//list��ת�� ";
	l5.reverse();
	printList(l5);
	cout << "//list���� ";
	//sort(l5);
	//���У�˫�����������������֧��������ʵĵ�������������������֧���㷨��׼ģ����з�װ��sort����
	//��ˣ����������з�װsort������
	l5.sort();//Ĭ������
	printList(l5);
	cout << "//list���򣨽��򣩣� ";
	//������������Ϸ�����
	l5.sort(myCompare);//sort��myCompare�����ص��������ǡ�
	printList(l5);
}