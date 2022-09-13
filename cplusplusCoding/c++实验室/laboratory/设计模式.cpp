#pragma warning(disable:4996)
#include<iostream>
#include <windows.h>
#include<thread>
#include"factory.hpp"
#include"abstractFactory.hpp"
#include "singleton.hpp"
#include "poly.h"
using namespace std;

void test_factory() {
	//����ģʽ
	Factory* fac = new ConcreteFactory();
	Product* pro = fac->CreateProduct();
	
	delete fac;
	delete pro;
	//�������ԣ�����factory��product�������ù��������create��Ʒ�����⣬û�й�ϵ������˳����ء�
	//����ģʽ���������ڣ����칤���࣬Ȼ�����createXXX����(�÷��������װ��new XXX�Ĳ���)����������XXX�Ĳ���������
	//ȱ�����ڣ�����XXX��YYY��Ʒ����Ҫ����һ���µ�XXX����������µ�YYY�����࣬Ȼ��Ҫ������Ҫ��new�ù�����������鷳�ĵ��ˡ�
	//�ؼ���������౬ը��
}

void test_abstract_factory() {
	//���󹤳�ģʽ
	//factoryģʽʵ��new����factory��Ȼ��factory��������ʵ�ֶ�product��Ķ���Ĵ�������һ��������ۺ϶����Ʒ��
	AbstractFactory* ab_fac = nullptr;
	ab_fac = new ChineseFactory;
	AbstractApple *apple =  ab_fac->createApple();
	AbstractBanana* banana = ab_fac->createBanana();

	apple->showName();
	banana->showName();

	delete banana;
	delete apple;
	delete ab_fac;
	//�ŵ㣬������౬ը�����⡣
	//ȱ�㣬����౬ը�ķ�������������չ��Ʒ���ʱ����Ҫ�ڹ�����Ļ��������������ӷ�������չ�ѡ�
}

SingletonLazy* test_threadSafe() {
	return SingletonLazy::getInstance();
}

void test_SingletonsLazy() {
	Sleep(1000);
	if (SingletonLazy::getCount()) cout << "�Ѵ�������..." << endl;
	else cout << "��δ��������..." << endl;
	thread th_1(test_threadSafe);
	Sleep(1000);
	SingletonLazy* sl1 = test_threadSafe();
	SingletonLazy* sl2 = test_threadSafe();
	Sleep(1000);
	if (SingletonLazy::getCount()) cout << "�Ѵ�������..." << endl;
	else cout << "��δ��������..." << endl;
	if (sl1 == sl2) cout << "ͬһ��" << endl;
	th_1.detach();

}

void test_SingletonHungry() {
	SingletonHungry* sh1 = SingletonHungry::getinstance();
	SingletonHungry* sh2 = SingletonHungry::getinstance();
	if (sh1 == sh2) cout << "ͬһ��" << endl;
	cout << (int)sh1 << endl;
	sh1->freeSpace();
	sh2->freeSpace();
	cout << (int)sh2 << endl;
	SingletonHungry* sh3 = SingletonHungry::getinstance();
	//SingletonHungry::freeSpace();
}

void test_poly() {
	Poly_grandson gs;
	Poly g;
	Poly_daughter d;
	Poly_son s;

	cout << sizeof(gs) << " ";
	cout << sizeof(g) << " ";
	cout << sizeof(d) << " ";
	cout << sizeof(s) << " ";
}

void test_strcpy(char * c) {
	//c = (char*)malloc(100);
	int i;
	char str[10], str1[10];
	if (strlen(c) <= 10) strcpy(str, c);
	cout << strlen(c) << endl;
}



/*int main() {
	//test_SingletonHungry();
	//test_SingletonsLazy();
	//char* p = nullptr;
	//test_strcpy(p);
	//if(p!=nullptr) strcpy(p, "abcdedf");
	//printf("%s\n", p);
	

	//int a = 15, b = 26; //���ű��ʽ
	//cout << (a, b) << endl;

	//   C++��"cout << �ַ���ָ��"���������ʽ���Ÿ�����ַ����ˣ�
	// ����˵��������������Ϊ��ָ�뿪ʼһ����һ��������ڴ浥Ԫ����ַ���
	// ֱ������'\0'ʱΪֹ��Ҫ�������ַ��ǿ�Ƴɱ�����;Ϳ����ˣ���cout << (void *)&c << endl;�Ϳ���.
	//char c[] = {'0','1','2','3','\0'};
	//char* const p1 = c + 1;
	////char* c1 = "0123456789";
	//cout << *p1 << endl;
	//char d = 'n';
	////d = *p1;
	//cout << (void*) & d << endl;
	//test_strcpy(c);

	//vector<char>��string
	//string s1 = "123456789";
	//s1 += '\0';
	//s1 += '0';
	//cout << s1.back() << " " << s1.size() << endl;
	//vector<char> s2{ '1','2','3','4','5','6','7','8','9','\0' };
	//s2.push_back('\0');
	////s2.push_back('0');
	//cout << s2.back() << " " << s2.size() << endl;

	unique_ptr<int> u_ptr = make_unique<int>(114514);
	cout << *u_ptr << endl;
	
	return 0;
}*/