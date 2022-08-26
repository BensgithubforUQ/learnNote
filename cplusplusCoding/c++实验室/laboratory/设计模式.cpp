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

void test_strcpy(char * &c) {
	c = (char*)malloc(100);
}

int main() {
	//test_SingletonHungry();
	//test_SingletonsLazy();
	char* p = nullptr;
	test_strcpy(p);
	if(p!=nullptr) strcpy(p, "abcdedf");
	printf("%s\n", p);
	return 0;
}